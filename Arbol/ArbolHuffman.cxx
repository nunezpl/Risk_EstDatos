#include "ArbolHuffman.h"
using namespace std;

void ArbolHuffman::setRaiz(Nodo* r){
    raiz = r;
}

Nodo* ArbolHuffman::getRaiz(){
    return raiz;
}


ArbolHuffman ArbolHuffman::construirArbolHuffman(vector<InfoNodo>& caracteres) {

    // Comparador para la cola de prioridad basada en las frecuencias
    auto comparador = [](Nodo* a, Nodo* b) {
        return a->getInfo().getFrecuencia() > b->getInfo().getFrecuencia();
    };

    // Cola de prioridad para mantener los nodos ordenados por frecuencia
    priority_queue<Nodo*, vector<Nodo*>, decltype(comparador)> colaPrioridad(comparador);


    // Crear nodos iniciales para cada carácter y agregarlos a la cola de prioridad
    for (InfoNodo info : caracteres) {
        Nodo* nodo = new Nodo(info);
        colaPrioridad.push(nodo);
    }

    priority_queue<Nodo*, vector<Nodo*>, decltype(comparador)> colaP2 = colaPrioridad;

    // Imprimir elementos de la cola de prioridad
    cout << "Elementos de la cola de prioridad:" << endl;

    while (!colaP2.empty()) {
            cout << colaP2.top()->getInfo().getFrecuencia() << "." << colaP2.top()->getInfo().getValor() << "  ";
            colaP2.pop();
    }
    cout<< endl;

    // Construir el árbol de Huffman
    while (colaPrioridad.size() > 1) {
        // Tomar los dos nodos con las frecuencias más bajas
        Nodo* izquierdo = colaPrioridad.top();
        colaPrioridad.pop();
        Nodo* derecho = colaPrioridad.top();
        colaPrioridad.pop();

        // Crear un nuevo nodo interno con los dos nodos como hijos
        Nodo* nuevoNodo = new Nodo(izquierdo, derecho, '\0', 0, "");

        nuevoNodo->getInfo().setFrecuencia(izquierdo->getInfo().getFrecuencia() + derecho->getInfo().getFrecuencia());

        colaPrioridad.push(nuevoNodo);
    }

    // El único nodo restante en la cola de prioridad es la raíz del árbol de Huffman
    this->raiz =colaPrioridad.top() ;

    imprimirArbolHuffman(raiz, 0);

    return *this;
}

void ArbolHuffman::imprimirArbolHuffman(Nodo* nodo, int nivel=0) {
    if (nodo == nullptr) {
        return;
    }

    // Imprimir información del nodo
    for (int i = 0; i < nivel; ++i) {
        cout << "  ";
    }
    cout << "|-- " << nodo->getInfo().getValor() << " (" << nodo->getInfo().getFrecuencia() << ")\n";

    // Recorrer hacia la izquierda con '0'
    imprimirArbolHuffman(nodo->getHijoIzq(), nivel + 1);

    // Recorrer hacia la derecha con '1'
    imprimirArbolHuffman(nodo->getHijoDer(), nivel + 1);
}

string ArbolHuffman::BuscarCharEnArbol(Nodo* nodo, char ch) {
    if (nodo == NULL) {
        return "";
    }
    if (nodo->getInfo().getValor() == ch) {
        return "";
    }
    string leftPath = BuscarCharEnArbol(nodo->getHijoIzq(), ch);
    if (leftPath != "") {
        return "0" + leftPath;
    }
    string rightPath = BuscarCharEnArbol(nodo->getHijoDer(), ch);
    if (rightPath != "") {
        return "1" + rightPath;
    }

    return "";
}

string ArbolHuffman::traduceBinario(Nodo* nodo, vector<string> binario){
    string resultado;
    Nodo* nodoActual = nodo;

    for (int i = 0; i < binario.size(); ++i) {
        for (char c : binario[i]) {
            if(c == '0'){
                nodoActual = nodoActual->getHijoIzq();
            }else if(c == '1'){
                nodoActual = nodoActual->getHijoDer();
            }

            // Si llegamos a una hoja del árbol, añadimos el carácter al resultado
            if (nodoActual->getHijoIzq() == nullptr && nodoActual->getHijoDer() == nullptr) {
                cout << nodoActual->getInfo().getValor() ;
                resultado += nodoActual->getInfo().getValor();
                nodoActual = nodo;  // Reiniciar desde la raíz para el próximo código binario
            }

        }
    }
    cout << "\n";
    return resultado;
}

