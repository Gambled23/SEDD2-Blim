#include <iostream>
#include <cstdlib>
#include "Usuarios.hpp"
using namespace std;

void menu();
int main()
{
    menu();
    return 0;
}

void menu()
{
    int opc = 1;
    while (opc)
    {
        cout << "Bienvenido al sistema para manejo de usuarios\n";
        cout << "0) Salir \n";
        cout << "1) Agregar\n";   // TODO
        cout << "2) Imprimir\n";  // TODO
        cout << "3) Buscar\n";    // TODO
        cout << "4) Modificar\n"; // TODO
        cout << "5) Eliminar\n";  // TODO
        cin >> opc;
        switch (opc)
        {
        case 1:
            usuar.agregar();
            break;
        case 2:
            usuar.imprimir();
            break;
        case 3:
            usuar.buscar();
            break;
        case 4:
            usuar.modificar();
            break;
        case 5:
            usuar.eliminar();
            break;
        case 0:
            cout << "Gracias por su preferencia\n";
            break;
        default:
            cout << "Opcion invalida\n";
            break;
        }
        system("pause");
        system("cls");
    }
}