#include "Grafo.h"
#include <iostream>
#include <string>

using namespace std;

Grafo::Grafo() {
	this->primero = NULL;
	this->tam = 0;
}

bool Grafo::estaVacio() {
	return (this->primero == NULL);
}
unsigned int Grafo::obtenerTamanio() {
	return this->tam;
}

Vertice* Grafo::obtenerUltimo() {
	Vertice* ultimo = this->primero;
	while (ultimo->obtenerSiguiente() != NULL) {
		ultimo = ultimo->obtenerSiguiente();
	}
	return ultimo;
}
bool Grafo::existeOrigen(string nombre) {
	bool encontrado = false;
	Vertice* analizado = this->obtenerPrimero();
	while (analizado != NULL && !encontrado) {
		encontrado = (nombre == analizado->obtenerNombre());
		analizado = analizado->obtenerSiguiente();
	}
	return encontrado;
}
Arista* Grafo::obtenerUltimaArista(Vertice* origen) {
	Arista* ultima = NULL;
	if (this->existeOrigen(origen->obtenerNombre())) {
		ultima = origen->obtenerAdyacente();
		Arista* ultima = origen->obtenerAdyacente();
		if (ultima != NULL) {
			while (ultima != NULL) {
				ultima = ultima->obtenerSiguiente();
			}
		}
	}
	return ultima;
}
void Grafo::agregarVertice(string nombre) {
	if (!existeOrigen(nombre)) {
		Vertice* nuevoVertice = new Vertice(nombre);

		if (estaVacio()) {
			this->primero = nuevoVertice;
		} else {
			Vertice* ultimo = this->obtenerUltimo();
			ultimo->cambiarSiguiente(nuevoVertice);
		}
		tam++;
	}
}
Vertice* Grafo::obtenerVertice(string nombre) {
	Vertice* vertice = this->primero;
	while (vertice != NULL) {
		if (vertice->obtenerNombre() == nombre) {
			return vertice;
		}
		vertice = vertice->obtenerSiguiente();
	}
	return NULL;
}

void Grafo::agregarArista(unsigned int peso, string nombreOrigen,
		string nombreDestino) {
	Vertice* destino = this->obtenerVertice(nombreDestino);
	Vertice* origen = this->obtenerVertice(nombreOrigen);
	Arista* nuevaArista = new Arista(peso, destino);
	Arista* ultimaArista = origen->obtenerAdyacente();
	if (ultimaArista == NULL) {
		origen->cambiarAdyacente(nuevaArista);
	} else {
		ultimaArista = this->obtenerUltimaArista(origen);
		ultimaArista->cambiarSiguiente(nuevaArista);
	}
}

void Grafo::mostrarListaDeAdyacencia() {
	Vertice* vertice = this->obtenerPrimero();

	while (vertice != NULL) {
		cout << vertice->obtenerNombre() << " -> ";
		Arista* arista = vertice->obtenerAdyacente();
		while (arista != NULL) {
			cout <<"("<< arista->obtenerPeso()<<"km)"<<arista->obtenerAdyacente()->obtenerNombre() << " -> ";
			arista = arista->obtenerSiguiente();
		}
		cout << endl;
		vertice = vertice->obtenerSiguiente();
	}
}
Grafo::~Grafo() {
	Vertice* vertice = this->primero;
	while (vertice != NULL) {
		Vertice* eliminar = vertice;
		Arista* arista = eliminar->obtenerAdyacente();
		while (arista != NULL) {
			Arista* eeliminar = arista;
			arista = eeliminar->obtenerSiguiente();
			delete eeliminar;
		}
		vertice = eliminar->obtenerSiguiente();
		delete eliminar;
	}
}
