#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <map>
#include <string>
#include <iterator>
#include <iostream>

using namespace std;

/**
 * @brief TDA LetterInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */

struct LetterInfo {
    int repetitions;
    int score;
};


/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */

class LetterSet {

private:
    map<char, LetterInfo> letters;

public:

    /**
     * @brief Constructor por defecto. Crea un LetterSet vacío.
     * Eficiencia: O(1)
     */
    LetterSet();

    /**
     * @brief Constructor de copia.
     * Eficiencia: O(n)
     * @param other LetterSet a copiar.
     */
    LetterSet(const LetterSet & other);

    /**
     * @brief Inserta un elemento en el LetterSet.
     * Eficiencia: O(log n)
     * @param val Pareja de letra y LetterInfo asociada a insertar.
     * @return booleano que marca si ha podido insertar la letra en LetterSet. La letra
     * solo se inserta correctamente si no estaba aún incluida en la colección.
     * */
    bool insert(const pair<char,LetterInfo> & val);

    /**
     * @brief elimina un caracter del LetterSet.
     * Eficiencia: O(log n)
     * @param key Caracter a eliminar.
     * @return Booleano que indica si se ha podido eliminar correctamente la letra del
     * LetterSet.
     */
    bool erase(const char & key);

    /**
     * @brief Limpia el contenido del LetterSet.
     * Eficiencia: O(n)
     */
    void clear();

    /**
     * @brief Consulta si el LetterSet está vacío.
     * Eficiencia: O(1)
     * @return true si el LetterSet está vacío, falso en caso contrario.
     */
    bool empty() const;

    /**
     * @brief Tamaño del LetterSet.
     * Eficiencia: O(1)
     * @return Número de elementos del LetterSet
     */
    unsigned int size() const;

    /**
     * @brief Calcula la puntuación dada una palabra.
     * Eficiencia: O(nlog(n))
     * @param word String con la palabra cuya puntuacíón queremos calcular
     * @return Puntuación de la palabra, calculada como la suma de las puntuaciones
     * de cada una de sus letras
     */
    int getScore(string word);

    /**
     * @brief sobrecarga del operador de asignación.
     * Eficiencia: O(n)
     * @param cl LetterSet a copiar
     * @returns Referencia al objeto this para poder encadenar el operador
     */
    LetterSet & operator=(const LetterSet & cl);

    /**
     * @brief Sobrecarga del operador de consulta.
     * Eficiencia: O(log n)
     * @param val Carácter a consultar.
     * @return Estructura de tipo LetterInfo con la información del carácter consultado, número
     * de repeteciones y puntuación.
     */
    LetterInfo & operator[](const char & val);

    /**
     * @brief Sobrecarga del operador de salida.
     * Eficiencia: O(n)
     * @param os Flujo de salida donde escribir el LetterSet.
     * @param cl LetterSet que se escribe
     */
    friend ostream & operator<<(ostream & os, const LetterSet & cl);

    /**
     * @brief Sobrecarga del operador de entrada.
     * Eficiencia: O(n)
     * @param is Flujo de entrada del que leer el LetterSet.
     * @param cl LetterSet en el que almacenar la información leida.
     */
    friend istream & operator>>(istream & is, LetterSet & cl);

    /**
     * @brief TDA iterator asociado a LetterSet y señala los elementos contenidos en el.
     * Permite recorrer el LetterSet con posible modificación del mismo, por lo que solo
     * se puede usar con contenedores no constantes.
     * Es mutable.
     */
    class iterator {
    private:
        map<char,LetterInfo>::iterator it;
    public:
        /**
         * @brief Constructor sin parametros. Crea un iterador nulo
         */
        iterator(){}
        /**
         * @brief Constructor de copia.
         * @param otro iterador sobre map que se copia
         */
        iterator(const map<char,LetterInfo>::iterator & otro):it(otro){}
        /**
         * @brief Constructor de copia.
         * @param otro dato de tipo iterador que se copia
         */
        iterator(const iterator & otro):it(otro.it){}
        /**
         * @brief Destructor.
         */
        ~iterator(){}
        /**
         * @brief Operador de asignación.
         * @param otro iterador sobre map
         * @return referencia al objeto implicito.
         */
        iterator& operator=(const map<char,LetterInfo>::iterator & otro){it=otro;return *this;}
        /**
         * @brief Operador de asignación.
         * @param otro dato de tipo iterador que se copia.
         * @return referencia al objeto implicito.
         */
        iterator& operator=(const iterator & otro){it=otro.it;return *this;}
        /**
         * @brief Obtiene el objeto al que apunta el iterador.
         * @pre El iterador es distinto de end().
         * @return Elemento del contenedor en la posición apuntada por el iterador.
         */
        pair<char,LetterInfo> operator*()const{return *it;}
        /**
         * @brief Operador de preincremento. Hace que el iterador apunte a la siguiente posición.
         * @pre Es distinto de end().
         * @return referencia al objeto implicito.
         */
        iterator& operator++(){++it;return *this;}
        /**
         * @brief Operador de predecremento. Hace que el iterador apunte a la posicion anterior.
         * @pre ES distinto de begin().
         * @return referencia al objeto implicito.
         */
        iterator& operator--(){--it;return *this;}
        /**
         * @brief Operador de postincremento. Hace que el iterador apunte a la siguiente posición.
         * @pre Es distinto de end().
         * @return referencia al objeto implicito.
         */
        iterator& operator++(int){it++;return *this;}
        /**
         * @brief Operador de postdecremento. Hace que el iterador apunte a la posicion anterior.
         * @pre ES distinto de begin().
         * @return referencia al objeto implicito.
         */
        iterator& operator--(int){it--;return *this;}
        /**
        * @brief Comparacion de desigualdad.
        * @param otro segundo iterador de la comparacion.
        * @return true si el receptor y otro no tienen el mismo valor.
        */
        bool operator!=(const iterator& otro){return it != otro.it;}
        /**
        * @brief Comparacion de igualdad.
        * @param otro segundo iterador de la comparacion.
        * @return true si el receptor y otro tienen el mismo valor.
        */
        bool operator==(const iterator& otro){return it == otro.it;}
    };

    /**
     * @brief TDA const_iterator asociado a LetterSet y señala los elementos contenidos en el.
     * Permite recorrer el LetterSet pero no modificarlo por lo que se puede usar tanto con
     * LetterSet constantes como no constantes.
     * Es mutable.
     */
    class const_iterator {
    private:
        map<char,LetterInfo>::const_iterator it;
    public:
        /**
        * @brief Constructor sin parametros. Crea un const_iterator nulo
        */
        const_iterator(){}
        /**
         * @brief Constructor de copia.
         * @param otro const_iterator sobre map que se copia
         */
        const_iterator(const map<char,LetterInfo>::const_iterator & otro):it(otro){}
        /**
         * @brief Constructor de copia.
         * @param otro dato de tipo const_iterator que se copia
         */
        const_iterator(const const_iterator & otro):it(otro.it){}
        /**
        * @brief Destructor.
        */
        ~const_iterator(){}
        /**
         * @brief Operador de asignación.
         * @param otro const_iterator sobre map
         * @return referencia al objeto implicito.
         */
        const_iterator& operator=(const map<char,LetterInfo>::const_iterator & otro){it=otro;return *this;}
        /**
         * @brief Operador de asignación.
         * @param otro dato de tipo const_iterator que se copia.
         * @return referencia al objeto implicito.
         */
        const_iterator& operator=(const const_iterator & otro){it=otro.it;return *this;}
        /**
         * @brief Obtiene el objeto al que apunta el const_iterator.
         * @pre El const_iterator es distinto de end().
         * @return Elemento del contenedor en la posición apuntada por el iterador.
         */
        const pair<char,LetterInfo> operator*()const{return *it;}
        /**
         * @brief Operador de preincremento. Hace que el const_iterator apunte a la siguiente posición.
         * @pre Es distinto de end().
         * @return referencia al objeto implicito.
         */
        const_iterator& operator++(){++it;return *this;}
        /**
         * @brief Operador de predecremento. Hace que el const_iterator apunte a la posicion anterior.
         * @pre ES distinto de begin().
         * @return referencia al objeto implicito.
         */
        const_iterator& operator--(){--it;return *this;}
        /**
         * @brief Operador de postincremento. Hace que el const_iterator apunte a la siguiente posición.
         * @pre Es distinto de end().
         * @return referencia al objeto implicito.
         */
        const_iterator& operator++(int){it++;return *this;}
        /**
         * @brief Operador de postdecremento. Hace que el const_iterator apunte a la posicion anterior.
         * @pre ES distinto de begin().
         * @return referencia al objeto implicito.
         */
        const_iterator& operator--(int){it--;return *this;}
        /**
        * @brief Comparacion de desigualdad.
        * @param otro segundo const_iterator de la comparacion.
        * @return true si el receptor y otro no tienen el mismo valor.
        */
        bool operator!=(const const_iterator& otro){return it != otro.it;}
        /**
        * @brief Comparacion de igualdad.
        * @param otro segundo const_iterator de la comparacion.
        * @return true si el receptor y otro tienen el mismo valor.
        */
        bool operator==(const const_iterator& otro){return it == otro.it;}
    };
    /**
     * @brief Devuelve un iterador señalando el primer elemento del LetterSet.
     * Eficiencia: O(1)
     * @return Un iterador de LetterSet apuntando al primer elemento.
     */
    iterator begin(){iterator i = letters.begin();return i;}

    /**
     * @brief Devuelve un iterador señalando el último elemento del LetterSet.
     * Eficiencia: O(1)
     * @return Un iterador de LetterSet apuntando al último elemento.
     */
    iterator end(){iterator i = letters.end();return i;}

    /**
    * @brief Devuelve un iterador constante señalando el primer elemento del LetterSet.
     * Eficiencia: O(1)
    * @return Un iterador constante de LetterSet apuntando al primer elemento.
    */
    const_iterator begin() const {const_iterator i = letters.begin();return i;}

    /**
     * @brief Devuelve un iterador constante señalando el último elemento del LetterSet.
     * Eficiencia: O(1)
     * @return Un iterador constante de LetterSet apuntando al último elemento.
     */
    const_iterator end() const {const_iterator i = letters.end();return i;}

};

#endif