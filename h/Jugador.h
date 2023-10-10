#ifndef JUGADOR_H
#define JUGADOR_H

using namespace std;
#include <iostream>
#include <list>
#include "Territorio.h"
#include "Ejercito.h"
#include "Tarjeta.h"
#include "Tablero.h"

class Territorio;

class Jugador {
  public:
    Jugador();
    Jugador(string n, long i, string c);

    void setNombre(string n);
    void setId(long i);
    void setColor(string c);

    string getNombre();
    string getColor();
    long getId();
    list<Territorio> getOcupados();
    list<Ejercito> getEjercito();
    list<Tarjeta> getTarjetas();

    void agregarTerritorioOcupado(Territorio t);
    void agregarEjercito(Ejercito e);
    void agregarTarjeta(Tarjeta t);

    void imprimirJugador();
    void turno();
    int totalEjercito();
    int totalUnidadesTarjetas();
    void ubicarInfanterias();
    int calcularNuevasUnidades();

    void atacarTerritorios();
    void realizarAtaque (Territorio* atacante, Territorio* defensor);
    int lanzarDado ();
    vector<int> seleccionarDosMasGrandes(vector<int>& dados);
    bool eliminarInfanteria(Jugador* j);
    void fortificar();


  protected:
    string nombre;
    long id;
    string color;
    list<Territorio> terrOcupados;
    list<Ejercito> ejercito;
    list<Tarjeta> tarjetas;
};

#endif