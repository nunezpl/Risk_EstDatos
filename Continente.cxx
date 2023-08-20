#include <iostream>
#include "Continente.h"

using namespace std;

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
vector<Territorio> Continente::getTerritorios(){
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
void Continente::setTerritorio(Territorio t){
    territorios.push_back(t);
}

// Otros metodos
void Continente::imprimirTerritorios(){
    for (int i = 0; i < territorios.size(); i++) {
        cout << "  "<< i << ": " << territorios[i].getNombre() << endl;
    }
}

void Continente::evaluarCostoConquista (){

    cout << "Para conquistar el territorio <territorio>, debe atacar desde <territorio_1>, pasando por los territorios <territorio_2>, <territorio_3>, ..., <territorio_m>. Debe conquistar <n> unidades de ejército." << endl;

}
void Continente::evaluarCostoConquistaBarata(){
    cout << "Evaluando ..." << endl;
    // Codigo para evaluar a conquista mas barata
    cout << "La conquista más barata es avanzar sobre el territorio .... Debe conquistar <n>unidades de ejército" << endl;
}
