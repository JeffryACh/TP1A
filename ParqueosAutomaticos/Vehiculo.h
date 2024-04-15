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
#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include "User.h"

using namespace std;

/*
	Struct Vehiculo, contiene los siguientes atributos:
	+ string placa -> placa del vehículo
	+ User* chofer -> puntero al chofer del vehículo
*/
typedef struct Vehiculo {
    string placa; 
    User* chofer;
}Vehicle;

#endif // VEHICULO_H