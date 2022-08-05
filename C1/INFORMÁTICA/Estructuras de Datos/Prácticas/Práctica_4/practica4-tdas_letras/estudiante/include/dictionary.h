#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <set>
#include <vector>
#include <string>
#include <iterator>
#include <iostream>

using namespace std;


/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */

class Dictionary {

private:
    set <string> words;

public:

    /**
     * @brief Constructor por defecto. Crea un Dictionary vacío.
     */
    Dictionary();

    /**
     * @brief Constructor de copia. Crea un dictionary con el mismo contenido que el que se
     * le pasa como argumento.
     * @param other Dictionary a copiar.
     */
    Dictionary(const Dictionary & other);

    /**
     * @brief Indica si una palabra está en el diccioanrio o no.
     * Este método comprueba si una determniada palabra se encuentra o no en el diccionario.
     * @param val la palabra que se quiere buscar
     * @return Booleano indicando si la palabra existe o no en el diccionario.
     */
    bool exists(const string & val) const;

    /**
     * @brief Inserta una palabra en el diccionario.
     * @param val Palabra a insertar en el diccionario.
     * @return booleano que marca si ha podido insertar la palabra en Dictionary.
     * La palabra solo se inserta correctamente si no estaba aún incluida en la colección.
     */
    bool insert(const string & val);

    /**
     * @brief elimina una palabra del diccionario.
     * @param val palabra a eliminar.
     * @return Booleano que indica si se ha podido eliminar correctamente la palabra del
     * diccionario.
     */
    bool erase(const string & val);

    /**
     * @brief Limpia el contenido del diccionario.
     */
    void clear();

    /**
     * @brief Consulta si el diccionario está vacío.
     * @return true si el diccionario está vacío, falso en caso contrario.
     */
    bool empty() const;

    /**
     * @brief Tamaño del diccionario
     * @return Número de elementos del diccionario
     */
    unsigned int size() const;

    /**
     * @brief Indica el número de aparicione de una letra.
     * @param c letra a buscar.
     * @return Un entero indicando el numero de apariciones.
     */
    int getOccurrences(const char c);

    /**
     * @brief Cuenta el total de las letras de un diccionario.
     * @return Entero con el total de las letras.
     */
    int getTotalLetters();

    /**
     * @brief Devuelve las palabras en el diccionario con una longitud dada.
     * @param lenght Longitud de las palabras buscadas.
     * @return Vector de palabras con la longiyud deseada.
     */
    vector<string> wordsOfLenght(int lenght);

    /**
     * @brief Sobrecarga del operador de salida.
     * @param os Flujo de salida donde escribir el LetterSet.
     * @param d Dictionary que se escribe
     */
    friend ostream & operator<<(ostream & os, const Dictionary & d);

    /**
     * @brief Sobrecarga del operador de entrada.
     * @param is Flujo de entrada del que leer el LetterSet.
     * @param d Dictionary en el que almacenar la información leida.
     */
    friend istream & operator>>(istream & is, Dictionary & d);

    /**
     * @brief TDA iterator asociado a Dictionary y señala los elementos contenidos en el.
     * Permite recorrer el Dictionary con posible modificación del mismo, por lo que solo
     * se puede usar con contenedores no constantes.
     * Es mutable.
     */
    class iterator{
    private:
        set<string>::iterator it;
    public:
        iterator(){}
        iterator(const set<string>::iterator& otro):it(otro){}
        iterator(const iterator& otro):it(otro.it){}
        ~iterator(){}
        iterator& operator=(const set<string>::iterator& otro){it=otro;return *this;}
        iterator& operator=(const iterator& otro){it=otro.it;return *this;}
        string operator*()const{return *it;}
        iterator& operator++(){++it;return *this;}
        iterator& operator--(){--it;return *this;}
        iterator& operator++(int){it++;return *this;}
        iterator& operator--(int){it--;return *this;}
        bool operator!=(const iterator& otro){return it != otro.it;}
        bool operator==(const iterator& otro){return it == otro.it;}
    };

    /**
     * @brief TDA const_iterator asociado a Dictionary y señala los elementos contenidos en el.
     * Permite recorrer el Dictionary pero no modificarlo por lo que se puede usar tanto con
     * Dictionary constantes como no constantes.
     * Es mutable.
     */
    class const_iterator{
    private:
        set<string>::const_iterator it;
    public:
        const_iterator(){}
        const_iterator(const set<string>::const_iterator& otro):it(otro){}
        const_iterator(const const_iterator& otro):it(otro.it){}
        ~const_iterator(){}
        const_iterator& operator=(const set<string>::const_iterator& otro){it=otro;return *this;}
        const_iterator& operator=(const const_iterator& otro){it=otro.it;return *this;}
        const string operator*()const{return *it;}
        const_iterator& operator++(){++it;return *this;}
        const_iterator& operator--(){--it;return *this;}
        const_iterator& operator++(int){it++;return *this;}
        const_iterator& operator--(int){it--;return *this;}
        bool operator!=(const const_iterator& otro){return it != otro.it;}
        bool operator==(const const_iterator& otro){return it == otro.it;}
    };

    /**
     * @brief Devuelve un iterador señalando el primer elemento del Dictionary.
     * @return Un iterador de Dictionary apuntando al primer elemento.
     */
    iterator begin(){iterator i = words.begin();return i;}

    /**
    * @brief Devuelve un iterador señalando el último elemento del Dictionary.
    * @return Un iterador de Dictionary apuntando al último elemento.
    */
    iterator end(){iterator i = words.end();return i;}

    /**
   * @brief Devuelve un iterador constante señalando el primer elemento del Dictionary.
   * @return Un iterador constante de Dictionary apuntando al primer elemento.
   */
    const_iterator begin() const{const_iterator i = words.begin();return i;}

    /**
     * @brief Devuelve un iterador constante señalando el último elemento del Dictionary.
     * @return Un iterador constante de Dictionary apuntando al último elemento.
     */
    const_iterator end() const{const_iterator i = words.end();return i;}

};

#endif
