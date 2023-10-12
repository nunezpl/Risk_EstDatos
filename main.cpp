/*Lorena Nunez Pava - Brayan Ocampo - Laura Ceballos*/
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdint>

#include "h/Jugador.h"
#include "h/Continente.h"
#include "h/Tablero.h"
#include "Arbol/InfoNodo.h"
#include "Arbol/ArbolHuffman.h"

using namespace std;


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
void mostrarJugadores();
void comandoTurno(long id_jugador);
void ocuparTerritorios();
void actualizarTurno(Jugador* jugadorActual);


void comandoInicializarArchivo (string nombreArchivo);
bool inicializarArchivoBin (string nombreArchivo);
bool inicializarArchivoTxt (string nombreArchivo);
void comandoGuardarArchivoTxt (string nombreArchivo);
bool guardarArchivo (string nombreArchivo);
void comandoGuardarArchivoComprimido (string nombreArchivo);
bool comprimirArchivo (string nombreArchivo);
vector<string> infoJugadoresString();
vector<InfoNodo> informacionCaracteres(vector<string> t);
string codificarMensaje(string mensaje, vector<InfoNodo>& caracteres);
bool guardarEnFormatoBinario(string nombreArchivo, vector<InfoNodo> caracteres, vector<string> mensajeCodificado);

void asignarCodigosBinariosRecursivo(Nodo* nodo, string codigo, vector<InfoNodo>& caracteres);
void asignarCodigosBinarios(Nodo* raiz, string codigo, vector<InfoNodo>& caracteres);

void comandoCostoConquista (string terri);
void comandoConquistaBarata();


int main() {
  cout << "Bienvenido a Risk!\n";
  string comando, comandoAux, auxS;

  Tablero::crearTablero();

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
        else if (comando == "turno" && (posEspacio+ 1) != 0) {
          // Código para turno
          long id_jugador = separaComandoP2Long(comandoAux);
          comandoTurno(id_jugador);
        }
        else if (comando == "guardar") { //  <nombre_archivo>
          // Código para guardar partida en <nombre_archivo> texto
          auxS = separaComandoP2String(comandoAux);
          comandoGuardarArchivoTxt(auxS);
        }
        else if (comando == "guardar_comprimido") { // <nombre_archivo>
          // Código para guardar partida en <nombre_archivo> bin
          auxS = separaComandoP2String(comandoAux);
            comandoGuardarArchivoComprimido(auxS);
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
        else if (comando == "tablero") {
          Tablero::imprimirTablero();
        }
        else if (comando == "jugadores") {
            mostrarJugadores();
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
  cout << "\n conquista_mas_barata \nDescripcion: De todos los territorios posibles, calcular aquel que pueda implicar un menor numero de unidades de ejercito perdidas."<< endl;
  cout << "\n --------------------- \n";
  cout << "\n tablero \nDescripcion: Imprime el tablero de juego"<<endl;
  cout << "\n --------------------- \n";
  cout << "\n jugadores \nDescripcion: Imprime la imformacion completa de todos los jugadores registrados"<<endl;
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
    cout << " Color (verde, azul, rojo, amarillo, negro y gris): ";
        cin >> auxS;
        aux.setColor(auxS);
    jugadores.push_back(aux);
    if(i ==1){
        list<Jugador>::iterator itJ = jugadores.begin();
        proxTurno = &(*itJ);
    }
  }
  ocuparTerritorios();
  cout << "Jugadores guardados con exito" <<endl;
}

// Funcion que reparte las infanterias iniciales a cada jugador y les da la posibilidad de escoger su posicion
void ocuparTerritorios(){
    // Define el numero de infanterias segun el numero de jugadores
    int infanterias = 10;
    switch (numJugadores) {
        case 3: infanterias = 35; break;
        case 4: infanterias = 30; break;
        case 5: infanterias = 25; break;
        case 6: infanterias = 20; break;
    }

    // Da la posibilidad de escoger la posicion de cada una a cada jugador
    cout<<"Donde ubicaran sus "<< infanterias <<" infanterias? \n";

    list<Jugador>::iterator itJ;
    int completa=0;
    for(int i=0; i< infanterias; i++){
        for(itJ = jugadores.begin(); itJ != jugadores.end(); itJ++){
            // Validar que el jugador no haya alcanzado su límite de ejércitos
            if (itJ->totalEjercito() >= infanterias) {
                cout << "El jugador " << itJ->getNombre() << " ya completo sus infanterias \n" << endl;
                completa++;
                continue;
            }
            itJ->ubicarInfanterias();
        }

        // Si ya todos los jugadores han completado sus infanterías, salir del bucle exterior
        if (completa >= numJugadores) {
            break;
        }
    }
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

void mostrarJugadores(){
    list<Jugador>::iterator it;
    for(it= jugadores.begin(); it != jugadores.end(); it++){
        it->imprimirJugador();
        cout<<endl;
    }
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
            cout << "\nNo es el turno del jugador "<< id_jugador << ", sigue " << proxTurno->getId() <<endl;
        }
        // (Turno terminado correctamente)
        else {
            aux->turno();
            cout << "\nEl turno del jugador "<< id_jugador << " ha terminado. "<<endl;
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



/*          IMPLEMENTACION DE METODOS ARCHIVOS        */

void comandoGuardarArchivoTxt (string nombreArchivo){
    bool aux;

    if (juegoIniciado == false) {
        cout << "El juego no ha sido inicializado" << endl;
        return;
    }

    aux = guardarArchivo (nombreArchivo);

    if (aux == false) {
        cout << nombreArchivo << " La partida no ha sido guardada correctamente.." << endl;
    }else{
        cout << "\nLa partida ha sido guardada correctamente"<<endl;
    }
}
bool guardarArchivo(string nombreArchivo) {
    // nombre color cantTerritorios nomTerrTi cantEjerTi cantTarjetas tarIdi

    ofstream file(nombreArchivo);

    if (file.is_open()) {
        vector<string> infoGuardar = infoJugadoresString();

        for (int i = 0; i < infoGuardar.size(); i++) {
            file << infoGuardar[i] << endl;
        }

        file.close();
        return true;
    } else {
        return false;
    }
}


void comandoInicializarArchivo (string nombreArchivo) {

    bool aux;

    if (juegoIniciado == true) {
        cout << "El juego ya ha sido inicializado" << endl;
    }

    // separar el nombre para saber la extension txt o bin
    size_t posEspacio = nombreArchivo.find('.');// Encontrar la posición del punto
    string ext = nombreArchivo.substr(posEspacio + 1);
    if(ext == "txt"){
        aux = inicializarArchivoTxt (nombreArchivo);
    }else {
        aux = inicializarArchivoBin (nombreArchivo);
    }

    if (aux == false) {
        cout << nombreArchivo << " No contiene información válida para inicializar el juego." << endl;
    }

}
bool inicializarArchivoBin (string nombreArchivo) {
    return true;
}
bool inicializarArchivoTxt (string nombreArchivo) {
// nombre color cantTerritorios idTerri cantEjerTi cantTarjetas tarIdi

    ifstream file(nombreArchivo);

    if (file.is_open()) {
        string linea;
        int jug = 0;
        while (getline(file, linea)) {
            istringstream iss(linea);
            string nombre, color;
            int cantTerritorios;

            // Leer nombre, color y cantidad de territorios
            iss >> nombre >> color >> cantTerritorios;

            // Crear jugador con nombre y color
            Jugador nuevoJugador(nombre,jug + 1, color);

            // Leer territorios
            for (int i = 0; i < cantTerritorios; ++i) {
                int idTerritorio, cantEjercitos;
                iss >> idTerritorio;
                iss >> cantEjercitos;

                // Crear territorio y agregarlo al jugador
                Territorio* nuevoTerritorio = Tablero::buscarTerritorioNom(idTerritorio, cantEjercitos);
                nuevoJugador.agregarTerritorioOcupado(*nuevoTerritorio);
            }

            // Leer cantidad de tarjetas
            int cantTarjetas;
            iss >> cantTarjetas;

            // Leer tarjetas
            for (int i = 0; i < cantTarjetas; ++i) {
                int tarjetaId;
                iss >> tarjetaId;

                // Crear tarjeta y agregarla al jugador
                Tarjeta* nuevaTarjeta = Tablero::buscarTarjetaId(tarjetaId);
                nuevoJugador.agregarTarjeta(*nuevaTarjeta);
            }

            // Agregar jugador a la lista de jugadores
            jugadores.push_back(nuevoJugador);
            jug++;

            if(jug == 1){
                list<Jugador>::iterator itJ = jugadores.begin();
                proxTurno = &(*itJ);
            }
        }
        numJugadores = jug;
        juegoIniciado = true;
        file.close();
        cout << " Datos cargados y partida iniciada exitosamente!\n";
        return true;
    } else {
        return false;
    }
}


void comandoGuardarArchivoComprimido (string nombreArchivo){
    bool aux;

    if (juegoIniciado == false) {
        cout << "El juego no ha sido inicializado" << endl;
        return;
    }

    aux = comprimirArchivo (nombreArchivo);

    if (aux == false) {
        cout << nombreArchivo << " La partida no ha sido guardada correctamente.." << endl;
    }else{
        cout << "\nLa partida ha sido guardada correctamente"<<endl;
    }
}
bool comprimirArchivo (string nombreArchivo){

    vector<string> texto = infoJugadoresString();

    cout << " Comprimiendo ... \n";
    // inicializar p5.txt
    // guardar_comprimido b5.bin
    // Separa caracteres, cuenta su frecuencia y los ordena
    vector<InfoNodo> infoDiv = informacionCaracteres(texto);


    // Construir el Árbol de Huffman
    ArbolHuffman arbol;
    arbol = arbol.construirArbolHuffman(infoDiv);

    // Asignar códigos binarios a cada carácter
    asignarCodigosBinarios(arbol.getRaiz(), "", infoDiv);

    // Codificar el mensaje
    vector<string> mensajeCodificado;
    for (int i = 0; i < texto.size(); ++i) {
        mensajeCodificado.push_back( codificarMensaje(texto[0], infoDiv) );
    }


    // Guardar en formato binario
    if (guardarEnFormatoBinario(nombreArchivo, infoDiv, mensajeCodificado)) {
        cout << "(Comando correcto) La partida ha sido codificada y guardada correctamente.\n";
        return true;
    } else
        cout << "(Error al codificar y/o guardar) La partida no ha sido codificada ni guardada correctamente.\n";
        return false;

}


vector<string> infoJugadoresString(){
    vector<string> info;
    for (list<Jugador>::iterator itJ = jugadores.begin(); itJ != jugadores.end(); itJ++) {
        string cadena = "";
        cadena = itJ->getNombre() + " " + itJ->getColor();

        // Territorios
        cadena += " " + to_string(itJ->getOcupados().size());

        if (!itJ->getOcupados().empty()) {
            list<Territorio> aux = itJ->getOcupados();
            for (list<Territorio>::iterator itT = aux.begin(); itT != aux.end(); itT++) {
                cadena += " " + to_string(itT->getId());
                cadena += " " + to_string(itT->getCantiEjercitos());
            }
        }

        // Tarjetas
        cadena += " " + to_string(itJ->getTarjetas().size());

        if (itJ->getTarjetas().size() > 0) {
            list<Tarjeta> aux = itJ->getTarjetas();
            for (list<Tarjeta>::iterator itTa = aux.begin(); itTa != aux.end(); itTa++) {
                cadena += " " + to_string(itTa->getId());
            }
        }
        // Agrega al vector
        info.push_back(cadena);
    }
    return info;
}

vector<InfoNodo> informacionCaracteres(vector<string> texto){
    cout << " Separando ... \n";
    // Separar texo en char
    vector<char> textoDiv;
    for (string palabra : texto) {
        for (char c : palabra) {
            cout << " c. "<<c<<endl;
            textoDiv.push_back(c);
        }
    }

    vector<InfoNodo> infoDiv;
    InfoNodo aux;

    for (char letra : textoDiv) {
        aux.setValor(letra);

        // Hallar la frecuencia de las letras
        int frec = 0;
        for (int i = 0; i < textoDiv.size(); ++i) {
            if( letra == textoDiv[i]){
                cout << " le: "<<letra<<" f: "<<frec<<endl;
                frec++;
            }
        }
        cout << letra <<" -> "<<frec<<endl;
        aux.setFrecuencia(frec);
        infoDiv.push_back(aux);
    }

    return infoDiv;
}


void asignarCodigosBinarios(Nodo* raiz, string codigo, vector<InfoNodo>& caracteres) {
    asignarCodigosBinariosRecursivo(raiz, codigo, caracteres);
}
void asignarCodigosBinariosRecursivo(Nodo* nodo, string codigo, vector<InfoNodo>& caracteres) {
    if (nodo == nullptr) {
        return;
    }

    // Si el nodo es una hoja, asigna el código binario al carácter correspondiente
    if (nodo->esHoja()) {
        char caracter = nodo->getInfo().getValor();
        for (InfoNodo& info : caracteres) {
            if (info.getValor() == caracter) {
                info.setAscii(codigo);
                break;
            }
        }
    }

    // Recorre hacia la izquierda con '0'
    asignarCodigosBinariosRecursivo(nodo->getHijoIzq(), codigo + "0", caracteres);

    // Recorre hacia la derecha con '1'
    asignarCodigosBinariosRecursivo(nodo->getHijoDer(), codigo + "1", caracteres);
}

// Función para codificar un mensaje utilizando códigos binarios
string codificarMensaje(string mensaje, vector<InfoNodo>& caracteres) {
    string mensajeCodificado;
    for (char caracter : mensaje) {
        for (InfoNodo info : caracteres) {
            if (info.getValor() == caracter) {
                mensajeCodificado += info.getAscii();
                break;
            }
        }
    }
    return mensajeCodificado;
}


bool guardarEnFormatoBinario(string nombreArchivo, vector<InfoNodo> caracteres, vector<string> mensajeCodificado) {
    // Abrir el archivo en modo binario
    ofstream file(nombreArchivo, ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo binario para escritura.\n";
        return false;
    }

    try {
        // Escribir la cantidad de caracteres diferentes presentes en el archivo
        uint16_t n = caracteres.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));

        // Escribir la información de cada carácter (ci y fi)
        for (InfoNodo& info : caracteres) {
            file.write(reinterpret_cast<const char*>(&info), sizeof(info));
        }

        // Escribir la longitud del archivo
        uint64_t longitudArchivo = mensajeCodificado.size();
        file.write(reinterpret_cast<char*>(&longitudArchivo), sizeof(longitudArchivo));

        // Escribir el mensaje codificado
        for (int i = 0; i < longitudArchivo ; ++i) {
            file.write(mensajeCodificado[i].c_str(), longitudArchivo);
        }

        file.close();
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error al escribir en el archivo binario: " << e.what() << "\n";
        file.close();
        return false;
    }
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

