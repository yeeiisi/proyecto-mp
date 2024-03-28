/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   MatrizEnteros.h
 * Author: Usuario
 *
 * Created on 20 de febrero de 2024
 */

#ifndef MATRIZENTEROS_H
#define MATRIZENTEROS_H
#include <string>
using namespace std;
class MatrizEnteros {
public: 
    /**@brief Inicializa la clase MatrizEnteros
        @param fil Número de filas de la matriz.
     * @param col Número de columnas de la matriz.
     * @param def valor por defecto de la matriz (de inicialización). 
     */
    MatrizEnteros(int fil=7, int col=7, int def=0);
    /**@brief dejar vacío*/
    MatrizEnteros(const MatrizEnteros& orig);
    /**@brief dejar vacío*/
    ~MatrizEnteros();
    /**@brief Devuelve un string que contiene la matriz. Se usará
     * \n al final de cada fila y se dejará un espacio entre los elementos.
     * Ejemplo (matriz de 2 filas y 5 columnas:
     * 1 2 3 4 5 \n 9 8 7 6 4 \n
     * Cuando se imprima con cout se mostrará:
     * 1 2 3 4 5
     * 9 8 7 6 4
     */
    string matriztostring();
    
    /**
     * @brief Devuelve el número de filas de la matriz
     */
    int numfilas();
    /**
     * @brief Devuelve el número de columnas de la matriz
     * @return 
     */
    int numcolumnas();
    
    /**
     * @brief Modifica el valor por defecto. Si se usa con una matriz
     * llena debe de dejar los valores que no sean el antiguo valor por defecto sin modificar. 
     * @param nuevodef nuevo valor por defecto.
     * Ejemplo:
     * valor por defecto: 0
     * 0 0 0 0 1 
     * 0 0 0 0 1
     * 0 0 2 0 1
     * modificarValorporDefecto(-1)
     * -1 -1 -1 -1 1
     * -1 -1 -1 -1 1
     * -1 -1 2 -1 -1
     */
    void modificarValorporDefecto(int nuevodef);
    
    /**
     * @brief Devuelve una referencia a un valor de la matriz lo que permite 
     * su modificación
     * @param fil número de fila.
     * @param col número de columna.
     * Ejemplo de uso:
     * 1 2 3 
     * 4 5 6
     * 7 8 9
     *  m.putValue(1,1) = 4
     * 1 2 3 
     * 4 4 6
     * 7 8 9
     */
    int & putValue(int fil, int col);
    
    /**
     * @brief Devuelve un valor de la matriz
     * @param fil
     * @param col
     * @return el valor de esa posición de la matriz
     */
    int getValue(int fil, int col);
    
    /**
     * @brief Devuelve cuál es el valor por defecto o de vacío de la matriz
     * @return 
     */
    int valordefecto();
    /**
     * @brief Todos los valores de la matriz pasan a ser el valor por defecto
     * (elimina la información). 
     */
    void inicializarMatriz();
    
    /**
     * @brief Modifica el tamaño de la matriz. Si la nueva matriz es más grande
     * que la original entonces se conservan los valores. Si es más chica se borra
     * la información.  
     * @param newf nuevo tamaño de fila
     * @param newc nuevo tamaño de columna
     */
    void resize(int newf, int newc);
private:
    const static int MAX = 100;
    int m[MAX][MAX];
    int filas;
    int columnas;
    int defecto = 0;
};

#endif /* MATRIZENTEROS_H */

