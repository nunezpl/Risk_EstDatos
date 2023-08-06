#ifndef CONTINENTE_H
#define CONTINENTE_H

using namespace std;
#include <iostream>
#include <list>
#include "Territorio.h"

class Continente {
  public:
    string getNombre();
    string getColor();
    int getUnidades();
    list<Territorio> getTerritorios();
    void setNombre(string n);
    void setColor(string c);
    void setUnidades(int u);
    // otros metodos ...
    void crearTablero();
  protected:
    string nombre;
    string color;
    int unidades; // si el jugador ocupa todos los territorios de un continente
    list<Territorio> territorios;
};

#endif