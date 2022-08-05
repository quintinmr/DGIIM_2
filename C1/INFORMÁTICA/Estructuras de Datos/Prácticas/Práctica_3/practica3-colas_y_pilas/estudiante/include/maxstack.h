/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA Maxstack
 * @author Mario Megías Mateo
 * @author Quintín Mesa Romero
 */

#include <queue>
#include <iostream>
using namespace std;


/**
 * @brief Estructura para almacenar las parejas (valor, maximo), usada en la clase Maxstack
 */

struct element {
    int value; // Current value to store
    int maximum; // Current max value in the structure
};

/**
 * @brief Sobrecarga del operador << que imprime los valores de los que consta un dato de tipo element.
 * @param flujo flujo de salida.
 * @param l elemento a imprimir.
 * @return Devuelve una referencia al flujo pasado como parámetro.
 */
ostream & operator<<(ostream & flujo, const element & l);


class Maxstack {

private:
    queue<element> cola;

public:

    /**
     * @brief Quita un elemento de la pila. Elimina el elemento en el tope de la pila.
     * @pre El receptor no puede estar vacío: !empty()
     */
    void pop();

    /**
     * @brief Informa si la pila está vacía (Método constante)
     * @return true, si la pila está vacía, false en otro caso
     */
    bool empty() const;

    /**
     * @brief Acceso al elemento en lo alto de la pila
     * @pre El receptor no puede estar vacío: !empty()
     * @return Referencia al elemento en el tope de la pila
     */
    element & top();

    /**
    * @brief Acceso al elemento en lo alto de la pila (versión constante)
    * @pre El receptor no puede estar vacío: !empty()
    * @return Referencia constante al elemento en el tope de la pila
    */
    const element & top() const;

    /**
     * @brief Obtiene el número de elementos (método constante)
     * @return Número de elementos de la pila
     */
    size_t size() const;

    /**
     * @brief Deposita un elemento en la pila. Dicho elemento se sitúa en el
     * tope de la pila
     * @param elem Elemento que se inserta
     */
    void push(const int &elem);

};