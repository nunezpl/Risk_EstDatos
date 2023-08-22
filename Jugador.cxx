#include <iostream>
#include <algorithm>
#include "Jugador.h"
#include "Territorio.h"
#include "Tablero.h"
using namespace std;

// constructor vacio
Jugador::Jugador( ) {
  nombre = "";
  id = 0;
  color = "";
}
// constructor con parametros
Jugador::Jugador(string n, long i, string c) {
  nombre = n;
  id = i;
  color = c;
}

// Settters
void Jugador::setNombre(string n) {
    nombre = n;
}
void Jugador::setId(long i) {
    id = i;
}
void Jugador::setColor(string c){
    color = c;
}

// Getters
string Jugador::getNombre(){
    return nombre;
}
long Jugador::getId(){
    return id;
}
string Jugador::getColor(){
    return color;
}

void Jugador::agregarTerritorioOcupado(Territorio t) {
    terrOcupados.push_back(t);
}
void Jugador::agregarEjercito(Ejercito e){
    ejercito.push_back(e);
}
void Jugador::agregarTarjeta(Tarjeta t){
    tarjetas.push_back(t);
}

// OTROS METODOS...

int Jugador::totalEjercito(){
    int cant=0;
    list<Ejercito>::iterator it;
    for(it = ejercito.begin(); it != ejercito.end(); it++){
        cant+= it->getUnidades();
    }
    return cant;
}
int Jugador::totalUnidadesTarjetas(){
    int total=0, inf=0, cab=0, art=0, com=0;

    list<Tarjeta>::iterator it;
    for(it = tarjetas.begin(); it != tarjetas.end(); it++){
        if (it->getEjercito().getCategoria() == "Infanteria")
            inf++;
        else if(it->getEjercito().getCategoria() == "Caballeria")
            cab++;
        else if(it->getEjercito().getCategoria() == "Artilleria")
            art++;
        else if(it->getEjercito().getCategoria() == "Comodin")
            com++;
    }

    // Determinar la cantidad de unidades de ejercito que se pueden dar;
    switch(Tarjeta::intercambios){
        case 1 : total = 4; break;
        case 2 : total = 6; break;
        case 3 : total = 8; break;
        case 4 : total = 10; break;
        case 5 : total = 12; break;
        case 6 : total = 15; break;
        default: total = (5 * (Tarjeta::intercambios - 6))+ 15; // nuevas + 15 de base
            break;
    }

    //con el mismo dibujo de ejército
    if(inf == 3 || cab == 3 || art == 3){
        cout << "Se tienen 3 cartas del mismo ejercito\n";
        Tarjeta::intercambios++;
        return total;
    }
    // con los tres dibujos de ejército
    else if(inf >= 1 && cab >= 1 && art >= 1){
        cout << "Se tienen 3 cartas con cada ejercito\n";
        Tarjeta::intercambios++;
        return total;
    }
    // cualquiera de los dos dibujos junto con una carta comodín
    else if(com >= 1){
        if( (inf >= 1 && cab >= 1) || (cab >= 1 && art >= 1) || (inf >= 1 && art >= 1) ) {
            cout << "Se tienen 2 cartas con cada ejercito y un comodin\n";
            Tarjeta::intercambios++;
            return total;
        }
    }

    return 0;
}

void Jugador::ubicarInfanterias(){

    int c=0, t=0, e;
    int cant = totalEjercito();

    cout << "\nJugador "<< nombre <<endl;

    cout<< "Cantidad unidades Ejercito: "<<cant<<endl;

    // Escoger el territorio
    for (int i=0; i < Tablero::tablero.size(); i++) {
        cout << i <<":" << Tablero::tablero[i].getNombre() << "   ";
    }
    cout << "\n Continente: ";
    cin >> c;
    // Validar continente válido
        if (c < 0 || c >= Tablero::tablero.size()) {
            cout << "Opcion invalida." << endl;
            return;
        }

    Tablero::tablero[c].imprimirTerritorios();
    cout << "\n Territorio: ";
    cin >> t;
        // Validar territorio válido
        if (t < 0 || t >= Tablero::tablero[c].getTerritorios().size()) {
            cout << "Opcion invalida." << endl;
            return;
        }

    Territorio& terri = Tablero::tablero[c].getTerritorios()[t];

        if(terri.getOcupado() == false){
            // Elegir tipo de ejército
            int tipoEjercito;
            cout << "Que clase de ejercito deseas poner? 1.Infanteria 2.Caballeria 3.Artilleria: ";
            cin >> tipoEjercito;

            // Validar tipo de ejército válido
            if (tipoEjercito < 1 || tipoEjercito > 3) {
                cout << "Opcion invalida." << endl;
                return;
            }

            string nombreEjercito;
            int unidadesEjercito;
            switch (tipoEjercito) {
                case 1: nombreEjercito = "Infanteria"; unidadesEjercito = 1; break;
                case 2: nombreEjercito = "Caballeria"; unidadesEjercito = 5; break;
                case 3: nombreEjercito = "Artilleria"; unidadesEjercito = 10; break;
            }

            // Crear ejército y ocupar territorio
            Ejercito ejer(nombreEjercito, color, unidadesEjercito);
            terri.setOcupado(true);
            terri.setOcupante( &(*this) ); // pasa la dirección del objeto Jugador a la función setOcupante
            agregarTerritorioOcupado(terri);
            agregarEjercito(ejer);
            // agregar tarjetas
        }
        else{
            cout << "Territorio ya ocupado!"<<endl;
        }
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
    cout << "\n Ejecucion del turno de " << id << " ..."<<endl;

    // Nuevas unidades
    char s;
    int aux = totalEjercito();
    int nUnidades = calcularNuevasUnidades();

    if(nUnidades > 0){
        cout << "Puedes reclamar " << nUnidades<<" unidades adicionales"<<endl;
        do{
            ubicarInfanterias();
            if(totalEjercito() > aux + nUnidades)
                break;
            cout << "Deseas continuar poniendo unidades? (s/n) " <<endl;
            cin >> s;
        }while( s == 's');
    }else{
        cout << "No puedes reclamar unidades adicionales"<<endl;
    }

    // Funcion atacar
    atacarTerritorios(*this);
    // Fortificar
}
    void Jugador::atacarTerritorios (Jugador& jugador) {
        cout << "Territorios disponibles para atacar: " << endl;

        // Aca se muestran los territorios ocupados del jugador
        int enumerar = 1; // Esta variable enumera las opciones de los territorios ocupados
        for (const Territorio& territorio : jugador.terrOcupados) {
            cout << enumerar << ". " << territorio.getNombre() << endl;
            enumerar++;
        }

        int seleccion;
        cout << "Seleccione el numero del territorio para atacar: ";
        cin >> seleccion;

        if (seleccion <= 0 || seleccion > jugador.terrOcupados.size()) {
            cout << "La seleccion es invalida." << endl;
            return;
        }

        auto it = jugador.terrOcupados.begin();
        advance (it, seleccion - 1); // Aca avanzamos el iterador hasta la seleccion del jugador
        Territorio territorioSeleccionado = *it;

        cout << "Territorios vecinos disponibles para atacar: " << endl;
        enumerar = 1;
        for (const Territorio& vecino : territorioSeleccionado.getVecinos()) {
            if (!vecino.getOcupado()) {
                cout << enumerar << ". " << vecino.getNombre() << endl;
                enumerar++;
            }
        }

        int seleccionVecino;
        cout << "Seleccione el numero del territorio vecino para atacar: ";
        cin >> seleccionVecino;

        if (seleccionVecino <= 0 || seleccionVecino > territorioSeleccionado.getVecinos().size()) {
            cout << "La seleccion es invalida." << endl;
            return;
        }

        auto vecinoIt = territorioSeleccionado.getVecinos().begin();
        advance (vecinoIt, seleccionVecino -1); // Aca avanzamos el iterador hasta la seleccion del jugador
        Territorio vecinoSeleccionado = *vecinoIt;

        realizarAtaque(territorioSeleccionado, vecinoSeleccionado);

        /*if (realizarAtaque(territorioSeleccionado, vecinoSeleccionado)) {
            vecinoSeleccionado.setOcupado(true);
            vecinoSeleccionado.setOcupante(&jugador);

            //territorioSeleccionado.perderEjercitos(territorioSeleccionado.getCantiEjercitos() - 1);
            //vecinoSeleccionado.

        }*/
    }
    void Jugador::realizarAtaque (Territorio& atacante, Territorio& defensor) {
        vector<int> rojo;
        vector<int> blanco;
        char s;
        do {

            rojo[0] = lanzarDado ();
            rojo[1] = lanzarDado ();
            rojo[2] = lanzarDado ();

            blanco[0] = lanzarDado ();
            blanco[1] = lanzarDado ();

            // Seleccionar los dos valores más grandes
                rojo = seleccionarDosMasGrandes(rojo);

            // Evaluar condiciones

                // Atacante mayor a defensor
                if (rojo[0] > blanco[0] || rojo[1] > blanco[1]) {
                    // El defensor pierde ejercito
                }

                // Defensor mayor a atacante
                else if (rojo[0] < blanco[0] || rojo[1] < blanco[1]) {
                    // Atacante pierde ejercito
                }

                // Empate
                else if (rojo[0] == blanco[0] || rojo[1] == blanco[1]) {
                    // El defensor gana y el atacante pierde una unidad de ejercito
                }

            // Territorio vacio

            if (defensor.getCantiEjercitos() == 0) {
                cout << defensor.getNombre() << " Esta vacio." << endl;
                // El atacante puede reclamarlo moviendo algunas de sus piezas de ejército allí.
            }

            cout << "Desea seguir? (si = s) ";
            cin >> s;

        } while ('s' == s);

    }

    int Jugador::lanzarDado () {
        return rand() % 6 + 1; // Número aleatorio entre 1 y 6
    }

    vector<int> Jugador::seleccionarDosMasGrandes(vector<int>& dados) {
        vector<int> sortedDados = dados; // Copia de los dados
        sort(sortedDados.rbegin(), sortedDados.rend()); // Ordenar en orden descendente

        // Crear un vector con los dos valores más grandes
        vector<int> dosMasGrandes = {sortedDados[0], sortedDados[1]};

        return dosMasGrandes;
    }


int Jugador::calcularNuevasUnidades() {
    // Obtener unidades por territorios ocupados
    int uTerritorios = terrOcupados.size() / 3;

    // Obtener unidades por continentes ocupados
    int uContinentes = 0;
    for (int i=0; i< Tablero::tablero.size(); i++) { // por cada continente
        if (Tablero::tablero[i].ocupadoPorJugador(*this) == true) {
            uContinentes += Tablero::tablero[i].getUnidades();
        }
    }

    // Obtener unidades por cartas
    int uTarjetas = totalUnidadesTarjetas();

    // Sumar las unidades obtenidas
    return (uTerritorios + uContinentes + uTarjetas);
}

