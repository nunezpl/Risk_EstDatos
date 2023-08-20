#include <iostream>
#include "Territorio.h"
using namespace std;

// Implementacion de metodos
void Territorio::setNombre(string n){
    nombre = n;
}
void Territorio::addVecino(Territorio& t){
    vecinos.push_back(t);
}
void Territorio::setOcupado(bool b){
    ocupado = b;
}

string Territorio::getNombre(){
    return nombre;
}
vector<Territorio> Territorio::getVecinos(){
    return vecinos;
}
bool Territorio::getOcupado(){
    return ocupado;
}