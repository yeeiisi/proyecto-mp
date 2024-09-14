/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * @Author: Jose Carlos Ibarrondo Maciá
 * @Author: Marcos Martínez Fernández
 *
 * Created on 15 de mayo de 2024, 14:49
 */

#include "Partida.h"
#include "ConjuntoJugadores.h"
#include "Tablero.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    string fichero = argv[1];
    string nuevapartida;
    int jug1 = 0, jug2 = 0;
    int tam = 0, ntowin = 0, numjugadores = 0;
    string * nombre, * apellido;
    string savefile;
    
    if (argc < 2) {
        cout << "Uso: " << argv[0] << " <configuración.txt>" << endl;
        return 1;
    }
    
    
    
    //cout << "El nombre del fichero pasado como argumento es: " << fichero << endl;
    
    ifstream archivo(fichero); // Abre el archivo para lectura

    
    if (archivo.is_open()) {
        string linea;
        getline(archivo, linea);
        size_t pos = linea.find("=");
        
        //Leemos los datos del fichero config.txt
        while (getline(archivo, linea)) {
            size_t pos = linea.find("=");
            if (pos != string::npos && pos < linea.size()) {
                string clave = linea.substr(0, pos);
                string valor = linea.substr(pos + 1);
                
                if (clave == "NUEVAPARTIDA ") {
                    nuevapartida = valor;
                } else if(clave == "FICHEROCAMPEONATO "){
                    savefile = valor;
                } else if (clave == "JUGADORESID ") {
                    jug1 = stoi(valor);
                    valor = linea.substr(pos + 3);
                    jug2 = stoi(valor);
                } else if (clave == "TAM ") {
                    tam = stoi(valor);
                } else if (clave == "NTOWIN ") {
                    ntowin = stoi(valor);
                } else if (clave == "JUGADORES ") {
                    numjugadores = stoi(valor);
                    nombre = new string[numjugadores];
                    apellido = new string[numjugadores];
                    for(int i = 0; i < numjugadores; i++){
                        archivo >> nombre[i] >> apellido[i]; 
                        //cout << nombre[i] << ", " << apellido[i];
                    }
                }
            }
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    cout << "Haciendo la lectura del fichero de configuración:" << endl
            << "\tNuevapartida: " << nuevapartida << endl
            << "\tFichero con actualización de campeonato: ./data/" << fichero << endl
            << "\tJugador1: " << jug1 << endl
            << "\tJugador2: " << jug2 << endl
            << "\tTamaño del tablero: " << tam << endl
            << "\tFichas consecutivas para ganar: " << ntowin << endl
            << "\tJugadores en el campeonato: " << numjugadores << endl;
    
    if(nuevapartida == " si"){
        cout << endl << "Creando una nueva partida" << endl;
        
        NuevaPartida(savefile, numjugadores, nombre, apellido, jug1, jug2, tam, ntowin);
    }
    else if(nuevapartida == " no"){
        cout << endl << "Cargando la partida del fichero ./data/" << fichero << endl;
        CargaPartida(savefile, jug1, jug2, tam, ntowin);
    }
    else{
        cout << "Error al leer los datos del fichero " << fichero;
        cout << endl << "Revise que esté bien configurado";
    }
    
    delete [] apellido;
    delete [] nombre;
    
    return 0;
}

