/*
	Autores:
	+ Jeffry Araya Ch.
	+ Gabriel Barrantes Vi.

	FechaDeCreación: 
	07/04/2024 16:05

	ÚltimaModificación:
	14/04/2024 19:00
*/

#include <iostream>
#include <string>
#include <vector>
#include "ParqueoAutomatico.h"
#include "SegundoParqueo.h"

using namespace std;

int main()
{
	//ParqueoAutomatico* parqueo = new ParqueoAutomatico(10);
	
	User* user1 = new User();
	user1->name = "Jeffry";
	user1->id = 1;

	Vehiculo* vehiculo1 = new Vehiculo();
	vehiculo1->placa = "ABC123";
	vehiculo1->chofer = user1;

	//parqueo->MeterVehiculo(vehiculo1);

	User* user2 = new User();
	user2->name = "Gabriel";
	user2->id = 2;

	Vehiculo* vehiculo2 = new Vehiculo();
	vehiculo2->placa = "DEF456";
	vehiculo2->chofer = user2;

	//parqueo->MeterVehiculo(vehiculo2);

	User* user3 = new User();
	user3->name = "Jorge";
	user3->id = 3;

	Vehiculo* vehiculo3 = new Vehiculo();
	vehiculo3->placa = "GHI789";
	vehiculo3->chofer = user3;

	User* user4 = new User();
	user4->name = "David";
	user4->id = 4;

	Vehiculo* vehiculo4 = new Vehiculo();
	vehiculo4->placa = "JKL101";
	vehiculo4->chofer = user4;

	//parqueo->MeterVehiculo(vehiculo3);

	//parqueo->mostrarVehiculos();

	/*Vehiculo* vehiculo = parqueo->SacarVehiculo("DEF456");

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
	delete vehiculo3;*/
	SegundoParqueo* parqueoDe2Plantas = new SegundoParqueo(2);
	parqueoDe2Plantas->MeterVehiculo(vehiculo1);
	parqueoDe2Plantas->MeterVehiculo(vehiculo2);
	parqueoDe2Plantas->MeterVehiculo(vehiculo3);
	parqueoDe2Plantas->MeterVehiculo(vehiculo4);
	parqueoDe2Plantas->mostrarVehiculos();
	bool estaLleno = parqueoDe2Plantas->estaLleno();
	if (estaLleno)
	{
		cout << "El parqueo está lleno" << endl;
	}
	else
	{
		cout << "El parqueo no está lleno" << endl;
	}
	cout << "Cantidad de vehiculos: " << parqueoDe2Plantas->CantidadDeVehiculos() << endl;
	Vehiculo* vehiculo = parqueoDe2Plantas->SacarVehiculo("DEF456");
	if (vehiculo != NULL)
	{
		cout << "Vehiculo con placa " << vehiculo->placa << " fue sacado del parqueo" << endl;
	}
	else
	{
		cout << "Vehiculo no encontrado" << endl;
	}
	estaLleno = parqueoDe2Plantas->estaLleno();
	if (estaLleno)
	{
		cout << "El parqueo está lleno" << endl;
	}
	else
	{
		cout << "El parqueo no está lleno" << endl;
	}
	cout << "Cantidad de vehiculos: " << parqueoDe2Plantas->CantidadDeVehiculos() << endl;
	parqueoDe2Plantas->mostrarVehiculos();

	return 0;
}