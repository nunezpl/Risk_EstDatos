#ifndef TABLERO_H
#define TABLERO_H

using namespace std;
#include <iostream>
#include <vector>
#include "Territorio.h"
#include "Continente.h"
#include "Territorio.h"

class Tablero {
  public:
    static vector<Continente> tablero;
    static void crearTablero();
    static void imprimirTablero();
    static void crearTerritorios();
  protected:

};

#endif
