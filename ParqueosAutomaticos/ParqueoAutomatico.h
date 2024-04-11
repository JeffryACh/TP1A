/*
	Autores:
	+ Jeffry Araya Ch.
	+ Gabriel Barrantes Vi.

	FechaDeCreación:
	07/04/2024 16:05

	ÚltimaModificación:
	10/04/2024 20:30
*/

#pragma once
#ifndef PARQUEOAUTOMATICO_H
#define PARQUEOAUTOMATICO_H

#include "Vehiculo.h"
#include "User.h"

typedef struct Nodo {
	Vehiculo* carro;
	bool ocupado;
	Nodo* next;
}Nodo;

class ParqueoAutomatico {
	private:
		Nodo* PrimerNodo;
		Nodo* UltimoNodo;
		int size;

		int CantidadDeVehiculos();
		int CantidadDeEspaciosDisponibles();
		Nodo* BuscarEspacioDisponible();
		Nodo* BuscarVehiculo(string placa);
	public:
		ParqueoAutomatico(int size);
		~ParqueoAutomatico();
		void MeterVehiculo(Vehiculo* vehiculo);
		Vehiculo* SacarVehiculo(string id);
		void mostrarVehiculos();
};

#endif // PARQUEOAUTOMATICO_H