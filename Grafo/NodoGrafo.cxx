#include "NodoGrafo.h"


template<class T>
void NodoGrafo<T>::updateCostAdj(int v, int cost) {
    for (pair<int, int> &neigh: this->adj) {
        if (neigh.first == v) {
            neigh.second = cost;
            break;
        }
    }
}

template<class T>
void NodoGrafo<T>::setAdj(vector<pair<int, int>> nuevo) {
    this->adj = nuevo;
}



