#ifndef TERRITORIO_H
#define TERRITORIO_H

using namespace std;
#include <iostream>
#include <list>

class Territorio {
  public:
    // Getters y setters
    void setNombre(string n);
    void setContinente(string c);
    void agregarVecinos(Territorio t);
    string getNombre();
    string getContinente();
    list<Territorio> getVecinos();
    // otros metodos
  protected:
    string nombre;
    string continente;
    list<Territorio> vecinos;
};

#endif