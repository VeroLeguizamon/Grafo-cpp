/*
 * Arista.h
 *
 *  Created on: 27 jun. 2018
 *      Author: veronica
 */

#ifndef ARISTA_H_
#define ARISTA_H_
#include <iostream>
#include <string>
#include "Vertice.h"
class Vertice;

class Arista{
private:
	Arista* siguiente;
	Vertice* adyacente;
	unsigned int peso;
public:
	Arista(unsigned int peso);
	Arista(unsigned int peso, Vertice* destino);
	~Arista();
	Arista* obtenerSiguiente(){return this->siguiente;}
	Vertice* obtenerAdyacente(){return this->adyacente;}
	unsigned int obtenerPeso(){return this->peso;}
	void cambiarSiguiente(Arista* nuevaArista);
	void cambiarAdyacente(Vertice* nuevoOrigen);

};




#endif /* ARISTA_H_ */
