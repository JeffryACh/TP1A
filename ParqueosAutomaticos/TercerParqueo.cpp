/*
	Autores:
	+ Jeffry Araya Ch.
	+ Gabriel Barrantes Vi.

	FechaDeCreaci�n:
	07/04/2024 16:05

	�ltimaModificaci�n:
	15/04/2024 10:20
*/

#include "TercerParqueo.h"

/*
	Constructor de la clase TercerParqueo
	param:
		+ int size -> tama�o del parqueo
*/
TercerParqueo::TercerParqueo(int size) {
	size = size;
	for (int i = 0; i < size; i++)
	{
		User* user = new User;
		Vehiculo* vehiculo = new Vehiculo;
		for (int j = 0; j < columnas; j++)
		{
			NodoDoble* nuevoNodo = new NodoDoble;
			nuevoNodo->nodos[j]->carro = vehiculo;
			nuevoNodo->nodos[j]->ocupado = false;
			nuevoNodo->nodos[j]->carro->chofer = user;
			nuevoNodo->next = NULL;
			if (i == 0 && j == 0)
			{
				PrimerNodoDoble = nuevoNodo;
				UltimoNodoDoble = nuevoNodo;
			}
			else
			{
				UltimoNodoDoble->next = nuevoNodo;
				UltimoNodoDoble = nuevoNodo;
			}
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
	M�todo que retorna la cantidad de veh�culos en el parqueo
	param:
		+ void -> no recibe parametros
	return:
		+ int -> retorna la cantidad de veh�culos en el parqueo
*/
int TercerParqueo::CantidadDeVehiculos() {
	int cantidad = 0;
	NodoDoble* AUX = PrimerNodoDoble;
	while (AUX != NULL)
	{
		for (int i = 0; i < columnas; i++)
		{
			if (AUX->nodos[i]->ocupado)
			{
				cantidad++;
			}
		}
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
int TercerParqueo::CantidadDeEspaciosDisponibles() {
	int cantidad = 0;
	NodoDoble* AUX = PrimerNodoDoble;
	while (AUX != NULL)
	{
		for (int i = 0; i < columnas; i++)
		{
			if (!AUX->nodos[i]->ocupado)
			{
				cantidad++;
			}
		}
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
NodoDoble* TercerParqueo::BuscarEspacioDisponible() 
{
	NodoDoble* AUX = PrimerNodoDoble;
	while (AUX != NULL)
	{
		for (int i = 0; i < columnas; i++)
		{
			if (!AUX->nodos[i]->ocupado)
			{
				return AUX;
			}
		}
	}

	return NULL;
}

/*
	Metodo que mete un vehiculo en el parqueo
	param:
		+ Vehiculo* vehiculo -> puntero al vehiculo que se va a meter
	return:
		+ void -> no retorna nada
*/
void TercerParqueo::MeterVehiculo(Vehiculo* vehiculo)
{
	NodoDoble* espacio = BuscarEspacioDisponible();
	if (espacio != NULL)
	{
		for (int i = 0; i < columnas; i++)
		{
			if (!espacio->nodos[i]->ocupado)
			{
				espacio->nodos[i]->carro = vehiculo;
				espacio->nodos[i]->ocupado = true;
				break;
			}
		}
	}
}

/*
	M�todo que saca un veh�culo del parqueo
	param:
		+ string id -> id del veh�culo a sacar
	return:
		+ Vehiculo* -> retorna un puntero al veh�culo que se sac�
*/
Vehiculo* TercerParqueo::SacarVehiculo(string id) 
{
	NodoDoble* AUX = PrimerNodoDoble;
	while (AUX != NULL)
	{
		for (int i = 0; i < columnas; i++)
		{
			if (AUX->nodos[i]->carro->placa == id)
			{
				Vehiculo* vehiculo = AUX->nodos[i]->carro;
				AUX->nodos[i]->carro = NULL;
				AUX->nodos[i]->ocupado = false;
				return vehiculo;
			}
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
void TercerParqueo::mostrarVehiculos() 
{
	NodoDoble* AUX = PrimerNodoDoble;
	cout << "*--------------------------------*" << endl;
	while (AUX != NULL)
	{
		for (int i = 0; i < columnas; i++)
		{
			if (AUX->nodos[i]->ocupado)
			{
				cout << "Placa: " << AUX->nodos[i]->carro->placa << endl;
				cout << "Chofer: " << AUX->nodos[i]->carro->chofer->name << endl;
				cout << "ID del Chofer: " << AUX->nodos[i]->carro->chofer->id << endl;
				cout << "--------------------------------" << endl;
			}
		}
		AUX = AUX->next;
	}
	cout << "*--------------------------------*" << endl;
}

/*
	M�todo que verifica si un veh�culo existe en el parqueo
	param:
		+ string placa -> placa del veh�culo a buscar
	return:
		+ bool -> retorna true si el veh�culo existe, false en caso contrario
*/
bool TercerParqueo::existeVehiculo(string placa) 
{
	NodoDoble* AUX = PrimerNodoDoble;
	while (AUX != NULL)
	{
		for (int i = 0; i < columnas; i++)
		{
			if (AUX->nodos[i]->carro->placa == placa)
			{
				return true;
			}
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
bool TercerParqueo::estaLleno() 
{
	NodoDoble* AUX = PrimerNodoDoble;
	while (AUX != NULL)
	{
		for (int i = 0; i < columnas; i++)
		{
			if (!AUX->nodos[i]->ocupado)
			{
				return false;
			}
		}
	}
	return true;
}

/*
	Metodo que busca un espacio disponible en el parqueo
	param:
		+ void -> no recibe parametro
	return:
		+ NodoDoble* -> retorna un puntero al nodo que representa el espacio disponible
*/
NodoDoble* TercerParqueo::BuscarEspacioDisponibleDoble() 
{
	NodoDoble* AUX = PrimerNodoDoble;
	while (AUX != NULL)
	{
		for (int i = 0; i < columnas; i++)
		{
			if (!AUX->nodos[i]->ocupado)
			{
				if (validarEspacioDoble(AUX))
				{
					return AUX;
				}
			}
		}
	}
	return NULL;
}

/*
	M�todo que valida si un espacio doble est� disponible
	param:
		+ NodoDoble* nodo -> puntero al nodo a validar
	return:
		+ bool -> retorna true si el espacio doble est� disponible, false en caso contrario
*/
bool TercerParqueo::validarEspacioDoble(NodoDoble* nodo) 
{
	if (nodo->next != NULL)
	{
		for (int i = 0; i < columnas; i++)
		{
			if (!nodo->next->nodos[i]->ocupado)
			{
				return true;
			}
		}
	}
	return false;
}