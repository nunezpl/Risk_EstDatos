#ifndef TERRITORIO_H
#define TERRITORIO_H

using namespace std;
#include <iostream>
#include <vector>

class Jugador;

class Territorio {
  public:
    // Getters y setters
    void setNombre(string n);
    void addVecino(Territorio& t);
    void setOcupado(bool b);
    void setOcupante(Jugador* j);

    string getNombre();
    vector<Territorio> getVecinos();
    bool getOcupado();
    Jugador* getOcupante();
    // otros metodos
  protected:
    string nombre;
    bool ocupado;
    vector<Territorio> vecinos;
    Jugador* ocupante; // Apuntador al jugador ocupante del territorio
};

#endif