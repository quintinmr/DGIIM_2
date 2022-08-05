/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author Mario Megías Mateo
 * @author Quintín Mesa Romero
 */

#include <stack>
#include <iostream>

using namespace std;


/**
 * @brief Estructura para almacenar las parejas (valor, maximo), usada en la clase MaxQueue
 */
struct element {
    int value; // Current value to store
    int maximum; // Current max value in the structure
};

/**
 * @brief Sobrecarga del operador << que imprime los valores de los que consta un dato de tipo element.
 * @param flujo flujo de salida.
 * @param elemento elemento a imprimir.
 * @return Devuelve una referencia al flujo pasado como parámetro.
 */
ostream & operator<<(ostream & flujo, const element & elemento);

class MaxQueue {

private:
    stack<element> pila;

public:

    /**
     * @brief Informa si la cola está vacía (método constante)
     * @return true, si la cola está vacía, false en otro caso
     */
    bool empty() const;

    /**
     * @brief Quita un elemento de la cola. Elimina el elemento en el frente de la cola.
     * @pre El receptor no puede estar vacío: !empty()
     */
    void pop();

    /**
     * @brief Obtiene el número de elementos (método constante)
     * @return Número de elementos de la cola
     */
    size_t size() const;

    /**
    * @brief Acceso al elemento del principio de la cola
    * @pre El receptor no puede estar vacío: !empty()
    * @return Referencia al elemento en el frente de la cola
    */
    element & front();

    /**
    * @brief Acceso al elemento del principio de la cola (versión constante)
    * @pre El receptor no puede estar vacío: !empty()
    * @return Referencia constante al elemento en el frente de la cola
    */
    const element & front() const;

    /**
    * @brief Añade un elemento en la cola. Inserta un nuevo elemento en la cola.
    * @param elem Elemento que se inserta
    */
    void push (const int & elem);

};