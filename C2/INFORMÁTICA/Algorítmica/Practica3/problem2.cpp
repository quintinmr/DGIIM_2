
/*
 Compilación y ejecución:
 g++ problem2.cpp -o problem2
 ./problem2 <opcion> <fichero_entrada> <fichero_salida>
 Opciones: 1 para cercanía, 2 para inserción, 3 para el que hemos elegido
*/ 

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <iomanip>

using namespace std;

/**************************Declaraciones**************************/

/**
 * @brief Estructura que representa un nodo del grafo. Los miembros son:
 * el número del nodo, la coordenada x y la coordenada y
 */
struct Node {
	int number;
	double x;
	double y;
};

/**
* @brief Algoritmo basado en la noción de cercanía que resuelve el problema del
* viajante de comercio.
* @param nodes Vector con los nodos de entrada
* @return vector con los nodos reordenados 
*/
vector<Node> tspNearest(vector<Node> nodes);

/**
 * @brief Función que dado un vector con los nodos de entrada devuelve
 * un vector de salida con los nodos reordenados por la heurística de inserción
 * @param input Vector con los nodos de entrada
 * @return Vector con los nodos reordenados
 */
vector<Node> tspCheapestInsertion(vector<Node> nodes);

/**
 * @brief Función que dado un vector con los nodos de entrada devuelve
 * un vector de salida con los nodos reordenados por la heurística de inserción lejana.
 * Inserta los nodos que maximicen su mínimo coste al añadirse, al contrario de
 * inserción, que añader los que minimizan su mínimo coste al añadirse.
 * @param input Vector con los nodos de entrada
 * @return Vector con los nodos reordenados
 */
vector<Node> tspFarthestInsertion(vector<Node> nodes);

/**
 * @brief Función que calcula el recorrido parcial y elimina esos nodos del vector inicial.
 * Este estará formado por los dos nodos más alejados.
 * @param nodes Vector con los nodos
 * @param distances Matriz con las distancias entre nodos
 * @return Vector con los nodos del recorrido parcial, se modifica el vector inicial
 */
vector<Node> initialRouteFarthest(vector<Node> & nodes, const vector<vector<int>> & distances);

/**
 * @brief Función que calcula el punto más alejado del circuito teniendo en cuenta
 * la suma de las distancias del nodo a cada uno de los que forman el circuito
 * @param circuit Circuito con al que se calcularán las distancias a cada nodo
 * @param candidates Nodos candidatos
 * @param distances Matriz con las distancias entre nodos
 * @return Nodo más lejano al circuito
 */
Node farthestNode(const vector<Node> & circuit, const vector<Node> & candidates, const vector<vector<int>> & distances);

/**
 * @brief Función que selecciona, de entre los nodos posibles, el más cercano a uno
 * dado.
 * @param node Nodo al que se le quiere encontrar el más cercano
 * @param nodes Nodos candidatos
 * @param distances Matriz con las distancias entre nodos
 * @return Nodo más cercano al nodo pasado como argumento
*/
Node nearestNode(const Node & node, const vector<Node> & candidates, const vector<vector<int>> & distances);

/**
 * @brief Función que devuelve un entero con la distancia entre dos nodos dados
 * @param n1 Primer nodo
 * @param n2 Segundo nodo
 * @return Entero con la distancia euclídea entre los nodos dados
 */
int distance(const Node & n1, const Node & n2);

/**
 * @brief Función que calcula la matriz con las distancias entre los nodos
 * @param nodes Vector con los nodos
 * @return Matriz con las distancias entre nodos
 */
vector<vector<int>> distanceMatrix(const vector<Node> & nodes);

/**
 * @brief Función que calcula el recorrido parcial y elimina esos nodos del vector inicial
 * @param nodes Vector con los nodos
 * @return Vector con los nodos del recorrido parcial, se modifica el vector inicial
 */
vector<Node> initialRoute(vector<Node> & nodes);

/**
 * @brief Función que elimina el nodo dado del vector de nodos dado
 * @param nodes Vector con los nodos, será modificado
 * @param node Nodo a eliminar
 */
void removeNode(vector<Node> & nodes, const Node & node);

/**
 * @brief Función que calcula el incremento en la longitud al insertar el nodo
 * con índice k entre los nodos con índices i y j
 * @param k nodo a insertar
 * @param i uno de los nodos entre los que se inserta
 * @param j uno de los nodos entre los que se inserta
 * @param distances Matriz con las distancias entre nodos
 * @return Entero con el incremento en longitud
 */
int lengthIncrease(int k, int i, int j, const vector<vector<int>> & distances);

/**
 * @brief Función que devuelve la longitud del camino entre los nodos
 * @param nodes Vector con los nodos del camino
 * @return Entero con la longitud del camino
 */
int routeLength(const vector<Node> & nodes);

/**
 * @brief Función que lee los nodos de un fichero y los guarda en un vector de nodos
 * @param fileName Cadena de caracteres con el nombre del fichero
 * @return Vector con los nodos leídos
 */
vector<Node> readFile(const char * fileName);

/**
 * @brief Función que escribe los nodos del vector dado en el archivo dado
 * @param output Vector con los nodos por escribir 
 * @param fileName Cadena de caracteres con el nombre del fichero de salida
 */
void writeFile(const vector<Node> & output, const char * fileName);

/**************************Implementaciones**************************/

int distance(const Node & n1, const Node & n2) {
	// Distancia euclídea truncada
	return trunc(sqrt(pow(n2.x-n1.x,2) + pow(n2.y-n1.y,2)));
}

vector<vector<int>> distanceMatrix(const vector<Node> & nodes) {
	// Vector salida de dimensiones size x size
	int size = nodes.size();
	vector<vector<int>> result(size, vector<int>(size));
	
	// Lo rellenamos con las distancias
	for (int i = 0; i < size; ++i) {
		for (int j = i; j < size; ++j) {
			int dist = distance(nodes[i], nodes[j]);
			result[i][j] = dist;
			result[j][i] = dist;
		}
	}
	return result;
}

void removeNode(vector<Node> & nodes, const Node & node) {
	bool deleted = false;
	auto it = nodes.begin();
	// Recorremos el vector hasta el final o hasta encontrar
	// el nodo a eliminar. 
	while (!deleted && it != nodes.end()) {
		if (it->number == node.number) {
			nodes.erase(it);
			deleted = true;
		}
		it++;
	}
}

vector<Node> initialRoute(vector<Node> & nodes) {
	vector<Node> result;
	Node north = nodes[0], east = nodes[0], west = nodes[0];
	
	// Calculamos los nodos más al norte, este y oeste
	for (auto node : nodes) {
		if (node.y > north.y)
			north = node;
		if (node.x > east.x)
			east = node;
		if (node.x < west.x)
			west = node;
	}
	
	// Rellenamos el recorrido parcial
	result.push_back(north);
	result.push_back(east);
	result.push_back(west);
	
	// Los eliminamos del vector original	
	removeNode(nodes, north);
	removeNode(nodes, east);
	removeNode(nodes, west);
	
	return result;
}

int lengthIncrease(int k, int i, int j, const vector<vector<int>> & distances) {
	return distances[k][i] + distances[k][j] - distances[i][j];
}

Node nearestNode(const Node & node, const vector<Node> & candidates, const vector<vector<int>> & distances) {

	// Cogemos al primer candidato para comparar con él a los siguientes
	int minDist = distances[candidates[0].number-1][node.number-1];
	Node nearest = candidates[0];
	
	// Recorremos a todos los candidatos y nos quedamos con el más cercano
	for (auto elem : candidates) {
		int currDist = distances[elem.number-1][node.number-1];
		if (currDist < minDist) {
			minDist = currDist;
			nearest = elem;
		}
	}
	
	// Retornamos el más cercano
	return nearest;
}

vector<Node> tspNearest(vector<Node> nodes)
{
	// Calculamos la matriz de distancias
	auto distances = distanceMatrix(nodes);
	vector<Node> result;
	
	// Metemos el primer nodo en la solución
	result.push_back(nodes[0]);
	removeNode(nodes, nodes[0]);
	
	// Bucle hasta que no queden nodos por visitar
	while (!nodes.empty()) {
		Node nearest = nearestNode(result.back(), nodes, distances);
		result.push_back(nearest);
		removeNode(nodes, nearest);
	}
	
	// Cerramos ciclo
	result.push_back(result[0]);	
	     
	return result;
}

vector<Node> tspCheapestInsertion(vector<Node> nodes) {
	
	// Calculamos la matriz de distancias y el recorrido parcial
	auto distances = distanceMatrix(nodes);
	auto result = initialRoute(nodes);
	
	// Bucle hasta que no queden nodos por visitar
	while (!nodes.empty()) {
		
		// Empezamos con un primer candidato para comparar con él
		Node bestCandidate = nodes[0];
		int bestIncrease = lengthIncrease(bestCandidate.number-1, result[0].number-1, result[1].number-1, distances);
		auto bestInsertionIter = result.begin() + 1;
		int resultSize = result.size();

		// Recorremos todos los nodos por visitar
		for (auto candidate : nodes) {
			
			// Incremento en distancia al insertar el candidato entre
			// el primer y el último nodo del recorrido actual
			// Si es el mínimo para el candidato se insertará al principio del result
			int minIncrease = lengthIncrease(candidate.number-1, result[0].number-1, result[resultSize-1].number-1, distances);
			auto insertionIter = result.begin();
			
			// Recorremos los nodos del recorrido actual
			for (int i = 1; i < resultSize; ++i) {
				
				// Incremento en distancia al insertar el candidato entre el nodo
				// i-1 y i del recorrido actual
				int increase = lengthIncrease(candidate.number-1, result[i-1].number-1, result[i].number-1, distances);
				
				// Si el incremento es menor que el mínimo, lo actualizamos
				if (increase < minIncrease) {
					minIncrease = increase;
					insertionIter = result.begin() + i;
				}
			}
			
			// Si el candidato es el mejor hasta ahora, actualizamos el mejor
			if (minIncrease < bestIncrease) {
				bestCandidate = candidate;
				bestIncrease = minIncrease;
				bestInsertionIter = insertionIter;
			}
		}
		
		// Insertamos el mejor candidato en la solución y lo eliminamos de los nodos candidatos
		result.insert(bestInsertionIter, bestCandidate);
		removeNode(nodes, bestCandidate);	
	}
	
	// Cerramos ciclo
	result.push_back(result[0]);
	
	return result;
}


vector<Node> initialRouteFarthest(vector<Node> & nodes, const vector<vector<int>> & distances){
	// La ruta inicial está formada por los nodos más lejanos
	Node a, b;
	int farthestDistance = distances[0][0];

	// Busca los dos nodos más lejanos entre sí
	for (int i=0; i<distances.size(); i++)
		for (int j=0; j<distances[i].size(); j++)
			if (distances[i][j] > farthestDistance){
				farthestDistance = distances[i][j];
				a = nodes[i];
				b = nodes[j];
			}

	vector<Node> result;
	result.push_back(a);
	removeNode(nodes, a);
	result.push_back(b);
	removeNode(nodes,b);

	return result;
}

Node farthestNode(const vector<Node> & circuit, const vector<Node> & candidates, const vector<vector<int>> & distances){
	// Empezamos con un primer candidato para comparar con él
	Node farthestCandidate = candidates[0];
	int farthestDistance = distances[farthestCandidate.number-1][circuit[0].number-1];

	// Recorremos todos los nodos por visitar
	for (auto candidate : candidates) {
		
		int distance = 0;

		// Suma de distancias entre el candidato y cada nodo insertado
		for (int i = 0; i < circuit.size(); ++i) {
			distance += distances[candidate.number-1][circuit[i].number-1];
		}
		
		// Si el candidato es el mejor hasta ahora, actualizamos el mejor,
		// es decir, el que maximice distance
		if (distance > farthestDistance) {
			farthestCandidate = candidate;
			farthestDistance = distance;
		}
	}

	return farthestCandidate;
}

vector<Node> tspFarthestInsertion(vector<Node> nodes) {
	
	// Calculamos la matriz de distancias y el recorrido parcial
	auto distances = distanceMatrix(nodes);
	auto result = initialRouteFarthest(nodes, distances);

	
	// Bucle hasta que no queden nodos por visitar
	while (!nodes.empty()) {
		// Buscamos el candidato a insertar
		Node bestCandidate = farthestNode(result, nodes, distances);
		
		// Buscamos la posición donde se insertará el candidato elegido
		
		// Empezamos con el incremento en distancia al insertar el candidato entre
		// el primer y el último nodo del recorrido actual
		int resultSize = result.size();
		int minIncrease = lengthIncrease(bestCandidate.number-1, result[0].number-1, result[resultSize-1].number-1, distances);
		auto insertionIter = result.begin();
		
		// Recorremos los nodos del recorrido actual
		for (int i = 1; i < resultSize; ++i) {
			
			// Incremento en distancia al insertar el candidato entre el nodo
			// i-1 y i del recorrido actual
			int increase = lengthIncrease(bestCandidate.number-1, result[i-1].number-1, result[i].number-1, distances);
			
			// Si el incremento es menor que el mínimo, lo actualizamos
			if (increase < minIncrease) {
				minIncrease = increase;
				insertionIter = result.begin() + i;
			}
		}
		
		// Insertamos el mejor candidato en la solución y lo eliminamos de los nodos candidatos
		result.insert(insertionIter, bestCandidate);
		removeNode(nodes, bestCandidate);	
	}
	
	// Cerramos ciclo
	result.push_back(result[0]);
	return result;
}

int routeLength(const vector<Node> & nodes) {
	int size = nodes.size();
	int length = 0;
	for (int i = 1; i < size; ++i)
		length += distance(nodes[i-1], nodes[i]);
	return length;
}

vector<Node> readFile(const char * fileName) {
	ifstream input;
	vector<Node> result;
	Node newNode;
	
	input.open(fileName);
	
	// No se pudo abrir el fichero
	if (!input) {
		cerr << "No se pudo abrir el fichero " << fileName << endl;
		exit(-1);
	}
	
	// Leemos del fichero
	input >> newNode.number >> newNode.x >> newNode.y;
	while(input) {
		result.push_back(newNode);
		input >> newNode.number >> newNode.x >> newNode.y;
	}
	
	input.close();
	return result;
}

void writeFile(const vector<Node> & nodes, const char * fileName) {
	ofstream output;
	
	output.open(fileName);
	
	// No se pudo abrir el fichero
	if (!output) {
		cerr << "No se pudo abrir el fichero " << fileName << endl;
		exit(-1);
	}
	
	// Escribimos en el fichero
	for (auto node : nodes)
		output << node.number << " " << node.x << " " << node.y << " " << endl;
	
	output.close();
}

/**************************Código principal**************************/

int main(int argc, char * argv[]) {
	
	// Gestión de errores
	if (argc < 4){
		cerr << "Formato: " << argv[0] << "<opcion> <fichero_entrada> <fichero_salida>" << endl <<
		"Opcion 1 para cercania, 2 para insercion y 3 para el que hemos elegido" << endl;
		return -1;
	}
	int option = atoi(argv[1]);
	clock_t timeBefore;
	clock_t timeAfter;
	vector<Node> output;
	
	// Leemos los nodos
	vector<Node> input = readFile(argv[2]);
	
	// Aplicamos la heurística apropiada
	if (option == 1) {
		timeBefore = clock();
		output    = tspNearest(input);
		timeAfter = clock();	
	} else if (option == 2) {
		timeBefore = clock();
		output = tspCheapestInsertion(input);
		timeAfter = clock();
	} else if (option == 3) {
		timeBefore = clock();
		output = tspFarthestInsertion(input);
		timeAfter = clock();
	}
	
	// Escribimos en el fichero de salida
	writeFile(output, argv[3]);
	
	//for (int i = 0; i < output.size(); i++) cout << output[i].number << "-->";
	//cout << endl;
	
	// Tiempo de ejecución por pantalla junto con la longitud del trayecto
    std::cout << routeLength(output) << "  " << std::fixed << std::setprecision(8) <<
    ((double)(timeAfter - timeBefore)) / (CLOCKS_PER_SEC) << std::endl;
}













