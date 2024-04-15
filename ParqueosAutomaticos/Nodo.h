/*
	Autores:
	+ Jeffry Araya Ch.
	+ Gabriel Barrantes Vi.

	FechaDeCreaci�n:
	07/04/2024 16:05

	�ltimaModificaci�n:
	15/04/2024 10:20
*/

#pragma once
#ifndef NODO_H
#define NODO_H

#include "Vehiculo.h"
#include "User.h"

/*
	Struct Nodo, contiene los siguientes atributos:
	+ Vehiculo* carro -> puntero a un objeto de tipo Vehiculo
	+ bool ocupado -> indica si el espacio est� ocupado o no
	+ Nodo* next -> puntero al siguiente nodo
*/
typedef struct Nodo {
	Vehiculo* carro;
	bool ocupado;
	Nodo* next;
}Nodo;

#endif // NODO_H