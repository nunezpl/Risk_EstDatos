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
    void setCantiEjercitos(int c);

    string getNombre() const;
    vector<Territorio> getVecinos();
    bool getOcupado() const;
    Jugador* getOcupante();
    int getCantiEjercitos();

    // otros metodos
    void imprimirVecinos();
    bool esVecino (const Territorio& otroTerritorio) const;

  protected:
    string nombre;
    bool ocupado;
    vector<Territorio> vecinos;
    Jugador* ocupante; // Apuntador al jugador ocupante del territorio
    int cantiEjercitos=0; // Aca podemos saber la cantidad de ejercitos encima.
};

#endif