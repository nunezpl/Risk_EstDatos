/*Lorena Nunez Pava - Brayan Ocampo - Laura Ceballos*/
#include <iostream>

#include "Jugador.h"
#include "Continente.h"
using namespace std;

/*
// Template
template <class T>
T separaComandoP2(string c){
    size_t posEspacio = c.find(' ');
    string palabraStr = c.substr(posEspacio + 1);
    if (is_same<T, long>::value){
        return stol(palabraStr); // Convertir a entero
    }else{
        return palabraStr;
    }
}*/

// Variables globales
bool juegoIniciado = false;
bool ganador = false;
int numJugadores=0;
list<Jugador> jugadores;
Jugador* proxTurno; // Se actualiza cada vez que se acabe un turno

// Declaracion de metodos
string separaComandoP2String(string c);
long separaComandoP2Long(string c);
void ayuda();
bool iniciarJuego();
void infoJugadores();
Jugador* encontrarJugador(long id_jugador);
void comandoTurno(long id_jugador);
void actualizarTurno(Jugador* jugadorActual);
void comandoInicializarArchivo (string nombreArchivo);
bool inicializarArchivo (string nombreArchivo);
void comandoCostoConquista (string terri);
void comandoConquistaBarata();


int main() {
  cout << "Bienvenido a Risk!\n";
  string comando, comandoAux, auxS;

  bool aux;

  do{
    cout<< "$ ";
    getline(cin, comando);
    comandoAux = comando;

    // Separar comando ej: turno xx -> return turno
    size_t posEspacio = comando.find(' '); // Encontrar la posición del primer espacio
    if (posEspacio != string::npos) // Si no se encontró espacio, toma el string completo como el comando
        comando = comando.substr(0, posEspacio);

    // Evaluar comando
        if (comando == "ayuda") {
            ayuda();
        }
        else if (comando == "inicializar" && (posEspacio+ 1) == 0) {
            // Código para inicializar
            bool aux = iniciarJuego();
            if(aux == true){
              infoJugadores();
            }
        }
        else if (comando == "turno") {
          // Código para turno
          long id_jugador = separaComandoP2Long(comandoAux);
          comandoTurno(id_jugador);
        }
        else if (comando == "guardar") { //  <nombre_archivo>
          // Código para guardar partida en <nombre_archivo> texto
          auxS = separaComandoP2String(comandoAux);
          if(juegoIniciado == false){
            cout << "Esta partida no ha sido inicializada correctamente."<<endl;
          }
        }
        else if (comando == "guardar_comprimido") { // <nombre_archivo>
          // Código para guardar partida en <nombre_archivo> bin
          auxS = separaComandoP2String(comandoAux);

        }
        else if (comando == "inicializar" && (posEspacio+ 1) != 0) { // <nombre_archivo>
          // Código para cargar partida de <nombre_archivo>
          auxS = separaComandoP2String(comandoAux);
          comandoInicializarArchivo (auxS);

        }
        else if (comando == "costo_conquista" && (posEspacio+ 1) == 0) { // <territorio>
          // Código para calcular el costo_conquista <territorio>
          auxS = separaComandoP2String(comandoAux);
          comandoCostoConquista (auxS);

        }
        else if (comando == "conquista_mas_barata") {
          // Código para calcular la conquista mas barata
          comandoConquistaBarata();
        }
        else if (comando == "salir") {
          cout << "Adios!";
        }
        cout<<endl;
  }while(comando != "salir");

}

/*            IMPLEMENTACION DE METODOS                */

// Separa y retorna la segunda palabra del comando
string separaComandoP2String(string c){
    size_t posEspacio = c.find(' ');// Encontrar la posición del primer espacio
    string palabraStr = c.substr(posEspacio + 1);
    return palabraStr;
}

// Separa y retorna la segunda parte del comando que sea un numero long
long separaComandoP2Long(string c){
    size_t posEspacio = c.find(' ');
    string palabraStr = c.substr(posEspacio + 1);
    return stol(palabraStr); // Convertir a entero
}

// Funcion que muestra la descripcion de todos los comandos
void ayuda(){
  cout << " --------------------- \n";
  cout << "\n inicializar \nDescripcion: Realiza las operaciones necesarias para inicializar el juego, de acuerdo a las instrucciones entregadas. De esta forma, el comando pregunta la informacion de los jugadores y luego, por turnos, preguntar a cada jugador en que territorio desea ubicar sus unidades de ejercito. "<< endl;
  cout << "\n --------------------- \n";
  cout << "\n turno <id_jugador> \nDescripcion: Realiza las operaciones descritas dentro del turno de un jugador (obtener nuevas unidades,atacar y fortificar)."<<endl;
  cout << "\n --------------------- \n";
  cout << "\n guardar <nombre_archivo> \nDescripcion: El estado actual del juego es guardado en un archivo de texto plano, sin codificacion. "<< endl;
  cout << "\n --------------------- \n";
  cout << "\n guardar_comprimido <nombre_archivo> \nDescripcion: El estado actual del juego es guardado en un archivo binario (con extension .bin) con la informacion comprimida, utilizando la codificacion de Huffman."<< endl;
  cout << "\n --------------------- \n";
  cout << "\n inicializar <nombre_archivo> \nDescripcion: Inicializa el juego con los datos contenidos en el archivo identificado por <nombre_archivo>. Inicializa el juego desde un archivo de juego normal o un archivo binario con los datos comprimidos."<< endl;
  cout << "\n --------------------- \n";
  cout << "\n costo_conquista <territorio> \nDescripcion: El programa debe calcular el costo y la secuencia de territorios a ser conquistados para lograr controlar el territorio dado por el usuario. El territorio desde donde debe atacar debe ser aquel que el jugador tenga controlado mas cerca al dado por el jugador."<< endl;
  cout << "\n --------------------- \n";
  cout << " conquista_mas_barata \nDescripcion: De todos los territorios posibles, calcular aquel que pueda implicar un menor numero de unidades de ejercito perdidas."<< endl;
  cout << "\n --------------------- \n";
  cout << "\n salir \nDescripcion: Termina la ejecucion de la aplicacion"<<endl;
  cout << "\n --------------------- \n";

}

// Funcion que verifica si el juego ha sido iniciado previamente, retorna true si no esta iniciado para pedir infoJugadores
bool iniciarJuego(){
  if(juegoIniciado == true){
    cout << "El juego ya ha sido inicializado.\n";
    return false;
  }else
    cout << "El juego se ha inicializado correctamente.\n";
  juegoIniciado = true;
  return true;
}


/*          IMPLEMENTACION DE METODOS JUGADORES        */
// Funcion que pide la cantidad y la informacion de todos los jugadores
void infoJugadores(){
  Jugador aux;
  string auxS;
  long id;

  do{
    cout << "Cuantos jugadores? (minimo 2, maximo 6): ";
    cin >> numJugadores;
  }while (numJugadores < 2 || numJugadores > 6);

  for(int i=1; i<numJugadores+1; i++){
    cout << " Nombre: ";
    cin >> auxS;
    aux.setNombre(auxS);
    cout << " Id: ";
    cin >> id;
    aux.setId(id);
    jugadores.push_back(aux);
    if(i ==1){
        list<Jugador>::iterator itJ = jugadores.begin();
        proxTurno = &(*itJ);
    }
  }

  cout << "Jugadores guardados con exito" <<endl;
}

// Encuentra el jugador por su id
Jugador* encontrarJugador(long id_jugador){
    Jugador aux;
    list<Jugador>::iterator itJ;

    for (itJ = jugadores.begin(); itJ != jugadores.end(); itJ++) {
        if (itJ->getId() == id_jugador) {
            return &(*itJ);
        }
    }
    cout<< "El jugador "<< id_jugador<< " no forma parte de esta partida."<<endl;
    return nullptr;
}

// Funcion que evalua las condiciones para ejecutar el turno del jugador
void comandoTurno(long id_jugador){

    // (Juego no inicializado)
    if(juegoIniciado == false){
        cout << "Esta partida no ha sido inicializada correctamente."<<endl;
    }
    // (Juego terminado)
    else if(ganador == true){
        cout << "Esta partida ya tuvo un ganador."<<endl;
    }
    else{
      Jugador* aux = encontrarJugador(id_jugador);
      // (Jugador no válido)
      if(aux != nullptr){
        // (Jugador fuera de turno)
        if( proxTurno != aux ){
            cout << "\n No es el turno del jugador "<< id_jugador << ", sigue " << proxTurno->getId() <<endl;
        }
        // (Turno terminado correctamente)
        else {
            aux->turno();
            cout << "\n El turno del jugador "<< id_jugador << " ha terminado. "<<endl;
            actualizarTurno(aux);
        }
      }
    }
}

// Funcion que actualiza el proximo jugador para ser comparado posteriormente
void actualizarTurno(Jugador* jugadorActual) {
    list<Jugador>::iterator itJ = jugadores.begin();
    while (itJ != jugadores.end()) {
        if (&(*itJ) == jugadorActual) {
            ++itJ; // Siguiente posicion del iterador
            if (itJ == jugadores.end()) {
                itJ = jugadores.begin();  // Ciclo circular: si se llega al final, vuelve al principio
            }
            proxTurno = &(*itJ);
            //cout << " prox = "<< proxTurno->getId() <<endl;
            break;
        }
        ++itJ;
    }
}

void comandoInicializarArchivo (string nombreArchivo) {

    bool aux;

    if (juegoIniciado == true) {

        cout << "El juego ya ha sido inicializado" << endl;
    }

    aux = inicializarArchivo (nombreArchivo);

    if (aux == false) {

        cout << nombreArchivo << " No contiene información válida para inicializar el juego." << endl;
    }

}

bool inicializarArchivo (string nombreArchivo) {

    // Codigo para iniciar la partida desde un archivo
    // Retorna true si se abre el archivo correctamente
    // Retorna false si hay algun problema en el archivo
    return true;
}

/*          IMPLEMENTACION DE METODOS CONQUISTAS        */

void comandoCostoConquista (string terri) {

    if (juegoIniciado == false){


        cout << "Esta partida no ha sido inicializada correctamente" << endl;
    }

    else if (ganador == true) {

        cout << " Esta partida ya tuvo un ganador." << endl;
    }

    else {

        Continente::evaluarCostoConquista ();

    }
}

// Funcion que evalua las condiciones para poder calcular la conquista mas barata para un jugador
void comandoConquistaBarata(){

    // (Juego no inicializado)
    if(juegoIniciado == false){
        cout << "Esta partida no ha sido inicializada correctamente."<<endl;
    }
    // (Juego terminado)
    else if(ganador == true){
        cout << "Esta partida ya tuvo un ganador."<<endl;
    }
    else{
        Continente::evaluarCostoConquistaBarata();
    }
}
