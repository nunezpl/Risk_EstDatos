#include <iostream>
#include "../h/Tablero.h"

using namespace std;

// Definición de la variable estática
vector<Continente> Tablero::tablero;

void Tablero::imprimirTablero(){
    for (int i=0; i < tablero.size(); i++) {
        cout << "\nContinente: " << tablero[i].getNombre() << "\n Territorios:"<< endl;
        tablero[i].imprimirTerritorios();
    }
}

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
    crearTarjetas();
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
        (tablero[0].getTerritorios()[0]).addVecino(&tablero[0].getTerritorios()[1]);
        (tablero[0].getTerritorios()[0]).addVecino(&tablero[0].getTerritorios()[5]);
    (tablero[0].getTerritorios()[0]).setId(1);
        //          2.Alberta
        (tablero[0].getTerritorios()[1]).addVecino(&tablero[0].getTerritorios()[5]);
        (tablero[0].getTerritorios()[1]).addVecino(&tablero[0].getTerritorios()[6]);
        (tablero[0].getTerritorios()[1]).addVecino(&tablero[0].getTerritorios()[8]);
    (tablero[0].getTerritorios()[1]).setId(2);
        //          3.America Central
        (tablero[0].getTerritorios()[2]).addVecino(&tablero[0].getTerritorios()[3]);
        (tablero[0].getTerritorios()[2]).addVecino(&tablero[0].getTerritorios()[8]);
        (tablero[0].getTerritorios()[2]).addVecino(&tablero[1].getTerritorios()[3]); // America del sur - Argentina
    (tablero[0].getTerritorios()[2]).setId(3);
        //          4. Estados Unidos Orientales
        (tablero[0].getTerritorios()[3]).addVecino(&tablero[0].getTerritorios()[6]);
        (tablero[0].getTerritorios()[3]).addVecino(&tablero[0].getTerritorios()[7]);
        (tablero[0].getTerritorios()[3]).addVecino(&tablero[0].getTerritorios()[8]);
        (tablero[0].getTerritorios()[3]).addVecino(&tablero[0].getTerritorios()[2]);
    (tablero[0].getTerritorios()[3]).setId(4);
        //          5. Groenlandia
        (tablero[0].getTerritorios()[4]).addVecino(&tablero[0].getTerritorios()[5]);
        (tablero[0].getTerritorios()[4]).addVecino(&tablero[0].getTerritorios()[6]);
        (tablero[0].getTerritorios()[4]).addVecino(&tablero[0].getTerritorios()[7]);
        (tablero[0].getTerritorios()[4]).addVecino(&tablero[2].getTerritorios()[1]); // Islandia - Europa
    (tablero[0].getTerritorios()[4]).setId(5);
        //          6. Territorio Noroccidental
        (tablero[0].getTerritorios()[5]).addVecino(&tablero[0].getTerritorios()[0]);
        (tablero[0].getTerritorios()[5]).addVecino(&tablero[0].getTerritorios()[1]);
        (tablero[0].getTerritorios()[5]).addVecino(&tablero[0].getTerritorios()[6]);
        (tablero[0].getTerritorios()[5]).addVecino(&tablero[0].getTerritorios()[4]);
    (tablero[0].getTerritorios()[5]).setId(6);
        //          7. Ontario
        (tablero[0].getTerritorios()[6]).addVecino(&tablero[0].getTerritorios()[1]);
        (tablero[0].getTerritorios()[6]).addVecino(&tablero[0].getTerritorios()[3]);
        (tablero[0].getTerritorios()[6]).addVecino(&tablero[0].getTerritorios()[5]);
        (tablero[0].getTerritorios()[6]).addVecino(&tablero[0].getTerritorios()[7]);
        (tablero[0].getTerritorios()[6]).addVecino(&tablero[0].getTerritorios()[4]);
    (tablero[0].getTerritorios()[6]).setId(7);
        //          8. Quebec
        (tablero[0].getTerritorios()[7]).addVecino(&tablero[0].getTerritorios()[4]);
        (tablero[0].getTerritorios()[7]).addVecino(&tablero[0].getTerritorios()[6]);
        (tablero[0].getTerritorios()[7]).addVecino(&tablero[0].getTerritorios()[3]);
    (tablero[0].getTerritorios()[7]).setId(8);
        //          9. Estados Unidos Occidentales
        (tablero[0].getTerritorios()[8]).addVecino(&tablero[0].getTerritorios()[1]);
        (tablero[0].getTerritorios()[8]).addVecino(&tablero[0].getTerritorios()[6]);
        (tablero[0].getTerritorios()[8]).addVecino(&tablero[0].getTerritorios()[4]);
        (tablero[0].getTerritorios()[8]).addVecino(&tablero[0].getTerritorios()[3]);
    (tablero[0].getTerritorios()[9]).setId(9);

    // 1. America del Sur
        //          1. Argentina
        (tablero[1].getTerritorios()[0]).addVecino(&tablero[1].getTerritorios()[1]);
        (tablero[1].getTerritorios()[0]).addVecino(&tablero[1].getTerritorios()[2]);
    (tablero[1].getTerritorios()[0]).setId(10);
        //          2. Brasil
        (tablero[1].getTerritorios()[1]).addVecino(&tablero[1].getTerritorios()[0]);
        (tablero[1].getTerritorios()[1]).addVecino(&tablero[1].getTerritorios()[2]);
        (tablero[1].getTerritorios()[1]).addVecino(&tablero[1].getTerritorios()[3]);
        (tablero[1].getTerritorios()[1]).addVecino(&tablero[3].getTerritorios()[4]); // Africa - Africa del Norte
    (tablero[1].getTerritorios()[1]).setId(11);
        //          3. Perú
        (tablero[1].getTerritorios()[2]).addVecino(&tablero[1].getTerritorios()[3]);
        (tablero[1].getTerritorios()[2]).addVecino(&tablero[1].getTerritorios()[1]);
        (tablero[1].getTerritorios()[2]).addVecino(&tablero[1].getTerritorios()[0]);
    (tablero[1].getTerritorios()[2]).setId(12);
        //          4. Venezuela
        (tablero[1].getTerritorios()[3]).addVecino(&tablero[1].getTerritorios()[2]);
        (tablero[1].getTerritorios()[3]).addVecino(&tablero[1].getTerritorios()[1]);
        (tablero[1].getTerritorios()[3]).addVecino(&tablero[0].getTerritorios()[2]);
    (tablero[1].getTerritorios()[3]).setId(13);

    // 2. Europa
        //          1. Gran Bretaña
        (tablero[2].getTerritorios()[0]).addVecino(&tablero[2].getTerritorios()[6]);
        (tablero[2].getTerritorios()[0]).addVecino(&tablero[2].getTerritorios()[1]);
        (tablero[2].getTerritorios()[0]).addVecino(&tablero[2].getTerritorios()[2]);
        (tablero[2].getTerritorios()[0]).addVecino(&tablero[2].getTerritorios()[3]);
    (tablero[2].getTerritorios()[0]).setId(14);
        //          2. Islandia
        (tablero[2].getTerritorios()[1]).addVecino(&tablero[2].getTerritorios()[1]);
        (tablero[2].getTerritorios()[1]).addVecino(&tablero[2].getTerritorios()[3]);
        (tablero[2].getTerritorios()[1]).addVecino(&tablero[0].getTerritorios()[4]); // America del Norte - Groenlandia
    (tablero[2].getTerritorios()[1]).setId(15);
        //          3. Europa del Norte
        (tablero[2].getTerritorios()[2]).addVecino(&tablero[2].getTerritorios()[0]);
        (tablero[2].getTerritorios()[2]).addVecino(&tablero[2].getTerritorios()[3]);
        (tablero[2].getTerritorios()[2]).addVecino(&tablero[2].getTerritorios()[4]);
        (tablero[2].getTerritorios()[2]).addVecino(&tablero[2].getTerritorios()[5]);
        (tablero[2].getTerritorios()[2]).addVecino(&tablero[2].getTerritorios()[6]);
    (tablero[2].getTerritorios()[2]).setId(16);
        //          4. Escandinavia
        (tablero[2].getTerritorios()[3]).addVecino(&tablero[2].getTerritorios()[0]);
        (tablero[2].getTerritorios()[3]).addVecino(&tablero[2].getTerritorios()[1]);
        (tablero[2].getTerritorios()[3]).addVecino(&tablero[2].getTerritorios()[2]);
        (tablero[2].getTerritorios()[3]).addVecino(&tablero[2].getTerritorios()[5]);
    (tablero[2].getTerritorios()[3]).setId(17);
        //          5. Europa del Sur
        (tablero[2].getTerritorios()[4]).addVecino(&tablero[2].getTerritorios()[2]);
        (tablero[2].getTerritorios()[4]).addVecino(&tablero[2].getTerritorios()[6]);
        (tablero[2].getTerritorios()[4]).addVecino(&tablero[2].getTerritorios()[5]);
        (tablero[2].getTerritorios()[4]).addVecino(&tablero[3].getTerritorios()[2]); // Africa
        (tablero[2].getTerritorios()[4]).addVecino(&tablero[3].getTerritorios()[4]); // Africa
        (tablero[2].getTerritorios()[4]).addVecino(&tablero[4].getTerritorios()[6]); // Asia
    (tablero[2].getTerritorios()[4]).setId(18);
        //          6. Ucrania
        (tablero[2].getTerritorios()[5]).addVecino(&tablero[2].getTerritorios()[2]);
        (tablero[2].getTerritorios()[5]).addVecino(&tablero[2].getTerritorios()[3]);
        (tablero[2].getTerritorios()[5]).addVecino(&tablero[2].getTerritorios()[4]);
        (tablero[2].getTerritorios()[5]).addVecino(&tablero[4].getTerritorios()[0]); // Asia
        (tablero[2].getTerritorios()[5]).addVecino(&tablero[4].getTerritorios()[6]); // Asia
        (tablero[2].getTerritorios()[5]).addVecino(&tablero[4].getTerritorios()[10]); // Asia
    (tablero[2].getTerritorios()[5]).setId(19);
        //          7. Europa Occidental
        (tablero[2].getTerritorios()[6]).addVecino(&tablero[2].getTerritorios()[0]);
        (tablero[2].getTerritorios()[6]).addVecino(&tablero[2].getTerritorios()[2]);
        (tablero[2].getTerritorios()[6]).addVecino(&tablero[2].getTerritorios()[4]);
        (tablero[2].getTerritorios()[6]).addVecino(&tablero[3].getTerritorios()[4]); // Africa
    (tablero[2].getTerritorios()[6]).setId(20);

        // 3. Africa
        //          1. Congo
        (tablero[3].getTerritorios()[0]).addVecino(&tablero[3].getTerritorios()[1]);
        (tablero[3].getTerritorios()[0]).addVecino(&tablero[3].getTerritorios()[4]);
        (tablero[3].getTerritorios()[0]).addVecino(&tablero[3].getTerritorios()[5]);
    (tablero[3].getTerritorios()[0]).setId(21);
        //          2. África Oriental
        (tablero[3].getTerritorios()[1]).addVecino(&tablero[3].getTerritorios()[0]);
        (tablero[3].getTerritorios()[1]).addVecino(&tablero[3].getTerritorios()[2]);
        (tablero[3].getTerritorios()[1]).addVecino(&tablero[3].getTerritorios()[3]);
        (tablero[3].getTerritorios()[1]).addVecino(&tablero[3].getTerritorios()[4]);
        (tablero[3].getTerritorios()[1]).addVecino(&tablero[3].getTerritorios()[5]);
    (tablero[3].getTerritorios()[1]).setId(22);
        //          3. Egipto
        (tablero[3].getTerritorios()[2]).addVecino(&tablero[3].getTerritorios()[1]);
        (tablero[3].getTerritorios()[2]).addVecino(&tablero[3].getTerritorios()[4]);
        (tablero[3].getTerritorios()[2]).addVecino(&tablero[2].getTerritorios()[4]); // Europa
        (tablero[3].getTerritorios()[2]).addVecino(&tablero[4].getTerritorios()[6]); // Asia
    (tablero[3].getTerritorios()[2]).setId(23);
        //          4. Madagascar
        (tablero[3].getTerritorios()[3]).addVecino(&tablero[3].getTerritorios()[1]);
        (tablero[3].getTerritorios()[3]).addVecino(&tablero[3].getTerritorios()[5]);
    (tablero[3].getTerritorios()[3]).setId(24);
        //          5. África del Norte
        (tablero[3].getTerritorios()[4]).addVecino(&tablero[3].getTerritorios()[0]);
        (tablero[3].getTerritorios()[4]).addVecino(&tablero[3].getTerritorios()[2]);
        (tablero[3].getTerritorios()[4]).addVecino(&tablero[2].getTerritorios()[4]); // Europa
        (tablero[3].getTerritorios()[4]).addVecino(&tablero[2].getTerritorios()[6]); // Europa
    (tablero[3].getTerritorios()[4]).setId(25);
        //          6. África del Sur
        (tablero[3].getTerritorios()[5]).addVecino(&tablero[3].getTerritorios()[0]);
        (tablero[3].getTerritorios()[5]).addVecino(&tablero[3].getTerritorios()[1]);
        (tablero[3].getTerritorios()[5]).addVecino(&tablero[3].getTerritorios()[3]);
    (tablero[3].getTerritorios()[5]).setId(26);

    // 4. Asia
        //          1. Afghanistán
        (tablero[4].getTerritorios()[0]).addVecino(&tablero[4].getTerritorios()[1]);
        (tablero[4].getTerritorios()[0]).addVecino(&tablero[4].getTerritorios()[2]);
        (tablero[4].getTerritorios()[0]).addVecino(&tablero[4].getTerritorios()[6]);
        (tablero[4].getTerritorios()[0]).addVecino(&tablero[4].getTerritorios()[10]);
        (tablero[4].getTerritorios()[0]).addVecino(&tablero[2].getTerritorios()[5]); // Europa
    (tablero[4].getTerritorios()[0]).setId(27);
        //          2. China
        (tablero[4].getTerritorios()[1]).addVecino(&tablero[4].getTerritorios()[0]);
        (tablero[4].getTerritorios()[1]).addVecino(&tablero[4].getTerritorios()[2]);
        (tablero[4].getTerritorios()[1]).addVecino(&tablero[4].getTerritorios()[7]);
        (tablero[4].getTerritorios()[1]).addVecino(&tablero[4].getTerritorios()[8]);
        (tablero[4].getTerritorios()[1]).addVecino(&tablero[4].getTerritorios()[9]);
        (tablero[4].getTerritorios()[1]).addVecino(&tablero[4].getTerritorios()[10]);
    (tablero[4].getTerritorios()[1]).setId(28);
        //          3. India
        (tablero[4].getTerritorios()[2]).addVecino(&tablero[4].getTerritorios()[0]);
        (tablero[4].getTerritorios()[2]).addVecino(&tablero[4].getTerritorios()[1]);
        (tablero[4].getTerritorios()[2]).addVecino(&tablero[4].getTerritorios()[6]);
        (tablero[4].getTerritorios()[2]).addVecino(&tablero[4].getTerritorios()[8]);
    (tablero[4].getTerritorios()[2]).setId(29);
        //          4. Irkutsk
        (tablero[4].getTerritorios()[3]).addVecino(&tablero[4].getTerritorios()[5]);
        (tablero[4].getTerritorios()[3]).addVecino(&tablero[4].getTerritorios()[7]);
        (tablero[4].getTerritorios()[3]).addVecino(&tablero[4].getTerritorios()[9]);
        (tablero[4].getTerritorios()[3]).addVecino(&tablero[4].getTerritorios()[11]);
    (tablero[4].getTerritorios()[3]).setId(30);
        //          5. Japón
        (tablero[4].getTerritorios()[4]).addVecino(&tablero[4].getTerritorios()[5]);
        (tablero[4].getTerritorios()[4]).addVecino(&tablero[4].getTerritorios()[7]);
    (tablero[4].getTerritorios()[4]).setId(31);
        //          6. Kamchatka
        (tablero[4].getTerritorios()[5]).addVecino(&tablero[4].getTerritorios()[3]);
        (tablero[4].getTerritorios()[5]).addVecino(&tablero[4].getTerritorios()[4]);
        (tablero[4].getTerritorios()[5]).addVecino(&tablero[4].getTerritorios()[7]);
        (tablero[4].getTerritorios()[5]).addVecino(&tablero[4].getTerritorios()[11]);
        (tablero[4].getTerritorios()[5]).addVecino(&tablero[0].getTerritorios()[0]); // America del Norte
    (tablero[4].getTerritorios()[5]).setId(32);
        //          7. Medio Oriente
        (tablero[4].getTerritorios()[6]).addVecino(&tablero[4].getTerritorios()[0]);
        (tablero[4].getTerritorios()[6]).addVecino(&tablero[4].getTerritorios()[2]);
        (tablero[4].getTerritorios()[6]).addVecino(&tablero[2].getTerritorios()[5]); // Europa
        (tablero[4].getTerritorios()[6]).addVecino(&tablero[2].getTerritorios()[4]); // Europa
        (tablero[4].getTerritorios()[6]).addVecino(&tablero[3].getTerritorios()[2]); // Africa
    (tablero[4].getTerritorios()[6]).setId(33);
        //          8. Mongolia
        (tablero[4].getTerritorios()[7]).addVecino(&tablero[4].getTerritorios()[1]);
        (tablero[4].getTerritorios()[7]).addVecino(&tablero[4].getTerritorios()[3]);
        (tablero[4].getTerritorios()[7]).addVecino(&tablero[4].getTerritorios()[4]);
        (tablero[4].getTerritorios()[7]).addVecino(&tablero[4].getTerritorios()[5]);
    (tablero[4].getTerritorios()[7]).setId(34);
        //          9. Siam
        (tablero[4].getTerritorios()[8]).addVecino(&tablero[4].getTerritorios()[1]);
        (tablero[4].getTerritorios()[8]).addVecino(&tablero[4].getTerritorios()[2]);
        (tablero[4].getTerritorios()[8]).addVecino(&tablero[5].getTerritorios()[1]); // Oceania
    (tablero[4].getTerritorios()[8]).setId(35);
        //          10. Siberia
        (tablero[4].getTerritorios()[9]).addVecino(&tablero[4].getTerritorios()[1]);
        (tablero[4].getTerritorios()[9]).addVecino(&tablero[4].getTerritorios()[3]);
        (tablero[4].getTerritorios()[9]).addVecino(&tablero[4].getTerritorios()[10]);
        (tablero[4].getTerritorios()[9]).addVecino(&tablero[4].getTerritorios()[11]);
    (tablero[4].getTerritorios()[9]).setId(36);
        //          11. Ural
        (tablero[4].getTerritorios()[10]).addVecino(&tablero[4].getTerritorios()[0]);
        (tablero[4].getTerritorios()[10]).addVecino(&tablero[4].getTerritorios()[1]);
        (tablero[4].getTerritorios()[10]).addVecino(&tablero[4].getTerritorios()[9]);
        (tablero[4].getTerritorios()[10]).addVecino(&tablero[2].getTerritorios()[5]); // Europa
    (tablero[4].getTerritorios()[10]).setId(37);
        //          12. Yakutsk
        (tablero[4].getTerritorios()[11]).addVecino(&tablero[4].getTerritorios()[3]);
        (tablero[4].getTerritorios()[11]).addVecino(&tablero[4].getTerritorios()[5]);
        (tablero[4].getTerritorios()[11]).addVecino(&tablero[4].getTerritorios()[11]);
    (tablero[4].getTerritorios()[11]).setId(38);

    // 5. Oceania/Australia
        //          1. Australia Oriental
        (tablero[5].getTerritorios()[0]).addVecino(&tablero[5].getTerritorios()[2]);
        (tablero[5].getTerritorios()[0]).addVecino(&tablero[5].getTerritorios()[3]);
    (tablero[5].getTerritorios()[0]).setId(39);
        //          2. Indonesia
        (tablero[5].getTerritorios()[1]).addVecino(&tablero[5].getTerritorios()[2]);
        (tablero[5].getTerritorios()[1]).addVecino(&tablero[5].getTerritorios()[3]);
        (tablero[5].getTerritorios()[1]).addVecino(&tablero[4].getTerritorios()[8]); // Asia
    (tablero[5].getTerritorios()[1]).setId(40);
        //          3. Nueva Guinea
        (tablero[5].getTerritorios()[2]).addVecino(&tablero[5].getTerritorios()[0]);
        (tablero[5].getTerritorios()[2]).addVecino(&tablero[5].getTerritorios()[1]);
        (tablero[5].getTerritorios()[2]).addVecino(&tablero[5].getTerritorios()[3]);
    (tablero[5].getTerritorios()[2]).setId(41);
        //          4. Australia Occidental
        (tablero[5].getTerritorios()[3]).addVecino(&tablero[5].getTerritorios()[0]);
        (tablero[5].getTerritorios()[3]).addVecino(&tablero[5].getTerritorios()[1]);
        (tablero[5].getTerritorios()[3]).addVecino(&tablero[5].getTerritorios()[2]);
    (tablero[5].getTerritorios()[3]).setId(42);
}

Territorio* Tablero::buscarTerritorioNom(int id, int e) {
    // Buscar y retornar el territorio que coincida con el nombre
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < (tablero[i].getTerritorios()).size(); ++j) {
            if((tablero[i].getTerritorios()[j]).getId() == id){
                (tablero[i].getTerritorios()[j]).setCantiEjercitos(e);
                return &(tablero[i].getTerritorios()[j]);
            }
        }
    }
    Territorio* aux = new Territorio();
    return (aux);
}


vector<Tarjeta> Tablero::maso;

void Tablero::crearTarjetas(){
    // variables auxiliares
    Tarjeta t;

    Ejercito inf("Infanteria", "Blanco", 1);
    Ejercito cab("Caballeria", "Blanco", 5);
    Ejercito art("Artilleria", "Blanco", 10);
    Ejercito com("Comodin", "Blanco", 0);
    Ejercito null("","",0);

    Territorio tNull;

    t.setMision("");
    // Tarjetas comodin (2)
    t.setTerritorio(tNull);
    t.setId(55);
    t.setEjercito(com);
    maso.push_back(t);
    t.setId(56);
    maso.push_back(t);

    // Tarjetas Territorios (42)

    // 0. America del Norte
        //          1. Alaska
        t.setTerritorio(tablero[0].getTerritorios()[0]);
            t.setEjercito(inf);
            t.setId(1);
            maso.push_back(t);
        //          2.Alberta
        t.setTerritorio(tablero[0].getTerritorios()[1]);
            t.setEjercito(inf);
            t.setId(2);
            maso.push_back(t);
        //          3.America Central
        t.setTerritorio(tablero[0].getTerritorios()[2]);
            t.setEjercito(art);
            t.setId(3);
            maso.push_back(t);
        //          4. Estados Unidos Orientales
        t.setTerritorio(tablero[0].getTerritorios()[3]);
            t.setEjercito(art);
            t.setId(4);
            maso.push_back(t);
        //          5. Groenlandia
        t.setTerritorio(tablero[0].getTerritorios()[4]);
            t.setEjercito(cab);
            t.setId(5);
            maso.push_back(t);
        //          6. Territorio Noroccidental
        t.setTerritorio(tablero[0].getTerritorios()[5]);
            t.setEjercito(art);
            t.setId(6);
            maso.push_back(t);
        //          7. Ontario
        t.setTerritorio(tablero[0].getTerritorios()[6]);
            t.setEjercito(cab);
            t.setId(7);
            maso.push_back(t);
        //          8. Quebec
        t.setTerritorio(tablero[0].getTerritorios()[7]);
            t.setEjercito(cab);
            t.setId(8);
            maso.push_back(t);
        //          9. Estados Unidos Occidentales
        t.setTerritorio(tablero[0].getTerritorios()[8]);
            t.setEjercito(art);
            t.setId(9);
            maso.push_back(t);

    // 1. America del Sur
        //          1. Argentina
        t.setTerritorio(tablero[1].getTerritorios()[0]);
            t.setEjercito(inf);
            t.setId(10);
            maso.push_back(t);
        //          2. Brasil
        t.setTerritorio(tablero[1].getTerritorios()[1]);
            t.setEjercito(art);
            t.setId(11);
            maso.push_back(t);
        //          3. Perú
        t.setTerritorio(tablero[1].getTerritorios()[2]);
            t.setEjercito(inf);
            t.setId(12);
            maso.push_back(t);
        //          4. Venezuela
        t.setTerritorio(tablero[1].getTerritorios()[3]);
            t.setEjercito(inf);
            t.setId(13);
            maso.push_back(t);

    // 2. Europa
        //          1. Gran Bretaña
        t.setTerritorio(tablero[2].getTerritorios()[0]);
            t.setEjercito(art);
            t.setId(14);
            maso.push_back(t);
        //          2. Islandia
        t.setTerritorio(tablero[2].getTerritorios()[1]);
            t.setEjercito(inf);
            t.setId(15);
            maso.push_back(t);
        //          3. Europa del Norte
        t.setTerritorio(tablero[2].getTerritorios()[2]);
            t.setEjercito(art);
            t.setId(16);
            maso.push_back(t);
        //          4. Escandinavia
        t.setTerritorio(tablero[2].getTerritorios()[3]);
            t.setEjercito(cab);
            t.setId(17);
            maso.push_back(t);
        //          5. Europa del Sur
        t.setTerritorio(tablero[2].getTerritorios()[4]);
            t.setEjercito(art);
            t.setId(18);
            maso.push_back(t);
        //          6. Ucrania
        t.setTerritorio(tablero[2].getTerritorios()[5]);
            t.setEjercito(cab);
            t.setId(19);
            maso.push_back(t);
        //          7. Europa Occidental
        t.setTerritorio(tablero[2].getTerritorios()[6]);
            t.setEjercito(art);
            t.setId(20);
            maso.push_back(t);

    // 3. Africa
        //          1. Congo
        t.setTerritorio(tablero[3].getTerritorios()[0]);
            t.setEjercito(inf);
            t.setId(21);
            maso.push_back(t);
        //          2. África Oriental
        t.setTerritorio(tablero[3].getTerritorios()[1]);
        t.setEjercito(inf);
        t.setId(22);
        maso.push_back(t);
        //          3. Egipto
        t.setTerritorio(tablero[3].getTerritorios()[2]);
        t.setEjercito(inf);
        t.setId(23);
        maso.push_back(t);
        //          4. Madagascar
        t.setTerritorio(tablero[3].getTerritorios()[3]);
        t.setEjercito(cab);
        t.setId(24);
        maso.push_back(t);
        //          5. África del Norte
        t.setTerritorio(tablero[3].getTerritorios()[4]);
        t.setEjercito(cab);
        t.setId(25);
        maso.push_back(t);
        //          6. África del Sur
        t.setTerritorio(tablero[3].getTerritorios()[5]);
        t.setEjercito(art);
        t.setId(26);
        maso.push_back(t);

    // 4. Asia
        //          1. Afghanistán
        t.setTerritorio(tablero[4].getTerritorios()[0]);
        t.setEjercito(cab);
        t.setId(27);
        maso.push_back(t);
        //          2. China
        t.setTerritorio(tablero[4].getTerritorios()[1]);
        t.setEjercito(inf);
        t.setId(28);
        maso.push_back(t);
        //          3. India
        t.setTerritorio(tablero[4].getTerritorios()[2]);
        t.setEjercito(cab);
        t.setId(29);
        maso.push_back(t);
        //          4. Irkutsk
        t.setTerritorio(tablero[4].getTerritorios()[3]);
        t.setEjercito(cab);
        t.setId(30);
        maso.push_back(t);
        //          5. Japón
        t.setTerritorio(tablero[4].getTerritorios()[4]);
        t.setEjercito(art);
        t.setId(31);
        maso.push_back(t);
        //          6. Kamchatka
        t.setTerritorio(tablero[4].getTerritorios()[5]);
        t.setEjercito(inf);
        t.setId(32);
        maso.push_back(t);
        //          7. Medio Oriente
        t.setTerritorio(tablero[4].getTerritorios()[6]);
        t.setEjercito(inf);
        t.setId(33);
        maso.push_back(t);
        //          8. Mongolia
        t.setTerritorio(tablero[4].getTerritorios()[7]);
        t.setEjercito(inf);
        t.setId(34);
        maso.push_back(t);
        //          9. Siam
        t.setTerritorio(tablero[4].getTerritorios()[8]);
        t.setEjercito(inf);
        t.setId(35);
        maso.push_back(t);
        //          10. Siberia
        t.setTerritorio(tablero[4].getTerritorios()[9]);
        t.setEjercito(cab);
        t.setId(36);
        maso.push_back(t);
        //          11. Ural
        t.setTerritorio(tablero[4].getTerritorios()[10]);
        t.setEjercito(cab);
        t.setId(37);
        maso.push_back(t);
        //          12. Yakutsk
        t.setTerritorio(tablero[4].getTerritorios()[11]);
        t.setEjercito(cab);
        t.setId(38);
        maso.push_back(t);

    // 5. Oceania/Australia
        //          1. Australia Oriental
        t.setTerritorio(tablero[5].getTerritorios()[0]);
        t.setEjercito(art);
        t.setId(39);
        maso.push_back(t);
        //          2. Indonesia
        t.setTerritorio(tablero[5].getTerritorios()[1]);
        t.setEjercito(art);
        t.setId(40);
        maso.push_back(t);
        //          3. Nueva Guinea
        t.setTerritorio(tablero[5].getTerritorios()[2]);
        t.setEjercito(inf);
        t.setId(41);
        maso.push_back(t);
        //          4. Australia Occidental
        t.setTerritorio(tablero[5].getTerritorios()[3]);
        t.setEjercito(art);
        t.setId(42);
        maso.push_back(t);

    // Tarjetas de mision (12)
    t.setTerritorio(tNull);
        t.setEjercito(null);

    t.setMision("Conquista Asia y America del sur");
        t.setId(43);
        maso.push_back(t);

    t.setMision("Conquista Asia y Africa");
        t.setId(44);
        maso.push_back(t);

    t.setMision("Conquista Oceania y America del norte");
        t.setId(45);
        maso.push_back(t);

    t.setMision("Conquista Africa y America del norte");
        t.setId(46);
        maso.push_back(t);

    t.setMision("Conquista 18 territorios de tu preferencia con almenos 2 ejercitos");
        t.setId(47);
        maso.push_back(t);

    t.setMision("Conquista 24 territorios de tu preferencia");
        t.setId(48);
        maso.push_back(t);

    t.setMision("Destruye al ejercito amarillo. En caso de ser tu, conquista 24 territorios de tu preferencia con almenos 2 ejercitos");
        t.setId(49);
        maso.push_back(t);
    t.setMision("Destruye al ejercito azul. En caso de ser tu, conquista 24 territorios de tu preferencia con almenos 2 ejercitos");
        t.setId(50);
        maso.push_back(t);
    t.setMision("Destruye al ejercito verde. En caso de ser tu, conquista 24 territorios de tu preferencia con almenos 2 ejercitos");
        t.setId(51);
        maso.push_back(t);
    t.setMision("Destruye al ejercito negro. En caso de ser tu, conquista 24 territorios de tu preferencia con almenos 2 ejercitos");
        t.setId(52);
        maso.push_back(t);
    t.setMision("Destruye al ejercito rojo. En caso de ser tu, conquista 24 territorios de tu preferencia con almenos 2 ejercitos");
        t.setId(53);
        maso.push_back(t);
    t.setMision("Destruye al ejercito gris. En caso de ser tu, conquista 24 territorios de tu preferencia con almenos 2 ejercitos");
        t.setId(54);
        maso.push_back(t);

}

Tarjeta Tablero::sacarTarjeta() {
    Tarjeta aux;
    if (maso.size() == 0) {
        cout << "No hay cartas en el maso." << endl;
        return aux;
    }
    aux = maso[0];
    maso.erase(maso.begin());
    cout << "Tienes una carta mas." << endl;
    return aux;

}

Tarjeta* Tablero::buscarTarjetaId(int id) {
    // Buscar y retornar la tarjeta que coincida con el id
    for (int i = 0; i < 56; ++i) {
        if(maso[i].getId()== id){
            return &(maso[i]);
        }
    }
    Tarjeta* aux = new Tarjeta();
    return (aux);
}