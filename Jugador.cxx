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
    cout << "\nTerritorio: ";
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
    cout << "\nEjecucion del turno de " << id << " ..."<<endl;

    // Nuevas unidades
    char s;
    int aux = totalEjercito();
    int nUnidades = calcularNuevasUnidades();

    if(nUnidades > 0){
        cout << "Puedes reclamar " << nUnidades<<" unidades adicionales"<<endl;
        do{
            ubicarInfanterias();
            if(totalEjercito() >= aux + nUnidades)
                break;
            cout << "Deseas continuar poniendo unidades? (s/n) " <<endl;
            cin >> s;
        }while( s == 's');
    }else{
        cout << "No puedes reclamar unidades adicionales"<<endl;
    }

    // Funcion atacar
    atacarTerritorios();

    // Fortificar

}

void Jugador::realizarAtaque (Territorio& atacante, Territorio& defensor) {

    // verificar si el teritorio defensor esta ocupado
    if (!defensor.getOcupado()) {
        cout << "\nEl territorio esta vacio" << endl;
        // Gana el atacante
        defensor.setOcupado(true);
        defensor.setOcupante(this); // El atacante se convierte en el ocupante
        defensor.setCantiEjercitos(1); // Establecer la cantidad de ejercitos

        // Agregar el territorio a la lista de territorios ocupados por el atacante
        agregarTerritorioOcupado(defensor);

        // Agregar una unidad de ejercito al jugador atacante
        Ejercito e ("Infanteria", color, 1);
        agregarEjercito(e);

        // Agregar una tarjeta al jugador atacante
        agregarTarjeta(Tablero::sacarTarjeta());
        cout << nombre << " se queda con " << defensor.getNombre() << endl;
        return;
    }


    Jugador* jDefensor= defensor.getOcupante(); // apuntador al jugador defensor

    if (jDefensor) {
        cout << " jDefensor tot ejer: " << jDefensor->totalEjercito() << endl;
    } else {
        cout << " jDefensor es nulo." << endl;
        return;
    }
    vector<int> rojo(3);
    vector<int> blanco(2);
    char s;
    do {
        //   Dados atacante
        rojo[0] = lanzarDado ();
        rojo[1] = lanzarDado ();
        rojo[2] = lanzarDado ();
        //   Dados defensor
        blanco[0] = lanzarDado ();
        blanco[1] = lanzarDado ();

        // Seleccionar los dos valores más grandes para el atacante
            rojo = seleccionarDosMasGrandes(rojo); // preguntarle al atacante que dados quiere usar debe seleccionar

        cout<< "Dados rojos: " << rojo[0]<<" , "<< rojo[1]<<endl;
        cout<< "Dados blanco: " << blanco[0]<<" , "<< blanco[1]<<endl;

        // Evaluar condiciones
            // Atacante gana, defensor pierde una unidad de ejército
            if (rojo[0] > blanco[0] || rojo[1] > blanco[1]) {
                cout<<"Atacante gana!"<< endl;

                if (jDefensor->eliminarInfanteria(jDefensor)) {
                    defensor.setCantiEjercitos(defensor.getCantiEjercitos() - 1);
                }
            }
            // Defensor gana, atacante pierde una unidad de ejército
            else if (rojo[0] < blanco[0] || rojo[1] < blanco[1]) {
                cout<<"Defensor gana!"<< endl;
                eliminarInfanteria(this);
                atacante.setCantiEjercitos(atacante.getCantiEjercitos() - 1);
            }
            // Empate, defensor gana y atacante pierde una unidad de ejército
            else {
                cout<<"¡Empate!"<< endl;
                eliminarInfanteria(this);
                atacante.setCantiEjercitos(atacante.getCantiEjercitos() - 1);
            }

        // Territorio vacio
        if (defensor.getCantiEjercitos() == 0) {
            cout << defensor.getNombre() << " Esta vacio." << endl;
            // El atacante puede reclamarlo moviendo algunas de sus piezas de ejército allí.
            defensor.setOcupante(this);
        }

        cout << "Desea seguir? (si = s) ";
        cin >> s;

    } while ('s' == s);

}

void Jugador::atacarTerritorios () {
    cout << "\nTerritorios disponibles para iniciar el ataque: " << endl;
    list<Territorio>::iterator it;

    // Muestran los territorios ocupados del jugador (desde donde ataca)
        int enumerar = 1; // Enumera las opciones de los territorios ocupados
        for (it= terrOcupados.begin(); it != terrOcupados.end(); it++) {
            cout << enumerar << ". " << it->getNombre() << endl;
            enumerar++;
        }

        int seleccion;
        cout << "Seleccione el numero del territorio: ";
        cin >> seleccion;

        if (seleccion < 0 || seleccion > terrOcupados.size()) {
            cout << "La seleccion es invalida." << endl;
            return;
        }

    it = terrOcupados.begin();
    advance (it, seleccion - 1); // Aca avanzamos el iterador hasta la seleccion del jugador
    Territorio territorioAtacar = *it;

    // Muestran los territorios que se pueden atacar
        cout << "\nTerritorios vecinos disponibles para atacar: " << endl;
        enumerar = 1;
        territorioAtacar.imprimirVecinos(); // Mostrar los vecinos disponibles

        int seleccionVecino;
        cout << "Seleccione el numero del territorio vecino para atacar: ";
        cin >> seleccionVecino;

        if (seleccionVecino < 1 || seleccionVecino > territorioAtacar.getVecinos().size()) {
            cout << "La seleccion es invalida." << endl;
            return;
        }

    // Avanza el territorio hasta la seleccion del jugador
    Territorio vecinoAtacado = territorioAtacar.getVecinos()[seleccionVecino - 1];

        if (!territorioAtacar.esVecino(vecinoAtacado)) {
            cout << "El territorio seleccionado no es un vecino valido para atacar." << endl;
            return;
        }

    realizarAtaque(territorioAtacar, vecinoAtacado); // Ataca

    cout << "\nAtaque finalizado!"<<endl;

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

bool Jugador::eliminarInfanteria(Jugador* j) {
    list<Ejercito>::iterator it = j->ejercito.begin(); // Inicializamos el iterador
    cout << "Item: " << it->getCategoria() << endl;
    while (it != j->ejercito.end()) {
        cout << "Categoria actual: " << it->getCategoria() << endl; // Depuración
        if (it->getCategoria() == "Infanteria") {
            it = j->ejercito.erase(it); // Borrar y atualizar el iterador
            return true;
        } else {
            ++it;
        }
    }

    cout << "No hay mas infanterias para eliminar" << endl;
    return false;
   }