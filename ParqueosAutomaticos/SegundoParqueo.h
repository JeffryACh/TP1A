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
#ifndef SEGUNDOPARQUEO_H
#define SEGUNDOPARQUEO_H

#include "Vehiculo.h"
#include "ParqueoAutomatico.h"
#include "User.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int Plantas = 2;

/*
	Clase SegundoParqueo, este es de 2 plantas, por lo que tiene '2*n' espacios. Contiene los siguientes atributos:
	+ ParqueoAutomatico* parqueos -> puntero a un objeto de tipo ParqueoAutomatico
	+ int size -> tamaño del parqueo
*/
class SegundoParqueo {
private:
	ParqueoAutomatico* parqueos[Plantas];
	int size;
public:
	SegundoParqueo(int size);
	~SegundoParqueo();
	int CantidadDeVehiculos();
	int CantidadDeEspaciosDisponibles();
	Nodo* BuscarEspacioDisponible();
	void MeterVehiculo(Vehiculo* vehiculo);
	Vehiculo* SacarVehiculo(string id);
	void mostrarVehiculos();
	bool existeVehiculo(string placa);
	bool estaLleno();
};

#endif // SEGUNDOPARQUEO_H
