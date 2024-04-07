#pragma once
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Vehiculo.h"

using namespace std;

typedef struct User {
	string name;
	int id;
	vector<Vehiculo*> vehiculos;
};
#endif // USER_H