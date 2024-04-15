/*
	Autores:
	+ Jeffry Araya Ch.
	+ Gabriel Barrantes Vi.

	FechaDeCreación:
	07/04/2024 16:05

	ÚltimaModificación:
	14/04/2024 19:00
*/

#pragma once
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Vehiculo.h"

using namespace std;

/*
	Struct User, contiene los siguientes atributos:
	+ string name -> nombre del usuario
	+ int id -> identificación del usuario
*/
typedef struct User {
	string name;
	int id;
}User;
#endif // USER_H