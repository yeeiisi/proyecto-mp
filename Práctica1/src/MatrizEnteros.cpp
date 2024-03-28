/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   MatrizEnteros.cpp
 * Author: Jose Carlos Ibarrondo Maciá
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
    if(((fil >= 0) && (fil < filas)) && ((col >= 0) && (col < columnas))){
        return m[fil][col];
    }
}

int MatrizEnteros::getValue(int fil, int col){
    if(((fil >= 0) && (fil < filas)) && ((col >= 0) && (col < columnas))){
        return m[fil][col];
    }
}

MatrizEnteros::MatrizEnteros(int fil, int col, int def) {
    if((fil > 0) && (col > 0)){
        filas = fil;
        columnas = col;
        defecto = def;
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
    
}

MatrizEnteros::~MatrizEnteros() {

}
string MatrizEnteros::matriztostring(){
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

void MatrizEnteros::resize(int newf, int newc){
    if((newf > 0) && (newc > 0)){    
        int nuevaMatriz[MAX][MAX];
        int i = 0, j = 0;

        for (i; i < filas; ++i) {
            for (j; j < columnas; ++j) {
                nuevaMatriz[i][j]= m[i][j];
            }
        }

        filas = newf;
        columnas = newc;

        for (i = 0; i < filas; ++i) {
            for (j = 0; j < columnas; ++j) {
                m[i][j] = nuevaMatriz[i][j];
            }
        }

        for (i = 0; i < filas; i++) {
            for (j = 0; j < columnas; j++) {
                m[i][j] = valordefecto();
            }
        }
    }
}