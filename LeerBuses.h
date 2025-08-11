#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "LeerRutas.h"
#include <cstdlib> // srand() y rand()
#include <ctime> // time()
//Estructuras
const int MAXBuses = 30;
typedef struct
{
	int numBus;
	int capacidad;
	int asientosReservados;
	tRuta ruta;
}tBus;
typedef struct
{
	tBus ListaBuses[MAXBuses];
	int contador;
}tBuses;

//Prototipos

//Lee la información de buses de un archivo .txt
void leerBuses(tBuses& buses, tRutas& rutas);
int buscarRuta(tRutas rutas, int numRuta); //Parte de otra función
int genera_aleatorios(); //Sirve para asignar de forma aleatoria los asientos de un bus.
//Guarda La informacion de los buses en el archivo de texto
void guardarBuses(const tBuses buses);