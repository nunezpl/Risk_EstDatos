#include <iostream>
#include "Territorio.h"
#include "Jugador.h"
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
void Territorio::setOcupante(Jugador* jugador) {
    ocupante = jugador;
}

void Territorio::setCantiEjercitos(int c) {
    cantiEjercitos = c;
}

string Territorio::getNombre() const{
    return nombre;
}
vector<Territorio> Territorio::getVecinos(){
    return vecinos;
}
bool Territorio::getOcupado() const{
    return ocupado;
}
Jugador* Territorio::getOcupante() {
    return ocupante;
}
int Territorio::getCantiEjercitos() {
    return cantiEjercitos;
}