/**
 *   \file solver.h
 *   \brief Archivo de declaración de la clase Solver
 */

#ifndef __SOLVER_H__
#define __SOLVER_H__

#include "letters_set.h"
#include "dictionary.h"

using namespace std;


/**
 * @brief TDA Solver
 * @details Ofrece la mejor solución para una partida y modo de juego determinado, usando un
 * conjunto de letras proporcionado por un dato de tipo LetterSet y un conjunto de palabras
 * proporcionado por un dato de tipo dictionary.
 *
 **/

class Solver {

private:

    LetterSet l;
    Dictionary d;

    /**
     * @brief Construye un vector con las palabras que pueden formarse con el conjunto de letras
     * pasado como parámetro.
     * Eficiencia: O(n²)
     * @param available_letters conjunto de letras para formar palabras
     * @return vector<string> con las palabras válidas.
     **/
    vector<string> validWords(const vector<char> & available_letters);


public:

    /**
    * @brief Constructor con parámetros. Crea un Solver que tiene asociado un Dictionary y
    * un LetterSet.
    * Eficiencia: O(n)
    * @param dict Dictionary a copiar.
    * @param letters_set LetterSet a copiar.
    * @return Dato de tipo vector<string> con las palabras válidas.
    **/
    Solver(const Dictionary & dict, const LetterSet & letters_set);

    /**
    * @brief Construye el vector de soluciones a partir de las letras de una partida.
    * Dado un conjunto de letras posibles para crear una solución y el modo de juego con el que se juega la partida,
    * se construye un vector con las soluciones encontradas en función del tipo de juego planteado.
    * Eficiencia: O(n²(log(n)))
    * @param available_letters DVector de letras disponibles para la partida
    * @param score_game Bool indicando el tipo de partida. True indica que la partida se juega a puntuación, false
    * que se juega a longitud.
    * @return Par <vector<string>, int>, con el vector de palabras que constituye las mejores soluciones (puede haber
    * empates) y la puntuación que obtienen.
    **/
    pair<vector<string>, int> getSolutions(const vector<char> & available_letters, bool score_game);

};

#endif