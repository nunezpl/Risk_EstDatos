#ifndef TERRITORIO_H
#define TERRITORIO_H

using namespace std;
#include <iostream>
#include <vector>

class Territorio {
  public:
    // Getters y setters
    void setNombre(string n);
    void addVecino(Territorio& t);
    void setOcupado(bool b);

    string getNombre();
    vector<Territorio> getVecinos();
    bool getOcupado();
    // otros metodos
  protected:
    string nombre;
    bool ocupado = false;
    vector<Territorio> vecinos;
};

#endif