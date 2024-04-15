/*
	Autores:
	+ Jeffry Araya Ch.
	+ Gabriel Barrantes Vi.

	FechaDeCreación:
	07/04/2024 16:05

	ÚltimaModificación:
	15/04/2024 10:20
*/

#pragma once
#ifndef NODODOBLE_H
#define NODODOBLE_H

#include "Nodo.h"
#include <iostream>
#include <string>

/*
	Struct NodoDoble, contiene los siguientes atributos:
    + Vehiculo* carro[2] -> puntero a un arreglo de dos objetos de tipo Vehiculo
	+ bool ocupado -> indica si el espacio está ocupado o no
	+ NodoDoble* next -> puntero al siguiente nodo
	+ NodoDoble* prev -> puntero al nodo anterior
*/
typedef struct NodoDoble {
	Nodo* nodos[2];
	bool completamenteOcupado;
	NodoDoble* next;
};

#endif // NODODOBLE_H