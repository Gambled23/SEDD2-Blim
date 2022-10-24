#ifndef USERS_H
#define USERS_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
#pragma once

using namespace std;

class users
{
public:
    char usuario[10], password[10], nombre[35];
    void Capturar();
    void Mostrar();
    void Modificar();
} datos;

void users::Capturar()
{

    cout << "\n Usuario: ";
    cin.getline(datos.usuario, 35);
    cout << "\n Password: ";
    cin.getline(datos.password, 10);
    cout << "\n Nombre: ";
    cin.getline(datos.nombre, 35);
    ofstream a;
    a.open("usuarios.txt", ios::out);
    if (a.fail())
    {
        cout << "Falla al abrir el archivo\n";
    }
    a.write(datos.usuario, sizeof(datos.usuario));
    a.write(datos.password, sizeof(datos.password));
    a.write(datos.nombre, sizeof(datos.nombre));
    a.close();
}

void users::Mostrar()
{
    char usuario2[10], password2[10];
    int band = 0;
    ifstream a("usuarios.txt");
    if (!a.good())
    {
        cout << "\n NO EXISTE ARCHIVO.....";
    }
    else
    {
        while (!a.eof())
        {
            a.read((char *)&datos, sizeof(datos));
            cout<<datos.nombre;
        }
        a.close();
    }
}

void users::Modificar()
{
}

#endif