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
#ifndef PARQUEOAUTOMATICO_H
#define PARQUEOAUTOMATICO_H

#include "Vehiculo.h"
#include "User.h"
#include "Nodo.h"
#include <iostream>
#include <string>

/*
	Clase ParqueoAutomatico, contiene los siguientes atributos:
	+ Nodo* PrimerNodo -> puntero al primer nodo
	+ Nodo* UltimoNodo -> puntero al último nodo
	+ int size -> tamaño del parqueo
*/
class ParqueoAutomatico {
	private:
		Nodo* PrimerNodo;
		Nodo* UltimoNodo;
		int size;

	public:
		ParqueoAutomatico(int size);
		~ParqueoAutomatico();
		void MeterVehiculo(Vehiculo* vehiculo);
		int CantidadDeVehiculos();
		Vehiculo* SacarVehiculo(string id);
		void mostrarVehiculos();
		Nodo* BuscarEspacioDisponible();
		Nodo* BuscarVehiculo(string placa);
		int CantidadDeEspaciosDisponibles();
		bool existeVehiculo(string placa);
		bool estaLleno();
};

#endif // PARQUEOAUTOMATICO_H