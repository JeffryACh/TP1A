/*
	Autores:
	+ Jeffry Araya Ch.
	+ Gabriel Barrantes Vi.

	FechaDeCreaci�n:
	07/04/2024 16:05

	�ltimaModificaci�n:
	10/04/2024 20:30
*/

#pragma once
#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include "User.h"

using namespace std;

typedef struct Vehiculo {
    string placa; 
    User* chofer;
}Vehicle;

#endif // VEHICULO_H