#ifndef RISK_ESTDATOS_ARBOLHUFFMAN_H
#define RISK_ESTDATOS_ARBOLHUFFMAN_H

using namespace std;
#include <iostream>
#include <list>
#include <queue>
#include <fstream>
#include <string>

#include "Nodo.h"
#include "InfoNodo.h"

class ArbolHuffman {
    public:
        void setRaiz(Nodo* r);
        Nodo* getRaiz();

        ArbolHuffman construirArbolHuffman(vector<InfoNodo>& caracteres);

        //void guardarArbolTxt(string nombre_archivo);

        void imprimirArbolHuffman(Nodo* nodo, int nivel);
        string BuscarCharEnArbol(Nodo* nodo, char ch);
        string traduceBinario(Nodo* nodo, vector<string> binario);

    protected:
        Nodo* raiz;
};

#include "ArbolHuffman.cxx"
#endif //RISK_ESTDATOS_ARBOLHUFFMAN_H
