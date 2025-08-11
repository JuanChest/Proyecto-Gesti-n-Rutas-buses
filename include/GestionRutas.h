#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <conio.h>
#include <iomanip>
#include <locale.h>
#include <wchar.h>
#include <Windows.h>
#include "LeerBuses.h"
#include "LeerRutas.h"

//Estructuras

//Prototipos

//Men� principal del M�dulo Gestionar Rutas
void menuGestionRutas(tBuses& buses, tRutas& rutas);
// A�adir rutas
void aniadirRuta(tRutas& rutas, tBuses& buses);
void imprimirBusesDisponibles(const tBuses buses); //Parte de otra funci�n
void asignarBuses(tBuses& buses, tRuta ruta); //Parte de otra funci�n
//Imprime las rutas que esten registradas
void imprimirRutas(const tRutas rutas);
//Elimina una ruta
void eliminarRuta(tRutas& ruta, tBuses& buses);
//Modifica la informaci�n de una ruta de la lista que se haya elejido
void modificarRuta(tRutas& rutas);
//Permite ubicar el cursor en cualquier parte de la consola 
void gotoxy(int x, int y);
//Centra una cadena de texto
void centrar_texto(const char* texto, int y);
//Enter para continuar
void enter();
//Dibuja un recuadro
void recuadro(int xs, int ys, int xi, int yi);
