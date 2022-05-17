
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <cmath>
using namespace std;

 
/**
* @brief Algoritmo basado en la noción de cercanía que resuelve el problema del
*        viajante de comercio.
* @param distancias matriz de adyacencia que contiene las distancias entre ciudades
* @param dist_results
*/

int vecino_mas_cercano (const vector<vector<int>> & distancias, vector<int> &dist_results)
{
	
    int min = INT_MAX;  // inicializamos la distancia mínima al máximo valor que 
	                // puede tomar un entero
    int d = 0, caux, t_distancias = 0;
    int tam = distancias.size();
	
    dist_results.resize(tam);
    dist_results.at(0)=0;
	
    for (int i = 0; i < tam; i++){
      for(int j = 0; j < tam; j++){
	  if (dist_results.end()==find(dist_results.begin(),dist_results.end(),j)){
	     d = distancias[max(j,dist_results[i-1])][min(j,dist_results[i-1])];
	     if (d < min){
	   	caux=j;
	   	min=d;
	     }
	  }
	  
      }
    
      t_distancias+=min;
      dist_results.at(i)=caux;
    }
 
    t_distancias+=distancias[max(dist_results[0], dist_results[n-1])][min(dist_results[0], dist_results[n-1]);
 
    return t_distancias;
}
	 

// PROGRAMA PRINCIPAL








vector<Node> tspCercania(vector<Node> nodes)
{

    // Creamos la matriz de las distancias entre las ciudades
    auto distances = distanceMatrix(nodes);
    
    // Vector de nodos con el recorrido final óptimo
    int tam = nodes.size();
    vector<Node> result(tam);

    // Elegimos la ciudad inicial con la que se va a comenzar el recorrido
    result.push_back(nodes[0]);
    
    vector<vector<int>>::iterator it = distances.begin();
    vector<int> cont(tam);
    
    int d = INT_MAX;
    int aux = 0;
    	
    while (!nodes.empty()){
    
    	for (int j = 0; j < tam; j++){
        
		if ((*it).at(j) < d && (*it).at(j)!=0){
		   d = (*it).at(j);
		   cont.push_back(j);
		}
	}
	
	int pos = cont.size()-1;
	result.push_back(nodes[pos]);
	removeNode(nodes, nodes[aux]);
	
	if (!nodes.empty()){
	 	if (pos > aux) advance(it, (aux + pos));
		else advance(it, (aux - pos));

		aux = pos;
		
		cont.clear();
	}
	
     }
         
    
    return result;
}


























   	    
	    
