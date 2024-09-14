/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tablero.h
 * Author: Usuario
 *
 * Created on 20 de febrero de 2024
 */

#ifndef TABLERO_H
#define TABLERO_H
#include "MatrizEnteros.h"
#include <string>

using namespace std;

class Tablero {
    /**
     * @class
     * - Esta clase utiliza un objeto de MatrizEnteros para 
     * implementar un tablero de conectaN.
     * - El valor por defecto es 0 y la matriz utilizada es cuadrada. Su tamaño viene determinado por tam. 
     * - Si en una casilla del tablero hay una ficha, está tendrá el id del jugador. 
     * - Si en una casilla del tablero no hay una ficha, entonces ésta tendrá valor 0
     *   que será el valor por defecto. 
     * - En el futuro implementaremos un conjunto de jugadores y cada uno tendrá su id. 
     */
public:
    /*
     * @brief Constructor por defecto
     */
    Tablero();
    /**
     * @brief constructor de la clase. El valor por defecto de la matriz es 0.  
     * @param newtam tamaño de la matriz (la matriz es cuadrada)
     * @param newNtowin cantidad de fichas en línea para ganar
     */
    Tablero(int newtam,int newNtowin);
    /**
     * @brief dejar vacío. 
     */
    Tablero(const Tablero& orig);
    /**
     * @brief quita todas las fichas del tablero. Se considera que el tablero
     * no tiene fichas si todas las casillas tienen el valor por defecto.  
     */
    void resetTablero();
    
    /**
     * @brief Cada ficha está identificada con el id del jugador. El jugador 
     * introduce la ficha en la columna y ésta baja hasta la posición
     * más baja del tablero en esa columna que no contenga ya una ficha. 
     * @param col Columna en la que se introduce la ficha. 
     * @param jug id del jugador que la introduce.
     * @return true si la inserción ha sido posible (la columna no está llena 
     * de fichas) o false en otro caso
     */
    bool introducirFicha(int col, int jug);
    /**
     * @return Devuelve true si el tablero está lleno de fichas
     * y no se puede introducir ni una más. 
     */
    bool tableroLleno();
    /**
     * dejar vacío
     */
    virtual ~Tablero();
    /**
     * @brief Imprime la matriz asociada al tablero.
     * @return un string con la matriz con la misma estructura
     * que la de la clase MatrizEnteros. 
     */
    string tablerotostring() const;
    /**
     * @brief Almacena la información del tablero con el formato descrito en el
     * guión de prácticas
     * @param file nombre del fichero. El fichero se guarda siempre en la carpeta
     * ./data (Importante: hay que crearlo a mano dentro de la carpeta de proyecto). 
     */
    void save(string file);
    /**
     * Carga los datos del Tablero de conecta N en la clase. 
     * @param file nombre del fichero dentro del directorio ./data/ de la carpeta
     * del proyecto. 
     */
    void load(string file);
    /**
     * @brief Devuelve un entero con el id del jugador al que le toca.      
     * @return El id del jugador que menos fichas ha echado en el tablero. 
     */
    int turno();
    
    
    /**
     * @brief recorrer la matriz buscando el jugador ganador
     * @return devuelve el jugador ganador
     */
    int ganador();
    
    /**
     * @brief método para sobrecargar el operador =
     * @param orig objeto a copiar
     * @return devuelve una referencia al objeto
     */
    Tablero & operator=(const Tablero &orig);
    
    
    /*
     * @brief Esta función se utilizará para mostrar, 
     * en cada turno de los jugadores, cómo va evolucionando la partida
     * @return devolvemos la variable flujo con el contenido de tablero
     */
    friend std::ostream & operator<< (std::ostream & flujo, const Tablero & tab);
    
private:
    MatrizEnteros t; //Matriz de la partida
    int tam; //Tamaño del tablero
    int Ntowin; //Fichas para ganar
    /**
     * @brief Modifica el tamaño de filas y columnas del tablero. 
     * @param newtam nuevo tamaño de filas y columnas del tablero.
     */
    void inicializarTablero(int newtam);
};

#endif /* TABLERO_H */

