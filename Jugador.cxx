#include <iostream>
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
    int total=0;
    list<Tarjeta>::iterator it;
    for(it = tarjetas.begin(); it != tarjetas.end(); it++){

    }
    //con el mismo dibujo de ejército,
    // con los tres dibujos de ejército
    // cualquiera de los dos dibujos junto con una carta comodín;

    return total;
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

    // Atacar

    cout << "Atacar" << endl;

    // Fortificar

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

