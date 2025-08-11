#pragma once
#include "LeerBuses.h"
#include "LeerRutas.h"
#include "GestionRutas.h"
using namespace std;

//Presenta el submenu para la gestion de buses
void menuGestionBuses(tBuses& buses, tRutas rutas);
//Agrega un bus
void agregarBus(tBuses& buses, tRutas rutas);
//Elimina un bus en conjunto con su ruta
void eliminarBus(tBuses& buses);
//Modifica un bus
void modificarBus(tBuses& buses, tRutas rutas);
//Imprimir buses
void imprimirBusesConRutas(const tBuses& buses);
