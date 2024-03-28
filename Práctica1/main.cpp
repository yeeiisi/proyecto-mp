/* 
 * File:   main.cpp
 *@author Jose Carlos Ibarrondo Maciá
 */

#include <cstdlib>
#include "Tablero.h"
#include "MatrizEnteros.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Pruebas para la clase MatrizEnteros
    cout << "Prueba para clase MatrizEnteros...:" << endl;
    MatrizEnteros a(3,4,-1);
    cout << a.matriztostring();
    //cout << "numero de filas de a: ";
    //cout << a.numfilas(),
    cout << endl;
     
    a.resize(7,7);
    cout << a.matriztostring();
    cout << endl;
     
    a.putValue(3,3) = 4;
    a.modificarValorporDefecto(8);
    cout << a.matriztostring();
    cout << endl;
     
    a.resize(2,2);
    cout << a.matriztostring();
    cout << endl;

    
    //Prueba para la clase Tablero    
    cout << "Prueba para clase Tablero...:" << endl;
    Tablero conecta(5,4);
    conecta.introducirFicha(2,1);
    conecta.introducirFicha(3,2);
    conecta.introducirFicha(1,1);
    conecta.introducirFicha(0,2);
    conecta.introducirFicha(0,1);
    conecta.introducirFicha(0,2);
    conecta.introducirFicha(0,1);
    conecta.introducirFicha(1,2);
    conecta.introducirFicha(1,1);
    conecta.introducirFicha(4,2);
    conecta.introducirFicha(4,1);
    conecta.introducirFicha(4,2);
    conecta.introducirFicha(4,1);
    cout << conecta.tablerotostring() << endl;
    cout << "Turno de: " << conecta.turno() << endl;  
    
    conecta.save("./data/partida.txt");
    cout << "Partida guardada"  << endl << endl;
    
    Tablero conectacarga(3,3);
    
    conectacarga.load("./data/partida.txt");
    cout << conectacarga.tablerotostring() << endl;
    cout << "carga realizda" << endl;
    
    return 0;
}

