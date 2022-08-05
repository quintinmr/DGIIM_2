
#ifndef __FICHA__H__
#define __FICHA__H__

/* ***************************************** */

#include <iostream>

/* ***************************************** */

// Tipos de fichas que se pueden poner en el tablero
enum Ficha {BLANCO, CIRCULO, CRUZ};

/* ***************************************** */

// Sobrecarga de << para mostrar en ostream el s�mbolo de la ficha
std::ostream& operator<<(std::ostream &salida, const Ficha &fic);

/* ***************************************** */

#endif
