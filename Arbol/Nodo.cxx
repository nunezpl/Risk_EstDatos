
#include "Nodo.h"
using namespace std;

void Nodo::setInfo(InfoNodo i){
    info = i;
}
void Nodo::setHijoDer(Nodo* n){
    hijoDer = n;
}
void Nodo::setHijoIzq(Nodo* n){
    hijoIzq = n;
}

InfoNodo Nodo::getInfo(){
    return info;
}
Nodo* Nodo::getHijoDer(){
    return hijoDer;
}
Nodo* Nodo::getHijoIzq(){
    return hijoIzq;
}


Nodo::Nodo() {

}
Nodo::Nodo(InfoNodo data){
    this->info = data;
    this->hijoDer = nullptr;
    this->hijoIzq = nullptr;
}
Nodo::Nodo(Nodo* de, Nodo* iz){
    this->hijoIzq = iz;
    this->hijoDer = de;
}
Nodo::Nodo(Nodo* de, Nodo* iz, char va, int as, string ru) {
    this->hijoIzq = iz;
    this->hijoDer = de;
    this->info.setValor(va);
    this->info.setAscii(as);
    this->info.setRuta(ru);
    if (iz && de) {
        this->info.setFrecuencia(iz->getInfo().getFrecuencia() + de->getInfo().getFrecuencia());
    }
}
Nodo::~Nodo(){
    delete hijoDer;
    hijoDer = nullptr;
    delete hijoIzq;
    hijoIzq = nullptr;
}

bool Nodo::operator<(Nodo &otherBinaryNode) {
    return info.getFrecuencia() < (otherBinaryNode.getInfo()).getFrecuencia();
}

bool Nodo::operator>(Nodo &otherBinaryNode) {
    return info.getFrecuencia() > (otherBinaryNode.getInfo()).getFrecuencia();
}

bool Nodo::esHoja(){
    if(this->hijoDer == nullptr && this->hijoIzq == nullptr){
        return true;
    }
        return false;
}
