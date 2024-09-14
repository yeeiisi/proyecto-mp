/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Tablero.h"
#include "Partida.h"
#include <iostream>

using namespace std;

Partida::Partida(Tablero& newtab, ConjuntoJugadores& newjug){
    tab = newtab;
    jug = newjug;
    jug1 = jug2 = turnoActual = 0;
    inicializaPartida(jug1,jug2);
}

Partida::Partida(const Partida & orig){
    tab = orig.tab;
    jug = orig.jug;
    jug1 = orig.jug1;
    jug2 = orig.jug2;
    turnoActual = orig.turnoActual;
    inicializaPartida(jug1,jug2);
}

Partida::~Partida(){
    
}

void Partida::turno(){
    cout << endl << "Jugador con el id " << turnoActual << " escoge una columna para introducir la ficha: ";
    cout << endl << tab;
    cin >> columna;
    if(tab.introducirFicha(columna, turnoActual)){
        if(turnoActual == jug1){
            turnoActual = jug2;
        }
        else{
            turnoActual = jug1;
        }
    }
    
}

void Partida::inicializaPartida(int newjug1, int newjug2){
    jug1 = newjug1;
    jug2 = newjug2;
    turnoActual = jug1;
}

void Partida::save(string file){
    ofstream fo;
    fo.open("./data/" + file);
    
    if(fo.is_open()){

        jug.save(file);
              
        
        fo.close();
    }
    else{
        cout << "No se pudo abrir el archivo: " << file << endl;
    }
}

void Partida::load(string file){
    ifstream fi;
    fi.open("./data/" + file);
    
    if(fi.is_open()){

        jug.load(file);
              
        
        fi.close();
    }
    else{
        cout << "No se pudo abrir el archivo: " << file << endl;
    }
}

void Partida::realizaPartida(){
    cout << endl;
    muestraResultadosCompeticion();
    
    
    while(tab.ganador() == 0){
        turno();
    }
    if(tab.ganador() > 0){
        cout << endl << tab << endl;
        cout << "El ganador es el jugador con el id: " << tab.ganador() << endl;
        if(tab.ganador() == jug1){
            jug.apuntaPartida(jug1 -1,jug2 -1);
        }
        else{
            jug.apuntaPartida(jug2 -1,jug1 -1);
        }
        muestraResultadosCompeticion();
    }
    else{
        cout << endl << "no se suman victorias a nadie" << endl;
        muestraResultadosCompeticion();
    }
}

void Partida::muestraResultadosCompeticion(){
    cout << jug.esquemaCompeticion() << endl << jug.rankingJugadores();
}

void NuevaPartida(string savefile, int numjugadores, string * nombres, 
                  string * apellidos, int jug1, int jug2, int N, int Ntowin){
    
    ConjuntoJugadores jugadores(numjugadores, nombres, apellidos);
    
    Tablero tablero(N, Ntowin);
    
    Partida partida(tablero, jugadores);
    
    partida.inicializaPartida(jug1, jug2);
    
    partida.realizaPartida();
    
    partida.save(savefile);
}

void CargaPartida(string savefile,int jug1,int jug2,int N,int Ntowin){
    
    Tablero tablero(N, Ntowin);
    
    ConjuntoJugadores jug;
    
    jug.load(savefile);
    
    Partida partida(tablero, jug);
    
    partida.inicializaPartida(jug1,jug2);
    
    partida.realizaPartida();
    
    jug.save(savefile);
    
    partida.save(savefile);
}
