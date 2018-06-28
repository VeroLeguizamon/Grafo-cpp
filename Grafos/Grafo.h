#ifndef GRAFO_H_
#define GRAFO_H_
#include "Vertice.h"
#include "Arista.h"

class Grafo{
private:
	Vertice* primero;
	unsigned int tam;

public:
	Grafo();
	Vertice* obtenerPrimero(){return this->primero;}
	unsigned int obtenerTam(){return this->tam;}
	bool estaVacio();
	unsigned int obtenerTamanio();
	void agregarVertice(std::string nombre);
	void agregarArista(unsigned int peso, std::string nombreOrigen, std::string nombreDestino);
	Vertice* obtenerUltimo();
	bool existeOrigen(std::string nombre);
	Arista* obtenerUltimaArista(Vertice* origen);
	void mostrarListaDeAdyacencia();
	Vertice* obtenerVertice(std::string nombre);
	~Grafo();
};

#endif
