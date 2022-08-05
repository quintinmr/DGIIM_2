#ifndef __BAG_H__
#define __BAG_H__

#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
/**
 *  \brief TDA abstracto Bolsa
 *
 *  Este TDA abstracto nos permite trabajar con una colección de elementos que
 *  permite la extracción de elementos de forma aleatoria sin reemplazamiento
 */

template <class T>
class Bag {

private:
    vector<T> v;

public:

    /**
     * @brief Constructor por defecto
     * Eficiencia: O(1)
     * Crea un objeto de la clase Bag vacío
     */
    Bag(){}

    /**
     * @brief Constructor de copia
     * Crea una copia exacta de otro objeto de tipo Bag.
     * Eficiencia: O(n)
     * @param other Obejto del tipo Bag<T> del que se va a realizar la copia
     */
    Bag(const Bag<T> &other){
        v = other.v;
    }

    /**
     * @brief Método que añade un elemento a la bolsa.
     * Eficiencia: O(1)
     * @param element Elemento del tipo T a añadir a la bolsa
     * @post El objeto es modificado
     */
    void add(const T &element){
        v.push_back(element);
    }

    /**
     * @brief Método que extrae un elemento aleatorio de la bolsa y lo elimina de la misma
     * Devuelve un elemento aleatorio de la bolsa y lo elimina de la misma.
     * Eficiencia: O(1)
     * @pre La bolsa no está vacía
     * @returns Elemento de tipo T extraído de la bolsa
     * @post El elemento devuelto se ha eliminado de la lista
     */
    T get(){

        int pos = rand() % v.size(); // Nº de posición aleatoria
        T elemento_get = v.at(pos); // Elemento en la posición aleatoria

        v.at(pos) = *(--v.end()); // Copiamos el elemento final en la posición pos
        v.pop_back(); // Eliminamos la posición final, dejando su
        // elemento en pos
        return elemento_get; // Devolvemos el elementos que hemos extraído
    }

    /**
     * @brief Método que elimina los elementos de la bolsa
     * Borra todos los elementos almacenados en la bolsa.
     * Eficiencia: O(n)
     * @post El objeto es modificado
     */
    void clear(){
        v.clear();
    }

    /**
     * @brief Método que devuelve el tamaño de la bolsa.
     * Eficiencia: O(1)
     * @returns Número de elementos que hay en la bolsa.
     */
    unsigned int size() const{
        return v.size();
    }

    /**
     * @brief Método que comprueba si la bolsa está vacía.
     * Eficiencia: O(1)
     * @returns true si la bolsa está vacía, false en caso contrario
     */
    bool empty(){
        return v.empty();
    }

    /**
     * @brief Sobrecarga del operador de asignación.
     * Eficiencia: O(n)
     * @param other Objeto del tipo Bag<T> a copiar
     * @returns Referencia a this para poder encadenar el operador
     */
     const Bag<T> & operator=(const Bag <T> & other){
         v = other.v;
         return *this;
     }

};

#endif

