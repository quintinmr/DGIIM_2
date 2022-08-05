#include "letters_bag.h"
#include "letters_set.h"
#include <iostream>
#include <map>

using namespace std;

LettersBag::LettersBag() {
    clear();
}

LettersBag::LettersBag(const LetterSet &letterSet) {

    for (LetterSet::const_iterator it = letterSet.begin(); it != letterSet.end(); ++it){
        for (int j = 0; j < (*it).second.repetitions; j++){
            insertLetter((*it).first);
        }
    }
}

void LettersBag::insertLetter(const char &l) {
    letters.add(l);
}

char LettersBag::extractLetter(){
    return letters.get();
}

vector <char> LettersBag::extractLetters (int num){
    vector <char> let;

    for (int i = 0; i < num; i++)
        let.at(i) = extractLetter();

    return let;
}

void LettersBag::clear() {
    letters.clear();
}

unsigned int LettersBag::size() const {
    return letters.size();
}

LettersBag & LettersBag::operator=(const LettersBag &other) {
    letters = other.letters;
    return *this;
}

ostream& operator<<(ostream& os, const LettersBag& bolsa){
    LettersBag b = bolsa;
    while (b.size()) os << b.extractLetter()<< endl;
    return os;
}
