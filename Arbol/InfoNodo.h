#ifndef RISK_ESTDATOS_INFONODO_H
#define RISK_ESTDATOS_INFONODO_H

using namespace std;
#include <iostream>

class InfoNodo {
public:
    void setValor(char c);
    void setFrecuencia(int f);
    void setAscii(string a);

    char getValor();
    int getFrecuencia();
    string getAscii();

protected:
    char valor;
    int frecuencia;
    string ascii;
};


#endif //RISK_ESTDATOS_INFONODO_H
