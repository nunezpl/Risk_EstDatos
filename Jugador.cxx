#include <iostream>
#include "Jugador.h"
#include "Territorio.h"
using namespace std;

// constructor vacio
Jugador::Jugador( ) {
  nombre = "";
  id = 0;
}
// constructor con parametros
Jugador::Jugador(string n, long i) {
  nombre = n;
  id = i;
}

// Settters
void Jugador::setNombre(string n) {
    nombre = n;
}
void Jugador::setId(long i) {
    id = i;
}

// Getters
string Jugador::getNombre(){
    return nombre;
}
long Jugador::getId(){
    return id;
}

// Metodos
void Jugador::agregarTerritorioOcupado(Territorio t) {
    terrOcupados.push_back(t);
}
void Jugador::agregarEjercito(Ejercito e){
    ejercito.push_back(e);
}
void Jugador::agregarCarta(Tarjeta t){
    tarjetas.push_back(t);
}

/*
Realiza las operaciones descritas dentro del turno de un jugador (obtener nuevas unidades, atacar y fortificar).
   - informar al jugador cuántas unidades adicionales puede reclamar, para luego preguntarle en cuáles de sus territorios las quiere asignar y en qué cantidad.
   - preguntar la configuración del ataque, desde cuál territorio y hacia cuál territorio,
   - informar los valores obtenidos con los dados, y la cantidad de unidades que se ganan o pierden.
  Este proceso se repite hasta que alguno de los dos territorios se quede sin unidades, o hasta que el atacante decida detenerse.
  - preguntar al jugador los territorios vecinos que desea seleccionar para la fortificación, así como la cantidad de unidades que se trasladarán de uno al otro.
*/
void Jugador::turno(){
    // Nuevas unidades

    // Atacar

    // Fortificar
}