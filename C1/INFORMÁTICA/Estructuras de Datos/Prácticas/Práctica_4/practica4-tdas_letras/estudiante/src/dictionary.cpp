/**
 * dictionary.cpp
 * Implementación del TDA Dictionary
 * */

#include "dictionary.h"

Dictionary::Dictionary() {}

Dictionary::Dictionary(const Dictionary & other) : words(other.words) {}

bool Dictionary::exists(const string & val) const {
    return words.count(val)==1;
}

bool Dictionary::insert(const string & val) {
    pair<set<string>::iterator,bool> result = words.insert(val);
    return result.second;
}

bool Dictionary::erase(const string & val) {
    return words.erase(val)==1;
}

void Dictionary::clear() {
    words.clear();
}

bool Dictionary::empty() const {
    return words.empty();
}

unsigned int Dictionary::size() const {
    return words.size();
}

int Dictionary::getOccurrences(const char c) {

    int ocurrences = 0, sizeWord;

    for (Dictionary::iterator i = begin(); i != end(); ++i) {
        sizeWord = (*i).size();
        for (int j = 0; j < sizeWord; j++)
            if ((*i).at(j) == tolower(c)) ocurrences++;
    }

    return ocurrences;
}

int Dictionary::getTotalLetters() {

    int totalLetters = 0;

    for (Dictionary::iterator i = begin(); i != end(); ++i)
        totalLetters += (*i).size();

    return totalLetters;
}

vector<string> Dictionary::wordsOfLenght(int lenght) {

    vector<string> selectedWords;

    for (Dictionary::iterator i = begin(); i != end(); ++i)
        if ((*i).size() == lenght)
            selectedWords.push_back(*i);

    return selectedWords;
}

ostream & operator<<(ostream & os, const Dictionary & d) {
    for (Dictionary::const_iterator it = d.begin(); it != d.end(); ++it)
        os << *it << endl;
    return os;
}

istream & operator>>(istream & is, Dictionary & d) {
    string word;
    while(is) {
        is >> word;
        d.insert(word);
    }
    return is;
}

