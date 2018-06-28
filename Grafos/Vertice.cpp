#include "Vertice.h"
#include <iostream>
#include <string>

using namespace std;

Vertice::Vertice(string nombre){
	this->nombre = nombre;
	this->adyacente = NULL;
	this->siguiente = NULL;
}

void Vertice::cambiarAdyacente(Arista* nuevoAdyacente){
	this->adyacente = nuevoAdyacente;
}
void Vertice::cambiarSiguiente(Vertice* nuevoSiguiente){
	this->siguiente = nuevoSiguiente;
}
bool Vertice::noTieneAristas(){
	return (this->adyacente == NULL);
}

Vertice::~Vertice(){

}
