
#ifndef RISK_ESTDATOS_NODOGRAFO_H
#define RISK_ESTDATOS_NODOGRAFO_H

#include <iostream>
#include <vector>

using namespace std;

template < class T >
class NodoGrafo {
    private:
        T info;
        vector< pair<int, int> > adj; // id, peso

    public:

        // Getters & Setters
        T getInfo();
        void setInfo(T nuevo);
        void setAdj(vector< pair<int, int> > nuevo);
        vector< pair<int, int> > getAdj();

        void clearAdj();

        void updateCostAdj(int v, int cost);

        void addVertexAdj(int v, int cost);

};

template<class T>
T NodoGrafo<T>::getInfo() {
    return this->info;
}

template<class T>
void NodoGrafo<T>::setInfo(T nuevo) {
    this->info = nuevo;
}

template<class T>
void NodoGrafo<T>::addVertexAdj(int v, int cost) {
    this->adj.push_back(make_pair(v, cost));
}

template<class T>
void NodoGrafo<T>::clearAdj() {
    this->adj.clear();
}

template<class T>
vector<pair<int, int> > NodoGrafo<T>::getAdj() {
    return this->adj;
}


//#include "NodoGrafo.cxx"
#endif //RISK_ESTDATOS_NODOGRAFO_H
