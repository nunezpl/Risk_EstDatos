#include <iostream>
#include "../h/Ejercito.h"
using namespace std;

// Implementacion de metodos

Ejercito::Ejercito(){
    categoria = "";
    color = "";
    unidades = 0;
}
Ejercito::Ejercito(string ca, string co, int u){
    categoria = ca;
    color = co;
    unidades = u;
}

// Getters y setters
void Ejercito::setCategoria(string c){
    categoria=c;
}
void Ejercito::setColor(string c){
    color=c;
}
void Ejercito::setUnidades(int u){
    unidades=u;
}

string Ejercito::getCategoria() const {
    return categoria;
}
string Ejercito::getColor(){
    return color;
}
int Ejercito::getUnidades(){
    return unidades;
}