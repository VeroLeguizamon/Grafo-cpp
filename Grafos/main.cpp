#include <iostream>
#include <string>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "Grafo.h"

using namespace std;

int main() {
	Grafo grafo;

	std::ifstream entrada;
	std::string rutaDeterminada = "destinos.txt";

	entrada.open(rutaDeterminada.c_str());
	if (entrada.fail()) {
		std::cout << "Ha ocurrido un error al abrir el archivo." << std::endl;
	}

	std::string linea;
	while (getline(entrada, linea)) {
		std::stringstream ss(linea);

		std::string nombreOrigen;
		getline(ss, nombreOrigen, ',');

		std::string nombreDestino;
		getline(ss, nombreDestino, ',');

		unsigned int peso;
		char cultivoAceptado;
		char separador;

		ss >> peso >> separador;
		ss >> cultivoAceptado >> separador;

		grafo.agregarVertice(nombreOrigen);
		grafo.agregarVertice(nombreDestino);
		grafo.agregarArista(peso, nombreOrigen, nombreDestino);

	}

	entrada.close();

	cout << "Mostrar Lista" << endl;
	grafo.mostrarListaDeAdyacencia();

	return 0;
}
