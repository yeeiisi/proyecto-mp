/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Partida.h
 * Author: usuario
 *
 * Created on 2 de junio de 2024, 18:36
 */

#ifndef PARTIDA_H
#define PARTIDA_H
#include "ConjuntoJugadores.h"
#include "Tablero.h"
#include <iostream>
using namespace std;

class Partida {
public:
    /*
     * @brief Constructor por parámetros
     */
    Partida(Tablero & newtab, ConjuntoJugadores & newjug);
    
    /*
     * @brief Constructor de copia
     */
    Partida(const Partida & orig);
    
    /*
     * @brief Destructor
     */
    ~Partida();
    
    /*
     * @brief Ejecuta las acciones relativas al turno de un jugador
     */
    void turno();
    
    /*
     * @brief Inicializa las variables jug1, jug2 y turnoactual 
     * del objeto Partida. El turno lo comienza el primer jugador (jug1)
     */
    void inicializaPartida(int newjug1, int newjug2);
    
    /*
     * @brief Almacena los resultados de la competición en un 
     * fichero en memoria. Hace una llamada al método save de 
     * la clase ConjuntoJugadores
     */
    void save(string file);
    
    /*
     * @brief Rellena las variables del objeto ConjuntoJugadores 
     * de partida con los datos de un fichero de competición. 
     * Hace una llamada al método load de la clase ConjuntoJugadores
     */
    void load(string file); 
    
    /*
     * @brief Este método arranca la partida. Llama reiteradamente al 
     * método turno hasta que uno de los jugadores finalmente gana la partida. 
     * Entonces, el método llama a apuntarPartida, 
     * método de ConjuntoJugadores, para anotar los resultados del enfrentamiento
     */
    void realizaPartida();
    
    /*
     * @brief Imprime por pantalla la matriz competición 
     * y el ranking de jugadores
     */
    void muestraResultadosCompeticion();
    
private:
    //Objeto tablero que representa el tablero de conectaN en donde están jugando los jugadores
    Tablero tab;
    //Objeto que contiene información de los jugadores que participan en el campeonato
    ConjuntoJugadores jug;
    int jug1, jug2; // ids de los jugadores que están participando en la partida
    int turnoActual; //id del jugador al que le toca introducir una ficha en el Tablero
    //Columna a leer para introducir ficha
    int columna;
};


/*
 * @brief Inicia nuvo campeonato, inicia partida entre jug1 y jug2,
 * inicia objeto ConjuntoJugadores, inicia objeto Partida a partir de Tablero
 * y ConjuntoJugadores, lleva a cabo la partida, se almacena la competición en
 *  savefile
 */
void NuevaPartida(string savefile, int numjugadores, string * nombres, 
                  string * apellidos, int jug1, int jug2, int N, int Ntowin);

/*
 * @brief Carga un campeonato, inicia nueva partia entre jug1 y jug2,
 * inicia objeto Tablero, objeto ConjuntoJugadores usando load y savefile,
 * objeto Partida, llama a inicializaPartida con jug1 y jug2,
 * lleva a cabo la partida, actualiza los datos en savefile
 */
void CargaPartida(string savefile,int jug1,int jug2,int N,int Ntowin);

#endif /* PARTIDA_H */

