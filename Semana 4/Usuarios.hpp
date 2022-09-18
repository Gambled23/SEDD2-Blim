#ifndef USUARIOS_H
#define USUARIOS_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

#pragma once

using namespace std;

class Usuarios
{
public:
    Usuarios();
    string nombre;
    string tarjeta;
    string domicilio;
    string inicioServicio;
    string estadoServicio;

    void agregar();               // TODO
    void imprimir();              // TODO
    void buscar();                // TODO
    void modificar();             // TODO
    void eliminar();              // TODO
    void escribirArchivo(string); // TODO
    void leerArchivo();           // TODO

} usuar;

Usuarios::Usuarios()
{
}

void Usuarios::agregar()
{
    string aux;
    cout << "Ingrese el nombre del usuario: \n";
    cin >> aux;
    cout << "Ingrese los 16 numeros de la tarjeta: \n";
    cin >> aux;
    cout << "Ingrese el domicilio de facturacion: \n";
    cin >> aux;
    // Obtener día de inicio del servicio
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);
    cout << "Su servicio se cobrara el dia " << timePtr->tm_mday << " de cada mes" << endl;
}
void Usuarios::imprimir()
{
}
void Usuarios::buscar()
{
}
void Usuarios::modificar()
{
}
void Usuarios::eliminar()
{
}
void Usuarios::escribirArchivo(string cadena)
{
    ofstream archivo;
    archivo.open("usuarios.txt", ios::out);
    if (archivo.fail())
    {
        cout << "Ha ocurrido un error al abrir el archivo\n";
        exit(1);
    }

    archivo.close();
}
void Usuarios::leerArchivo()
{
    ifstream archivo;
    archivo.open("usuarios.txt", ios::in);
    if (archivo.fail())
    {
        cout << "Ha ocurrido un error al abrir el archivo\n";
        exit(1);
    }

    archivo.close();
}
#endif