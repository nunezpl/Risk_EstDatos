#ifndef EJERCITO_H
#define EJERCITO_H

using namespace std;
#include <iostream>
#include <list>

class Ejercito {
  public:
    Ejercito();
    // Getters y setters
    // otros metodos
  protected:
    string categoria; // infanteria, caballeria y artilleria
    string color;
    int unidades;
};

#endif