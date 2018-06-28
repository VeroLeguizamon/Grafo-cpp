#include "Arista.h"
using namespace std;

Arista::Arista(unsigned int peso) {
	this->peso = peso;
	this->adyacente = NULL;
	this->siguiente = NULL;
}

void Arista::cambiarAdyacente(Vertice* nuevoOrigen) {
	this->adyacente = nuevoOrigen;
}
void Arista::cambiarSiguiente(Arista* nuevaArista) {
	this->siguiente = nuevaArista;
}
Arista::Arista(unsigned int peso, Vertice* destino) {
	this->peso = peso;
	this->adyacente = destino;
	this->siguiente = NULL;
}

Arista::~Arista(){

}
