#ifndef RISK_ESTDATOS_NODO_H
#define RISK_ESTDATOS_NODO_H

using namespace std;
#include <iostream>

class Nodo {
    public:
        void setValor(char c);
        void setFrecuencia(int f);
        char getValor();
        int getFrecuencia();

        void addHijo(int lado);

    protected:
        char valor;
        int frecuencia;
        Nodo* hijoDer;
        Nodo* hijoIzq;
};


#endif //RISK_ESTDATOS_NODO_H
