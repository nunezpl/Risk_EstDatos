#include <iostream>
#include "../h/Tarjeta.h"
#include "../h/Territorio.h"
using namespace std;

// Definición de la variable estática
int Tarjeta::intercambios = 0;

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
int Tarjeta::getId(){
    return id;
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
void Tarjeta::setId(int i){
    id = i;
}
