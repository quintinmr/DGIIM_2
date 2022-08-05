/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA Maxstack
 * @author Mario Megías Mateo
 * @author Quintín Mesa Romero
 */

#include <iostream>
#include <maxstack.h>
using namespace std;


// Quitar un elemento de la maxstack
void Maxstack::pop() {
    cola.pop();
}

// Comprueba si está vacía
bool Maxstack::empty() const {
    if (cola.size() == 0) return true;
    else return false;
}

//Devuelve el elemento del frente
element & Maxstack::top() {
    return cola.front();
}

//Devuelve el elemento del frente
const element & Maxstack::top() const{
    return cola.front();
}

//Devuelve el tamaño de la pila con máximo
size_t Maxstack::size() const{
    return cola.size();
}

//Inserta un nuevo elemento en la pila
void Maxstack::push(const int &elem) {

    element dato;
    dato.value = elem;
    queue <element> cola_auxiliar_copiar;


    if (cola.empty()){
        dato.maximum = elem;
    }
    else
        if (cola.front().maximum < elem) dato.maximum = elem;
        else
            dato.maximum = cola.front().maximum;

    cola_auxiliar_copiar.push(dato);

    while (!this->cola.empty()){
        cola_auxiliar_copiar.push(this->cola.front());
        this->cola.pop();
    }
    this->cola = cola_auxiliar_copiar;

}

//Operador de salida
ostream & operator<<(ostream & flujo, const element & elemento){

    cout << elemento.value << "," << elemento.maximum;
    return flujo;
}











