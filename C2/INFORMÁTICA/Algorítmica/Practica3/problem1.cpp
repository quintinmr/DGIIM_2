// g++ problem1.cpp -o problem1; ./problem1 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Opción 1: Maximizar el número de contenedores
 * @param k entero con la capacidad de carga del buque
 * @param containers vector de double con los pesos de los contenedores
 * @param containersResult vector de double con el contenedor resultante
 */

void maxNumContainers(int k, vector<double> & containers, vector<double> & containersResult) {
	// Ordenación del vector dado con complejidad O(n*logn)
	sort(containers.begin(), containers.end());

	// Capacidad de carga usada
	double capacityUsed = 0;

	// Recorremos los contenedores de menor a mayor
	for (int i=0; i<containers.size() && capacityUsed+containers[i]<k; ++i){
		// Añadimos el siguiente contenedor con menor peso
		containersResult.push_back(containers[i]);
		
		// Incrementamos la carga usada
		capacityUsed += containers[i];
	}
}

/**
 * @brief Opción 2: Maximizar el número de toneladas
 * @param k entero con la capacidad de carga del buque
 * @param containers vector de double con los pesos de los contenedores
 * @param containersResult vector de double con el contenedor resultante
 */
void maxNumTons(int k,  vector<double> & containers,  vector<double> & containersResult) {
	sort(containers.begin(), containers.end(), greater<double>() );
	
	// Capacidad de carga usada
	double capacityUsed = 0;
	
	for(int i=0; i!=containers.size(); ++i){
	
		if(capacityUsed+containers[i]<=k){
		// Añadimos el siguiente contenedor con menor peso
		containersResult.push_back(containers[i]);
		
		// Incrementamos la carga usada
		capacityUsed += containers[i];
		}
	}
}

int main(int argc, char * argv[]){
	// Capacidad de carga
	int capacity;
	// Contenedores de entrada y de salida
	vector<double> input, output;
	double data;

	// Gestión de errores
	if (argc < 2){
		cerr << "Formato: " << argv[0] << "<opcion>" << endl << 
		"Opcion 1 para maximizar el numero de contenedores, 2 para el numero de toneladas" << endl;
		return -1;
	}
	int option = atoi(argv[1]);
	
	// Entrada
	cout << "Introduzca la capacidad de carga: ";
	cin >> capacity;
	
	cout << "Introduzca los pesos de los contenedores: ";
	while (cin >> data)
		input.push_back(data);

	// Cálculos
	if (option == 1)
		maxNumContainers(capacity, input, output);
	else
		maxNumTons(capacity, input, output);
	
	// Salida
	cout << "Contenedores resultantes: ";
	for (auto el : output)
		cout << el << " ";
	cout << endl;
	
	return 0;
}
