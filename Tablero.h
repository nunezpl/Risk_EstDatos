#ifndef TABLERO_H
#define TABLERO_H

using namespace std;
#include <iostream>
#include <vector>
#include "Continente.h"

class Continente;

class Tablero {
  public:
    static vector<Continente> tablero;
    static void crearTablero();
    static void imprimirTablero();
    static void crearTerritorios();
    static void enlazarVecinos();
};

#endif
