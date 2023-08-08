#include <iostream>
#include "Continente.h"

using namespace std;

// Definición de la variable estática
list<Continente> Continente::tablero;

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
    Continente::tablero.push_back(aux);

    aux.setNombre("America del sur");
    aux.setColor("Rojo");
    aux.setUnidades(2);
    Continente::tablero.push_back(aux);

    aux.setNombre("Europa");
    aux.setColor("Azul");
    aux.setUnidades(5);
    Continente::tablero.push_back(aux);

    aux.setNombre("Africa");
    aux.setColor("Naranja");
    aux.setUnidades(3);
    Continente::tablero.push_back(aux);

    aux.setNombre("Asia");
    aux.setColor("Verde");
    aux.setUnidades(7);
    Continente::tablero.push_back(aux);

    aux.setNombre("Oceania/Australia");
    aux.setColor("Rosado");
    aux.setUnidades(2);
    Continente::tablero.push_back(aux);
}

void Continente::evaluarCostoConquista (){

    cout << "Para conquistar el territorio <territorio>, debe atacar desde <territorio_1>, pasando por los territorios <territorio_2>, <territorio_3>, ..., <territorio_m>. Debe conquistar <n> unidades de ejército." << endl;

}
void Continente::evaluarCostoConquistaBarata(){
    cout << "Evaluando ..." << endl;
    // Codigo para evaluar a conquista mas barata
    cout << "La conquista más barata es avanzar sobre el territorio .... Debe conquistar <n>unidades de ejército" << endl;
}
