/*
	Autores:
	+ Jeffry Araya Ch.
	+ Gabriel Barrantes Vi.

	FechaDeCreaci�n:
	07/04/2024 16:05

	�ltimaModificaci�n:
	15/04/2024 10:20
*/

#include "SegundoParqueo.h"

/*
	Constructor de la clase SegundoParqueo
	param:
		+ int size -> tama�o del parqueo
	return:
		+ void -> no retorna nada
*/
SegundoParqueo::SegundoParqueo(int size) {
	size = size;
	for (int i = 0; i < Plantas; i++)
	{
		parqueos[i] = new ParqueoAutomatico(size);
	}
}

/*
	Destructor de la clase SegundoParqueo
	param:
		+ void -> no recibe parametros
	return:
		+ void -> no retorna nada
*/
SegundoParqueo::~SegundoParqueo() {
	for (int i = 0; i < Plantas; i++)
	{
		delete parqueos[i];
	}
}

/*
	M�todo que retorna la cantidad de veh�culos en el parqueo
	param:
		+ void -> no recibe parametros
	return:
		+ int -> retorna la cantidad de veh�culos en el parqueo
*/
int SegundoParqueo::CantidadDeVehiculos() {
	int cantidad = 0;
	for (int i = 0; i < Plantas; i++)
	{
		cantidad += parqueos[i]->CantidadDeVehiculos();
	}
	return cantidad;
}

/*
	M�todo que retorna la cantidad de espacios disponibles en el parqueo
	param:
		+ void -> no recibe parametros
	return:
		+ int -> retorna la cantidad de espacios disponibles en el parqueo
*/
int SegundoParqueo::CantidadDeEspaciosDisponibles() {
	int cantidad = 0;
	for (int i = 0; i < Plantas; i++)
	{
		cantidad += parqueos[i]->CantidadDeEspaciosDisponibles();
	}
	return cantidad;
}

/*
	M�todo que busca un espacio disponible en el parqueo
	param:
		+ void -> no recibe parametros
	return:
		+ Nodo* -> retorna un puntero al nodo que representa el espacio disponible
*/
Nodo* SegundoParqueo::BuscarEspacioDisponible() {
	for (int i = 0; i < Plantas; i++)
	{
		Nodo* espacio = parqueos[i]->BuscarEspacioDisponible();
		if (espacio != NULL)
		{
			return espacio;
		}
	}
	return NULL;
}

/*
	M�todo que mete un veh�culo en el parqueo
	param:
		+ Vehiculo* vehiculo -> puntero al veh�culo que se va a meter
	return:
		+ void -> no retorna nada
*/
void SegundoParqueo::MeterVehiculo(Vehiculo* vehiculo) {
	Nodo* espacio = BuscarEspacioDisponible();
	if (espacio != NULL)
	{
		espacio->carro = vehiculo;
		espacio->ocupado = true;
	}
	else
	{
		cout << "No hay espacios disponibles" << endl;
	}
}

/*
	M�todo que saca un veh�culo del parqueo
	param:
		+ string id -> id del veh�culo que se va a sacar
	return:
		+ Vehiculo* -> retorna un puntero al veh�culo que se sac�
*/
Vehiculo* SegundoParqueo::SacarVehiculo(string id) {
	for (int i = 0; i < Plantas; i++)
	{
		Vehiculo* vehiculo = parqueos[i]->SacarVehiculo(id);
		if (vehiculo != NULL)
		{
			return vehiculo;
		}
	}
	return NULL;
}

/*
	M�todo que muestra los veh�culos en el parqueo
	param:
		+ void -> no recibe parametros
	return:
		+ void -> no retorna nada
*/
void SegundoParqueo::mostrarVehiculos() {
	for (int i = 0; i < Plantas; i++)
	{
		parqueos[i]->mostrarVehiculos();
	}
}

/*
	M�todo que verifica si un veh�culo existe en el parqueo
	param:
		+ string placa -> placa del veh�culo a buscar
	return:
		+ bool -> retorna true si el veh�culo existe, false en caso contrario
*/
bool SegundoParqueo::existeVehiculo(string placa) {
	for (int i = 0; i < Plantas; i++)
	{
		if (parqueos[i]->existeVehiculo(placa))
		{
			return true;
		}
	}
	return false;
}

/*
	M�todo que verifica si el parqueo est� lleno
	param:
		+ void -> no recibe parametros
	return:
		+ bool -> retorna true si el parqueo est� lleno, false en caso contrario
*/
bool SegundoParqueo::estaLleno() {
	for (int i = 0; i < Plantas; i++)
	{
		if (!parqueos[i]->estaLleno())
		{
			return false;
		}
	}
	return true;
}