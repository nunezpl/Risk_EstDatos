#include <iostream>
#include "Tablero.h"

using namespace std;

// Definición de la variable estática
vector<Continente> Tablero::tablero;

void Tablero::crearTablero(){
    Continente aux;

    aux.setNombre("America del Norte");
    aux.setColor("Amarillo");
    aux.setUnidades(5);
    Tablero::tablero.push_back(aux);

    aux.setNombre("America del sur");
    aux.setColor("Rojo");
    aux.setUnidades(2);
    Tablero::tablero.push_back(aux);

    aux.setNombre("Europa");
    aux.setColor("Azul");
    aux.setUnidades(5);
    Tablero::tablero.push_back(aux);

    aux.setNombre("Africa");
    aux.setColor("Naranja");
    aux.setUnidades(3);
    Tablero::tablero.push_back(aux);

    aux.setNombre("Asia");
    aux.setColor("Verde");
    aux.setUnidades(7);
    Tablero::tablero.push_back(aux);

    aux.setNombre("Oceania/Australia");
    aux.setColor("Rosado");
    aux.setUnidades(2);
    Tablero::tablero.push_back(aux);

    crearTerritorios();
}

void Tablero::crearTerritorios(){
    Territorio t;

    //America del Norte
    t.setNombre("Alaska");
    tablero[0].setTerritorio(t);

    t.setNombre("Alberta");
    tablero[0].setTerritorio(t);

    t.setNombre("America Central");
    tablero[0].setTerritorio(t);

    t.setNombre("Estados Unidos Orientales");
    tablero[0].setTerritorio(t);

    t.setNombre("Groenlandia");
    tablero[0].setTerritorio(t);

    t.setNombre("Territorio Noroccidental");
    tablero[0].setTerritorio(t);

    t.setNombre("Ontario");
    tablero[0].setTerritorio(t);

    t.setNombre("Quebec");
    tablero[0].setTerritorio(t);

    t.setNombre("Estados Unidos Occidentales");
    tablero[0].setTerritorio(t);

    // Vecinos
    /*Territorio& territorio1 = tablero[0].getTerritorios()[0];  // Accede al territorio
    territorio1.addVecino(tablero[0].getTerritorios()[1]);
    territorio1.addVecino(tablero[0].getTerritorios()[5]);*/

    // America del sur
    t.setNombre("Argentina");
    tablero[1].setTerritorio(t);

    t.setNombre("Brasil");
    tablero[1].setTerritorio(t);

    t.setNombre("Peru");
    tablero[1].setTerritorio(t);

    t.setNombre("Venezuela");
    tablero[1].setTerritorio(t);

    // Europa
    t.setNombre("Gran Bretana");
    tablero[2].setTerritorio(t);

    t.setNombre("Islandia");
    tablero[2].setTerritorio(t);

    t.setNombre("Europa del Norte");
    tablero[2].setTerritorio(t);

    t.setNombre("Escandinavia");
    tablero[2].setTerritorio(t);

    t.setNombre("Europa del Sur");
    tablero[2].setTerritorio(t);

    t.setNombre("Ucrania");
    tablero[2].setTerritorio(t);

    t.setNombre("Europa Occidental");
    tablero[2].setTerritorio(t);

    // Africa
    t.setNombre("Congo");
    tablero[3].setTerritorio(t);

    t.setNombre("Africa Oriental");
    tablero[3].setTerritorio(t);

    t.setNombre("Egipto");
    tablero[3].setTerritorio(t);

    t.setNombre("Madagascar");
    tablero[3].setTerritorio(t);

    t.setNombre("Africa del Norte");
    tablero[3].setTerritorio(t);

    t.setNombre("Africa del Sur");
    tablero[3].setTerritorio(t);

    // Asia
    t.setNombre("Afghanistan");
    tablero[4].setTerritorio(t);

    t.setNombre("China");
    tablero[4].setTerritorio(t);

    t.setNombre("India");
    tablero[4].setTerritorio(t);

    t.setNombre("Irkutsk");
    tablero[4].setTerritorio(t);

    t.setNombre("Japon");
    tablero[4].setTerritorio(t);

    t.setNombre("Kamchatka");
    tablero[4].setTerritorio(t);

    t.setNombre("Medio Oriente");
    tablero[4].setTerritorio(t);

    t.setNombre("Mongolia");
    tablero[4].setTerritorio(t);

    t.setNombre("Siam");
    tablero[4].setTerritorio(t);

    t.setNombre("Siberia");
    tablero[4].setTerritorio(t);

    t.setNombre("Ural");
    tablero[4].setTerritorio(t);

    t.setNombre("Yakutsk");
    tablero[4].setTerritorio(t);

    // Oceania/Australia
    t.setNombre("Australia Oriental");
    tablero[5].setTerritorio(t);

    t.setNombre("Indonesia");
    tablero[5].setTerritorio(t);

    t.setNombre("Nueva Guinea");
    tablero[5].setTerritorio(t);

    t.setNombre("Australia Occidental");
    tablero[5].setTerritorio(t);
}

void Tablero::imprimirTablero(){
    for (int i=0; i < tablero.size(); i++) {
        cout << "\nContinente: " << tablero[i].getNombre() << "\n Territorios:"<< endl;
        tablero[i].imprimirTerritorios();
    }
}