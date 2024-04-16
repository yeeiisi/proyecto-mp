/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jose Carlos Ibarrondo Maciá
 *
 * Created on 24 de febrero de 2024
 */

#include <cstdlib>
#include "Jugador.h"
#include "ConjuntoJugadores.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Pruebas jugador
    cout << "\n---Inicio prueba clase Jugador---\n\n";
    Jugador jug1(1,"Juan","Aguilera");
    Jugador jug2(2,"Pedro","Torres");
    Jugador jug3(3,"Lucas","Montes");
    Jugador jug4(7,"Marcos", "Polo");
    Jugador jug5(6,"Roberto", "Sanchez");
    Jugador jug6(5,"Pepe", "Ramirez");
    Jugador jug7(4,"Daniel", "Rubio");
    
    jug1.partidaJugada();
    jug1.partidaJugada();
    jug1.partidaGanada();
    jug1.partidaGanada();
    
    jug2.partidaJugada();
    jug2.partidaJugada();
    jug2.partidaGanada();
    
    jug3.partidaJugada();
    
    if(jug1 > jug2) cout << "ok1" << endl;
    if(jug1 <= jug2) cout << "NOT ok1" << endl;
    if(jug3 < jug2) cout << "ok2" << endl;
    if(jug3 >= jug2) cout << "NOT ok 2" << endl;
    if(jug1 != jug2) cout << "ok3" << endl;
    if(jug1 == jug2) cout << "NOT ok 3" << endl;    
    
    cout << jug1 << endl;
    cout << jug2 << endl;
    cout << jug3 << endl;
    cout << jug4 << endl << endl;
    
    Jugador jug8=jug2;
    cout << jug8 << endl;
    jug8 = jug3 = jug3;
    cout << jug8 << endl << endl;
     
    
    
    //Pruebas conjuntoJugadores
    cout << "\n---Inicio prueba clase conjuntoJugadores---\n\n";
    
    cout << "--Primera prueba:--" << endl; 
    ConjuntoJugadores conj;
    Jugador jug11(11,"Marta","Lopez");
    Jugador jug22(22,"Carla","Martinez");
    Jugador jug33(33,"Sofia","Fernandez");
    Jugador jug44(44,"Mercedes", "Lopez");
    conj += jug11;
    conj += jug22;
    conj += jug33;
    conj += jug44;
    cout << conj << endl;
    cout << conj[1] << endl;
    //cout << "¿Funciona?";
    Jugador pruebaasignacion = conj[2];
    cout << pruebaasignacion << endl << endl;
    
    
    cout << "--Segunda prueba:--" << endl;
    cout << "¿Funciona?";
    ConjuntoJugadores conj1, conj2, conj3;
    cout << "¿Funciona?";
    
    conj1 += jug1; //1,"Juan","Aguilera"
    conj1 += jug2; //2,"Pedro","Torres"
    conj1 += jug3; //3,"Lucas","Montes"
    conj2 += jug4; //7,"Marcos", "Polo"
    conj3 += jug5; //6,"Roberto", "Sanchez"
    conj3 += jug6; //5,"Pepe", "Ramirez"
    cout << "¿Funciona?";
    ConjuntoJugadores conj4 = conj1+conj2+conj3;
    //cout << "¿Funciona?";
    //cout << conj4 << endl;
    //cout << "¿Funciona?";
    conj4 += jug7;   //4,"Daniel", "Rubio"
    //cout << "¿Funciona?";
    cout << conj4 << endl;
    
    
    cout << "--Tercera prueba:--" << endl;
    cout << conj4.buscaJugador(2) << endl;
    cout << conj4.buscaJugador("Lucas") << endl;
    cout << conj4.buscaJugador("Daniel") << endl;
    conj4.optimizar();
    
    cout << "\n--Cuarta prueba:--" << endl;
    ConjuntoJugadores conj5 = conj4;
    cout <<  conj5 << endl;
    
    cout << "--Quinta prueba:--" << endl;
    cout << conj5.rankingJugadores() << endl;
    conj5.eliminaJugador(2);
    cout << conj5 << endl;   
    
    return 0;
}
