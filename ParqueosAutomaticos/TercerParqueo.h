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
#ifndef TERCERPARQUEO_H
#define TERCERPARQUEO_H

#include "NodoDoble.h"
#include "ParqueoAutomatico.h"

using namespace std;

const int columnas = 2;

/*
	Clase ParqueoAutomatico, contiene los siguientes atributos:
	+ int size -> tamaño del parqueo
	+ Nodo* PrimerNodo -> puntero al primer nodo
	+ Nodo* UltimoNodo -> puntero al último nodo
*/
class TercerParqueo {
	private:
		NodoDoble* PrimerNodoDoble;
		NodoDoble* UltimoNodoDoble;
		int size;
	public:
		TercerParqueo(int size);
		~TercerParqueo();
		int CantidadDeVehiculos();
		int CantidadDeEspaciosDisponibles();
		Nodo* BuscarEspacioDisponible();
		void MeterVehiculo(Vehiculo* vehiculo);
		Vehiculo* SacarVehiculo(string id);
		void mostrarVehiculos();
		bool existeVehiculo(string placa);
		bool estaLleno();
		NodoDoble* BuscarEspacioDisponibleDoble();
		bool validarEspacioDoble(NodoDoble* nodo);
};

#endif // TERCERPARQUEO_H