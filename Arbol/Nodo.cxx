
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


bool Nodo::traduccionAscii(){
    // cambia el codigo ascii de una letra

    if ( isdigit(static_cast<unsigned char>( (info.getValor()) )) == 0 ) {
        // Obtiene el carácter y calcula su código ASCII
        char letra = info.getValor();
        int codigoAscii = static_cast<int>(letra);

        // Establece el código ASCII en la info del nodo
        info.setAscii(reinterpret_cast<const char *>(codigoAscii));
        cout << " Letra: "<<(info.getValor()) << " Ascii: "<<codigoAscii<<endl;
        return true;
    }else if ( isdigit(static_cast<unsigned char>( (info.getValor()) )) != 0 ){
        // Establece el código ASCII en la info del nodo
        info.setAscii(reinterpret_cast<const char *>(info.getValor()));
        cout << " Num: "<<(info.getValor())<<endl;
        return true;
    } else {
        // Manejar el caso en el que la info no sea un carácter válido
        cout << " Error: no se reconoce si es letra o numero.\n";
        return false;
    }
}

string Nodo::convertirABinario(){
    bool aux = traduccionAscii();
    string a = info.getAscii();
    string binCode= bitset<8>( a ).to_string();;

    return binCode;
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
Nodo::Nodo(Nodo* de, Nodo* iz, char va, string as) {
    this->hijoIzq = iz;
    this->hijoDer = de;
    this->info.setValor(va);
    this->info.setAscii(as);

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