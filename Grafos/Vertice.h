/*
 * Vertice.h
 *
 *  Created on: 27 jun. 2018
 *      Author: veronica
 */

#ifndef VERTICE_H_
#define VERTICE_H_
#include <iostream>
#include <string>
#include "Arista.h"
class Arista;
class Vertice{
	private:
		Vertice* siguiente;
		Arista* adyacente;
		std::string nombre;
	public:
		Vertice(std::string nombre);
		~Vertice();
		std::string obtenerNombre(){return this->nombre;}
		Vertice* obtenerSiguiente(){return this->siguiente;}
		Arista* obtenerAdyacente(){return this->adyacente;}
		void cambiarSiguiente(Vertice* nuevoSiguiente);
		void cambiarAdyacente(Arista* nuevoAdyacente);
		bool noTieneAristas();
};

#endif /* VERTICE_H_ */
