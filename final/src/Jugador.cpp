/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Jugador.cpp
 * Author: COMPLETAR
 * 
 * Created on 8 de febrero de 2024
 */

#include "Jugador.h"
#include <iostream>
#include <memory>
using namespace std;
Jugador::Jugador() {
    //vacio
}

Jugador::Jugador(const Jugador& orig) { 
    id = orig.id;
    apellidos = orig.apellidos;
    nombre = orig.nombre;
    partidasganadas = orig.partidasganadas;
    partidasjugadas = orig.partidasjugadas;
}

Jugador::~Jugador() {
    //vacío
}

Jugador::Jugador(int newid, string newnombre, string newapellidos){
    id = newid;
    nombre = newnombre;
    apellidos = newapellidos;
}


string Jugador::getApellidos(){
    return apellidos;
}


string Jugador::getNombre(){
    return nombre;
}


int Jugador::getPartidasGanadas() const{
    return partidasganadas;
}


int Jugador::getId(){
    return id;
}


int Jugador::getPartidasJugadas()const{
    return partidasjugadas;
}


string & Jugador::putNombre(){ 
    return nombre;
}


string & Jugador::putApellidos(){ 
    return apellidos;
}


int & Jugador::setId(){
    return id;
}


void Jugador::partidaGanada(){
    partidasganadas++;
}


void Jugador::partidaJugada(){
    partidasjugadas++;
}


Jugador & Jugador::operator=(const Jugador & orig){ 
    if (this != &orig) {
        id = orig.id;
        apellidos = orig.apellidos;
        nombre = orig.nombre;
        partidasganadas = orig.partidasganadas;
        partidasjugadas = orig.partidasjugadas;
    }
    return *this;
}


bool operator==( const Jugador & izq, const Jugador & dch){
    if(izq.getPartidasGanadas() == dch.getPartidasGanadas()){
        return true;
    }
    else{
        return false;
    }
}
 
bool operator!=( const Jugador & izq, const  Jugador & dch){
    if(izq.getPartidasGanadas() != dch.getPartidasGanadas()){
        return true;
    }
    else{
        return false;
    }
}


bool operator<( const Jugador &izq, const Jugador & dch){
    if(izq.getPartidasGanadas() < dch.getPartidasGanadas()){
        return true;
    }
    else{
        return false;
    }
}


bool operator>( const Jugador &izq, const Jugador & dch){
   if(izq.getPartidasGanadas() > dch.getPartidasGanadas()){
        return true;
    }
    else{
        return false;
    }
}


bool operator<=( const Jugador &izq,  const Jugador & dch){
      if(izq.getPartidasGanadas() <= dch.getPartidasGanadas()){
        return true;
    }
    else{
        return false;
    }
}

 
bool operator>=( const Jugador &izq, const Jugador & dch){
   if(izq.getPartidasGanadas() >= dch.getPartidasGanadas()){
        return true;
    }
    else{
        return false;
    }
}
 

std::ostream & operator << (std::ostream & flujo, const  Jugador & jug){ 
    flujo << "ID: " << jug.id << ", Nombre: " << jug.nombre << ", Apellidos: " << jug.apellidos 
          << ", Partidas Ganadas: " << jug.partidasganadas << ", Partidas Jugadas: " << jug.partidasjugadas;
    return flujo;
}
