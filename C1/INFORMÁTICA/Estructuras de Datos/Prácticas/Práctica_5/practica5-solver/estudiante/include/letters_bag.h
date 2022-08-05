#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "bag.h"
#include "letters_set.h"
#include <iostream>

using namespace std;

/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 */

class LettersBag{

private:
    Bag <char> letters;

public:

    /**
     * @brief Constructor por defecto.
     * Crea una bolsa de letras vacía.
     * Eficiencia: O(1)
     */
     LettersBag ();

     /**
      * @brief Constructor dado un LetterSet.
      * Dado un LetterSet como argumento, este constructor debe rellenar la LettersBag con las letras que contiene el LetterSet
      * introduciendo cada letra el número de veces indicado por el campo LetterInfo::repetitions.
      * Eficiencia: O(n²)
      * @param letterSet TDA LetterSet a pasar
      */
     LettersBag (const LetterSet & letterSet);

      /**
       * @brief Método para insertar una nueva letra en la bolsa.
       * Introduce una letra en la bolsa.
       * Eficiencia: O(1)
       * @param l letra a añadir a la LettersBag
       */
       void insertLetter (const char & l);

       /**
        * @brief Método que nos permita extraer una sola letra y un conjunto de letras.
        * Extrae una letra aleatoria de la bolsa, eliminándola del conjunto.
        * Eficiencia: O(1)
        * @return char representa la letra extraída
        */
        char extractLetter();

        /**
         * @brief Método que nos permite extraer un conjunto de letras de la bolsa.
         * Extrae un conjunto de letras de la LettersBag, eliminańdolas del conjunto.
         * Eficiencia: O(n)
         * @param num Número de letras a extraer
         * @return Lista con las letras extraídas aleatoriamente.
         */
         vector <char> extractLetters (int num);

         /**
          * @brief Método que vacía la bolsa.
          * Eficiencia: O(n)
          * @post El objeto es modificado
          */
          void clear();

          /**
           * @brief Método que permite consultar el tamaño de la bolsa.
           * Eficiencia: O(1)
           * @return int con el tamaño de la bolsa
           * @post El oobjeto no es modificado
           */
           unsigned int size() const;

          /**
           * @brief Sobregarga del operador de asignación.
           * Eficiencia: O(n)
           * @return Referencia a this. De esta forma el operador puede ser encadenao
           * @post El objeto es modificado
           */
           LettersBag & operator= (const LettersBag & other);

          /**
           * @brief Sobrecarga del operador de salida.
           * Eficiencia: O(n)
           * @param os Flujo de salida
           * @param cl LettersBag que se escribe
           * @return Flujo de salida para encadenarlo
           */
         friend ostream& operator<<(ostream& os, const LettersBag& bolsa);

};

#endif
