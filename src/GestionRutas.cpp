#include "GestionRutas.h"

void menuGestionRutas(tBuses& buses, tRutas& rutas)
{
	setlocale(LC_ALL, "");
	int opcion = -1;
	while (opcion != 5)
	{

		do
		{
			recuadro(1, 23, 119, 27);
			centrar_texto("T R A N S. P O L I B U S", 25);
			centrar_texto("======Gestionar Rutas======", 1);
			centrar_texto(" ---------------------", 2);
			centrar_texto("1. Imprimir rutas    ", 3);
			centrar_texto(" ---------------------", 4);
			centrar_texto("2. Añadir una ruta   ", 5);
			centrar_texto(" ---------------------", 6);
			centrar_texto("3. Eliminar una ruta ", 7);
			centrar_texto(" ---------------------", 8);
			centrar_texto("4. Modificar una ruta", 9);
			centrar_texto(" ---------------------", 10);
			centrar_texto("5. Volver            ", 11);
			centrar_texto(" ---------------------", 12);
			gotoxy(50, 13); cout << "Ingrese un opción: ";
			gotoxy(69, 13); cin >> opcion;
			if ((opcion < 1) || (opcion > 5))
			{
				cout << "Opción no válida" << endl;
				enter();
			}

		} while ((opcion < 1) || (opcion > 5));

		switch (opcion)
		{
		case 1:
			imprimirRutas(rutas);
			break;
		case 2:
			aniadirRuta(rutas, buses);
			break;
		case 3:
			eliminarRuta(rutas, buses);
			break;
		case 4:
			modificarRuta(rutas);
			break;
		}
	}
	system("cls");
}
void aniadirRuta(tRutas& rutas, tBuses& buses)
{
	system("cls");
	centrar_texto("=====Añadir Ruta=====", 0);
	//Se completan los campos de la ruta nueva
	tRuta ruta;
	gotoxy(1, 4); cout << "Ingrese y complete los siguientes campos:" << endl;
	gotoxy(1, 5); cout << "-----------------------------------------";
	gotoxy(1, 6); cout << "   " << "Lugar de partida: ";
	gotoxy(22, 6); cin >> ruta.rutaPartida;
	gotoxy(1, 7); cout << "   " << "Lugar de destino: ";
	gotoxy(22, 7); cin >> ruta.rutaDestino;
	gotoxy(1, 8); cout << "   " << "Hora de Salida(hh:mm): ";
	string horaIngresada;
	gotoxy(27, 8); cin >> horaIngresada;

	if (!verificarFormatoHora(horaIngresada)) {
		cout << endl;
		cout << "Hora INCORRECTA" << endl;
		enter();
	}
	else {
		ruta.horario = horaIngresada;
		gotoxy(1, 9); cout << "-----------------------------------------";
		/*
		Se le asigna el numero de ruta, como es algo nuevo se le asigna el numero siguiente de la
		ultima ruta de la lista, esto esta muy ligado al indice del arreglo;
		*/

		ruta.numRuta = 1 + rutas.ListaRutas[rutas.contador - 1].numRuta;
		rutas.ListaRutas[rutas.contador] = ruta;
		rutas.contador++;
		//Se imprimen los Buses que no tengan una ruta asignada o los que tiene por numero de ruta 0
		imprimirBusesDisponibles(buses);
		asignarBuses(buses, ruta);
	}
}
bool verificarFormatoHora(string horaIngresada) {
	regex formato("^([01]\\d|2[0-3]):([0-5]\\d)$");
	return regex_match(horaIngresada, formato);
}
void imprimirBusesDisponibles(const tBuses buses)
{
	int columna = 45;
	int fila = 3;
	int j = 0; //ayuda a la alineación de las filas 
	gotoxy(45, 2); cout << "Buses disponibles:" << endl;
	for (int i = 0; i < MAXBuses; i++)
	{
		if (buses.ListaBuses[i].ruta.numRuta == 0)
		{
			gotoxy(columna, fila + j); cout << "Bus #" << buses.ListaBuses[i].numBus;
			if (i % 10 == 0)
			{
				columna += 10;
				fila = 3;
				j = -1;
			}
			j++;
		}
	}
}
void asignarBuses(tBuses& buses, tRuta ruta)
{
	/*
	Se le asigna el numero de ruta a el numero de bus que se ingrese, a priori causaria problemas con el contador
	que pueda elejir cualquier bus
	*/

	int numBus;
	cout << endl << endl;
	cout << "Asignar Ruta a un Bus" << endl;
	do
	{
		cout << "Ingrese el número de Bus: ";
		cin >> numBus;
		if ((numBus < 1) || (numBus > MAXBuses) || (buses.ListaBuses[(numBus - 1)].ruta.numRuta != 0))
		{
			cout << "Bus no Disponible" << endl;
		}
	} while ((numBus < 1) || (numBus > MAXBuses) || (buses.ListaBuses[(numBus - 1)].ruta.numRuta != 0));
	cout << "Asignando..." << endl;
	buses.ListaBuses[numBus - 1].ruta = ruta; //IMPORTANTE!!!!! OJO A ESTO
	buses.contador = numBus; //IMPORTANTE!!!!! OJO A ESTO
	cout << "Bus asignado!" << endl;
	enter();
}
void imprimirRutas(const tRutas rutas)
{
	system("cls");
	centrar_texto("=====Rutas disponibles=====", 0);
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
	enter();
}
void modificarRuta(tRutas& rutas)
{
	tRuta ruta;
	int guardar;
	int numRuta;
	system("cls");
	centrar_texto("=====Modificar Ruta=====", 0);
	do
	{
		cout << endl;
		cout << "Ingrese el número de ruta a modificar: ";
		cin >> numRuta;
		if ((numRuta < 1) || (numRuta > rutas.contador) || (rutas.ListaRutas[numRuta - 1].numRuta == 0))
		{
			cout << "No se encuentra la ruta ingresada" << endl;
			enter();
			centrar_texto("=====Modificar Ruta=====", 0);
		}
	} while ((numRuta < 1) || (numRuta > rutas.contador) || (rutas.ListaRutas[numRuta - 1].numRuta == 0));
	cout << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Nuevo Lugar de partida: ";
	cin >> ruta.rutaPartida;
	cout << "Nuevo Destino: ";
	cin >> ruta.rutaDestino;
	string horaIngresada;
	do {
		cout << "Nuevo Horario: ";
		cin >> horaIngresada;
		if (!verificarFormatoHora(horaIngresada)) {
			cout << "Hora INCORRECTA" << endl;
		}
	} while (!verificarFormatoHora(horaIngresada));

	ruta.horario = horaIngresada;
	cout << endl;
	cout << "-----------------------------------------" << endl;
	ruta.numRuta = rutas.ListaRutas[numRuta - 1].numRuta;
	gotoxy(45, 3); cout << "\t" << left << setw(7) << "Ruta #" << left << setw(13) << ruta.numRuta 
		<< "|" << left << setw(20)
		<< "Antes: " << "|" << left << setw(20) << "Despues: " << "|" << endl;
	gotoxy(45, 4); cout << "\t" << "--------------------|" << "--------------------|" << "--------------------|" 
		<< endl;
	gotoxy(45, 5); cout << "\t" << left << setw(20) << "Lugar de Partida: " << "|" << left << setw(20)
		<< rutas.ListaRutas[numRuta - 1].rutaPartida << "|" << left << setw(20)
		<< ruta.rutaPartida << "|" << endl;
	gotoxy(45, 6); cout << "\t" << left << setw(20) << "Destino: " << "|" << left << setw(20)
		<< rutas.ListaRutas[numRuta - 1].rutaDestino << "|" << left << setw(20)
		<< ruta.rutaDestino << "|" << endl;
	gotoxy(45, 7); cout << "\t" << left << setw(20) << "Hora salida: " << "|" << left << setw(20)
		<< rutas.ListaRutas[numRuta - 1].horario << "|" << left << setw(20)
		<< ruta.horario << "|" << endl;
	do
	{
		cout << endl;
		cout << endl;
		cout << "¿Guardar cambio? |1. Si|2. No|: ";
		cin >> guardar;
		if ((guardar < 1) || (guardar > 2))
		{
			cout << "ERROR" << endl;
		}
	} while ((guardar < 1) || (guardar > 2));
	
	if (guardar == 1)
	{
		rutas.ListaRutas[numRuta - 1] = ruta;
		cout << "Cambio hecho" << endl;
	}
	else
	{
		cout << "No se realizó ningun cambio" << endl;
	}
	cout << endl;
	enter();
}
void eliminarRuta(tRutas& ruta, tBuses& buses)
{
	system("cls");
	centrar_texto("=====Eliminar Ruta=====", 0);
	cout << endl;
	int num;
	gotoxy(1, 4); cout << "Ingrese el numero de ruta que desea eliminar: ";
	gotoxy(1, 5); cout << "--------------------------------------------";
	gotoxy(48, 4);	cin >> num;
	bool rutaEncontrada = false;

	for (int i = 0; i < ruta.contador; i++)
	{
		if (ruta.ListaRutas[i].numRuta == num)
		{
			for (int j = 0; j < MAXBuses; j++)
			{
				if (buses.ListaBuses[j].ruta.numRuta == num)
				{
					ruta.ListaRutas[i].numRuta = 0;
					buses.ListaBuses[j].ruta.numRuta = 0;
					rutaEncontrada = true;
				}
			}
			break; // Salir del bucle una vez encontrada la ruta.
		}
	}

	if (rutaEncontrada)
	{
		cout << endl;
		cout << " Ruta eliminada correctamente" << endl;
		cout << endl;
		ruta.contador--;
	}
	else
	{
		cout << endl;
		gotoxy(1, 7); cout << "No existe una ruta con ese número" << endl;
		cout << endl;
	}
	enter();
}

void gotoxy(int x, int y) // permite ubicar el cursor y texto en cualquier parte de la consola
{
	HANDLE Manipulador;
	COORD Coordenadas;
	Manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
	Coordenadas.X = x;
	Coordenadas.Y = y;
	SetConsoleCursorPosition(Manipulador, Coordenadas);
}
void centrar_texto(const char *texto, int y) //Recibe un texto y el numero de fila para centrar ese texto
{
	int size_texto = strlen(texto);
	gotoxy(60 - (size_texto / 2), y);
	cout << texto << endl;
}
void enter() // Enter para continuar
{
	int enter;
	cout << "Presione ENTER para continuar....";
	enter = _getch(); 
	system("cls");
}
void recuadro(int xs, int ys, int xi, int yi) //Dibuja dos lineas como un igual ===
{
	for (int i = xs; i < xi; i++)
	{
		gotoxy(i, ys); cout << "-"; 
		gotoxy(i, yi); cout << "-";
	}
}
