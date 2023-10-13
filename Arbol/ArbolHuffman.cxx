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

/*
 * void ArbolHuffman::guardarArbolTxt(string nombre_archivo) {
    ofstream archivo(nombre_archivo);
    if (archivo.is_open()) {
        archivo << to_string();
        archivo.close();
    }
}*/

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