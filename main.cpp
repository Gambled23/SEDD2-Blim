#include <iostream>
#include <string.h>
#include <fstream>
#include "peliculas.hpp"

using namespace std;

int main()
{
    int opc;
    peliculas peli;

    cout << "Bienvenido a nuestra platafroma\nElige una opcion para continuar\n";
    cout << "1)Agregar\n2)Imprimir\n3)Buscar\n4)Modificar\n5)Eliminar\n"
         << endl;
    cin >> opc;

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
        peli.eliminar();
        break;
    }
    system("pause");
}
