/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   conjuntoJugadores.cpp
 * Author: Jose Carlos Ibarrondo Maciá
 * 
 * Created on 8 de febrero de 2024
 */

#include "ConjuntoJugadores.h"
#include <iostream>

using namespace std;
ConjuntoJugadores::ConjuntoJugadores(int k) { 
    tamreservado = k;
    numjugadores = 0;
    vectorJugadores = new Jugador[tamreservado];
}

ConjuntoJugadores::~ConjuntoJugadores() { 
    delete[] vectorJugadores;
}

ConjuntoJugadores & ConjuntoJugadores::operator+=(const Jugador& newjug){
    if (numjugadores >= tamreservado) {
        resize(tamreservado + 5); //Aumentamos el tamaño en 1
    }
    
    vectorJugadores[numjugadores] = newjug;
    numjugadores++; //Actualizamos el numjugadores
    return *this;
}

void ConjuntoJugadores::resize(int newtam){
    if(newtam > tamreservado){
        Jugador * vectorAux = new Jugador[newtam];
        for(int i = 0; i < numjugadores; i++){
            vectorAux[i] = vectorJugadores[i];
        }
    
    delete[] vectorJugadores;
    vectorJugadores = vectorAux;
    tamreservado = newtam;
    }
}

ConjuntoJugadores::ConjuntoJugadores(const ConjuntoJugadores& orig){ 
    tamreservado = orig.tamreservado;
    numjugadores = orig.numjugadores;
    vectorJugadores = new Jugador[tamreservado];
    
    for(int i = 0; i < numjugadores; i++){
        vectorJugadores[i] = orig[i];
    }
}
    
void swap(Jugador* a, Jugador* b) { //Función para hacer el intercambio
    if (a != b) {
        Jugador temp = *a;
        *a = *b;
        *b = temp;
    }
}

void ConjuntoJugadores::ordenaporId(){
    for (int i = 0; i < numjugadores - 1; i++) {
        for (int j = 0; j < numjugadores - i - 1; ++j) {
            if (vectorJugadores[j].getId() > vectorJugadores[j + 1].getId()) {
                swap(vectorJugadores[j], vectorJugadores[j + 1]);
            }
        }
    }
}
    

Jugador & ConjuntoJugadores::operator[](int i) const{
    return vectorJugadores[i];
}


ConjuntoJugadores operator+( const ConjuntoJugadores & left, const ConjuntoJugadores & right){
    ConjuntoJugadores total(left.numjugadores + right.numjugadores);

    for (int i = 0; i < left.numjugadores; i++) {
        total += left.vectorJugadores[i];
    }

    for (int i = 0; i < right.numjugadores; i++) {
        total += right.vectorJugadores[i];
    }

    return total;
}

std::ostream & operator<< (std::ostream & flujo, const ConjuntoJugadores & conjug){
    for(int i = 0; i < conjug.numjugadores; i++){    
        if (conjug.vectorJugadores && i < conjug.numjugadores) {
            flujo << conjug.vectorJugadores[i] << "\n";
        }
    }
    return flujo;
}
   

int ConjuntoJugadores::buscaJugador(int jugid){
    int i = 0;
    while((jugid != vectorJugadores[i].getId()) && (i < numjugadores)){
        i++;
    }
    if(i >= numjugadores){
        i = -1;
    }
    return i;
}

int ConjuntoJugadores::buscaJugador(string nombre){
    int i = 0;
    while((nombre != vectorJugadores[i].getNombre()) && (i < numjugadores)){
        i++;
    }
    if(i >= numjugadores){
        i = -1;
    }
    return i;
}
    
void ConjuntoJugadores::optimizar(){     
    tamreservado = numjugadores; 
    Jugador *vectorAux = new Jugador[tamreservado]; 
    
    for (int i = 0; i < numjugadores; i++) {
        vectorAux[i] = vectorJugadores[i];
    }
    
    delete[] vectorJugadores;
    
    vectorJugadores = vectorAux; 
}


void ConjuntoJugadores::eliminaJugador(int jugid){
    int posJugador = buscaJugador(jugid);
    
    if (posJugador != -1 && posJugador < numjugadores) {
        for(int i = posJugador; i < numjugadores - 1; i++){
            vectorJugadores[i] = vectorJugadores[i +1];
        }
        numjugadores--;
    }
}
    
string ConjuntoJugadores::rankingJugadores(){
    string lista;
    float porcentaje1, porcentaje2;
    
    //Ordenamos por porcentaje
    for (int i = 0; i < numjugadores - 1; i++) {
        for (int j = 0; j < numjugadores - i - 1; j++) {
            if (vectorJugadores[j].getPartidasJugadas() != 0) {
                porcentaje1 = (float)vectorJugadores[j].getPartidasGanadas() / vectorJugadores[j].getPartidasJugadas();
            } else {
                porcentaje1 = 0.0;
            }
            if (vectorJugadores[j + 1].getPartidasJugadas() != 0) {
                porcentaje2 = (float)vectorJugadores[j + 1].getPartidasGanadas() / vectorJugadores[j + 1].getPartidasJugadas();
            } else {
                porcentaje2 = 0.0;
            }
            if (porcentaje1 < porcentaje2) {
                swap(vectorJugadores[j], vectorJugadores[j + 1]);
            }
        }
    }
    
    for (int i = 0; i < numjugadores; i++){
        lista += to_string(vectorJugadores[i].getId()) + " ";
        lista += vectorJugadores[i].getNombre() + " ";
        lista += vectorJugadores[i].getApellidos() + " ";
        if (vectorJugadores[i].getPartidasJugadas() != 0) {
            lista += to_string(vectorJugadores[i].getPartidasGanadas() / vectorJugadores[i].getPartidasJugadas()) + " ";
        } else {
            lista += "0 ";
        }
        float porcentaje;
        if (vectorJugadores[i].getPartidasJugadas() != 0) {
            porcentaje = (float)vectorJugadores[i].getPartidasGanadas() / vectorJugadores[i].getPartidasJugadas();
        } else {
            porcentaje = 0.0;
        }
        lista += to_string(porcentaje) + "\n";
    }
    return lista;
}

ConjuntoJugadores & ConjuntoJugadores::operator=(const ConjuntoJugadores & orig){
    if (this == &orig) {
        return *this;
    }

    delete[] vectorJugadores;

    numjugadores = orig.numjugadores;
    tamreservado = orig.tamreservado;

    vectorJugadores = new Jugador[tamreservado];

    for(int i = 0; i < numjugadores; i++) {
        vectorJugadores[i] = orig.vectorJugadores[i];
    }

    return *this;
}


ConjuntoJugadores::ConjuntoJugadores(int n, string * nombres, string * apellidos){
    tamreservado = n;
    numjugadores = n;
    vectorJugadores = new Jugador[tamreservado];
    
    for(int i = 0; i < n; i++){
        vectorJugadores[i].putNombre() = nombres[i];
        vectorJugadores[i].putApellidos() = apellidos[i];
        vectorJugadores[i].setId() = i + 1;
    }
}
