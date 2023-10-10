#ifndef TARJETA_H
#define TARJETA_H

using namespace std;
#include <iostream>
#include <list>
#include "Ejercito.h"
#include "Territorio.h"

class Tarjeta {
  public:
    Tarjeta();

    // Getters
    Territorio getTerritorio();
    Ejercito getEjercito();
    string getMision();
    int getId();

    // Setters
    void setTerritorio(Territorio t);
    void setEjercito(Ejercito e);
    void setMision(string m);
    void setId(int i);

    static int intercambios;

    // Otros metodos
  protected:
    int id;
    Territorio territorio;// pais
    Ejercito ejercito; // infanteria, caballeria y artilleria
    string mision; // En caso de estar en ese modo de juego, else = null
};

#endif