#include "ElegirRuta.h"

void elegirRuta(tBuses& buses, tRutas& rutas)
{
	setlocale(LC_ALL, "");
	int ruta;
	int reservar;
	int indice = 0;
	centrar_texto("=====Elegir Ruta y Reservar asientos====", 0);
	imprimirRutas1(rutas);
	cout << endl;
	do
	{
		cout << "Elegir Ruta (Número de la Ruta): ";
		cin >> ruta;
		if ((ruta < 1) || (ruta > rutas.contador))
		{
			cout << "La ruta no se encuentra en el listado" << endl;
		}
	} while ((ruta < 1) || (ruta > rutas.contador));
	verticales(45, 4, 1, 30);
	for (int i = 0; i < MAXBuses; i++)
	{
		if (buses.ListaBuses[i].ruta.numRuta == ruta)
		{
			indice = i;
			break;
		}
	}
	gotoxy(50, 4); cout << "Bus N°: " << buses.ListaBuses[indice].numBus << endl;
	gotoxy(50, 5); cout << "\t" << "Sigue la Ruta #" << buses.ListaBuses[indice].ruta.numRuta
		<< endl;
	gotoxy(50, 6); cout << "\t" << "Lugar de Partida: " << buses.ListaBuses[indice].ruta.rutaPartida
		<< endl;
	gotoxy(50, 7); cout << "\t" << "Lugar de Partida: " << buses.ListaBuses[indice].ruta.rutaDestino
		<< endl;
	gotoxy(50, 8); cout << "\t" << "Asientos disponibles: "
		<< buses.ListaBuses[indice].capacidad - buses.ListaBuses[indice].asientosReservados
		<< endl;
	do
	{
		gotoxy(50, 10); cout << "¿Reservar un asiento? |1. Si|2. No|: ";
		gotoxy(87, 10); cin >> reservar;
		if ((reservar < 1) || (reservar > 2))
		{
			gotoxy(50, 11); cout << "ERROR, Ingrese de nuevo" << endl;
		}
	} while ((reservar < 1) || (reservar > 2));
	if (reservar == 1)
	{
		int asientosElejidos;
		do
		{
			gotoxy(50, 12); cout << "Ingrese la cantidad de asientos a reservar: ";
			gotoxy(94, 12); cin >> asientosElejidos;
			if ((asientosElejidos < 1) || (asientosElejidos > buses.ListaBuses[indice].capacidad))
			{
				gotoxy(50, 13); cout << "ERROR, ingrese de nuevo" << endl;
			}
		} while ((asientosElejidos < 1) || (asientosElejidos > buses.ListaBuses[indice].capacidad));
		buses.ListaBuses[indice].asientosReservados = asientosElejidos;
		gotoxy(50, 14); cout << "Asientos Reservados!" << endl;
		gotoxy(50, 15); cout << "Asientos disponibles: "
			<< buses.ListaBuses[indice].capacidad - buses.ListaBuses[indice].asientosReservados
			<< " de " << buses.ListaBuses[indice].capacidad << endl;
		gotoxy(50, 16); enter();
	}
	else
	{
		gotoxy(50, 16); enter();
	}
}
void imprimirRutas1(const tRutas rutas)
{
	centrar_texto("=====Rutas disponibles=====", 2);
	cout << endl;
	for (int i = 0; i < rutas.contador; i++)
	{
		if (rutas.ListaRutas[i].numRuta != 0)
		{
			cout << "Ruta #" << rutas.ListaRutas[i].numRuta << ";" << endl;
			cout << "\t" << "Lugar de partida: " << rutas.ListaRutas[i].rutaPartida << endl;
			cout << "\t" << "Lugar de destino: " << rutas.ListaRutas[i].rutaDestino << endl;
			cout << "\t" << "Hora de salida: " << rutas.ListaRutas[i].horario << endl;
			cout << endl;
		}
	}
}
void verticales(int xs, int ys, int xi, int yi) //Dibuja una linea vertical de separación
{
	for (int i = ys; i < yi; i++)
	{
		gotoxy(xs, i); cout << "|";
	}
}