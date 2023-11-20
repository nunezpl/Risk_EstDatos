#ifndef RISK_ESTDATOS_MASTER_H
#define RISK_ESTDATOS_MASTER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdint>
#include <unordered_map>

#include "../Grafo/NodoGrafo.h"
#include "../Grafo/Grafo.h"

#include "Jugador.h"
#include "Continente.h"
#include "Tablero.h"
#include "../Arbol/ArbolHuffman.h"

using namespace std;

class Master {
    public:
        // Declaracion de metodos
        void comandos();
        void ayuda();

        // Auxiliares
        string separaComandoP2String(string c);
        long separaComandoP2Long(string c);
        vector<string> separaLineaEspacio(string l);
        bool iniciarJuego();

        // Jugadores
        void actualizarTurno(Jugador* jugadorActual);
        Jugador* encontrarJugador(long id_jugador);
        void infoJugadores();
        void ocuparTerritorios();
        void mostrarJugadores();
        void comandoTurno(long id_jugador);
        vector<string> infoJugadoresString();

        // Archivos
        void comandoGuardarArchivoTxt (string nombreArchivo);
        bool guardarArchivo (string nombreArchivo);

        void comandoInicializarArchivo (string nombreArchivo);
        bool inicializarArchivoTxt (string nombreArchivo);
        bool inicializarArchivoBin (string nombreArchivo);
        vector<string> leerArchivoBinario(string nombreArchivo);

        void comandoGuardarArchivoComprimido (string nombreArchivo);
        bool comprimirArchivo (string nombreArchivo);
        vector<InfoNodo> informacionCaracteres(vector<string> t);
        void asignarCodigosBinarios(Nodo* nodo, string codigo, vector<InfoNodo>& caracteres);
        string codificarMensaje(string mensaje, vector<InfoNodo>& caracteres);
        bool guardarEnFormatoBinario(string nombreArchivo, vector<InfoNodo> caracteres, vector<string> mensajeCodificado);

        // Conquistas
        void comandoCostoConquista (string terri);
        void comandoConquistaBarata();
        void crearGrafo();
        void evaluarCostoConquista (string d);
        void evaluarCostoConquistaBarata();
        vector<int> obtenerPosicionesVertices(string from, string to);
        vector<Territorio> buildPath(int start, vector<int> parent);
        string caminoToString(vector<Territorio> camino);
        int pesoCamino(vector<Territorio> camino);
        pair<int, vector<Territorio>> territorioCercano(int pos);
        vector<Territorio> territoriosAConquistar();
        void imprimirResultado(vector<Territorio> ts);

protected:
        // Variables globales
        bool juegoIniciado = false;
        bool ganador = false;
        int numJugadores=0;
        list<Jugador> jugadores;
        Jugador* proxTurno; // Se actualiza cada vez que se acabe un turno
        ArbolHuffman arbol;
        Grafo<Territorio> grafo;
};

//#include "../c/Master.cxx"
#endif //RISK_ESTDATOS_MASTER_H
