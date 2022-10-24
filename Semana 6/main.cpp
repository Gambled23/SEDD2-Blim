#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

#define NUMREGISTROS 100

class Pago
{
    private:
        char id[ 12 ];
        char tarjeta[ 35 ];
        char suscripcion[4];
        char mensual[4];
        char pagado[2];

        int dispersion( const char llave[ 12 ] );
        long int buscarId( const string & );
    public:
        Pago(void );
        Pago( const Pago & );
        void setId( const string & );
        void setTajeta( const string & );
        void setSuscripcion( const string & );
        void setMensual( const string & );
        void setPagado(const string&);
        friend ostream &operator<<( ostream &, const Pago & );


        bool agregar( const Pago & );
        void mostrar( void );
        bool buscar( const string &, Pago & );
        bool eliminar( const string &, Pago & );
        bool modificar( const string &, const Pago & );
        void mostrarIndice( void );
        Pago pedirRegistro( void );
        bool contiene( const string & );
        void genera( void );
};


// constructor
Pago::Pago( void )
{
    for( int i = 0; i < sizeof( id ); id[ i++ ] = '\0' );
    for( int j = 0; j < sizeof( tarjeta ); tarjeta[ j++ ] = '\0' );
    for( int k = 0; k < sizeof( suscripcion ); suscripcion[ k++ ] = '\0' );
    for( int i = 0; i < sizeof( mensual ); mensual[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( pagado ); pagado[ i++ ] = '\0' );


}

void Pago::genera( void )
{
    Pago promo;
    ofstream archivo( "dispersion.txt", ios::out );
    if( !archivo )
        cout << "No se pudo crear el archivo" << endl;
    else
        for( int i = 0; i < NUMREGISTROS; i++ )
            archivo.write( ( char * ) &promo, sizeof( Pago ) );
            archivo.close();
}

bool Pago::contiene( const string &idABuscar )
{
    if( buscarId( idABuscar ) == -1 )
        return false;
    return true;
}

Pago Pago::pedirRegistro( void )
{
    Pago registroARetornar;
    string cadena;
    int opc;

    cout << endl << "ID: ";
    fflush( stdin );
    getline( cin, cadena );
    while( contiene( cadena ) )
    {
        cout << "Ese ID ya existe: ";
        fflush( stdin );
        getline( cin, cadena );
    }
    registroARetornar.setId( cadena );

    cout << "Tarjeta: ";
    fflush( stdin );
    getline( cin, cadena );
    registroARetornar.setTajeta( cadena );

    registroARetornar.setSuscripcion("$150");
    registroARetornar.setMensual("$100");

    cout << "Que quieres pagar 1)Suscripcion 2)Renovar: ";
    cin>>opc;
    cin.ignore();
    switch(opc){

    case 1:
    cout<<"La suscripcion ha sido pagada"<<endl;
    registroARetornar.setSuscripcion("$0");
    break;

    case 2:
    cout << "La renovacion ha sido pagado"<<endl;
    registroARetornar.setMensual("$0");
    break;
    }
    registroARetornar.setPagado("S");
    return registroARetornar;
}

int Pago::dispersion( const char llave[ 12 ] )
{
    // llena el sobrante de la llave con espacios
    char llaveCopia[ 12 ];
    strcpy( llaveCopia, llave );
    if( strlen( llaveCopia ) < 12 )
        for( int i = strlen( llaveCopia ); i < 12; i++ )
            llaveCopia[ i ] = ' ';
    llaveCopia[ 12 ] = '\0';

    // realiza el algoritmo
    int sum = 0;
    int j = 0;
    while( j < 12 )
    {
        sum = ( sum + 100 * llaveCopia[ j ] + llaveCopia[ j + 1 ] )  % 20000;
        j += 2;
    }
    return ( sum % 99 ); // retorna la posición donde se guardará el registros.
}

long int Pago::buscarId( const string &idABuscar )
{
    Pago promo;
    int posIndice;
    long int posByte;

    ifstream archivo( "dispersion.txt", ios::in );
    if( !archivo )
    {
        archivo.close();
        return -1;
    }
    else
    {
        posIndice = dispersion( idABuscar.c_str() );
        posByte = posIndice * sizeof( Pago );
        archivo.seekg( posByte, ios::beg );
        archivo.read( ( char * ) &promo, sizeof( Pago ) );
        if( strcmp( promo.id, idABuscar.c_str() ) == 0 )
        {
            archivo.close();
            return posByte;
        }
    }
    archivo.close();
    return -1;
}

void Pago::setId( const string &valorId )
{
    int longitud = valorId.size();
    longitud = ( longitud < 12 ? longitud : 11 );
    valorId.copy( id, longitud );
    id[ longitud ] = '\0';
}

void Pago::setTajeta( const string &valorTarjeta )
{
    int longitud = valorTarjeta.size();
    longitud = ( longitud < 35 ? longitud : 34 );
    valorTarjeta.copy( tarjeta, longitud );
    tarjeta[ longitud ] = '\0';
}

void Pago::setSuscripcion( const string &valorSuscripcion )
{
    int longitud = valorSuscripcion.size();
    longitud = ( longitud < 35 ? longitud : 34 );
    valorSuscripcion.copy( suscripcion, longitud );
    suscripcion[ longitud ] = '\0';
}

void Pago::setPagado( const string &valorPagado )
{
    int longitud = valorPagado.size();
    longitud = ( longitud < 35 ? longitud : 34 );
    valorPagado.copy( pagado, longitud );
    pagado[ longitud ] = '\0';
}

void Pago::setMensual( const string &valorMensual )
{
    int longitud = valorMensual.size();
    longitud = ( longitud < 10 ? longitud : 9 );
    valorMensual.copy( mensual, longitud );
    mensual[ longitud ] = '\0';
}

ostream &operator<<( ostream &salida, const Pago &pago )
{
    salida << "ID:        " << pago.id << endl
            << "Producto:  " << pago.tarjeta << endl
            << "Suscripcion: " << pago.suscripcion << endl
            << "Mensual:    " << pago.mensual << endl
            <<"Pagado "<<pago.pagado<<endl;

    return salida;
}

bool Pago::agregar( const Pago &nuevaPago )
{
    int posIndice;
    long int posByte;
    string idString = nuevaPago.id;

    if( contiene( idString ) )
        return false;

    posIndice = dispersion( nuevaPago.id );
    cout << "Se guardara en la posicion indice: " << posIndice << endl;
    fstream archivo( "dispersion.txt", ios::in | ios::out );
    posByte = posIndice * sizeof( Pago );
    archivo.seekg( posByte, ios::beg );
    archivo.write( ( char * ) &nuevaPago, sizeof( Pago ) );

    archivo.close();
    return true;
}

void Pago::mostrar( void )
{
    Pago promo;
    ifstream archivo( "dispersion.txt", ios::in );
    if( !archivo )
        cout << "No existe el archivo" << endl;
    else
        for( int i = 0; i < NUMREGISTROS; i++ )
        {
            archivo.read( ( char * ) &promo, sizeof( Pago ) );
            if( !( promo.id[ 0 ] == '\0' ) )
                cout << endl << promo << endl;
        }
    archivo.close();
}

bool Pago::buscar( const string &idABuscar, Pago &pagoEncontrada )
{
    int posIndice;
    long int posByte;

    if( !contiene( idABuscar ) )
        return false;

    ifstream archivo( "dispersion.txt", ios::in );
    if( !archivo )
    {
        cout << "El archivo no existe" << endl;
        archivo.close();
        return false;
    }

    posByte = buscarId( idABuscar );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &pagoEncontrada, sizeof( Pago ) );
    archivo.close();
    return true;
}

bool Pago::modificar( const string &idAModificar, const Pago &pagoNueva )
{
    Pago promo;
    long int posByteAnterior, posByteNuevo;
    int posRegAnterior;

    if( !contiene( idAModificar ) )
        return false;

    fstream archivo( "dispersion.txt", ios::in | ios::out );
    if( !archivo )
    {
        cout << "El archivo no exite" << endl;
        archivo.close();
        return false;
    }

    posRegAnterior = dispersion( pagoNueva.id );
    posByteNuevo = posRegAnterior * sizeof( Pago );

    posByteAnterior = buscarId( idAModificar );

    archivo.seekp( posByteAnterior, ios::beg );
    archivo.write( ( char * ) &promo, sizeof( Pago) );
    archivo.seekp( posByteNuevo, ios::beg );
    archivo.write( ( char * ) &pagoNueva, sizeof( Pago) );
    archivo.close();
    return true;
}

bool Pago::eliminar( const string &idAEliminar, Pago &destinoEliminado )
{
    Pago promo;
    if( !contiene( idAEliminar ) )
        return false;

    fstream archivo( "dispersion.txt", ios::in | ios::out );
    if( !archivo )
    {
        cout << "El archivo no exite" << endl;
        archivo.close();
        return false;
    }

    long int posByte = buscarId( idAEliminar );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &destinoEliminado, sizeof(  Pago) );
    archivo.seekg( posByte, ios::beg );
    archivo.write( ( char * ) &promo, sizeof(  Pago) );
    archivo.close();
    return true;
}


int main( void )
{
    Pago pago, pagoBuscar, pagoModificar, pagoEliminar, registroAgregar;
    string idABuscar, idAModificar, idAEliminar;
    char opcion, op;

    pago.genera();

    system( "cls" );

    do{
        cout<<"\n\n\t\tBienvenido al menu Pagoes\n\n";
        cout<<"Seleccione una opcion" << endl
            << "1. Agregar"   << endl
            << "2. Mostrar"   << endl
            << "3. Buscar"    << endl
            << "4. Modificar" << endl
            << "5. Eliminar"  << endl
            << "6. Salir"     << endl
            << endl;
        cin >> opcion;
        switch( opcion )
        {
          case '1':
            registroAgregar = pago.pedirRegistro();
            if( pago.agregar( registroAgregar ) )
                cout << "Cliente agregado con exito" << endl;
            else
                cout << "No se agrego la pago" << endl;
            break;

          case '2':
            system( "cls" );
            pago.mostrar();
            break;

          case '3':
            cout << "Ingrese el ID de la pago a buscar: ";
            fflush( stdin );
            getline( cin, idABuscar );
            if( pago.buscar( idABuscar, pagoBuscar ) )
                cout << endl << pagoBuscar << endl;
            else
                cout << "No existe el registro" << endl;
            break;

          case '4':
            cout << "Ingrese el ID de la pago a modificar: ";
            fflush( stdin );
            getline( cin, idAModificar );
            if( pago.buscar( idAModificar, pagoBuscar ) )
            {
                cout << endl << pagoBuscar << endl;
                cout << "Desea modificarlo?" << endl;
                cout << "1) Si" << endl;
                cout << "2) No" << endl;
                cin >> op;

                if( op == '1' )
                {
                    pagoModificar = pago.pedirRegistro();
                    if( pago.modificar( idAModificar, pagoModificar ) )
                        cout << endl << "Pago modificada con exito" << endl;
                    else
                        cout << endl << "No se pudo modificar" << endl;
                }
            }
            else
                cout << "No existe el registro" << endl;
            break;

          case '5':
            cout << "Ingrese el ID de la pago a eliminar: ";
            fflush( stdin );
            getline( cin, idAEliminar );
            if( pago.buscar( idAEliminar, pagoBuscar ) )
            {
                cout << endl << pagoBuscar << endl;
                cout << "Desea eliminarlo?" << endl;
                cout << "1) Si" << endl;
                cout << "2) No" << endl;
                cin >> op;

                if( op == '1' )
                    if( pago.eliminar( idAEliminar, pagoEliminar ) )
                        cout << endl << pagoEliminar << endl << "SE ELIMINO CORRECTAMENTE" << endl;
                    else
                        cout << "NO SE PUDO ELIMINAR" << endl;
            }
            else
                cout << "No existe el registro" << endl;
            break;
        }
        cout << endl;
        system("Pause");
        system( "cls" );
    }while(opcion != '6');
}
