#include <cstdlib> 
#include <iostream>
#include <fstream>
#include <chrono>

#include <image.h>

using namespace std; 

auto do_routine(int rows, int cols, int repeats){

    // INICIO PARTE FUERA DEL CRONO

    Image im(rows,cols);

    // FIN FUERA DEL CRONO

    // start time
    auto start = chrono::high_resolution_clock::now();

    // INICIO PARTE DENTRO DEL CRONO

    for (int j=0; j<repeats; j++){
        im.ShuffleRows();
    }

    //FIN PARTE DENTRO DEL CRONO

    // end time
    auto stop = chrono::high_resolution_clock::now();
    // microseconds count
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
    // return elapsed microseconds
    return duration;
}

int main (int argc, char ** argv) {

    string dest= argv[1];
    const int REPEATS = 100;

    ofstream fo;
    fo.open(dest);

    fo << "SIZE\tROWS\tCOLS\tELAPSED\n";

    for (int rows=100; rows<=1000; rows+=100) {
        for (int cols=100; cols<=1000; cols+=100) {
            fo << rows*cols << "\t" << rows << "\t" << cols << "\t" << do_routine(rows,cols,REPEATS) << endl;
        }
    }


    return 0;
}



