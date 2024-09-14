/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   conjuntoJugadores.cpp
 * Author: COMPLETAR
 * 
 * Created on 8 de febrero de 2024
 */

#include "ConjuntoJugadores.h"
#include <stdexcept>
#include <iostream>

using namespace std;
ConjuntoJugadores::ConjuntoJugadores(int k) { 
    if(k > 0){
        tamreservado = k;
        numjugadores = 0;
        vectorJugadores = new Jugador[tamreservado];
        competicion.reservarMemoria(k,k);  
        competicion.inicializarMatriz();
    }
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
    
    if((newtam > tamreservado) && (newtam > 0)){
        Jugador * vectorAux = new Jugador[newtam];
        for(int i = 0; i < numjugadores; i++){
            vectorAux[i] = vectorJugadores[i];
        }
    
    delete[] vectorJugadores;
    vectorJugadores = vectorAux;
    tamreservado = newtam;
    
    competicion.resize(newtam);
    }
}

ConjuntoJugadores::ConjuntoJugadores(const ConjuntoJugadores& orig){ 
    tamreservado = orig.tamreservado;
    numjugadores = orig.numjugadores;
    vectorJugadores = new Jugador[tamreservado];
    
    for(int i = 0; i < numjugadores; i++){
        vectorJugadores[i] = orig[i];
    }
    
    competicion.resize(orig.numjugadores);
    competicion = orig.competicion;
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
    if((i >= 0) && (i <= numjugadores)){
        return vectorJugadores[i];
    }
    else {
        throw out_of_range("Índice fuera de rango");
    }
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
    lista = "RANKING DE JUGADORES\n";
    float porcentaje1, porcentaje2;

    // Creamos una copia del vector de jugadores
    Jugador* copiaJugadores = new Jugador[numjugadores];
    for (int i = 0; i < numjugadores; i++) {
        copiaJugadores[i] = vectorJugadores[i];
    }

    // Ordenamos la copia por porcentaje
    for (int i = 0; i < numjugadores - 1; i++) {
        for (int j = 0; j < numjugadores - i - 1; j++) {
            if (copiaJugadores[j].getPartidasJugadas() != 0) {
                porcentaje1 = (float)copiaJugadores[j].getPartidasGanadas() / copiaJugadores[j].getPartidasJugadas();
            } else {
                porcentaje1 = 0.0;
            }
            if (copiaJugadores[j + 1].getPartidasJugadas() != 0) {
                porcentaje2 = (float)copiaJugadores[j + 1].getPartidasGanadas() / copiaJugadores[j + 1].getPartidasJugadas();
            } else {
                porcentaje2 = 0.0;
            }
            if (porcentaje1 < porcentaje2) {
                swap(copiaJugadores[j], copiaJugadores[j + 1]);
            }
        }
    }

    // Generamos la lista con la copia ordenada
    for (int i = 0; i < numjugadores; i++){
        lista += copiaJugadores[i].getNombre() + " ";
        lista += copiaJugadores[i].getApellidos() + " ";
        float porcentaje;
        if (copiaJugadores[i].getPartidasJugadas() != 0) {
            porcentaje = (float)copiaJugadores[i].getPartidasGanadas() / copiaJugadores[i].getPartidasJugadas();
        } else {
            porcentaje = 0.0;
        }
        lista += to_string(porcentaje) + "\n";
    }

    // Liberamos la memoria de la copia
    delete[] copiaJugadores;

    return lista;
}


ConjuntoJugadores & ConjuntoJugadores::operator=(const ConjuntoJugadores & orig){
    if (this == &orig) {
        return *this;
    }
    competicion = orig.competicion;

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
    competicion.resize(n);
}

string ConjuntoJugadores::esquemaCompeticion(){
    string resultado;
    resultado = "MATRIZ JUGADOR X JUGADOR\n";
    /*cout << competicion.matriztostring(); 
     * no funcionaría porque el matriztostring es una función constante, deberíamos 
     * arreglarlo para que funcionase, cambiando el que la función deje de ser constante
     */
    
    for(int i = 0; i < competicion.numfilas(); i++){
        //int jug = i+1;
        //resultado += "Jugador " + vectorJugadores[i].getNombre() + ": ";
        for(int j = 0; j < competicion.numcolumnas(); j++){
            if(i == j){
                resultado += "- ";
            }
            else{
                resultado += to_string(competicion.getValue(i,j)) + ' ';
            }
        }
        resultado += '\n';
    }
    
    return resultado;
}

void ConjuntoJugadores::apuntaPartida(int jug1, int jug2){
    vectorJugadores[jug1].partidaGanada();
    competicion.putValue(jug1,jug2) = competicion.getValue(jug1,jug2) + 1;
    vectorJugadores[jug1].partidaJugada();
    vectorJugadores[jug2].partidaJugada();
}

void ConjuntoJugadores::save(string fichero) {
    ofstream fo;
    fo.open("./data/" + fichero);
    if (fo.is_open()) {
        
        fo << numjugadores << "\n";
        
        for(int i = 0; i < numjugadores; i++){
            fo << vectorJugadores[i].getId() << "\t"
               << vectorJugadores[i].getNombre() << "\t"
               << vectorJugadores[i].getApellidos() << "\t\t"
               << vectorJugadores[i].getPartidasGanadas() << "\t\t"
               << vectorJugadores[i].getPartidasJugadas() << "\n";
        }
        
        fo << competicion;
        
        fo.close();
    } else {
        cout << "No se pudo abrir el archivo: " << fichero << endl;
    }
}

void ConjuntoJugadores::load(string fichero) {
    ifstream fi("./data/" + fichero);
    if (fi.is_open()) {
        int id = 0, jugadas = 0, ganadas = 0, aux = 0;
        int tam;
        fi >> tam;
        numjugadores = tam;
        //cout << tam;
        string nombre, apellido;
        competicion.resize(tam);
        resize(tam);
        
        for(int aux = 0; aux < tam; aux++){
            int id, ganadas, jugadas;
            fi >> id >> nombre >> apellido >> ganadas >> jugadas;
            
            vectorJugadores[aux].setId() = id;
            vectorJugadores[aux].putNombre() = nombre;
            vectorJugadores[aux].putApellidos() = apellido;
            
            for(int i = 0; i < ganadas; i++){
                vectorJugadores[aux].partidaGanada();
            }
            for(int i = 0; i < jugadas; i++){
                vectorJugadores[aux].partidaJugada();
            }
        }
        
        for(int fil = 0; fil < tam; fil++){
            for(int col = 0; col < tam; col++){
                int mat;
                fi >> mat;
                competicion.putValue(fil,col) = mat;
            }
        }

        fi.close();
    } 
    else {
        cout << "No se pudo abrir el archivo: " << fichero << endl;
    }
}

