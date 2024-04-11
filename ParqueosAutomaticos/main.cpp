/*
	Autores:
	+ Jeffry Araya Ch.
	+ Gabriel Barrantes Vi.

	FechaDeCreación: 
	07/04/2024 16:05

	ÚltimaModificación:
	10/04/2024 20:30
*/

#include <iostream>
#include <string>
#include <vector>
#include "ParqueoAutomatico.h"

using namespace std;

int main()
{
	ParqueoAutomatico* parqueo = new ParqueoAutomatico(10);
	
	User* user1 = new User();
	user1->name = "Jeffry";
	user1->id = 1;

	Vehiculo* vehiculo1 = new Vehiculo();
	vehiculo1->placa = "ABC123";
	vehiculo1->chofer = user1;

	parqueo->MeterVehiculo(vehiculo1);

	User* user2 = new User();
	user2->name = "Gabriel";
	user2->id = 2;

	Vehiculo* vehiculo2 = new Vehiculo();
	vehiculo2->placa = "DEF456";
	vehiculo2->chofer = user2;

	parqueo->MeterVehiculo(vehiculo2);

	User* user3 = new User();
	user3->name = "Jorge";
	user3->id = 3;

	Vehiculo* vehiculo3 = new Vehiculo();
	vehiculo3->placa = "GHI789";
	vehiculo3->chofer = user3;

	parqueo->MeterVehiculo(vehiculo3);

	parqueo->mostrarVehiculos();

	Vehiculo* vehiculo = parqueo->SacarVehiculo("DEF456");

	if (vehiculo != NULL)
	{
		cout << "Vehiculo con placa " << vehiculo->placa << " fue sacado del parqueo" << endl;
	}
	else
	{
		cout << "Vehiculo no encontrado" << endl;
	}

	parqueo->mostrarVehiculos();

	delete parqueo;
	delete user1;
	delete vehiculo1;
	delete user2;
	delete vehiculo2;
	delete user3;
	delete vehiculo3;

	return 0;
}