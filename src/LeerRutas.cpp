#include "LeerRutas.h"

// Se lee de forma normal las rutas que existan en el archivo 
void leerRutas(tRutas& rutas)
{
	tRuta ruta;
	ifstream lectura;
	rutas.contador = 0;
	lectura.open("src/Archivos/Rutas.txt");
	if (!lectura.is_open())
	{
		cout << "No se pudo leer el archivo" << endl;
	}
	else
	{
		lectura >> ruta.numRuta;
		while ((ruta.numRuta != -1) && (rutas.contador < MAXRutas))
		{
			lectura >> ruta.rutaPartida;
			lectura >> ruta.rutaDestino;
			lectura >> ruta.horario;

			rutas.ListaRutas[rutas.contador] = ruta;
			rutas.contador++;
			lectura >> ruta.numRuta;
		}
		lectura.close();
	}
}
void guardarRutas(const tRutas rutas)
{
	ofstream escritura;
	escritura.open("src/Archivos/Rutas.txt");
	for (int i = 0; i < rutas.contador; i++)
	{
		if (rutas.ListaRutas[i].numRuta != 0)
		{
			escritura << rutas.ListaRutas[i].numRuta << " " << rutas.ListaRutas[i].rutaPartida
				<< " " << rutas.ListaRutas[i].rutaDestino << " " << rutas.ListaRutas[i].horario
				<< endl;
		}
	}
	escritura << -1;
	escritura.close();
}