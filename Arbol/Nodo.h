#ifndef RISK_ESTDATOS_NODO_H
#define RISK_ESTDATOS_NODO_H

using namespace std;
#include <iostream>
#include <vector>
#include <bitset>
#include "InfoNodo.h"

class Nodo {
    public:
        Nodo();
        Nodo(InfoNodo data);
        Nodo(Nodo* de, Nodo* iz);
        Nodo(Nodo* de, Nodo* iz, char va, string as);
        ~Nodo();

        void setInfo(InfoNodo v);
        void setHijoDer(Nodo* n);
        void setHijoIzq(Nodo* n);

        InfoNodo getInfo();
        Nodo* getHijoDer();
        Nodo* getHijoIzq();

        void addHijo(int lado);
        bool traduccionAscii();
        string convertirABinario();

        bool operator<(Nodo &otherBinaryNode);
        bool operator>(Nodo &otherBinaryNode);
        bool esHoja();

    protected:
        InfoNodo info;
        Nodo* hijoDer;
        Nodo* hijoIzq;
};

#include "Nodo.cxx"
#endif //RISK_ESTDATOS_NODO_H
