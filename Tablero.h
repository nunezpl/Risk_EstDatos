#ifndef TABLERO_H
#define TABLERO_H

using namespace std;
#include <iostream>
#include <vector>
#include "Continente.h"
#include "Tarjeta.h"

class Continente;
class Tarjeta;

class Tablero {
  public:
    // Mapa
    static vector<Continente> tablero;
    static void crearTablero();
    static void imprimirTablero();
    static void crearTerritorios();
    static void enlazarVecinos();
    // Maso de tarjetas
    static vector<Tarjeta> maso;
    static void crearTarjetas();
    static Tarjeta sacarTarjeta();
};

#endif
