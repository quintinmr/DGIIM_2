/**
 *   \file solver.cpp
 *   \brief Archivo de implementación de la clase Solver
 */

#include "solver.h"

Solver::Solver(const Dictionary & dict, const LetterSet & letters_set) : d(dict), l(letters_set) {}


vector<string> Solver::validWords(const vector<char> & available_letters) {

    vector<string> valid_words;

    if (!available_letters.empty()) {

        const char MIN = 'a';
        const char MAX = 'z';
        const int TAM = MAX - MIN + 1;
        vector<int> available_letters_count(TAM, 0);
        vector<int> aux;
        bool valid = true;
        int sizeAvailableLetters = available_letters.size(), wordSize = 0;

        // Calculamos en available_letters_count el número de repeticiones de un misma letra
        // que hay en available_letters, obteniendo un vector donde en cada posición tenemos
        // las repetiones de la letra que ocupa esa posicion, de forma que la letra 'a' ocupa la
        // posicion 0, y la letra 'z' ocupa la ultima posicion.

        for (int i = 0; i < sizeAvailableLetters; i++)
            available_letters_count[tolower(available_letters[i]) - MIN]++;

        for (Dictionary::iterator it = d.begin(); it != d.end(); ++it) {

            aux.assign(TAM, 0);
            valid = true;
            wordSize = (*it).size();

            // Para cada palabra del diccionario creamos un vector aux con la misma funcionalidad
            // que el vector available_letteres_count para available_letters.

            for (int i = 0; i < wordSize; i++)
                aux[tolower((*it).at(i)) - MIN]++;

            // Si el numero de repeticiones de una letra en la palabra es mayor que las repeticiones
            // de la letra del conjunto available_letters, entonces dicha palabra no puede formarse
            // a partir de las letras del conjunto.

            for (int j = 0; j < TAM && valid; j++)
                if (aux[j] > available_letters_count[j])
                    valid = false;

            // Si se ha podido formar la palabra, la añadimos a valid_words.

            if (valid) valid_words.push_back(*it);
        }
    }

    return valid_words;
}


pair<vector<string>,int> Solver::getSolutions(const vector<char> & available_letters, bool score_game) {

    pair<vector<string>, int> solution;

    if (!available_letters.empty()) {

        // Vector con las palabras que pueden construirse con available_letters, usando
        // el método validWords.
        vector<string> valid_words(validWords(available_letters));

        int sizeValidWords = valid_words.size();
        solution.second = -1;

        if (score_game) {

            // Recorremos valid_words y calculamos cuál es la mayor puntuación de las palabras
            // del vector y añadimos a solution.first las palabras que tengan esa puntuación.

            int score = -1;

            for (int i = 0; i < sizeValidWords; i++) {
                score = l.getScore(valid_words[i]);
                if (score > solution.second) {
                    solution.second = score;
                    solution.first.clear();
                    solution.first.push_back(valid_words[i]);
                } else if (score == solution.second) {
                    solution.first.push_back(valid_words[i]);
                }
            }

        } else {

            // Recorremos valid_words y calculamos cuál es la mayor longitud de las palabras
            // y añadimos a solution.first las palabras que tengan esa longitud.

            int sizeWord = 0;

            for (int i = 0; i < sizeValidWords; i++) {
                sizeWord = valid_words[i].size();
                if (sizeWord > solution.second) {
                    solution.second = sizeWord;
                    solution.first.clear();
                    solution.first.push_back(valid_words[i]);
                } else if (sizeWord == solution.second) {
                    solution.first.push_back(valid_words[i]);
                }
            }
        }
    }

    return solution;
}