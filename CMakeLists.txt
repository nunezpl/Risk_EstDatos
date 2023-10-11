cmake_minimum_required(VERSION 3.26)
project(Risk_EstDatos)

set(CMAKE_CXX_STANDARD 14)

include_directories(Arbol)
include_directories(c)
include_directories(h)

add_executable(Risk_EstDatos
        Arbol/ArbolHuffman.cxx
        Arbol/ArbolHuffman.h
        Arbol/Nodo.cxx
        Arbol/Nodo.h
        c/Continente.cxx
        c/Ejercito.cxx
        c/Jugador.cxx
        c/Tablero.cxx
        c/Tarjeta.cxx
        c/Territorio.cxx
        h/Continente.h
        h/Ejercito.h
        h/Jugador.h
        h/Tablero.h
        h/Tarjeta.h
        h/Territorio.h
        main.cpp)
