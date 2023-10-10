
#include "Nodo.h"
using namespace std;

void Nodo::setValor(char c){
    valor = c;
}
void Nodo::setFrecuencia(int f){
    frecuencia = f;
}

char Nodo::getValor(){
    return valor;
}
int Nodo::getFrecuencia(){
    return frecuencia;
}