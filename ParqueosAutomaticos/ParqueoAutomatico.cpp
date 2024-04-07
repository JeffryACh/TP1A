#include "ParqueoAutomatico.h"
#include <iostream>

ParqueoAutomatico::ParqueoAutomatico(int size) {
	this->size = 0;
	this->Nodo = NULL;
}

ParqueoAutomatico::~ParqueoAutomatico() {
	while (this->Nodo != NULL) {
		Nodo* temp = this->Nodo;
		this->Nodo = this->Nodo->next;
		delete temp;
	}
}

void ParqueoAutomatico::MeterVehiculo(Vehiculo* vehiculo) {
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->user = vehiculo->chofer;
	nuevoNodo->next = this->Nodo;
	nuevoNodo->prev = NULL;
	if (this->Nodo != NULL) {
		this->Nodo->prev = nuevoNodo;
	}
	this->Nodo = nuevoNodo;
	this->size++;
}

Vehiculo ParqueoAutomatico::SacarVehiculo(int id) {
	Nodo* temp = this->Nodo;
	while (temp != NULL) {
		if (temp->user.id == id) {
			Vehiculo vehiculo = temp->user.vehiculos[0];
			if (temp->prev != NULL) {
				temp->prev->next = temp->next;
			}
			if (temp->next != NULL) {
				temp->next->prev = temp->prev;
			}
			if (temp == this->Nodo) {
				this->Nodo = temp->next;
			}
			delete temp;
			this->size--;
			return vehiculo;
		}
		temp = temp->next;
	}
}

void ParqueoAutomatico::mostrarVehiculos() {
	Nodo* temp = this->Nodo;
	while (temp != NULL) {
		cout << "Usuario: " << temp->user.name << endl;
		for (int i = 0; i < temp->user.vehiculos.size(); i++) {
			cout << "Vehiculo: " << temp->user.vehiculos[i]->placa << endl;
		}
		temp = temp->next;
	}
}

bool ParqueoAutomatico::buscarVehiculo(int id) {
	Nodo* temp = this->Nodo;
	while (temp != NULL) {
		if (temp->user.id == id) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void ParqueoAutomatico::mostrarVehiculosPorUsuario(int id) {
	Nodo* temp = this->Nodo;
	while (temp != NULL) {
		if (temp->user.id == id) {
			cout << "Usuario: " << temp->user.name << endl;
			for (int i = 0; i < temp->user.vehiculos.size(); i++) {
				cout << "Vehiculo: " << temp->user.vehiculos[i]->placa << endl;
			}
			return;
		}
		temp = temp->next;
	}
	cout << "Usuario no encontrado" << endl;
}