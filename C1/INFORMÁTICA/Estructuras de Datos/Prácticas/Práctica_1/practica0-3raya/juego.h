
#ifndef __JUEGO__H__
#define __JUEGO__H__

/* ***************************************** */

#include "tablero.h"
#include "jugador.h"

/* ***************************************** */

class Juego3Raya {
  private:
    Jugador jug1, jug2;    // Jugadores
    Tablero tab;           // Tablero
    int turno;             // A quien le toca jugar

  public:
    // No existe constructor por defecto
    // Contructor. Para crear un nuevo juego hemos de dar un tablero
    // y dos jugadores obligatoriamente
    Juego3Raya(const Tablero &t, const Jugador &j1, const Jugador &j2);
    ~Juego3Raya()  { };     // Destructor vac�o

    void NuevoJuego();      // Prepara el juego para comenzar una nueva partida
    void JugarTurno();      // Avanza un turno

    // Devuelve una referencia (const) al tablero de juego (consultor)
    const Tablero &ElTablero() const { return tab; };

    // Devuelve una referencia al jugador n-�simo (n=0 � 1)
    const Jugador &ElJugador(int n) const;

    // Devuelve true si el juego ha terminado (porque haya 3 en raya
    //  o porque haya empate)
    bool HemosAcabado() const;

    // Devuelve el n�mero de jugador a quien le toca poner ficha
    int AQuienLeToca() const  { return turno; };

    // Devuelve el n�mero del jugador que ha ganado. Si a�n no ha ganado
    // ninguno o hay empate devuelve -1
    int QuienGana() const;
};

/* ***************************************** */

#endif
