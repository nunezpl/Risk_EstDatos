#include <iostream>
#include <list>
#include "Territorio.h"
using namespace std;

// Implementacion de metodos
void Territorio::setNombre(string n){
    nombre = n;
}
void Territorio::setContinente(string c){
    continente = c;
}
void Territorio::agregarVecinos(Territorio t){
    vecinos.push_back(t);
}

string Territorio::getNombre(){
    return nombre;
}
string Territorio::getContinente(){
    return continente;
}
list<Territorio> Territorio::getVecinos(){
    return vecinos;
}