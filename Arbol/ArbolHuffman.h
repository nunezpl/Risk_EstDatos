#ifndef RISK_ESTDATOS_ARBOLHUFFMAN_H
#define RISK_ESTDATOS_ARBOLHUFFMAN_H

using namespace std;
#include <iostream>
#include "Nodo.h"

class ArbolHuffman {
    public:
        void setRaiz(Nodo r);
        Nodo getRaiz();

        bool repetidos();
        bool traduccionAscii();

    protected:
        Nodo* raiz;
};


#endif //RISK_ESTDATOS_ARBOLHUFFMAN_H
