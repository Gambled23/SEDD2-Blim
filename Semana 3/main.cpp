#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>

#include "peliculas.h"

using namespace std;

int main()
{
    int opc;
    string pelicula;
    peliculas peli;
    do
    {
        cout << "Bienvenido a nuestra platafroma\nElige una opcion para continuar\n";
        cout << "1)Agregar\n2)Imprimir\n3)Buscar\n4)Modificar\n5)Eliminar\n6)Salir\n"
             << endl;
        cin >> opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
            peli.agregar();
            break;
        case 2:
            peli.imprimir();
            break;
        case 3:
            peli.buscar();
            break;
        case 4:
            peli.modificar();
            break;
        case 5:
            peli.eliminar(pelicula);
            break;
        case 6:
            cout << "Vuelva pronto" << endl;
            break;
        default:
            cout << "Esa opcion no existe" << endl;
        }
        system("pause");
        system("cls");
    } while (opc != 6);
}
