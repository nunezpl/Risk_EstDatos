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
    t.setOcupado(false);
    t.setOcupante(nullptr);

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

    // Vecinos
    enlazarVecinos();
}

void Tablero::enlazarVecinos(){
    // ( Accede al territorio ). addVecino( accede al vecino )

    // 0. America del Norte
        //          1. Alaska
        (tablero[0].getTerritorios()[0]).addVecino(tablero[0].getTerritorios()[1]);
        (tablero[0].getTerritorios()[0]).addVecino(tablero[0].getTerritorios()[5]);
        //          2.Alberta
        (tablero[0].getTerritorios()[1]).addVecino(tablero[0].getTerritorios()[5]);
        (tablero[0].getTerritorios()[1]).addVecino(tablero[0].getTerritorios()[6]);
        (tablero[0].getTerritorios()[1]).addVecino(tablero[0].getTerritorios()[8]);
        //          3.America Central
        (tablero[0].getTerritorios()[2]).addVecino(tablero[0].getTerritorios()[3]);
        (tablero[0].getTerritorios()[2]).addVecino(tablero[0].getTerritorios()[8]);
        //          4. Estados Unidos Orientales
        (tablero[0].getTerritorios()[3]).addVecino(tablero[0].getTerritorios()[6]);
        (tablero[0].getTerritorios()[3]).addVecino(tablero[0].getTerritorios()[7]);
        (tablero[0].getTerritorios()[3]).addVecino(tablero[0].getTerritorios()[8]);
        (tablero[0].getTerritorios()[3]).addVecino(tablero[0].getTerritorios()[2]);
        //          5. Groenlandia
        (tablero[0].getTerritorios()[4]).addVecino(tablero[0].getTerritorios()[5]);
        (tablero[0].getTerritorios()[4]).addVecino(tablero[0].getTerritorios()[6]);
        (tablero[0].getTerritorios()[4]).addVecino(tablero[0].getTerritorios()[7]);
        (tablero[0].getTerritorios()[4]).addVecino(tablero[2].getTerritorios()[1]); // Islandia - Europa
        //          6. Territorio Noroccidental
        (tablero[0].getTerritorios()[5]).addVecino(tablero[0].getTerritorios()[0]);
        (tablero[0].getTerritorios()[5]).addVecino(tablero[0].getTerritorios()[1]);
        (tablero[0].getTerritorios()[5]).addVecino(tablero[0].getTerritorios()[6]);
        (tablero[0].getTerritorios()[5]).addVecino(tablero[0].getTerritorios()[4]);
        //          7. Ontario
        (tablero[0].getTerritorios()[6]).addVecino(tablero[0].getTerritorios()[1]);
        (tablero[0].getTerritorios()[6]).addVecino(tablero[0].getTerritorios()[3]);
        (tablero[0].getTerritorios()[6]).addVecino(tablero[0].getTerritorios()[5]);
        (tablero[0].getTerritorios()[6]).addVecino(tablero[0].getTerritorios()[7]);
        (tablero[0].getTerritorios()[6]).addVecino(tablero[0].getTerritorios()[4]);
        //          8. Quebec
        (tablero[0].getTerritorios()[7]).addVecino(tablero[0].getTerritorios()[4]);
        (tablero[0].getTerritorios()[7]).addVecino(tablero[0].getTerritorios()[6]);
        (tablero[0].getTerritorios()[7]).addVecino(tablero[0].getTerritorios()[3]);
        //          9. Estados Unidos Occidentales
        (tablero[0].getTerritorios()[8]).addVecino(tablero[0].getTerritorios()[1]);
        (tablero[0].getTerritorios()[8]).addVecino(tablero[0].getTerritorios()[6]);
        (tablero[0].getTerritorios()[8]).addVecino(tablero[0].getTerritorios()[4]);
        (tablero[0].getTerritorios()[8]).addVecino(tablero[0].getTerritorios()[3]);

    // 1. America del Sur
        //          1. Argentina
        (tablero[1].getTerritorios()[0]).addVecino(tablero[1].getTerritorios()[1]);
        (tablero[1].getTerritorios()[0]).addVecino(tablero[1].getTerritorios()[2]);
        //          2. Brasil
        (tablero[1].getTerritorios()[1]).addVecino(tablero[1].getTerritorios()[0]);
        (tablero[1].getTerritorios()[1]).addVecino(tablero[1].getTerritorios()[2]);
        (tablero[1].getTerritorios()[1]).addVecino(tablero[1].getTerritorios()[3]);
        (tablero[1].getTerritorios()[1]).addVecino(tablero[3].getTerritorios()[4]);
        //          3. Perú
        (tablero[1].getTerritorios()[2]).addVecino(tablero[1].getTerritorios()[3]);
        (tablero[1].getTerritorios()[2]).addVecino(tablero[1].getTerritorios()[1]);
        (tablero[1].getTerritorios()[2]).addVecino(tablero[1].getTerritorios()[0]);
        //          4. Venezuela
        (tablero[1].getTerritorios()[3]).addVecino(tablero[1].getTerritorios()[2]);
        (tablero[1].getTerritorios()[3]).addVecino(tablero[1].getTerritorios()[1]);

    // 2. Europa
        //          1. Gran Bretaña
        //          2. Islandia
        //          3. Europa del Norte
        //          4. Escandinavia
        //          5. Europa del Sur
        //          6. Ucrania
        //          7. Europa Occidental

    // 3. Africa
        //          1. Congo
        //          2. África Oriental
        //          3. Egipto
        //          4. Madagascar
        //          5. África del Norte
        //          6. África del Sur

    // 4. Asia
        //          1. Afghanistán
        //          2. China
        //          3. India
        //          4. Irkutsk
        //          5. Japón
        //          6. Kamchatka
        //          7. Medio Oriente
        //          8. Mongolia
        //          9. Siam
        //          10. Siberia
        //          11. Ural
        //          12. Yakutsk

    // 5. Oceania/Australia
        //          1. Australia Oriental
        //          2. Indonesia
        //          3. Nueva Guinea
        //          4. Australia Occidental
}

void Tablero::imprimirTablero(){
    for (int i=0; i < tablero.size(); i++) {
        cout << "\nContinente: " << tablero[i].getNombre() << "\n Territorios:"<< endl;
        tablero[i].imprimirTerritorios();
    }
}