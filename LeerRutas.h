#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <fstream>

//Estructuras
const int MAXRutas = 30;
typedef struct
{
	int numRuta;
	string rutaPartida;
	string rutaDestino;
	string horario;
}tRuta;
typedef struct
{
	tRuta ListaRutas[MAXRutas];
	int contador;
}tRutas;
//Prototipos
void leerRutas(tRutas& rutas);
void guardarRutas(const tRutas rutas);