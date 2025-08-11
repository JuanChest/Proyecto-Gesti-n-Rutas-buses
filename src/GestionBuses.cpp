#include "GestionBuses.h"

void agregarBus(tBuses& buses, tRutas rutas)
{
    system("cls");
    centrar_texto("=====Añadir Bus=====", 0);
    if (buses.contador >= MAXBuses)
    {
        cout << "No hay espacio para agregar más buses." << endl;
        enter();
        return;
    }
    tBus nuevoBus;
    int numruta;
    nuevoBus.numBus = buses.contador + 1; // Asignar el siguiente número de bus
    cout << "Ingrese la capacidad del bus: ";
    cin >> nuevoBus.capacidad;
    nuevoBus.asientosReservados = 0;
    cout << "¿Desea agregar un número de ruta para este bus? (1: Sí, 0: No): ";
    cin >> numruta;

    if (numruta == 1)
    {
        do
        {
            cout << "Ingrese el número de ruta: ";
            cin >> nuevoBus.ruta.numRuta;
            if ((nuevoBus.ruta.numRuta < 1) || (nuevoBus.ruta.numRuta > rutas.contador))
            {
                cout << "ERROR, el número de ruta no es correcto" << endl;
            }
        } while ((nuevoBus.ruta.numRuta < 1) || (nuevoBus.ruta.numRuta > rutas.contador));
    }
    else
    {
        nuevoBus.ruta.numRuta = 0; //se pone el número de ruta en 0.
    }
    buses.ListaBuses[buses.contador] = nuevoBus;
    buses.contador++;
    cout << "Bus agregado correctamente." << endl;
    enter();
}

void eliminarBus(tBuses& buses)
{
    system("cls");
    centrar_texto("=====Eliminar Bus=====", 0);

    int numBus;
    cout << "Ingrese el número de bus que desea eliminar: ";
    cin >> numBus;

    bool busEncontrado = false;
    for (int i = 0; i < buses.contador; i++)
    {
        if (buses.ListaBuses[i].numBus == numBus)
        {
            // Eliminar el bus y su ruta asignada (si la tiene)
            buses.ListaBuses[i].ruta.numRuta = 0;
            buses.ListaBuses[i].capacidad = 0;

            // Mover los buses restantes hacia arriba en el arreglo
            for (int j = i; j < buses.contador - 1; j++)
            {
                buses.ListaBuses[j] = buses.ListaBuses[j + 1];
            }

            buses.contador--;
            busEncontrado = true;
            cout << "Bus eliminado correctamente." << endl;
            break;
        }
    }

    if (!busEncontrado)
    {
        cout << "No existe un bus con ese número." << endl;
    }

    enter();
}

void modificarBus(tBuses& buses, tRutas rutas)
{
    system("cls");
    centrar_texto("=====Modificar Bus=====", 0);

    int numBus;
    cout << "Ingrese el número de bus que desea modificar: ";
    cin >> numBus;

    for (int i = 0; i < buses.contador; i++)
    {
        if (buses.ListaBuses[i].numBus == numBus)
        {
            cout << "Modificar el bus #" << numBus << endl;
            cout << "1. Modificar capacidad" << endl;
            cout << "2. Modificar número de ruta" << endl;
            int opcion;
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                cout << "Ingrese la nueva capacidad: ";
                cin >> buses.ListaBuses[i].capacidad;
                cout << "Capacidad modificada correctamente." << endl;
                break;
            case 2:
                do
                {
                    cout << "Ingrese el nuevo número de ruta (0 para eliminar la ruta actual): ";
                    cin >> buses.ListaBuses[i].ruta.numRuta;
                    if ((buses.ListaBuses[i].ruta.numRuta < 1) || (buses.ListaBuses[i].ruta.numRuta > rutas.contador))
                    {
                        cout << "ERROR, Ruta no válida, ingrese de nuevo" << endl;
                    }
                } while ((buses.ListaBuses[i].ruta.numRuta < 1) || (buses.ListaBuses[i].ruta.numRuta > rutas.contador));
                cout << "Número de ruta modificado correctamente." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
            }

            enter();
            return;
        }
    }

    cout << "No existe un bus con ese número." << endl;
    enter();
}
void imprimirBusesDisponibles(const tBuses& buses)
{
    system("cls");
    centrar_texto("=====Buses Disponibles=====", 0);
    cout << endl;

    if (buses.contador == 0)
    {
        cout << "No hay buses disponibles." << endl;
    }
    else
    {
        for (int i = 0; i < buses.contador; i++)
        {
            if (buses.ListaBuses[i].ruta.numRuta != 0)
            {
                cout << "Bus #" << buses.ListaBuses[i].numBus << " | Capacidad: " << buses.ListaBuses[i].capacidad << endl;
            }
        }
    }

    enter();
}
void imprimirBusesConRutas(const tBuses& buses)
{
    cout << "Listado de Buses con Rutas:" << endl;
    for (int i = 0; i < buses.contador; i++)
    {
        cout << "Bus #" << buses.ListaBuses[i].numBus << " (Capacidad: " << buses.ListaBuses[i].capacidad << ")";
        if (buses.ListaBuses[i].ruta.numRuta != 0)
        {
            cout << " - Ruta #" << buses.ListaBuses[i].ruta.numRuta;
        }
        cout << endl;
    }
    enter();
}

void menuGestionBuses(tBuses& buses, tRutas rutas)
{
    setlocale(LC_ALL, "");
    int opcion = -1;
    while (opcion != 5)
    {

        do
        {
            recuadro(1, 23, 119, 27);
            centrar_texto("T R A N S. P O L I B U S", 25);
            centrar_texto("======Gestionar Buses======", 1);
            centrar_texto(" ---------------------", 2);
            centrar_texto("1. Añadir un bus    ", 3);
            centrar_texto(" ---------------------", 4);
            centrar_texto("2. Eliminar un bus   ", 5);
            centrar_texto(" ---------------------", 6);
            centrar_texto("3. Modificar un bus ", 7);
            centrar_texto(" ---------------------", 8);
            centrar_texto("4. Imprimir buses   ", 9);
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
            agregarBus(buses, rutas);

            break;
        case 2:
            eliminarBus(buses);
            break;
        case 3:
            modificarBus(buses, rutas);
            break;
        case 4:
            imprimirBusesConRutas(buses);
            break;
        }
    }
    guardarBuses(buses);
    system("cls");
}