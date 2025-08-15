// Pruebas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Autores: Grupo E

#include <iostream>
using namespace std;
#include "LeerBuses.h"
#include "GestionRutas.h"
#include "ElegirRuta.h"
#include "GestionBuses.h"

void menuPrincipal(tBuses& buses, tRutas& rutas);

int main()
{
    system("COLOR F0");
    system("title Gestor de Transportes");
    tRutas rutas;
    tBuses buses;
    leerRutas(rutas);
    leerBuses(buses, rutas);
    menuPrincipal(buses, rutas);
    guardarRutas(rutas);
    guardarBuses(buses);
    system("cls");
    return 0;
}
void menuPrincipal(tBuses& buses, tRutas& rutas)
{
    int opcion = -1;
    while (opcion != 4)
    {
        setlocale(LC_ALL, "es_ES.UTF-8");  //Permite la impresión de caracteres en español
        do
        {
            recuadro(1, 0, 119, 4);
            recuadro(1, 23, 119, 27);
            recuadro(1, 24, 119, 26);
            centrar_texto("T R A N S. P O L I B U S", 2);
            centrar_texto("Autores: | Alison Betancourt | Juan Cofre |", 25);
            centrar_texto("======Gestor de Transporte======", 7);
            centrar_texto("----------------------", 9);
            centrar_texto("1. Elegir Ruta        ", 10);
            centrar_texto("----------------------", 11);
            centrar_texto("2. Gestionar Rutas    ", 12);
            centrar_texto("----------------------", 13);
            centrar_texto("3. Gestionar Buses    ", 14);
            centrar_texto("----------------------", 15);
            centrar_texto("4. Salir              ", 16);
            centrar_texto("----------------------", 17);
            gotoxy(50, 18); cout << "Ingrese un opción: ";
            gotoxy(69, 18); cin >> opcion;
            if ((opcion < 1) || (opcion > 4))
            {
                cout << "Opción no válida" << endl;
                enter();
            }
        } while ((opcion < 1) || (opcion > 4));
        switch (opcion)
        {
        case 1:
            system("cls");
            elegirRuta(buses, rutas);
            break;
        case 2:
            system("cls");
            menuGestionRutas(buses, rutas);
            break;
        case 3:
            system("cls");
            menuGestionBuses(buses,rutas);
            break;
        }
    }
}
