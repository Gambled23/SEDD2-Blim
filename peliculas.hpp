#ifndef PELICULAS_H
#define PELICULAS_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#pragma once

using namespace std;

class peliculas
{
public:
    peliculas();
    string titulo;
    string director;
    string categoria;
    string idioma;
    string subtitulo;
    string duracion;
    string ano;
    void agregar();
    void imprimir();  // TODO
    void buscar();    // TODO
    void modificar(); // TODO
    void eliminar();  // TODO
    void guardar(peliculas);

private:
};

peliculas::peliculas()
{
}

void peliculas::agregar()
{
    peliculas *peliAux = new peliculas;
    cout << "Bienvenido al sistema para agregar peliculas\n\n";
    cout << "Ingresa el titulo de la pelicula\n";
    cin >> peliAux->titulo;
    cout << "Ingresa el director de la pelicula\n";
    cin >> peliAux->director;
    cout << "Ingresa la categoria de la pelicula\n";
    cin >> peliAux->categoria;
    cout << "Ingresa la duracion de la pelicula\n";
    cin >> peliAux->duracion;
    cout << "Ingresa el ano de la pelicula\n";
    cin >> peliAux->ano;
    cout << "Ingresa el idioma principal de la pelicula\n";
    cin >> peliAux->idioma;
    cout << "La pelicula tiene pista de subtitulos?\n  0)No  1)Si\n";
    cin >> peliAux->subtitulo;
    guardar(*peliAux);
}
void peliculas::imprimir()
{
    
}
void peliculas::buscar()
{
}
void peliculas::modificar()
{
}
void peliculas::eliminar()
{
}
void peliculas::guardar(peliculas peliAux)
{
    string cadena;
    // Leer contenido actual archivo
    ifstream archivoLectura;
    archivoLectura.open("peliculas.txt", ios::in);
    if (archivoLectura.fail())
    {
        cout << "No se pudo abrir el archivo\n";
        exit(1);
    }
    while (!archivoLectura.eof()) // Mientras no sea el end of file
    {
        getline(archivoLectura, cadena); // Guarda todo el contenido del archivo en cadena
    }
    cadena = cadena + peliAux.titulo + "|" + peliAux.director + "|" + peliAux.categoria + "|" + peliAux.duracion + "|" + peliAux.ano + "|" + peliAux.idioma + "|" + peliAux.subtitulo + "*";
    archivoLectura.close();
    // Escribir nuevo contenido en archivo
    ofstream archivoEscritura;
    archivoEscritura.open("peliculas.txt", ios::out);
    if (archivoEscritura.fail()) // True/false, si hubo error se da mensaje
    {
        cout << "No se pudo abrir el archivo";
        exit(1); // Salir del programa
    }
    archivoEscritura << cadena;
}

#endif