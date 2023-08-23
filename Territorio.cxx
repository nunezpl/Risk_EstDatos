#include <iostream>
#include "Territorio.h"
#include "Jugador.h"
using namespace std;

// Implementacion de metodos
void Territorio::setNombre(string n){
    nombre = n;
}
void Territorio::addVecino(Territorio* t){
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
vector<Territorio*>& Territorio::getVecinos(){
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

void Territorio::imprimirVecinos(){
    for(int i=0; i< vecinos.size(); i++){
        cout << i << ": " << vecinos[i]->nombre << endl;
    }
}
bool Territorio::esVecino(const Territorio& otroTerritorio) const {
    for (Territorio* vecino : vecinos) {
        if (vecino->getNombre() == otroTerritorio.getNombre()) {
            return true; // Encontramos un territorio vecino con el mismo nombre
        }
    }
    return false; // No se encontro el territorio como vecino
}