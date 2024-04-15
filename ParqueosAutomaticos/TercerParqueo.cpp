/*
	Autores:
	+ Jeffry Araya Ch.
	+ Gabriel Barrantes Vi.

	FechaDeCreación:
	07/04/2024 16:05

	ÚltimaModificación:
	15/04/2024 10:20
*/

#include "TercerParqueo.h"

/*
	Constructor de la clase TercerParqueo
	param:
		+ int size -> tamaño del parqueo
	return:
		+ void -> no retorna nada
*/
TercerParqueo::TercerParqueo(int size) {
	size = size;
	for (int i = 0; i < size; i++)
	{
		User* user = new User();
		Vehiculo* vehiculo = new Vehiculo();
		vehiculo->chofer = user;
		for (int j = 0; j < columnas; j++)
		{
			NodoDoble* nuevoNodo = new NodoDoble();
			nuevoNodo->carro[j] = vehiculo;
			nuevoNodo->ocupado = false;

		}
	}
}

/*
	Destructor de la clase TercerParqueo
	param:
		+ void -> no recibe parametros
	return:
		+ void -> no retorna nada
*/
TercerParqueo::~TercerParqueo() {
	while (PrimerNodoDoble != NULL)
	{
		NodoDoble* AUX = PrimerNodoDoble;
		PrimerNodoDoble = PrimerNodoDoble->next;
		delete AUX;
	}
}

/*
	Método que retorna la cantidad de vehículos en el parqueo
	param:
		+ void -> no recibe parametros
	return:
		+ int -> retorna la cantidad de vehículos en el parqueo
*/
int TercerParqueo::CantidadDeVehiculos() {
	int cantidad = 0;
	
}

/*
	Método que retorna la cantidad de espacios disponibles en el parqueo
	param:
		+ void -> no recibe parametros
	return:
		+ int -> retorna la cantidad de espacios disponibles en el parqueo
*/
int TercerParqueo::CantidadDeEspaciosDisponibles() {
	int cantidad = 0;
	
}

/*
	Método que busca un espacio disponible en el parqueo
	param:
		+ void -> no recibe parametros
	return:
		+ Nodo* -> retorna un puntero al nodo que representa el espacio disponible
*/
Nodo* TercerParqueo::BuscarEspacioDisponible() {
	
	return NULL;
}

/*
	Metodo que mete un vehiculo en el parqueo
	param:
		+ Vehiculo* vehiculo -> puntero al vehiculo que se va a meter
	return:
		+ void -> no retorna nada
*/
void TercerParqueo::MeterVehiculo(Vehiculo* vehiculo) {
	
}

/*
	Método que saca un vehículo del parqueo
	param:
		+ string id -> id del vehículo a sacar
	return:
		+ Vehiculo* -> retorna un puntero al vehículo que se sacó
*/
Vehiculo* TercerParqueo::SacarVehiculo(string id) {
	
	return NULL;
}

/*
	Método que muestra los vehículos en el parqueo
	param:
		+ void -> no recibe parametros
	return:
		+ void -> no retorna nada
*/
void TercerParqueo::mostrarVehiculos() {
	
}

/*
	Método que verifica si un vehículo existe en el parqueo
	param:
		+ string placa -> placa del vehículo a buscar
	return:
		+ bool -> retorna true si el vehículo existe, false en caso contrario
*/
bool TercerParqueo::existeVehiculo(string placa) {
	
	return false;
}

/*
	Método que verifica si el parqueo está lleno
	param:
		+ void -> no recibe parametros
	return:
		+ bool -> retorna true si el parqueo está lleno, false en caso contrario
*/
bool TercerParqueo::estaLleno() {
	
	return false;
}

/*
	Método que verifica si el parqueo está vacío
	param:
		+ void -> no recibe parametros
	return:
		+ bool -> retorna true si el parqueo está vacío, false en caso contrario
*/
bool TercerParqueo::estaVacio() {
	
	return false;
}

/*
	Metodo que busca un espacio disponible en el parqueo
	param:
		+ void -> no recibe parametro
	return:
		+ NodoDoble* -> retorna un puntero al nodo que representa el espacio disponible
*/
NodoDoble* TercerParqueo::BuscarEspacioDisponibleDoble() {
	
	return NULL;
}