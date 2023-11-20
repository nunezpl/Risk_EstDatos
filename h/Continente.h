#ifndef CONTINENTE_H
#define CONTINENTE_H

using namespace std;
#include <iostream>
#include <list>
#include "Territorio.h"
#include "Jugador.h"

class Jugador;  // Declaración adelantada de la clase

class Continente {
  public:
    string getNombre();
    string getColor();
    int getUnidades();
    vector<Territorio>& getTerritorios();

    void setNombre(string n);
    void setColor(string c);
    void setUnidades(int u);
    void setTerritorio(Territorio t);

    // otros metodos ...
    void imprimirTerritorios();
    bool ocupadoPorJugador(Jugador& jugador);

  protected:
    string nombre;
    string color;
    int unidades; // si el jugador ocupa todos los territorios de un continente
    vector<Territorio> territorios;
};

#endif
