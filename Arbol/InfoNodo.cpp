#include "InfoNodo.h"

void InfoNodo::setValor(char c){
    valor = c;
}
void InfoNodo::setFrecuencia(int f){
    frecuencia = f;
}
void InfoNodo::setAscii(string a){
    ascii = a;
}

char InfoNodo::getValor(){
    return valor;
}
int InfoNodo::getFrecuencia(){
    return frecuencia;
}
string InfoNodo::getAscii(){
    return ascii;
}