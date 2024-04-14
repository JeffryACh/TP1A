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

/*
	Struct Nodo, contiene los siguientes atributos:
	+ Vehiculo* carro -> puntero a un objeto de tipo Vehiculo
	+ bool ocupado -> indica si el espacio está ocupado o no
	+ Nodo* next -> puntero al siguiente nodo
*/
typedef struct Nodo {
	Vehiculo* carro;
	bool ocupado;
	Nodo* next;
}Nodo;

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
		bool existeVehiculo(string placa);
		bool estaLleno();
};

#endif // PARQUEOAUTOMATICO_H