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
     */
    LetterSet();

    /**
     * @brief Constructor de copia.
     * @param other LetterSet a copiar.
     */
    LetterSet(const LetterSet & other);

    /**
     * @brief Inserta un elemento en el LetterSet.
     * @param val Pareja de letra y LetterInfo asociada a insertar.
     * @return booleano que marca si ha podido insertar la letra en LetterSet. La letra
     * solo se inserta correctamente si no estaba aún incluida en la colección.
     * */
    bool insert(const pair<char,LetterInfo> & val);

    /**
     * @brief elimina un caracter del LetterSet.
     * @param key Caracter a eliminar.
     * @return Booleano que indica si se ha podido eliminar correctamente la letra del
     * LetterSet.
     */
    bool erase(const char & key);

    /**
     * @brief Limpia el contenido del LetterSet.
     */
    void clear();

    /**
     * @brief Consulta si el LetterSet está vacío.
     * @return true si el LetterSet está vacío, falso en caso contrario.
     */
    bool empty() const;

    /**
     * @brief Tamaño del LetterSet
     * @return Número de elementos del LetterSet
     */
    unsigned int size() const;

    /**
     * @brief Calcula la puntuación dada una palabra
     * @param word String con la palabra cuya puntuacíón queremos calcular
     * @return Puntuación de la palabra, calculada como la suma de las puntuaciones
     * de cada una de sus letras
     */
    int getScore(string word);

    /**
     * @brief sobrecarga del operador de asignación
     * @param cl LetterSet a copiar
     * @returns Referencia al objeto this para poder encadenar el operador
     */
    LetterSet & operator=(const LetterSet & cl);

    /**
     * @brief Sobrecarga del operador de consulta.
     * @param val Carácter a consultar.
     * @return Estructura de tipo LetterInfo con la información del carácter consultado, número
     * de repeteciones y puntuación.
     */
    LetterInfo & operator[](const char & val);

    /**
     * @brief Sobrecarga del operador de salida.
     * @param os Flujo de salida donde escribir el LetterSet.
     * @param cl LetterSet que se escribe
     */
    friend ostream & operator<<(ostream & os, const LetterSet & cl);

    /**
     * @brief Sobrecarga del operador de entrada.
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
        iterator(){}
        iterator(const map<char,LetterInfo>::iterator & otro):it(otro){}
        iterator(const iterator & otro):it(otro.it){}
        ~iterator(){}
        iterator& operator=(const map<char,LetterInfo>::iterator & otro){it=otro;return *this;}
        iterator& operator=(const iterator & otro){it=otro.it;return *this;}
        pair<char,LetterInfo> operator*()const{return *it;}
        iterator& operator++(){++it;return *this;}
        iterator& operator--(){--it;return *this;}
        iterator& operator++(int){it++;return *this;}
        iterator& operator--(int){it--;return *this;}
        bool operator!=(const iterator& otro){return it != otro.it;}
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
        const_iterator(){}
        const_iterator(const map<char,LetterInfo>::const_iterator & otro):it(otro){}
        const_iterator(const const_iterator & otro):it(otro.it){}
        ~const_iterator(){}
        const_iterator& operator=(const map<char,LetterInfo>::const_iterator & otro){it=otro;return *this;}
        const_iterator& operator=(const const_iterator & otro){it=otro.it;return *this;}
        const pair<char,LetterInfo> operator*()const{return *it;}
        const_iterator& operator++(){++it;return *this;}
        const_iterator& operator--(){--it;return *this;}
        const_iterator& operator++(int){it++;return *this;}
        const_iterator& operator--(int){it--;return *this;}
        bool operator!=(const const_iterator& otro){return it != otro.it;}
        bool operator==(const const_iterator& otro){return it == otro.it;}
    };

    /**
     * @brief Devuelve un iterador señalando el primer elemento del LetterSet.
     * @return Un iterador de LetterSet apuntando al primer elemento.
     */
    iterator begin(){iterator i = letters.begin();return i;}

    /**
     * @brief Devuelve un iterador señalando el último elemento del LetterSet.
     * @return Un iterador de LetterSet apuntando al último elemento.
     */
    iterator end(){iterator i = letters.end();return i;}

    /**
    * @brief Devuelve un iterador constante señalando el primer elemento del LetterSet.
    * @return Un iterador constante de LetterSet apuntando al primer elemento.
    */
    const_iterator begin() const {const_iterator i = letters.begin();return i;}

    /**
     * @brief Devuelve un iterador constante señalando el último elemento del LetterSet.
     * @return Un iterador constante de LetterSet apuntando al último elemento.
     */
    const_iterator end() const {const_iterator i = letters.end();return i;}

};


#endif