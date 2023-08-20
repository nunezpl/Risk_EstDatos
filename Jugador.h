#ifndef JUGADOR_H
#define JUGADOR_H

using namespace std;
#include <iostream>
#include <list>
#include "Territorio.h"
#include "Ejercito.h"
#include "Tarjeta.h"

class Jugador {
  public:
    Jugador();
    Jugador(string n, long i);

    void setNombre(string n);
    void setId(long i);
    void setColor(string c);

    string getNombre();
    string getColor();
    long getId();

    void agregarTerritorioOcupado(Territorio t);
    void agregarEjercito(Ejercito e);
    void agregarCarta(Tarjeta t);

    void turno();
    int totalEjercito();
  protected:
    string nombre;
    long id;
    string color;
    list<Territorio> terrOcupados;
    list<Ejercito> ejercito;
    list<Tarjeta> tarjetas;
};

#endif