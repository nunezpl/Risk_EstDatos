#include "InfoNodo.h"

void InfoNodo::setValor(char c){
    valor = c;
}
void InfoNodo::setFrecuencia(int f){
    frecuencia = f;
}
void InfoNodo::setAscii(int a){
    ascii = a;
}
void InfoNodo::setRuta(string r) {
    ruta = r;
}

char InfoNodo::getValor() {
    if (valor == '\0') {
        return ' ';
    }
    return valor;
}

int InfoNodo::getFrecuencia(){
    return frecuencia;
}
int InfoNodo::getAscii(){
    return ascii;
}
string InfoNodo::getRuta(){
    return ruta;
}

bool InfoNodo::traduccionAscii(){
        // cambia el codigo ascii de una letra
    if(valor == ' ') {
        ascii =  32;
        return true;
    } else if (isalpha(valor)) {
        ascii =  static_cast<int>(valor);
        //cout << " Letra: "<< valor << " Ascii: "<< ascii << endl;
        return true;
    } else if (isdigit(valor)) {
        ascii = valor;
        //cout << " Letra: "<< valor << " Ascii: "<< ascii << endl;
        return true;
    }
    return false;
}