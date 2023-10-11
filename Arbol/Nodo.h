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

        vector<string> obtenerBitCode();
        long convertirABinario(string letra);

    protected:
        char valor;
        int frecuencia;
        int ascii;
        Nodo* hijoDer;
        Nodo* hijoIzq;
};


#endif //RISK_ESTDATOS_NODO_H
