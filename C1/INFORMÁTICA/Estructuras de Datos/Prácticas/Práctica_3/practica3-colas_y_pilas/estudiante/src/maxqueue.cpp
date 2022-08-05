/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author Mario Megías Mateo
 * @author Quintín Mesa Romero
 */

#include <iostream>
#include <maxqueue.h>
using namespace std;


// Quitar un elemento de la maxstack
void MaxQueue::pop() {
    pila.pop();
}

// Comprueba si está vacía
bool MaxQueue::empty() const {
    if (pila.size() == 0) return true;
    else return false;
}

//Devuelve el elemento del frente
element & MaxQueue::front() {
    return pila.top();
}

//Devuelve el elemento del frente
const element & MaxQueue::front() const{
    return pila.top();
}

//Devuelve el tamaño de la cola con máximo
size_t MaxQueue::size() const{
    return pila.size();
}

//Inserta un elemento en la cola con máximo
void MaxQueue::push(const int &elem){

    // Inicializamos un dato de tipo element con el entero elem que será el que añadamos
    // a la cola

    element dato;
    dato.value = elem;
    dato.maximum = elem;

    if (pila.empty()) {

        pila.push(dato);

    } else {

        // Contruimos una pila de element auxiliar que nos permitirá añadir dato al
        // back de la cola

        stack<element> invertPila;

        int max = pila.top().maximum;
        if (max < elem) max = elem;

        while (!this->pila.empty()) {
            invertPila.push(this->pila.top());
            this->pila.pop();
        }

        // Añadimos dato a la pila invertido, de forma que al volver a introducir los elementos en
        // la pila dato ocupará la posición back de la cola

        invertPila.push(dato);
        size_t sizeInvertPila = invertPila.size();

        if (max == elem) {

            // Si el máximo de invertPila es el elemento a insertar, debemos de cambiar el
            // máximo en los elementos anteriores al elemento insertado

            while (this->pila.size() != sizeInvertPila) {
                invertPila.top().maximum = max;
                this->pila.push(invertPila.top());
                invertPila.pop();
            }

        } else {

            // En el caso contrario, el valor a insertar no es mayor que el máximo de la
            // invertPila, luego  solo debemos modificar el maximo en los elementos cuyo
            // máximo sea menor que el elemento a insertar

            while (this->pila.size() != sizeInvertPila) {
                if (invertPila.top().maximum < elem) {
                    invertPila.top().maximum = elem;
                }
                this->pila.push(invertPila.top());
                invertPila.pop();
            }
        }

    }

}

// Operador de salida
ostream & operator<<(ostream & flujo, const element & elemento){

    cout << elemento.value << "," << elemento.maximum;
    return flujo;
}