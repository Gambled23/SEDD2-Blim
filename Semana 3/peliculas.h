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
    char titulo[30];
    char director[20];
    char categoria[15];
    char idioma[10];
    char subtitulo[2];
    char duracion[4];
    char ano[4];

    int dimTitulo;
    int dimDirector;
    int dimCategoria;
    int dimIdioma;
    int dimSubtitulo;
    int dimDuracion;
    int dimAno;

    void agregar();
    void imprimir();
    void buscar();
    void modificar(); // TODO
    void eliminar(string);
    void guardar();
    void leeArchivo(ifstream&);
    void vaciarArchivo();

private:
};

peliculas::peliculas()
{
}

void peliculas::agregar()
{
    cout << "Bienvenido al sistema para agregar peliculas\n\n";
    cout << "Ingresa el titulo de la pelicula\n";
    cin.getline(titulo,30);
    dimTitulo=strlen(titulo);
    cout << "Ingresa el director de la pelicula\n";
    cin.getline(director,20);
    dimDirector=strlen(director);
    cout << "Ingresa la categoria de la pelicula\n";
    cin.getline(categoria,15);
    dimCategoria=strlen(categoria);
    cout << "Ingresa la duracion de la pelicula(en minutos)\n";
    cin.getline(duracion,4);
    dimDuracion=strlen(duracion);
    cout << "Ingresa el ano de la pelicula\n";
    cin.getline(ano,4);
    dimAno=strlen(ano);
    cout << "Ingresa el idioma principal de la pelicula\n";
    cin.getline(idioma,6);
    dimIdioma=strlen(idioma);
    cout << "La pelicula tiene pista de subtitulos?\n  0)No  1)Si\n";
    cin.getline(subtitulo,2);
    dimSubtitulo=strlen(subtitulo);
    guardar();
}
void peliculas::imprimir()
{
    peliculas peliAux;
    ifstream archivoLista;
    archivoLista.open("peliculas.txt", ios::in);

    while (!archivoLista.eof())
    {

            leeArchivo(archivoLista);

            cout << titulo << " | " << director << " | " << categoria <<"  | "<<idioma<<"  |  "<<subtitulo<<"  |  "
            <<duracion<<"  |  "<<ano<<endl;



        cout << "-----------------------\n\n";

            }
    cout << "Los datos han sido cargados exitosamente" << endl;
    archivoLista.close();
}
void peliculas::buscar()
{
    char aux[30];
    cout<<"Cual pelicula buscas"<<endl;
    cin.getline(aux,30);
    ifstream archivo;

    archivo.open("peliculas.txt", ios::in);

     if (archivo.fail()) // True/false, si hubo error se da mensaje
    {
        cout << "No se pudo abrir el archivo";
        exit(1); // Salir del programa
    }

    while(!archivo.eof()){
        leeArchivo(archivo);
        if(titulo==aux){

            cout << titulo << " | " << director << " | " << categoria <<"  | "<<idioma<<"  |  "<<subtitulo<<"  |  "
            <<duracion<<"  |  "<<ano<<endl;
        }
    }
    archivo.close();

}

void peliculas::modificar()
{
    peliculas peliAux;
    string cadena;// = obtenerCadena(peliAux); // Guarda todo el contenido de el archivo en la string cadena

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
            while (getline(registroStream, campo, '|'))
            {
                switch (aux)
                {
                case 1:
                     cout << "Ingrese el nuevo titulo: ";
                    cin >> titulo;
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

    char aux[30];

    cout<<"Como se llama la pelicula a eliminar"<<endl;
    cin.getline(aux,30);

    ifstream archivo;
    archivo.open("peliculas.txt", ios::in);

     if (archivo.fail()) // True/false, si hubo error se da mensaje
    {
        cout << "No se pudo abrir el archivo";
        exit(1); // Salir del programa
    }

    while (!archivo.eof())
    {

        leeArchivo(archivo);

        if (titulo!= aux)
        {
            guardar();
        }
    }
    vaciarArchivo();
    archivo.close();
    cout << "La pelicula ha sido eliminada\n";
}
void peliculas::guardar()
{
    ofstream archivoEscritura;
    archivoEscritura.open("peliculas.txt", ios::out);
     if (archivoEscritura.fail()) // True/false, si hubo error se da mensaje
    {
        cout << "No se pudo abrir el archivo";
        exit(1); // Salir del programa
    }


    // Escribir nuevo contenido en archivo

    archivoEscritura.write((char*)&dimTitulo, sizeof(int));//Reserva la cantidad que tiene dimTitulo en el archivo
    archivoEscritura.write(titulo, dimTitulo);//Escribe en el archivo el titulo
    archivoEscritura.write((char*)&dimDirector, sizeof(int));
    archivoEscritura.write(director, dimDirector);
    archivoEscritura.write((char*)&dimCategoria, sizeof(int));
    archivoEscritura.write(categoria, dimCategoria);
    archivoEscritura.write((char*)&dimIdioma, sizeof(int));
    archivoEscritura.write(idioma, dimIdioma);
    archivoEscritura.write((char*)&dimSubtitulo, sizeof(int));
    archivoEscritura.write(subtitulo, dimSubtitulo);
    archivoEscritura.write((char*)&dimDuracion, sizeof(int));
    archivoEscritura.write(duracion, dimDuracion);
    archivoEscritura.write((char*)&dimAno, sizeof(int));
    archivoEscritura.write(ano, dimAno);

    archivoEscritura.close();
}
void peliculas::leeArchivo(ifstream &archivoLista)
{

            archivoLista.read((char*)&dimTitulo, sizeof(int));// dim1 contiene el tama o de la cadena que se quiere leer
			archivoLista.read((char*)&titulo, dimTitulo);
			titulo[dimTitulo] = '\0'; // asignar fin de cadena al arreglo usuario para que no imprima basura
            archivoLista.read((char*)&dimDirector, sizeof(int));
			archivoLista.read((char*)&director, dimDirector);
			director[dimDirector] = '\0';
			archivoLista.read((char*)&dimCategoria, sizeof(int));
			archivoLista.read((char*)&categoria, dimCategoria);
			categoria[dimCategoria] = '\0';
			archivoLista.read((char*)&dimIdioma, sizeof(int));
			archivoLista.read((char*)&idioma, dimIdioma);
			idioma[dimIdioma] = '\0';
			archivoLista.read((char*)&dimSubtitulo, sizeof(int));
			archivoLista.read((char*)&subtitulo, dimSubtitulo);
			subtitulo[dimSubtitulo] = '\0';
			archivoLista.read((char*)&dimDuracion, sizeof(int));
			archivoLista.read((char*)&duracion, dimDuracion);
			duracion[dimDuracion] = '\0';
			archivoLista.read((char*)&dimAno, sizeof(int));
			archivoLista.read((char*)&ano, dimAno);
			ano[dimAno] = '\0';

}

void peliculas::vaciarArchivo()
{
    ofstream archivoLista;
    archivoLista.open("peliculas.txt", std::ofstream::out | std::ofstream::trunc);
    archivoLista.close();
}
#endif
