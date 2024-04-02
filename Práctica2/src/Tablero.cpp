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
#include <iostream>
#include <fstream>
#include <valarray>
#include <string>
#include <sstream>
using namespace std;


Tablero::Tablero(const Tablero& orig) {

}

Tablero::~Tablero() {
    
}

Tablero::Tablero(int newN=4, int newNtowin=4){
    if((newN > 0) && (newNtowin > 0)){
        MatrizEnteros t(newN=4,newN=4,t.valordefecto());
        Ntowin = newNtowin=4;
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
    bool colocada = false;
    if((col >= 0) && (col <= t.numcolumnas())){
        int i = t.numfilas() - 1;
        for(i; (i >= 0) && !colocada; i--){
            if(t.getValue(i, col) == t.valordefecto()){
                t.putValue(i, col) = jug;
                colocada = true;
            }
        }
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

string Tablero::tablerotostring(){
    string tablero = t.matriztostring();
    return tablero;
}

void Tablero::inicializarTablero(int newtam){
    if(newtam > 0){
        t.resize(newtam, newtam);
    }
}

int Tablero::turno(){
    int id1 = 0;
    int id2 = 0;
    int jug = 0;
    int i = 0, j = 0; 
    
    for(i; i < t.numfilas(); i++){
        for(j; j < t.numcolumnas(); j++){
            if(t.getValue(i,j) == 1){
                id1++;
            }
            if(t.getValue(i,j) == 2){
                id2++;
            }
        }
    }
    
    if(id1 < id2){
        return 1;
    }
    else{
        return 2;
    }
    
    return jug;
}

void Tablero::save(string fichero){
    ofstream fo;
    fo.open(fichero);
    if(fo.is_open()){
        fo <<  "#partida conectaN" << endl << "#ids jugadores: \n1 2" << endl << "#Turno del jugador:\n" << turno() <<
                endl << "#Tamaño: " << t.numcolumnas() << endl << "#N: " << Ntowin << endl << "#Tablero:\n" << t.matriztostring();
    }
    else {
        cout << "No se pudo abrir el archivo: " << fichero << endl;
    }
}

void Tablero::load(string fichero) {
    ifstream fi(fichero);
    if (fi.is_open()) {
        string line;
        int tamanio, aux;

        while (getline(fi, line)) {
            if (line.find("#Tamaño: ") != string::npos) {
                size_t pos = line.find(":") + 1;
                while (pos < line.length() && !isdigit(line[pos])) {
                    pos++;
                }
                tamanio = 0;
                while (pos < line.length() && isdigit(line[pos])) {
                    tamanio = tamanio * 10 + (line[pos] - '0');
                    pos++;
                }
                t.resize(tamanio, tamanio);
                //cout << "tamaño de t: " << tamanio << endl;
            }
            else if (line.find("#N:") != string::npos) {
                size_t pos = line.find(":") + 1;
                while (pos < line.length() && !isdigit(line[pos])) {
                    pos++;
                }
                aux = 0;
                while (pos < line.length() && isdigit(line[pos])) {
                    aux = aux * 10 + (line[pos] - '0');
                    pos++;
                }
            } 
            else if (line.find("#Tablero:") != string::npos) {
                int i = 0;
                while (i < tamanio && getline(fi, line)) {
                    int j = 0;
                    for (char c : line) {
                        if (isdigit(c)) {
                            t.putValue(i, j++) = c - '0'; 
                        }
                    }
                    i++;
                }
            }
        }
        tam = tamanio;
        Ntowin = aux;
        fi.close();
    } 
    else {
        cout << "No se pudo abrir el archivo: " << fichero << endl;
    }
}
