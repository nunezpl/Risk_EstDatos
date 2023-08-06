#ifndef TERRITORIO_H
#define TERRITORIO_H

using namespace std;
#include <iostream>
#include <list>

class Territorio {
  public:
    // Getters y setters
    // otros metodos
  protected:
    string nombre;
    string continente;
    list<Territorio> vecinos;
};

#endif