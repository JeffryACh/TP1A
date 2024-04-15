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
#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include "User.h"

using namespace std;

/*
	Struct Vehiculo, contiene los siguientes atributos:
	+ string placa -> placa del veh�culo
	+ User* chofer -> puntero al chofer del veh�culo
*/
typedef struct Vehiculo {
    string placa; 
    User* chofer;
}Vehicle;

#endif // VEHICULO_H