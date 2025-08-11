#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "LeerBuses.h"
#include "LeerRutas.h"
#include "GestionRutas.h"


//Función Principal
void elegirRuta(tBuses& buses, tRutas& rutas);
//Imprime las Rutas disponibles, funcion exclusiva para este apartado
void imprimirRutas1(const tRutas rutas);
//Dibuja una vertical en las coordenadas fijadas "xs": x superior "yi": y inferior, etc.
void verticales(int xs, int ys, int xi, int yi);
