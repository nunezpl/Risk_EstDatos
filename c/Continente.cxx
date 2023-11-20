#include <iostream>
#include "../h/Continente.h"
#include "../h/Territorio.h"

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
vector<Territorio>& Continente::getTerritorios(){
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
    cout << "  #  Ocupado   #Vecinos   #Ejercito   Nombre"<< endl;
    for (int i = 0; i < territorios.size(); i++) {
        cout << "  "<< i << ":    " << territorios[i].getOcupado()<< "        " << territorios[i].getVecinos().size()<< "            " <<territorios[i].getCantiEjercitos()<< "        " << territorios[i].getNombre()<< endl;
    }
}

bool Continente::ocupadoPorJugador(Jugador& jugador) {
    for (int i=0; i< territorios.size(); i++) {
        if (!territorios[i].getOcupado() || territorios[i].getOcupante() != &jugador) {
            return false;  // Si algún territorio no está ocupado por el jugador, retorna false
        }
    }
    return true;  // Todos los territorios están ocupados por el jugador
}
