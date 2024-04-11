/*
	Autores:
	+ Jeffry Araya Ch.
	+ Gabriel Barrantes Vi.

	FechaDeCreación:
	07/04/2024 16:05

	ÚltimaModificación:
	10/04/2024 20:30
*/

#include "ParqueoAutomatico.h"
#include <iostream>

using namespace std;

ParqueoAutomatico::ParqueoAutomatico(int size) {
	size = size;
	for (int i = 0; i < size; i++) 
	{
		Nodo* nuevoNodo = new Nodo();
		nuevoNodo->carro = NULL;
		nuevoNodo->ocupado = false;
		if (i == 0) 
		{
			PrimerNodo = nuevoNodo;
			UltimoNodo = nuevoNodo;
		}
		else 
		{
			UltimoNodo->next = nuevoNodo;
			UltimoNodo = nuevoNodo;
		}
	}
}

ParqueoAutomatico::~ParqueoAutomatico() {
	Nodo* AUX = PrimerNodo;
	while (AUX != NULL) 
	{
		Nodo* AUX2 = AUX->next;
		delete AUX;
		AUX = AUX2;
	}
}

int ParqueoAutomatico::CantidadDeVehiculos() {
	Nodo* AUX = PrimerNodo;
	int contador = 0;
	while (AUX != NULL)
	{
		if (AUX->ocupado)
 {
			contador++;
		}
		AUX = AUX->next;
	}
	return contador;
}

int ParqueoAutomatico::CantidadDeEspaciosDisponibles() {
	Nodo* AUX = PrimerNodo;
	int contador = 0;
	while (AUX != NULL) 
	{
		if (!AUX->ocupado)
		{
			contador++;
		}
		AUX = AUX->next;
	}
	return contador;
}

Nodo* ParqueoAutomatico::BuscarEspacioDisponible() {
	Nodo* AUX = PrimerNodo;
	while (AUX != NULL) 
	{
		if (!AUX->ocupado)
		{
			return AUX;
		}
		AUX = AUX->next;
	}
	return NULL;
}

Nodo* ParqueoAutomatico::BuscarVehiculo(string placa) {
	Nodo* AUX = PrimerNodo;
	while (AUX != NULL)
	{
		if (AUX->carro->placa == placa)
		{
			return AUX;
		}
		AUX = AUX->next;
	}
	return NULL;
}

void ParqueoAutomatico::MeterVehiculo(Vehiculo* vehiculo)
{
	if (CantidadDeEspaciosDisponibles() > 0)
	{
		Nodo* espacio = BuscarEspacioDisponible();
		espacio->carro = vehiculo;
		espacio->ocupado = true;
	}
	else
	{
		cout << "No hay espacios disponibles" << endl;
	}
}

Vehiculo* ParqueoAutomatico::SacarVehiculo(string id) 
{
	Nodo* espacio = BuscarVehiculo(id);
	if (espacio != NULL)
	{
		Vehiculo* vehiculo = espacio->carro;
		espacio->carro = NULL;
		espacio->ocupado = false;
		return vehiculo;
	}
	else
	{
		cout << "Vehiculo no encontrado" << endl;
	}
}

void ParqueoAutomatico::mostrarVehiculos() 
{
	Nodo* AUX = PrimerNodo;
	while (AUX != NULL)
	{
		if (AUX->ocupado)
		{
			cout << "Chofer: " << AUX->carro->chofer->name << endl;
			cout << "ID del Chofer: " << AUX->carro->chofer->id << endl;
			cout << "Placa: " << AUX->carro->placa << endl;
		}
		AUX = AUX->next;
	}
}