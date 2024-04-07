#pragma once
#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include "User.h"

using namespace std;

typedef struct Vehiculo {
    int data;
    string placa; 
    User* chofer;
};

#endif // VEHICULO_H