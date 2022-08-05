/**
 * letters_set.cpp
 * Implementación del TDA LetterSet
 * */

#include "letters_set.h"


LetterSet::LetterSet() {}

LetterSet::LetterSet(const LetterSet & other) : letters(other.letters) {}

bool LetterSet::insert(const pair<char,LetterInfo> & val) {
    pair <map<char,LetterInfo>::iterator, bool> result = letters.insert(val);
    return result.second;
}

bool LetterSet::erase(const char & key) {
    int n = letters.erase(key);
    return n==1;
}

void LetterSet::clear() {
    letters.clear();
}

bool LetterSet::empty() const {
    return letters.empty();
}

unsigned int LetterSet::size() const {
    return letters.size();
}

int LetterSet::getScore(string word) {

    int sizeWord = word.size(), score = 0;
    map<char,LetterInfo>::iterator it;

    for (int j=0; j < sizeWord; j++) {
        it = letters.find(toupper(word.at(j)));
        score += (*it).second.score;
    }

    return score;
}

LetterSet & LetterSet::operator=(const LetterSet & cl) {
    letters = cl.letters;
    return *this;
}

LetterInfo & LetterSet::operator[](const char & val) {
    map<char, LetterInfo>::iterator it = letters.find(val);
    return (*it).second;
}

ostream & operator<<(ostream & os, const LetterSet & cl) {
    for (LetterSet::const_iterator it = cl.begin(); it != cl.end(); ++it)
        os << (*it).first << "\t" << (*it).second.repetitions << "\t" << (*it).second.score << endl;
    return os;
}

istream & operator>>(istream & is, LetterSet & cl) {

    pair<char,LetterInfo> info;
    string cad;

    getline(is, cad);

    while (is) {
        is >> info.first;
        is >> info.second.repetitions;
        is >> info.second.score;
        cl.insert(info);
    }

    return is;
}