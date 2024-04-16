/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Jugador.h
 * Author: COMPLETAR
 *
 * Created on 8 de febrero de 2024
 */

/**@class Jugador
 * @brief Esta clase registra el número de partidas ganadas y jugadas
 *  de un jugador que participa en partidas de un juego con regularidad.
 *  El jugador tiene un id único que lo identifica así como su nombre y 
 *  apellidos. 
 */

#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
using namespace std;
class Jugador {
public:
    /**@brief Constructor de la clase jugador, deja los valores sin iniciar. 
     */
    Jugador();
    /**@brief Constructor de copia. Copia los datos de orig en jugador.
     *
     */
    Jugador(const Jugador& orig);
    /**@brief Jugador no usa memoria dinámica con lo que no hay que implementar
     * aquí.
     */
    virtual ~Jugador();
    
    /** @brief Devuelve los apellidos del jugador.
     * @retval Un string con los apellidos.
     */
    string getApellidos();
    
     /** @brief Devuelve el nombre del jugador.
     * @retval Un string con el nombre del jugador.
     */
    string getNombre();
    
    /** @brief Devuelve un entero con el número de partidas que ha ganado el jugador.
     * @retval Un entero con las partidas que el jugador ha ganado.
     */
    int getPartidasGanadas() const;
    
    /** @brief Devuelve un entero con el número de partidas en las que ha
     * participado el jugador.
     * @retval Un entero con las partidas que el jugador ha participado.
     */
    int getPartidasJugadas() const;
    
     /** @brief Devuelve el id del jugador.
     * @retval Devuelve el id del jugador.
     */
    int getId();
    
     /** @brief Devuelve una referencia al id del jugador.
     * @retval Referencia al id del jugador que permite su modificación.
     */
    int & setId();
    
     /** @brief Devuelve una referencia al string que contiene el nombre del jugador.
     * @retval Referencia que permite la modificación del nombre del jugador.
     */
    string & putNombre();
    
   /** @brief Devuelve una referencia al string que contiene los apellidos del jugador.
     * @retval Referencia que permite la modificación de los apellidos del jugador.
     */
    string &putApellidos();
    
  /** @brief Incrementa el número de partidas ganadas en 1.
     */
    void partidaGanada();
      /** @brief Incrementa el número de partidas jugadas en 1.
     */
    void partidaJugada();
    
     /** @brief Crea un objeto jugador con un id, nombre y apellidos determinado
     */
    Jugador(int newid, string newnombre, string newapellidos);
 
    /**  
     * @brief Operador de asignación (asigna los valores de orig al objeto). 
     * @param orig objeto jugador que se asigna.
     * @return Devuelve el objeto jugador ya asignado. 
     */
    Jugador & operator=(const Jugador & orig);
    
    /**@brief Operador de flujo de salida. Introduce en la variable ostream flujo
     * los valores de id, nombre, apellidos, partidasganadas y partidasjugadas en ese orden.  
     * Los valores están separados por espacios. 
     * @return Devuelve flujo con los valores del objeto jugador introducidos.
     */
    friend std::ostream & operator<< (std::ostream & flujo, const  Jugador & jug);
private:
    string apellidos;
    string nombre;
    int id;
    int partidasganadas=0;
    int partidasjugadas=0;
};
/*
 * A continuación se definen los operadores de comparación entre objetos Jugador. 
 * Aunque se pueden implementar con diferentes objetivos en esta práctica los 
 * implementaremos para determinar qué jugadores son los que han ganado más partidas. 
 */

/**
 * @brief Determina si 2 jugadores tienen el mismo número de partidas ganadas.
 * @param izq uno de los jugadores.
 * @param dch el otro jugador. 
 * @return true si los 2 jugadores tienen el mismo número de partidas ganadas. 
 * false en otro caso. 
 */
 bool operator==(  const Jugador & izq,  const Jugador & dch);
 
 /**
 * @brief Determina si 2 jugadores tienen distinto número de partidas ganadas.
 * @param izq uno de los jugadores.
 * @param dch el otro jugador. 
 * @return true si los 2 jugadores tienen distinto número de partidas ganadas. 
 * false en otro caso. 
 */
 bool operator!=( const Jugador & izq,  const Jugador & dch);
 
  /**
 * @brief Determina si el jug izq tiene menos partidas ganadas que el jugador dch.
 * @param izq uno de los jugadores.
 * @param dch el otro jugador. 
 * @return true si el jugador izq tiene menos partidas ganadas que el jugador dch. 
 */
 bool operator<( const Jugador &izq,  const Jugador & dch);
 
 /**
 * @brief Determina si el jug izq tiene más partidas ganadas que el jugador dch.
 * @param izq uno de los jugadores.
 * @param dch el otro jugador. 
 * @return true si el jugador izq tiene más partidas ganadas que el jugador dch. 
 */
 bool operator>( const Jugador &izq,  const Jugador & dch);
 
  /**
 * @brief Determina si el jug izq tiene menos o las mismas partidas ganadas que el jugador dch.
 * @param izq uno de los jugadores.
 * @param dch el otro jugador. 
 * @return true si el jugador izq tiene menos o las mismas partidas ganadas que el jugador dch. 
 */
 bool operator<=( const Jugador &izq, const  Jugador & dch);
 
   /**
 * @brief Determina si el jug izq tiene más o las mismas partidas ganadas que el jugador dch.
 * @param izq uno de los jugadores.
 * @param dch el otro jugador. 
 * @return true si el jugador izq tiene más o las mismas partidas ganadas que el jugador dch. 
 */
 bool operator>=( const Jugador &izq, const Jugador & dch);

#endif /* JUGADOR_H */

