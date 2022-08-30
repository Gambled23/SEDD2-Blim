#ifndef PELICULAS_H
#define PELICULAS_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
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
    void imprimir();
    void buscar();
    void modificar(); // TODO
    void eliminar(string);
    void guardar(peliculas);
    string obtenerCadena(peliculas);
    void vaciarArchivo();

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
    cout << "Ingresa la duracion de la pelicula(en minutos)\n";
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
    peliculas peliAux;
    string registro, campo;
    int aux;
    ifstream archivoLista;
    archivoLista.open("peliculas.txt", ios::in);
    string cadena = obtenerCadena(peliAux); // Guarda todo el contenido de el archivo en la string cadena
    stringstream cadenaStream(cadena);
    while (getline(cadenaStream, registro, '*'))
    {
        cout << "-----------------------\n";
        aux = 1;
        stringstream registroStream(registro);
        while (getline(registroStream, campo, '|'))
        {
            switch (aux)
            {
            case 1:
                cout << "Pelicula: " << campo << endl;
                break;
            case 2:
                cout << "Director: " << campo << endl;
                break;
            case 3:
                cout << "Categoria: " << campo << endl;
                break;
            case 4:
                cout << "Minutos de duracion: " << campo << endl;
                break;
            case 5:
                cout << "Ano: " << campo << endl;
                break;
            case 6:
                cout << "Idioma: " << campo << endl;
                break;
            case 7:
                if (campo == "1")
                {
                    cout << "Cuenta con subtitulos: Si\n";
                }
                else
                {
                    cout << "Cuenta con subtitulos: No\n";
                }
                break;
            default:
                break;
            }
            aux++;
        }
        cout << "-----------------------\n\n";
    }
    cout << "Los datos han sido cargados exitosamente" << endl;
    archivoLista.close();
}
void peliculas::buscar()
{
    peliculas peliAux;
    string cadena = obtenerCadena(peliAux); // Guarda todo el contenido de el archivo en la string cadena

    string pelicula, registro, campo;
    int aux;
    cout << "Ingrese el nombre de la pelicula a buscar: ";
    cin >> pelicula;
    stringstream cadenaStream(cadena);
    while (getline(cadenaStream, registro, '*'))
    {
        cout << "-----------------------\n";
        aux = 1;
        stringstream registroStream(registro);
        getline(registroStream, campo, '|');
        if (campo == pelicula)
        {
            cout << "Pelicula: " << campo << endl;
            while (getline(registroStream, campo, '|'))
            {
                switch (aux)
                {
                case 1:
                    cout << "Director: " << campo << endl;
                    break;
                case 2:
                    cout << "Categoria: " << campo << endl;
                    break;
                case 3:
                    cout << "Minutos de duracion: " << campo << endl;
                    break;
                case 4:
                    cout << "Ano:" << campo << endl;
                    break;
                case 5:
                    cout << "Idioma: " << campo << endl;
                    break;
                case 6:
                    if (campo == "1")
                    {
                        cout << "Cuenta con subtitulos: Si\n";
                    }
                    else
                    {
                        cout << "Cuenta con subtitulos: No\n";
                    }
                    break;
                default:
                    break;
                }
                aux++;
            }
        }
    }
}

void peliculas::modificar()
{
    peliculas peliAux;
    string cadena = obtenerCadena(peliAux); // Guarda todo el contenido de el archivo en la string cadena

    string pelicula, registro, campo;
    string titulo, director, categoria, duracion, ano, idioma, subtitulos;
    int aux;
    cout << "Ingrese el nombre de la pelicula a modificar: ";
    cin >> pelicula;
    stringstream cadenaStream(cadena);
    while (getline(cadenaStream, registro, '*'))
    {
        aux = 1;
        stringstream registroStream(registro);
        getline(registroStream, campo, '|');
        if (campo == pelicula)
        {
            cout << "Ingrese el nuevo titulo: ";
            cin >> titulo;
            while (getline(registroStream, campo, '|'))
            {
                switch (aux)
                {
                case 1:
                    cout << "Ingrese el nuevo director: ";
                    cin >> director;
                    break;
                case 2:
                    cout << "Ingrese la nueva categoria: ";
                    cin >> categoria;
                    break;
                case 3:
                    cout << "Ingrese la nueva duracion: ";
                    cin >> duracion;
                    break;
                case 4:
                    cout << "Ingrese el nuevo ano de estreno: ";
                    cin >> ano;
                    break;
                case 5:
                    cout << "Ingrese el nuevo idioma: ";
                    cin >> idioma;
                    break;
                case 6:
                    cout << "Cuenta con subtitulos? 1)Si 0)No: ";
                    cin >> subtitulo;
                    break;
                default:
                    break;
                }
                aux++;
            }
        }
    }
    ofstream archivoEscritura;
    archivoEscritura.open("peliculas.txt", ios::out);
    if (archivoEscritura.fail()) // True/false, si hubo error se da mensaje
    {
        cout << "No se pudo abrir el archivo";
        exit(1); // Salir del programa
    }
    cadena = cadena + titulo + "|" + director + "|" + categoria + "|" + duracion + "|" + ano + "|" + idioma + "|" + subtitulo + "*";
    archivoEscritura << cadena;
    archivoEscritura.close();
    eliminar(pelicula);
}

void peliculas::eliminar(string pelicula)
{
    peliculas peliAux;
    string cadena = obtenerCadena(peliAux); // Guarda todo el contenido de el archivo en la string cadena

    string registro, campo, cadenaNueva = "";
    string titulo, director, categoria, duracion, ano, idioma, subtitulos;
    int aux;
    stringstream cadenaStream(cadena);
    while (getline(cadenaStream, registro, '*'))
    {
        aux = 1;
        stringstream registroStream(registro);
        getline(registroStream, campo, '|');
        if (campo != pelicula)
        {
            cadenaNueva = cadenaNueva + registro + "*";
        }
    }
    vaciarArchivo();
    ofstream archivoEscritura;
    archivoEscritura.open("peliculas.txt", ios::out);
    if (archivoEscritura.fail()) // True/false, si hubo error se da mensaje
    {
        cout << "No se pudo abrir el archivo";
        exit(1); // Salir del programa
    }
    archivoEscritura << cadenaNueva;
    archivoEscritura.close();
    cout << "La pelicula ha sido eliminada\n";
}
void peliculas::guardar(peliculas peliAux)
{
    string cadena = obtenerCadena(peliAux);
    // Escribir nuevo contenido en archivo
    ofstream archivoEscritura;
    archivoEscritura.open("peliculas.txt", ios::out);
    if (archivoEscritura.fail()) // True/false, si hubo error se da mensaje
    {
        cout << "No se pudo abrir el archivo";
        exit(1); // Salir del programa
    }
    archivoEscritura << cadena;
    archivoEscritura.close();
}
string peliculas::obtenerCadena(peliculas peliAux)
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
    if (peliAux.titulo != "")
    {
        cadena = cadena + peliAux.titulo + "|" + peliAux.director + "|" + peliAux.categoria + "|" + peliAux.duracion + "|" + peliAux.ano + "|" + peliAux.idioma + "|" + peliAux.subtitulo + "*";
    }
    archivoLectura.close();
    return cadena;
}

void peliculas::vaciarArchivo()
{
    ofstream archivoLista;
    archivoLista.open("peliculas.txt", std::ofstream::out | std::ofstream::trunc);
    archivoLista.close();
}
#endif