#ifndef RISK_ESTDATOS_GRAFO_H
#define RISK_ESTDATOS_GRAFO_H

#include "NodoGrafo.h"
#include <vector>
#include <limits>
#include <queue>


template < class T >
class Grafo {
    private:
        vector< NodoGrafo<T> > vertices;
    public:
        vector<NodoGrafo<T>> getVertices();
        void setVertices(vector<NodoGrafo<T>> nuevo);

        // determinar el camino mas corto desde un nodo inicial
        void Dijkstra(int S, vector<long double> &dist, vector<int>&parent);

        void addVertex(T info);

        void addArc(int o, int d, int cost);

        void deleteArcs();

        //algoritmo de Floyd-Warshall para encontrar el camino minimo entre todos los pares de vertices del grafo
        void FloydWarshall(vector<vector<int>> &dist, vector< vector<int> > &parent);

};

// Estos metodos se pusieron aca para que compile
template<class T>
vector<NodoGrafo<T>> Grafo<T>::getVertices() {
    return vertices;
}

template<class T>
void Grafo<T>::addVertex(T info) {
    NodoGrafo<T> nuevo;
    nuevo.setInfo(info);
    this->vertices.push_back(nuevo);
}

template<class T>
void Grafo<T>::addArc(int o, int d, int cost) {
    this->vertices[o].addVertexAdj(d, cost);
}

template<class T>
void Grafo<T>::deleteArcs() {
    for (NodoGrafo<T> &vertex: this->vertices) vertex.clearAdj();
}

template< class T >
void Grafo<T>::Dijkstra(int S, vector<long double> &dist, vector<int>&parent) {

    for (int i = 0; i < dist.size(); i++) {
        dist[i] = 1e17;
        parent[i] = -1;
    }

    priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int>>> pq;
    dist[S] = 0;
    pq.push(make_pair(0, S));
    while (!pq.empty()) {
        pair<int, int> V = pq.top(); pq.pop();
        int dist_V = V.first;
        int vertex_V = V.second;
        if (dist_V > dist[vertex_V]) continue;

        for (pair<int, int> arc: this->vertices[vertex_V].getAdj()) {
            int to = arc.first;
            int len = arc.second;

            if (dist[vertex_V] + len < dist[to]) {
                dist[to] = dist[vertex_V] + len;
                parent[to] = vertex_V;
                pq.push(make_pair(dist[to], to));
            }
        }
    }
}


template< class T >
void Grafo<T>::setVertices(vector<NodoGrafo<T>> nuevo){
    this->vertices = nuevo;
}

#endif //RISK_ESTDATOS_GRAFO_H
