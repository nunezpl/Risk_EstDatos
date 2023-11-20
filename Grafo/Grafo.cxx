
#include "Grafo.h"






template<class T>
void Grafo<T>::FloydWarshall(vector<vector<int>> &dist, vector< vector<int> > &parent) {
    int n = (int)this->vertices.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 1e8;

            if (i == j) parent[i][j] = i;
            else parent[i][j] = -1;
        }
        for (pair<int, int> v: this->vertices[i].getAdj()) {
            dist[i][v.first] = v.second;
            parent[i][v.first] = i;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j] = k;
                }
            }
        }
    }
}

