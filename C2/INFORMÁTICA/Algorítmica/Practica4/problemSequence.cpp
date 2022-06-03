/*
g++ problemSequence.cpp -o problemSequence; ./problemSequence
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <iomanip>

using namespace std;

/**
 * @brief Calcula la tabla con las longitudes de la mayor subsecuencia en
 * la que coindicen los vectores a y b
 * @param a Vector con la primera cadena
 * @param a Vector con la segunda cadena
 */
vector<vector<int>> tableSequences(const vector<char> & a, const vector<char> & b) {
	// Crea la matriz de longitud de subsecuencias
	int sizeA = a.size();
	int sizeB = b.size();
	vector<vector<int>> table(sizeA + 1, vector<int>(sizeB + 1));

	// Rellena la primera fila con 0
	for (int i = 0; i <= sizeB; i++)
		table[0][i] = 0;
	// Rellena la primera columna con 0
	for (int i = 1; i <= sizeA; i++)
		table[i][0] = 0;
	
	// Rellena la tabla con la longitud de las subsecuencias
	for (int i = 1; i <= sizeA; ++i)
		for (int j = 1; j <= sizeB; ++j){
			if (a[i-1] == b[j-1])
				table[i][j] = 1 + table[i-1][j-1];
			else
				table[i][j] = max(table[i-1][j], table[i][j-1]);
		}
	
	return table;
}

/**
 * @brief Busca la mayor subsecuencia en la que coinciden los vectores a y b
 * @param a Vector con la primera cadena
 * @param a Vector con la segunda cadena
 * @param result Vector con la subsecuencia resultante
 */
void longestSequence(const vector<char> & a, const vector<char> & b, stack<char> & result) {
	auto table = tableSequences(a,b);
	int i = a.size();
	int j = b.size();
	while (i != 0 && j != 0) {
		if ((table[i][j] - 1) == table[i-1][j-1] && a[i-1] == b[j-1]) {
			result.push(a[i-1]);
			i--;
			j--;	
		} 
		else if (table[i][j] == table[i-1][j])
			i--;
		else
			j--;
	}
}

int main(int argc, char * argv[]){

	// Vectores con las secuencias a comparar
	vector<char> first, second;
	stack<char> result;
	int size1 = 0, size2 = 0, sizeRes = 0;
	string s1, s2;

	// Entrada
	cout << "Introduzca las secuencias..." << endl;
	cout << "Primera secuencia: ";
	getline(cin, s1);
	cout << "Segunda secuencia: ";
	getline(cin, s2);
	
	for (auto ch : s1)
		first.push_back(ch);
	for (auto ch : s2)
		second.push_back(ch);
	size1 = first.size();
	size2 = second.size();

	// Cálculos
	vector<vector<int>> table = tableSequences(first,second);
	longestSequence(first,second,result);
	sizeRes = result.size();
	
	// Salida tabla
	cout << endl << "Tabla de longitud de secuencias: " << endl;
	cout << setw(8) << "#2" << setw(4);
	for (auto ch : second)
		cout << ch << setw(4);
	cout << endl << setw(4) << "#1" << setw(4);
	
	for (int j = 0; j <= size2; ++j)
		cout << table[0][j] << setw(4);
	cout << endl;
	
	for (int i = 1; i <= size1; ++i){
		cout << first[i-1] << setw(4);
		for (int j = 0; j <= size2; ++j)
			cout << table[i][j] << setw(4);
		cout << endl;
	}
	cout << endl;

	// Salida subsecuencia
	cout << "La subsecuencia coincidente más larga tiene longitud "<<
	sizeRes << " y es: ";
	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}
		
	cout << endl;

	// Salida % de similitud
	cout << "El porcentaje de similitud entre las dos cadenas es: "
		<< sizeRes*100.00 / size1 << " %" << endl << endl;

	return 0;
}
