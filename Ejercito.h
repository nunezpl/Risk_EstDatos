#ifndef EJERCITO_H
#define EJERCITO_H

using namespace std;
#include <iostream>
#include <list>

class Ejercito {
  public:
    Ejercito();
    Ejercito(string ca, string co, int u);
    // Getters y setters
    void setCategoria(string c);
    void setColor(string c);
    void setUnidades(int u);

    string getCategoria();
    string getColor();
    int getUnidades();
    // otros metodos
  protected:
    string categoria; // infanteria, caballeria y artilleria
    string color;
    int unidades;
};

#endif