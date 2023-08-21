#include <iostream>
#include "Tarjeta.h"
#include "Territorio.h"
using namespace std;

// Implementacion de metodos

Tarjeta::Tarjeta(){

}

// Getters
Territorio Tarjeta::getTerritorio() {
    return territorio;
}
Ejercito Tarjeta::getEjercito() {
    return ejercito;
}
string Tarjeta::getMision() {
    return mision;
}

// Setters
void Tarjeta::setTerritorio(Territorio t) {
    territorio = t;
}
void Tarjeta::setEjercito(Ejercito e) {
    ejercito = e;
}
void Tarjeta::setMision(string m) {
    mision = m;
}

