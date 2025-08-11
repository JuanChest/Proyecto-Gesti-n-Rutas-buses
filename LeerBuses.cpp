#include "LeerBuses.h"

void leerBuses(tBuses& buses, tRutas& rutas)
{
	tBus bus;
	ifstream lectura;
	int numRuta = -1;
	buses.contador = 0;
	lectura.open("Buses.txt");
	if (!lectura.is_open())
	{
		cout << "No se pudo leer el archivo" << endl;
	}
	else
	{
		//A toda la lista de buses se le asigna un número prederminado de bus
		//Además se coloca 0 en el numero de ruta de cada bus esto por facilidad
		for (int i = 0; i < MAXBuses; i++)
		{
			buses.ListaBuses[i].ruta.numRuta = 0;
			buses.ListaBuses[i].capacidad = genera_aleatorios();
			buses.ListaBuses[i].asientosReservados = 0;
			buses.ListaBuses[i].numBus = 1 + i;
		}
		//Se empieza a leer el archivo 
		lectura >> bus.numBus;
		while ((bus.numBus != -1) && (buses.contador < MAXBuses))
		{
			lectura >> bus.capacidad;
			lectura >> bus.asientosReservados;
			lectura >> bus.ruta.numRuta;
			//La siguiente condición sirve para asignar las rutas a cada bus 
			if (bus.ruta.numRuta == 0)
			{
				//Recordar que se puso un 0 a cada numero de ruta, esto para distinguir entre buses que tienen
				//una ruta prederminada y buses que no tiene una ruta puesta
				buses.ListaBuses[bus.numBus - 1] = bus;
			}
			else
			{
				//Se busca el numero de ruta al cual correponde y se le asigna al bus la informacion de esa ruta
				numRuta = bus.ruta.numRuta;
				numRuta = buscarRuta(rutas, numRuta);
				buses.ListaBuses[bus.numBus - 1] = bus;
				buses.ListaBuses[bus.numBus - 1].ruta = rutas.ListaRutas[numRuta];
			}
			buses.contador++;
			lectura >> bus.numBus;
		}
		lectura.close();
	}
}
int buscarRuta(tRutas rutas, int numRuta)
{
	int indice = -1;
	bool encontrado = false;
	int i = 0;
	while (!encontrado && i < rutas.contador)
	{
		if (rutas.ListaRutas[i].numRuta == numRuta)
		{
			encontrado = true;
			indice=i;
		}
		i++;
	}
	return indice;
}
int genera_aleatorios()
{
	int num_aleatorio;
	srand(time(NULL)); // Inicia la secuencia aleatoria
	num_aleatorio = rand() % 10 + 40; // número aleatorio entre 0 y 10, luego se le suma 40 para el rango de 40 a 50 asientos
	return num_aleatorio;
}
void guardarBuses(const tBuses buses)
{
	ofstream escritura;
	escritura.open("Buses.txt");
	for (int i = 0; i < MAXBuses; i++)
	{
		if (buses.ListaBuses[i].ruta.numRuta != 0)
		{
			escritura << buses.ListaBuses[i].numBus << " " << buses.ListaBuses[i].capacidad
				<< " " << buses.ListaBuses[i].asientosReservados
				<< " " << buses.ListaBuses[i].ruta.numRuta << endl;
		}
	}
	escritura << -1;
	escritura.close();
}