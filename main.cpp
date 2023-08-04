#include <iostream>
#include "risk.h"

using namespace std;

int main() {
  cout << "Bienvenido a Risk!\n";
  string comando;

  bool aux;

  do{
    cout<< "$ ";
    cin >> comando;

      if (comando == "ayuda") {
        ayuda();
      } else if (comando == "inicializar") {
        // Código para inicializar
        aux = iniciarJuego();
        if(aux == true){
          infoJugadores();
        }
      } else if (comando == "turno") {
          // Código para turno
      } else if (comando == "guardar <nombre_archivo>") {
          // Código para guardar partida en <nombre_archivo> texto
      } else if (comando == "guardar_comprimido <nombre_archivo>") {
          // Código para guardar partida en <nombre_archivo> bin
      } else if (comando == "inicializar <nombre_archivo>") {
          // Código para cargar partida de <nombre_archivo>
      } else if (comando == "costo_conquista <territorio>") {
          // Código para calcular el costo_conquista <territorio>
      } else if (comando == "conquista_mas_barata") {
          // Código para calcular la conquista mas barata
      }else if (comando == "salir") {
          cout << "Adios!";
      }

  }while(comando != "salir");

}

// Funcion que muestra la descripcion de todos los comandos
void ayuda(){
  cout << " --------------------- \n";
  cout << "\n inicializar \nDescripción: Realiza las operaciones necesarias para inicializar el juego, de acuerdo a las instrucciones entregadas. De esta forma, el comando pregunta la informacion de los jugadores y luego, por turnos, preguntar a cada jugador en qué territorio desea ubicar sus unidades de ejército. "<< endl;
  cout << "\n --------------------- \n";
  cout << "\n turno <id_jugador> \nDescripción: Realiza las operaciones descritas dentro del turno de un jugador (obtener nuevas unidades,atacar y fortificar)."<<endl;
  cout << "\n --------------------- \n";
  cout << "\n guardar <nombre_archivo> \nDescripción: El estado actual del juego es guardado en un archivo de texto plano, sin codificación. "<< endl;
  cout << "\n --------------------- \n";
  cout << "\n guardar_comprimido <nombre_archivo> \nDescripción: El estado actual del juego es guardado en un archivo binario (con extensión .bin) con la información comprimida, utilizando la codificación de Huffman."<< endl;
  cout << "\n --------------------- \n";
  cout << "\n inicializar <nombre_archivo> \nDescripción: Inicializa el juego con los datos contenidos en el archivo identificado por <nombre_archivo>. Inicializa el juego desde un archivo de juego normal o un archivo binario con los datos comprimidos."<< endl;
  cout << "\n --------------------- \n";
  cout << "\n costo_conquista <territorio> \nDescripción: El programa debe calcular el costo y la secuencia de territorios a ser conquistados para lograr controlar el territorio dado por el usuario. El territorio desde donde debe atacar debe ser aquel que el jugador tenga controlado más cerca al dado por el jugador."<< endl;
  cout << "\n --------------------- \n";
  cout << " conquista_mas_barata \nDescripción: De todos los territorios posibles, calcular aquel que pueda implicar un menor número de unidades de ejército perdidas."<< endl;
  cout << "\n --------------------- \n";
  cout << "\n salir \nDescripción: Termina la ejecución de la aplicación"<<endl;
  cout << "\n --------------------- \n";

}

// Funcion que verifica si el juego ha sido iniciado previamente
bool iniciarJuego(){
  if(inicio == true){
    cout << "El juego ya ha sido inicializado.\n";
    return false;
  }else
    cout << "El juego se ha inicializado correctamente.\n";
  inicio = true;
  return true;
}

// Funcion que
void infoJugadores(){
  Jugador aux;
  string auxS;

  do{
    cout << "Cuantos jugadores? (maximo 6): ";
    cin >> numJugadores;
  }while (numJugadores < 2 || numJugadores > 6);

  for(int i=0; i<numJugadores; i++){
    cout << "Nombre: ";
    cin >> auxS;
      aux.setNombre(auxS);
    cout << "Id: ";
    cin >> auxS;
      aux.setId(auxS);
    jugadores.push_back(aux);
  }

  cout << "Jugadores guardados con exito" <<endl;
}


void crearTablero(){
  Continente aux;

  aux.setNombre("America del Norte");
  aux.setColor("Amarillo");
  aux.setUnidades(5);
  tablero.push_back(aux);

  aux.setNombre("America del sur");
  aux.setColor("Rojo");
  aux.setUnidades(2);
  tablero.push_back(aux);

  aux.setNombre("Europa");
  aux.setColor("Azul");
  aux.setUnidades(5);
  tablero.push_back(aux);

  aux.setNombre("Africa");
  aux.setColor("Naranja");
  aux.setUnidades(3);
  tablero.push_back(aux);

  aux.setNombre("Asia");
  aux.setColor("Verde");
  aux.setUnidades(7);
  tablero.push_back(aux);

  aux.setNombre("Oceania/Australia");
  aux.setColor("Rosado");
  aux.setUnidades(2);
  tablero.push_back(aux);
}

