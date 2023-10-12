#include "ArbolHuffman.h"
using namespace std;

void ArbolHuffman::setRaiz(Nodo* r){
    raiz = r;
}

Nodo* ArbolHuffman::getRaiz(){
    return raiz;
}

bool ArbolHuffman::repetidos(){
    return true;
}

bool ArbolHuffman::codificar(){
    return true;
}

bool ArbolHuffman::decodificar(){
    return true;
}

bool ArbolHuffman::addNode(Nodo &data) {
    if (raiz == nullptr)
    {
        raiz = new Nodo(data);
        return true;
    }

    return addNodeAux(data, *raiz);
}
bool ArbolHuffman::addNodeAux(Nodo &nuevo, Nodo &padre) {
    if ( padre.esHoja())
    {
        Nodo* aux = new Nodo(*&nuevo);
        nuevo = *aux;
        return true;
    }

    else if (nuevo.getInfo().getFrecuencia() < (padre.getInfo()).getFrecuencia())
    { // Si la frecuencia que llega es mejor al padre, se pone como derecho
        return addNodeAux(nuevo, *(padre.getHijoDer()));
    }
    else if (nuevo.getInfo().getFrecuencia() > (padre.getInfo()).getFrecuencia())
    { // si la frecuencia es mayor, se pone en el izq
        return addNodeAux(nuevo, *(padre.getHijoIzq()));
    }
    else if (nuevo.getInfo().getFrecuencia() == (padre.getInfo()).getFrecuencia())
    { // si la frecuencia es igual, se guarda en la derecha
        return addNodeAux(nuevo, *(padre.getHijoDer()));
    }

    return false;
}

list<InfoNodo> ArbolHuffman::preOrder() {
    // Creamos una lista vacia para almacenar los datos del arbol
    // en preorden.
    list<InfoNodo> list;

    // Llamamos a la funcion auxiliar para recorrer el arbol en preorden.
    // Recibe por referencia la lista vacia para ir agregando los datos del arbol.
    preOrderAux(raiz, list);

    return list;
}
void ArbolHuffman::preOrderAux(Nodo* node, list<InfoNodo> &list) {
    if (node == nullptr)
    {
        return;
    }

    list.push_back(node->getInfo());
    preOrderAux(node->getHijoIzq(), list);
    preOrderAux(node->getHijoDer(), list);
}


ArbolHuffman ArbolHuffman::construirArbolHuffman(vector<InfoNodo>& caracteres) {

    // Comparador para la cola de prioridad basada en las frecuencias
    auto comparador = [](Nodo* a, Nodo* b) { return a->getInfo().getFrecuencia() > b->getInfo().getFrecuencia(); };

    // Cola de prioridad para mantener los nodos ordenados por frecuencia
    priority_queue<Nodo*, vector<Nodo*>, decltype(comparador)> colaPrioridad(comparador);

    // Crear nodos iniciales para cada carácter y agregarlos a la cola de prioridad
    for (InfoNodo info : caracteres) {
        Nodo* nodo = new Nodo(info);
        colaPrioridad.push(nodo);
    }

    // Construir el árbol de Huffman
    while (colaPrioridad.size() > 1) {
        // Tomar los dos nodos con las frecuencias más bajas
        Nodo* izquierdo = colaPrioridad.top();
        colaPrioridad.pop();
        Nodo* derecho = colaPrioridad.top();
        colaPrioridad.pop();

        // Crear un nuevo nodo interno con los dos nodos como hijos
        Nodo* nuevoNodo = new Nodo(izquierdo, derecho);
        colaPrioridad.push(nuevoNodo);
    }

    // El único nodo restante en la cola de prioridad es la raíz del árbol de Huffman
    this->raiz =colaPrioridad.top() ;

    return *this;
}