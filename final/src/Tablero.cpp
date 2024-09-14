/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tablero.cpp
 * Author: Usuario
 * 
 * Created on 20 de febrero de 2024
 */

#include "Tablero.h"
#include "fstream"
#include <iostream>

using namespace std;

Tablero::Tablero(){
    tam = 0;
    Ntowin = 0;
    inicializarTablero(tam);
    t.resize(tam);
}

Tablero::Tablero(const Tablero& orig) {
    tam = orig.tam;
    Ntowin = orig.Ntowin;
    inicializarTablero(tam);
    t = orig.t;
}

Tablero::~Tablero() {
    
}

Tablero::Tablero(int newN=4, int newNtowin=4){
    if((newN > 0) && (newNtowin > 0)){
        tam = newN;
        Ntowin = newNtowin=4;
        t.reservarMemoria(tam,tam);
        inicializarTablero(tam);
    }
}

void Tablero::resetTablero(){
    int filas = t.numfilas(), columnas = t.numcolumnas();
    int i, j;
    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            t.putValue(i, j) = t.valordefecto();
        }
    }
}

bool Tablero::introducirFicha(int col, int jug){
    col--; //Le quitamos 1 para ponerlo en la columna "real" 1 y no en la 0
    bool colocada = false;
    if((col >= 0) && (col < t.numcolumnas())){
        int i = t.numfilas() - 1;
        for(i; (i >= 0) && !colocada; i--){
            if(t.getValue(i, col) == t.valordefecto()){
                t.putValue(i, col) = jug;
                colocada = true;
            }
        }
    }
    else{
        cout << "Error al introducir ficha, prueba de nuevo";
    }
    return colocada;
}

bool Tablero:: tableroLleno(){
    bool lleno = true;
    int filas = t.numfilas(), columnas = t.numcolumnas();
    int i, j;
    for(i = 0; (i < filas) && lleno; i++){
        for(j = 0; (j < columnas) && lleno; j++){
            if(t.getValue(i, j) == t.valordefecto()){
                lleno = false;
            }
        }
    }
    return lleno;
}

string Tablero::tablerotostring() const{
    string tablero = t.matriztostring();
    return tablero;
}

void Tablero::inicializarTablero(int newtam){
    if(newtam > 0){
        t.resize(newtam);
    }
}

int Tablero::turno(){
    int id1 = 0;
    int id2 = 0;
    int jug1 = 0;
    int jug2 = 0;
    
    for(int i = 0; i < t.numfilas(); i++){
        for(int j = 0; j < t.numcolumnas(); j++){
            if(t.getValue(i,j) == 1){
                id1++;
                jug1 = t.getValue(i,j);
            }
            if(t.getValue(i,j) == 2){
                id2++;
                jug2 = t.getValue(i,j);
            }
        }
    }
    
    if(id1 <= id2){
        return jug1;
    }
    else{
        return jug2;
    }
}

std::ostream & operator << (std::ostream & flujo, const Tablero & tab){
    flujo << tab.tablerotostring();
    return flujo;
}

Tablero & Tablero::operator=(const Tablero &orig){
    if(this == &orig){
        return *this;
    }
    else{
        tam = orig.tam;
        Ntowin = orig.Ntowin;
        t = orig.t;
        
        return *this;
    }
}

int Tablero::ganador() {
    int ganador = 0;
    bool gana;

    // Buscamos en horizontal
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j <= tam - Ntowin; j++) {
            int jug = t.getValue(i, j);
            if (jug != 0) {
                gana = true;
                for (int k = 1; k < Ntowin; k++) {
                    if (jug != t.getValue(i, j + k)) {
                        gana = false;
                        break;
                    }
                }
                if (gana) {
                    return jug;
                }
            }
        }
    }

    // Buscamos en vertical
    for (int i = 0; i <= tam - Ntowin; i++) {
        for (int j = 0; j < tam; j++) {
            int jug = t.getValue(i, j);
            if (jug != 0) {
                gana = true;
                for (int k = 1; k < Ntowin; k++) {
                    if (jug != t.getValue(i + k, j)) {
                        gana = false;
                        break;
                    }
                }
                if (gana) {
                    return jug;
                }
            }
        }
    }

    // Buscamos en diagonal up-left hasta down-right
    for (int i = 0; i <= tam - Ntowin; i++) {
        for (int j = 0; j <= tam - Ntowin; j++) {
            int jug = t.getValue(i, j);
            if (jug != 0) {
                gana = true;
                for (int k = 1; k < Ntowin; k++) {
                    if (jug != t.getValue(i + k, j + k)) {
                        gana = false;
                        break;
                    }
                }
                if (gana) {
                    return jug;
                }
            }
        }
    }

    // Buscamos en diagonal down-left hasta up-right
    for (int i = Ntowin - 1; i < tam; i++) {
        for (int j = 0; j <= tam - Ntowin; j++) {
            int jug = t.getValue(i, j);
            if (jug != 0) {
                gana = true;
                for (int k = 1; k < Ntowin; k++) {
                    if (jug != t.getValue(i - k, j + k)) {
                        gana = false;
                        break;
                    }
                }
                if (gana) {
                    return jug;
                }
            }
        }
    }
    
    if(tableroLleno() && ganador == 0){
        ganador = -1;
        cout << "EMPATE" << endl;
    }

    return ganador;
}
