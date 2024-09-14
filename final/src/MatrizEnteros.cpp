/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   MatrizEnteros.cpp
 * Author: usuario
 * 
 * Created on 20 de febrero de 2024
 */

#include "MatrizEnteros.h"
#include <iostream>
using namespace std;


int MatrizEnteros::numfilas(){
    return filas;
}

int MatrizEnteros::numcolumnas(){
    return columnas;
}

void MatrizEnteros::modificarValorporDefecto(int nuevodef){
   int i, j;
    for (i = 0; i < filas; i++){
        for (j = 0; j < columnas; j++){
            if(m[i][j] == valordefecto()){
                m[i][j] = nuevodef;
            }
        }
    }
   defecto = nuevodef;
}

int & MatrizEnteros:: putValue(int fil, int col){
    int *a;
    if(((fil >= 0) && (fil < filas)) && ((col >= 0) && (col < columnas))){
        a = &m[fil][col];
    }
    return *a;
}

int MatrizEnteros::getValue(int fil, int col) const{
    if(((fil >= 0) && (fil < filas)) && ((col >= 0) && (col < columnas))){
        return m[fil][col];
    }
    return 1;
}

MatrizEnteros::MatrizEnteros(int fil, int col, int def) {
    if((fil > 0) && (col > 0)){
        filas = fil;
        columnas = col;
        defecto = def;
        reservarMemoria(filas, columnas);
        modificarValorporDefecto(def);
        inicializarMatriz();
    }
}

void MatrizEnteros::inicializarMatriz(){
    int i, j;
    for (i = 0; i < filas; i++){
        for (j = 0; j < columnas; j++){
            m[i][j] = defecto;
        }
    }
}

MatrizEnteros::MatrizEnteros(const MatrizEnteros& orig) {
    filas = orig.filas;
    columnas = orig.columnas;
    reservarMemoria(filas, columnas);
    
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            putValue(i,j) = orig.getValue(i,j);
        }    
    }
}

MatrizEnteros::~MatrizEnteros() {
    liberarMemoria();
}
string MatrizEnteros::matriztostring() const{
    string resultado;
    int i, j;
    
    for (i = 0; i < filas; i++){
        for (j = 0; j < columnas; j++){
            resultado += to_string(m[i][j]) + ' ';
        }
        resultado += '\n';
    }
    
    return resultado;
}

int MatrizEnteros::valordefecto(){
    return defecto;
}

void MatrizEnteros::resize(int newtam){
    
    if((newtam > tamreservado) && (newtam > 0)){
        int ** aux = new int * [newtam];
        for(int i = 0; i < newtam; i++){
                aux[i] = new int [newtam];
        }
        
        for(int i = 0; i < newtam; i++){
            for(int j = 0; j < newtam; j++){
                aux[i][j] = getValue(i,j);
            }
        }
    
    liberarMemoria();
    tamreservado = newtam;
    filas = newtam;
    columnas = newtam;
    m = aux;
    aux = nullptr;
    inicializarMatriz();
    }
}

void MatrizEnteros::liberarMemoria(){
    for (int i = 0; i < filas; i++){
        delete[] m[i];
    }
    delete[] m;
    tamreservado = 0;
    filas = 0;
}

void MatrizEnteros::reservarMemoria(int f, int c){
    filas = f;
    columnas = c;
    m = new int * [filas];
    for(int i = 0; i < filas; i++){
        m[i] = new int [columnas];
    }
}

MatrizEnteros & MatrizEnteros::operator=(const MatrizEnteros &orig){
    if(this == &orig){
        return *this;
    }
    else{
    filas = orig.filas;
    columnas = orig.columnas;
    defecto = orig.defecto;
    
    reservarMemoria(filas, columnas);
    
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            putValue(i,j) = orig.getValue(i,j);
        }
    }
    
    return *this;
    }
}

std::ostream & operator<< (std::ostream & flujo, const MatrizEnteros & m){
    flujo << m.matriztostring();
    return flujo;
}