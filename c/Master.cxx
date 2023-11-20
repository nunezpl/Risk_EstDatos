#include "../h/Master.h"


/*            IMPLEMENTACION DE METODOS                 */

void Master::comandos(){
    // Pide el comando y lo evalua para llamar a la funcion deseada

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
        else if (comando == "costo_conquista" && (posEspacio+ 1) != 0) { // <territorio>

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


void Master::ayuda(){
    // Funcion que muestra la descripcion de todos los comandos

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




/*          IMPLEMENTACION DE METODOS AUXILIARES        */

string Master::separaComandoP2String(string c){
    // Separa y retorna la segunda palabra del comando

    size_t posEspacio = c.find(' ');// Encontrar la posición del primer espacio
    string palabraStr = c.substr(posEspacio + 1);
    return palabraStr;
}


long Master::separaComandoP2Long(string c){
    // Separa y retorna la segunda parte del comando que sea un numero long

    size_t posEspacio = c.find(' ');
    string palabraStr = c.substr(posEspacio + 1);
    return stol(palabraStr); // Convertir a entero
}


vector<string> Master::separaLineaEspacio(string l) {
    // Llega un string con espacios y retorna un vector con cada palabra como valor string

    vector<string> linea;
    istringstream iss(l);
    do {
        string palabra;
        iss >> palabra;
        if (!palabra.empty()) {
            linea.push_back(palabra);
        }
    } while (iss);
    return linea;
}




/*          IMPLEMENTACION DE METODOS SETUP JUEGO        */

bool Master::iniciarJuego(){
    // Funcion que verifica si el juego ha sido iniciado previamente,
    // retorna true si no esta iniciado para pedir infoJugadores

    if(juegoIniciado == true){
        cout << "El juego ya ha sido inicializado.\n";
        return false;
    }else
        cout << "El juego se ha inicializado correctamente.\n";
    juegoIniciado = true;
    return true;
}




/*          IMPLEMENTACION DE METODOS JUGADORES          */

void Master::actualizarTurno(Jugador* jugadorActual) {
    // Funcion que actualiza el proximo jugador para ser comparado posteriormente

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


Jugador* Master::encontrarJugador(long id_jugador){
    // Encuentra el jugador por su id

    for (list<Jugador>::iterator itJ = jugadores.begin(); itJ != jugadores.end(); itJ++) {
        if (itJ->getId() == id_jugador) {
            return &(*itJ);
        }
    }
    cout<< "El jugador "<< id_jugador<< " no forma parte de esta partida."<<endl;
    return nullptr;
}


void Master::infoJugadores(){
    // Funcion que pide la cantidad y la informacion de todos los jugadores

    Jugador aux;
    string auxS;
    long id;

    do{
        cout << "Cuantos jugadores? (minimo 2, maximo 6): ";
        cin >> numJugadores;
    }while (numJugadores < 2 || numJugadores > 6);

    for(int i=1; i<numJugadores+1; i++){
        cout << "\n Nombre: ";
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


void Master::ocuparTerritorios(){
    // Funcion que reparte las infanterias iniciales a cada jugador y les da la posibilidad de escoger su posicion

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


void Master::mostrarJugadores(){
    // Muestra la informacion de todos los jugadores

    list<Jugador>::iterator it;
    for(it= jugadores.begin(); it != jugadores.end(); it++){
        it->imprimirJugador();
        cout<<endl;
    }
}


void Master::comandoTurno(long id_jugador){
    // Funcion que evalua las condiciones para ejecutar el turno del jugador


    if(juegoIniciado == false){
        cout << "Esta partida no ha sido inicializada correctamente."<<endl;
    }
    else if(ganador == true){
        cout << "Esta partida ya tuvo un ganador."<<endl;
    }
    else{
        Jugador* aux = encontrarJugador(id_jugador);

        if(aux != nullptr){
            if( proxTurno != aux ){
                cout << "\nNo es el turno del jugador "<< id_jugador << ", sigue " << proxTurno->getId() <<endl;
            }
            else {
                aux->turno();
                cout << "\nEl turno del jugador "<< id_jugador << " ha terminado. "<<endl;
                actualizarTurno(aux);
            }
        }
    }
}


vector<string> Master::infoJugadoresString(){
    // Funcion que guarda la informacion de todos los jugadores en un vector de strings
    // La info de un jugador corresponde a un espacio en el vector (un string)

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



/*          IMPLEMENTACION DE METODOS ARCHIVOS          */

/*    GUARDAR ARCHIVO TXT    */

void Master::comandoGuardarArchivoTxt (string nombreArchivo){
    // Funcion que evalua las condiciones para guardar la partida en un archivo txt

    if (juegoIniciado == false) {
        cout << "El juego no ha sido inicializado" << endl;
        return;
    }

    bool aux = guardarArchivo (nombreArchivo);

    if (aux == false) {
        cout << nombreArchivo << " La partida no ha sido guardada correctamente.." << endl;
    }else{
        cout << "\nLa partida ha sido guardada correctamente"<<endl;
    }
}

bool Master::guardarArchivo(string nombreArchivo) {
    // Guarda un vector string en un archivo txt con la estructura:
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


/*    CARGAR ARCHIVOS        */

void Master::comandoInicializarArchivo (string nombreArchivo) {
    // Funcion que evalua las condiciones para inicializar la partida desde un archivo

    if (juegoIniciado == true) {
        cout << "El juego ya ha sido inicializado" << endl;
        return;
    }

    // separar el nombre para saber la extension TXT o BIN
    size_t posEspacio = nombreArchivo.find('.'); // Encontrar la posición del punto
    string ext = nombreArchivo.substr(posEspacio + 1); // Saca la extension

    bool aux;

    if(ext == "txt"){
        aux = inicializarArchivoTxt (nombreArchivo);
        cout << " Datos cargados y partida iniciada exitosamente!\n";
    }else {
        aux = inicializarArchivoBin (nombreArchivo);
    }

    if (aux == false) {
        cout << nombreArchivo << " No contiene información válida para inicializar el juego." << endl;
    }

}


bool Master::inicializarArchivoTxt (string nombreArchivo) {
    // Lee la informacion de un archivo de texto y carga los datos de los jugadores
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

            // Agregar jugador a la lista de jugadores
            jugadores.push_back(nuevoJugador);
            list<Jugador>::iterator itJ = jugadores.begin();
            advance(itJ, jug);

            // Leer territorios
            for (int i = 0; i < cantTerritorios; ++i) {
                int idTerritorio, cantEjercitos;
                iss >> idTerritorio;
                iss >> cantEjercitos;

                // Crear territorio y agregarlo al jugador
                Territorio* nuevoTerritorio = Tablero::buscarTerritorioNom(idTerritorio, cantEjercitos, &(*itJ));
                itJ->agregarTerritorioOcupado(*nuevoTerritorio);
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
                itJ->agregarTarjeta(*nuevaTarjeta);
            }


            jug++;

            if(jug == 1){
                // Asigna el primer turno
                proxTurno = &(*itJ);
            }
        }
        numJugadores = jug;
        juegoIniciado = true;

        file.close();

        return true;
    } else {
        return false;
    }
}


vector<string> Master::leerArchivoBinario(string nombreArchivo) {
    // Abrir el archivo en modo binario
    ifstream file(nombreArchivo, ios::binary);

    if (!file.is_open()) {
        cout << "Error al abrir el archivo binario: " << nombreArchivo << endl;
        return vector<string>();
    }

    // Leer la cantidad de caracteres diferentes presentes en el archivo (N)
    uint8_t n;
    file.read(reinterpret_cast<char*>(&n), sizeof(n));
    //cout << " n:" << n << endl;

    // Leer la información de cada carácter (ci y fi) con los que se crea el arbol huffman
    vector<InfoNodo> caracteres;
    for (int i = 0; i < n; ++i) {
        // Leer el ASCII como binario C
        int ascii;
        file.read(reinterpret_cast<char*>(&ascii), sizeof(ascii));
        file.ignore(1);
        //cout << "  as:" << ascii;

        // Leer la frecuencia como binario F
        int frecuencia;
        file.read(reinterpret_cast<char*>(&frecuencia), sizeof(frecuencia));
        file.ignore(1);
        //cout << "  fr:" << frecuencia << endl;

        caracteres.push_back(InfoNodo(frecuencia, ascii));
    }

    // Construir el arbol asociado a este archivo
    arbol.construirArbolHuffman(caracteres);

    // Leer la longitud del archivo (W)
    int longitudArchivo;
    file.read(reinterpret_cast<char*>(&longitudArchivo), sizeof(longitudArchivo));
    file.ignore(1);
    //cout << "   W:" << longitudArchivo << endl;
    file.ignore(1); // Ignora el salto de linea

    // Leer el mensaje codificado con la informacion de todos los jugadores
    vector<string> mensajeCodificado;
    for (int i = 0; i < longitudArchivo; ++i) {

        string linea;
        getline(file, linea);
        mensajeCodificado.push_back(linea);
    }

    file.close();
    return mensajeCodificado;
}


bool Master::inicializarArchivoBin(string nombreArchivo) {
    // Lee la informacion de un archivo binario y carga los datos de los jugadores

    vector<string> bin = leerArchivoBinario(nombreArchivo); // Se crea el arbol y retorna info juga codificada
    vector<string> texto;

    cout << " decodificado: \n";
    for (int i = 0; i < bin.size(); ++i) {
        cout << bin[i] <<endl;

        // Traducir lo binario
        string aux = arbol.traduceBinario( arbol.getRaiz(), separaLineaEspacio(bin[i]) );
        texto.push_back(aux);
    }


    // Llenar estructura de datos de los jugadores
    // Texto[i] es una linea con la info completa de un jugador
    for (int i = 0; i < texto.size(); ++i) {
        // Separar cada dato del jugador i
        vector<string> linea = separaLineaEspacio(texto[i]);

        // Guardar la info de cada jugador
        // Leer nombre, color y cantidad de territorios
        string nombre = linea[0];
        string color = linea[1];
        int cantTerritorios = stoi(linea[2]);

        // Crear jugador con nombre y color
        Jugador nuevoJugador(nombre, i + 1, color);


        // Leer territorios
        for (int j = 3; j < 3 + cantTerritorios; ++j) {
            int idTerritorio = stoi(linea[j]);
            int cantEjercitos = stoi(linea[j]);

            // Crear territorio y agregarlo al jugador
            Territorio *nuevoTerritorio = Tablero::buscarTerritorioNom(idTerritorio, cantEjercitos, &nuevoJugador);
            nuevoJugador.agregarTerritorioOcupado(*nuevoTerritorio);
        }

        int pos = 3 + (cantTerritorios * 2); // Aux para saber la posicion de linea

        // Leer cantidad de tarjetas
        int cantTarjetas = stoi(linea[pos]);

        // Leer tarjetas
        for (int j = pos; j < cantTarjetas + pos; ++j) {
            int tarjetaId = stoi(linea[j]);

            // Crear tarjeta y agregarla al jugador
            Tarjeta *nuevaTarjeta = Tablero::buscarTarjetaId(tarjetaId);
            nuevoJugador.agregarTarjeta(*nuevaTarjeta);
        }

        // Agregar jugador a la lista de jugadores
        jugadores.push_back(nuevoJugador);

        if(i == 1){
            // Asigna el turno al primer jugador
            list<Jugador>::iterator itJ = jugadores.begin();
            proxTurno = &(*itJ);
        }
    }
    numJugadores = texto.size();
    juegoIniciado = true;

    return true;
}


/*    GUARDAR ARCHIVO BIN    */

void Master::comandoGuardarArchivoComprimido (string nombreArchivo){
    // Funcion que evalua las condiciones para guardar la partida en un archivo bin

    if (juegoIniciado == false) {
        cout << "El juego no ha sido inicializado" << endl;
        return;
    }

    bool aux = comprimirArchivo (nombreArchivo);

    if (aux == false) {
        cout << nombreArchivo << " La partida no ha sido guardada correctamente.." << endl;
    }else{
        cout << "\nLa partida ha sido guardada correctamente"<<endl;
    }
}


bool Master::comprimirArchivo(string nombreArchivo) {
    // Funcion que realiza el proceso para guardar la partida en un bin

    vector<string> texto = infoJugadoresString();

    cout << "Comprimiendo ... \n";

    // Separa caracteres, cuenta su frecuencia
    vector<InfoNodo> infoDiv = informacionCaracteres(texto);

    // Construir el árbol de Huffman
    ArbolHuffman arbol;
    arbol = arbol.construirArbolHuffman(infoDiv);

    // Asignar códigos binarios (ruta) a cada carácter
    asignarCodigosBinarios(arbol.getRaiz(), "", infoDiv);

    // Codificar el mensaje
    vector<string> mensajeCodificado;
    for (int i = 0; i < texto.size(); ++i) {
        mensajeCodificado.push_back( codificarMensaje(texto[i], infoDiv) );
    }

    cout << "Mensaje codificado: \n";
    for (int i = 0; i < mensajeCodificado.size(); ++i) {
        cout << mensajeCodificado[i] << endl;
    }

    // Guardar en formato binario
    if (guardarEnFormatoBinario(nombreArchivo, infoDiv, mensajeCodificado)) {
        return true;
    } else
        return false;
}


vector<InfoNodo> Master::informacionCaracteres(vector<string> texto){
    // Funcion que separa la cadena string en char, cuenta la frecuencia de cada letra
    // y la guarda en la estructura infoNodo

    cout << " Separando ... \n";

    // Separar texo en char
    vector<char> textoDiv;

    for (string palabra : texto) {
        for (char c : palabra) {
            //cout << " c. "<<c<<endl;
            textoDiv.push_back(c);
        }
    }

    vector<InfoNodo> infoDiv;
    InfoNodo aux;
    bool auxB = false;

    for (char letra : textoDiv) {
        aux.setValor(letra); // Guarda letra

        // Busca en el vector que se llena si ya esta la letra
        for (int i = 0; i < infoDiv.size(); ++i) {
            if (letra == infoDiv[i].getValor()){
                auxB = true;
            }
        }

        if(auxB == false) {
            // Hallar la frecuencia de las letras, busca en el texto donde esta toda la informacion
            int frec = 0;
            for (int i = 0; i < textoDiv.size(); ++i) {
                if (letra == textoDiv[i])
                    frec++;
            }
            cout << letra << " -> " << frec << endl;
            aux.setFrecuencia(frec);
            infoDiv.push_back(aux);
        }
        auxB = false;
    }

    return infoDiv;
}


void Master::asignarCodigosBinarios(Nodo* nodo, string codigo, vector<InfoNodo>& caracteres) {
    // Funcion que guarda la ruta de 0s y 1s para llegar en el arbol, de cada caracter

    if (nodo == nullptr) {
        return;
    }

    // Si el nodo es una hoja, asigna el código binario al carácter correspondiente
    if (nodo->esHoja()) {
        char caracter = nodo->getInfo().getValor();
        for (InfoNodo& info : caracteres) {
            if (info.getValor() == caracter ) {
                info.setRuta(codigo);
                info.traduccionAscii();
                cout << " R: "<< info.getRuta() << " A: "<< info.getAscii() <<" V: "<<info.getValor()<<endl;
                break;
            }
        }
    }

    // Recorre hacia la izquierda con '0'
    asignarCodigosBinarios(nodo->getHijoIzq(), codigo + "0", caracteres);

    // Recorre hacia la derecha con '1'
    asignarCodigosBinarios(nodo->getHijoDer(), codigo + "1", caracteres);
}


string Master::codificarMensaje(string mensaje, vector<InfoNodo>& caracteres) {
    // Función para codificar un mensaje utilizando códigos binarios

    string mensajeCodificado = "";
    for (char caracter : mensaje) {
        for (InfoNodo info : caracteres) {
            if (info.getValor() == caracter) {
                mensajeCodificado += info.getRuta() + " ";
                break;
            }
        }
    }
    return mensajeCodificado;
}


bool Master::guardarEnFormatoBinario(string nombreArchivo, vector<InfoNodo> caracteres, vector<string> mensajeCodificado) {
    // Abrir el archivo en modo binario
    ofstream file(nombreArchivo, ios::binary);
    if (!file.is_open()) {
        cout << "Error al abrir el archivo binario: " << nombreArchivo << endl;
        return false;
    }

    // Escribir la cantidad de caracteres diferentes presentes en el archivo (N)
    uint8_t n = caracteres.size();
    //cout << " n:"<<n<<endl;
    file.write(reinterpret_cast<const char*>(&n), sizeof(n));

    // Escribir la información de cada carácter (ci y fi)
    for (InfoNodo info : caracteres) {

        // Convertir el ASCII a formato binario C
        int ascii = info.getAscii();
        //cout<<"  as:"<<ascii;
        file.write(reinterpret_cast<char *>(&ascii), sizeof(ascii));
        file.write(" ", 1);

        // Escribir la frecuencia como binario F
        int frecuencia = info.getFrecuencia();
        //cout<<"  fr:"<<frecuencia<<endl;
        file.write(reinterpret_cast<char*>(&frecuencia), sizeof(frecuencia));
        file.write(" ", 1);
    }

    // Escribir la longitud del archivo (W)
    int longitudArchivo = mensajeCodificado.size();
    //cout << "   W:"<<longitudArchivo<<endl;
    file.write(reinterpret_cast<char*>(&longitudArchivo), sizeof(longitudArchivo));
    file.write(" ", 1);

    // Escribir el mensaje codificado
    for (int i = 0; i < longitudArchivo; ++i) {
        file.write("\n", 1);
        file.write(mensajeCodificado[i].c_str(), mensajeCodificado[i].size());
    }

    file.close();
    return true;
}




/*          IMPLEMENTACION DE METODOS CONQUISTAS        */

void Master::comandoCostoConquista (string terri) {

    if (juegoIniciado == false){
        cout << "Esta partida no ha sido inicializada correctamente" << endl;
    }

    else if (ganador == true) {
        cout << " Esta partida ya tuvo un ganador." << endl;
    }

    else {
        grafo.deleteArcs();
        crearGrafo(); // Crea el grafo

        evaluarCostoConquista(terri);
    }
}


void Master::imprimirResultado(vector<Territorio> ts){
    string result;

    for (Territorio t: ts) {
        result += (t.getNombre() + ", ");
    }

    if (result.size() == 0) cout << "No hay camino!!\n";
    else {
        result.pop_back();
        cout << result << endl;
    }
}


void Master::comandoConquistaBarata(){
// Funcion que evalua las condiciones para poder calcular la conquista mas barata para un jugador

    // (Juego no inicializado)
    if(juegoIniciado == false){
        cout << "Esta partida no ha sido inicializada correctamente."<<endl;
    }
        // (Juego terminado)
    else if(ganador == true){
        cout << "Esta partida ya tuvo un ganador."<<endl;
    }
    else{
        grafo.deleteArcs();

        crearGrafo(); // Crea el grafo
        evaluarCostoConquistaBarata();
    }
}


void Master::crearGrafo(){
    // Si ya existe, lo crea desde 0
    vector< NodoGrafo<Territorio> > nuevo;
    grafo.setVertices(nuevo);

    for (Continente c: Tablero::tablero) { // Continente
        for (Territorio t : c.getTerritorios()) { // Territorios de un continente
            grafo.addVertex(t); // Añade nodo
        }
    }
    //cout << " Terminaron los nodos, hay "<< grafo.getVertices().size() << endl;

    // Añadir aristas al grafo
    for (NodoGrafo<Territorio> &n : grafo.getVertices()) {
        vector<Territorio*> vecinos = n.getInfo().getVecinos();
        for (Territorio* v : vecinos) {
            // Calcular peso del camino entre dos territorios
            int peso = pesoCamino({n.getInfo(), *v});

            vector<int> arist = obtenerPosicionesVertices(n.getInfo().getNombre(), v->getNombre());
            grafo.addArc(arist[0], arist[1], peso);
            //cout << "Arista de " << n.getInfo().getNombre() << " a " << v->getNombre() << " con peso " << peso << endl;
        }
    }

    cout << "\n Grafo construido con exito!"<<endl;

    //IMPRIMIR GRAFO
    /*for (NodoGrafo<Territorio> n : grafo.getVertices()) {
        Territorio t = n.getInfo();
        cout << "\nTerritorio: " << t.getNombre() ;//<< " (Propietario: " << t.getOcupante()->getId() << ", Ejercitos: " << t.getCantiEjercitos() << ")";
        cout << "   Vecinos: ";
        for (pair<int, int> t : n.getAdj()) {
            cout << t.first << " ";
        }
        cout << endl;
    }*/
}


string Master::caminoToString(vector<Territorio> camino){
    string result;

    for (Territorio t: camino) {
        result += (t.getNombre() + ", ");
    }

    return result;
}


vector<Territorio> Master::territoriosAConquistar(){
    vector<Territorio> conquistar;
    for (Continente c : Tablero::tablero) {
        for (Territorio t : c.getTerritorios()) {
            if (t.getOcupante() != proxTurno) {
                conquistar.push_back(t);
            }
        }
    }
    cout << "\n Puede atacar a "<< conquistar.size() << " territorios.\n" <<endl;
    return conquistar;
}


void Master::evaluarCostoConquistaBarata(){

    // Territorios que pueden ser atacados por el jugador actual
    vector<Territorio> territoriosParaConquistar = territoriosAConquistar();


    // Almacena todos los caminos posibles desde los territorios del jugador hasta cada territorio objetivo
    vector<pair<int, vector<Territorio>>> caminos;

    // Calcula cada camino
    for (Territorio t : territoriosParaConquistar) {
        int aux = obtenerPosicionesVertices(t.getNombre(), "x")[0];
        caminos.push_back(territorioCercano(aux));
    }

    /*for (pair<int, vector<Territorio>> c:caminos) {
        cout << "\n Peso: " << c.first << " camino: " << c.second.begin()->getNombre() << " a: " << c.second.back().getNombre();
    }*/

    // Evalua la conquista mas barata de todas
    // Evaluar el mas barato de todos
    pair<int, vector<Territorio>> caminoMinimo = caminos[0];

    for (pair<int, vector<Territorio>> c : caminos) {
        if (c.first < caminoMinimo.first) {
            caminoMinimo = c;
        }
    }

    // Confirmar peso del camino
    //caminoMinimo.first = pesoCamino(caminoMinimo.second);

    cout << proxTurno->getNombre() << ": La conquista mas barata es avanzar sobre el territorio ";
    cout << caminoMinimo.second.begin()->getNombre() << " desde el territorio ";
    cout << caminoMinimo.second.back().getNombre() << ". Para conquistar, debe pasar por los territorios " ;
    imprimirResultado(caminoMinimo.second);
    cout << "Debe conquistar "<< caminoMinimo.first << " unidades de ejercito."<<endl;
}


int Master::pesoCamino(vector<Territorio> camino){
    int peso = 0;

    for (Territorio t : camino) {
        peso += t.getCantiEjercitos();
    }

    return peso;
}


void Master::evaluarCostoConquista(string to) {

    // Almacena todos los caminos posibles desde los territorios del jugador hasta el territorio objetivo
    pair<int, vector<Territorio>> camino;

    // Calcula camino
        int aux = obtenerPosicionesVertices(to, "x")[0];
        camino = (territorioCercano(aux));

    // Confirmar peso del camino
    //camino.first = pesoCamino(camino.second);

    cout << " Para conquistar el territorio"<< camino.second.back().getNombre() << " , debe atacar desde "<< camino.second.begin()->getNombre() ;
    cout << ", pasando por los territorios ";
    imprimirResultado(camino.second);
    cout << "Debe conquistar "<<  camino.first << " unidades de ejercito." <<endl;

}


vector<int> Master::obtenerPosicionesVertices(string from, string to) {
    vector<int> positions(2, -1);
    int i = 0;
    for (NodoGrafo<Territorio> n: this->grafo.getVertices()) {
        Territorio t = n.getInfo();
        if (t.getNombre() == from)
            positions[0] = i;
        if (t.getNombre() == to)
            positions[1] = i;
        i++;
    }

    return positions;
}


vector<Territorio> Master::buildPath(int start, vector<int> parent) {
    vector<NodoGrafo<Territorio>> vertices = this->grafo.getVertices();
    deque<Territorio> path;
    path.push_front(vertices[start].getInfo());

    for (int p = parent[start]; p != -1; p = parent[p]) {
        path.push_front(vertices[p].getInfo());
    }
    vector<Territorio> res(path.begin(), path.end());

    return res;
}


pair<int, vector<Territorio>> Master::territorioCercano(int pos) {
// Función para buscar el territorio más cercano propiedad del jugador dado

    // Mapa para mantener un registro de nodos visitados
    unordered_map<int, bool> visitados;
    visitados[pos] = true; // Marca el nodo inicial como visitado

    int peso = 0;

    // Cola para realizar un recorrido en amplitud (BFS)
    queue<pair<int, vector<Territorio>>> cola;
    // Inicializa la cola con el nodo inicial y el camino actual
    cola.push({pos, {grafo.getVertices()[pos].getInfo()}});

    // Realiza un recorrido en amplitud (BFS)
    while (!cola.empty()) {
        // Obtiene la información del nodo actual
        int indiceActual = cola.front().first;
        vector<Territorio> caminoActual = cola.front().second;
        cola.pop();

        // Verifica si el territorio actual pertenece al jugador actual
        if (grafo.getVertices()[indiceActual].getInfo().getOcupante() == proxTurno) {
            // Peso del camino
            peso = pesoCamino(caminoActual);

            return {peso, caminoActual};
        }

        // Explora los vecinos del territorio actual
        for (pair<int, int> vecino : grafo.getVertices()[indiceActual].getAdj()) {
            int id = vecino.first;
            int peso = vecino.second;

            // Si el vecino no ha sido visitado, se agrega a la cola
            if (!visitados[id]) {
                // Crea un nuevo camino añadiendo el vecino al camino actual
                vector<Territorio> nuevoCamino = caminoActual;
                nuevoCamino.push_back(grafo.getVertices()[id].getInfo());

                // Agrega el vecino y su nuevo camino a la cola
                cola.push({id, nuevoCamino});

                // Marca el vecino como visitado
                visitados[id] = true;
            }
        }
    }

    // Si no se encuentra un país cercano, retorna una pareja vacía
    return {};
}
