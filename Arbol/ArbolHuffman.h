#ifndef RISK_ESTDATOS_ARBOLHUFFMAN_H
#define RISK_ESTDATOS_ARBOLHUFFMAN_H

using namespace std;
#include <iostream>
#include <list>
#include <queue>

#include "Nodo.h"
#include "InfoNodo.h"

class ArbolHuffman {
    public:
        void setRaiz(Nodo* r);
        Nodo* getRaiz();

        bool repetidos();

        bool codificar();
        bool  decodificar();

        ArbolHuffman construirArbolHuffman(vector<InfoNodo>& caracteres);

        bool addNode(Nodo &data);
        bool addNodeAux(Nodo &data, Nodo &node);

        list<InfoNodo> preOrder();
        void preOrderAux(Nodo* node, list<InfoNodo> &list);

        void imprimirArbolHuffman(Nodo* nodo, int nivel);

    protected:
        Nodo* raiz;
};


#endif //RISK_ESTDATOS_ARBOLHUFFMAN_H
