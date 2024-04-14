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

/*
	Constructor de la clase ParqueoAutomatico
	param:
		+ int size -> tamaño del parqueo
	return:
		+ void -> no retorna nada
*/
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

/*
	Destructor de la clase ParqueoAutomatico
	param:
		+ void -> no recibe parametros
	return:
		+ void -> no retorna nada
*/
ParqueoAutomatico::~ParqueoAutomatico() {
	Nodo* AUX = PrimerNodo;
	while (AUX != NULL) 
	{
		Nodo* AUX2 = AUX->next;
		delete AUX;
		AUX = AUX2;
	}
}

/*
	Funcion que retorna la cantidad de vehiculos en el parqueo
	param:
		+ void -> no recibe parametros
	return:
		+ int -> retorna la cantidad de vehiculos en el parqueo
*/
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

/*
	Funcion que retorna la cantidad de espacios disponibles en el parqueo
	param:
		+ void -> no recibe parametros
	return:
		+ int -> retorna la cantidad de espacios disponibles
*/
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

/*
	Funcion que busca un espacio disponible en el parqueo
	param:
		+ void -> no recibe parametros
	return:
		+ Nodo* -> retorna el nodo del espacio disponible
*/
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

/*
	Funcion que busca un vehiculo en el parqueo
	param:
		+ string placa -> placa del vehiculo a buscar
	return:
		+ Nodo* -> retorna el nodo del vehiculo buscado
*/
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

/*
    Funcion que mete un vehiculo al parqueo
	param:
		+ Vehiculo* vehiculo -> vehiculo a meter
	return:
		+ void -> no retorna nada
*/
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

/*
	FUncion que saca un vehiculo del parqueo
	param:
		+ string id -> id del vehiculo a sacar
	return:
		+ Vehiculo* -> retorna el vehiculo sacado
*/
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

/*
	Funcion que muestra los vehiculos en el parqueo
	param:
		+ void -> no recibe parametros
	return:
		+ void -> no retorna nada
*/
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

/*
	Funcion que verifica si un vehiculo existe en el parqueo
	param:
		+ string placa -> placa del vehiculo a buscar
	return:
		+ bool -> retorna true si el vehiculo existe, false si no
*/
bool ParqueoAutomatico::existeVehiculo(string placa)
{
	Nodo* AUX = PrimerNodo;
	while (AUX != NULL)
	{
		if (AUX->carro->placa == placa)
		{
			return true;
		}
		AUX = AUX->next;
	}
	return false;
}

/*
	Funcion que verifica si el parqueo esta lleno
	param:
		+ void -> no recibe parametros
	return:
		+ bool -> retorna true si el parqueo esta lleno, false si no
*/
bool ParqueoAutomatico::estaLleno()
{
	return CantidadDeEspaciosDisponibles() == 0;
}