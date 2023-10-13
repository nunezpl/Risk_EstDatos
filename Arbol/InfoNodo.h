#ifndef RISK_ESTDATOS_INFONODO_H
#define RISK_ESTDATOS_INFONODO_H

using namespace std;
#include <iostream>

class InfoNodo {
public:
    void setValor(char c);
    void setFrecuencia(int f);
    void setAscii(int a);
    void setRuta(string r);

    char getValor();
    int getFrecuencia();
    int getAscii();
    string getRuta();

    bool traduccionAscii();

protected:
    char valor;
    int frecuencia;
    int ascii;
    string ruta;
};

#include "InfoNodo.cpp"
#endif //RISK_ESTDATOS_INFONODO_H
