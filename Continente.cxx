#include <iostream>
#include "Continente.h"

using namespace std;

list<Continente> tablero;

// Setters
string Continente::getNombre(){
    return nombre;
}
string Continente::getColor(){
    return color;
}
int Continente::getUnidades(){
    return unidades;
}
list<Territorio> Continente::getTerritorios(){
    return territorios;
}

// Setters
void Continente::setNombre(string n){
    nombre = n;
}
void Continente::setColor(string c) {
    color = c;
}
void Continente::setUnidades(int u) {
    unidades = u;
}

void Continente::crearTablero(){
    Continente aux;

    aux.setNombre("America del Norte");
    aux.setColor("Amarillo");
    aux.setUnidades(5);
    tablero.push_back(aux);

    aux.setNombre("America del sur");
    aux.setColor("Rojo");
    aux.setUnidades(2);
    tablero.push_back(aux);

    aux.setNombre("Europa");
    aux.setColor("Azul");
    aux.setUnidades(5);
    tablero.push_back(aux);

    aux.setNombre("Africa");
    aux.setColor("Naranja");
    aux.setUnidades(3);
    tablero.push_back(aux);

    aux.setNombre("Asia");
    aux.setColor("Verde");
    aux.setUnidades(7);
    tablero.push_back(aux);

    aux.setNombre("Oceania/Australia");
    aux.setColor("Rosado");
    aux.setUnidades(2);
    tablero.push_back(aux);
}