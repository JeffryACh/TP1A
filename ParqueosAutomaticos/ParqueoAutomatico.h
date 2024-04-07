#pragma once
#ifndef PARQUEOAUTOMATICO_H
#define PARQUEOAUTOMATICO_H

#include "Vehiculo.h"
#include "User.h"

typedef struct Nodo {
	User user;
	Nodo* next;
	Nodo* prev;
};

class ParqueoAutomatico {
	private:
		Nodo* Nodo;
		int size;
	public:
		ParqueoAutomatico(int size);
		~ParqueoAutomatico();
		void MeterVehiculo(Vehiculo* vehiculo);
		Vehiculo SacarVehiculo(int id);
		void mostrarVehiculos();
		bool buscarVehiculo(int id);
		void mostrarVehiculosPorUsuario(int id);

};

#endif // PARQUEOAUTOMATICO_H