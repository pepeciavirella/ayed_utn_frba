#include <iostream>
// Tip: Incluido para poder usar las funciones strcmp() y strcpy()
#include <cstring>
// Tip: Incluido para usar la función setw()
#include <iomanip>

// Tip: Definimos el tamaño de la agenda y el de cada columna en constantes para modificarlos fácilmente
#define CANTIDAD_CONTACTOS 3
#define TAMANIO_COLUMNA 50

///---------Ej.9---------
/// Diseñar un algoritmo para ordenar una agenda que contiene
/// apellido y nombre, dirección, teléfono, código postal por la columna
/// de código postal creciente.

using namespace std;

void inicializarAgenda (char contactos[][4][TAMANIO_COLUMNA], int cantidadContactos)
{
    for (int i = 0; i < cantidadContactos; i++)
    {
        cout << "****CONTACTO " << i + 1 << "****" << endl;
        cout << "Apellido y nombre: ";
        // Tip: Usamos cin.getline para tomar lineas enteras, con y sin espacios; como no estamos usando cin >> para la entrada, no es necesario usar cin.ignore()
        cin.getline(contactos[i][0], TAMANIO_COLUMNA);
        cout << "Dirección: ";
        cin.getline(contactos[i][1], TAMANIO_COLUMNA);
        cout << "Teléfono: ";
        cin.getline(contactos[i][2], TAMANIO_COLUMNA);
        cout << "Codigo postal: ";
        cin.getline(contactos[i][3], TAMANIO_COLUMNA);
        // Tip: Sólo por estética, para dejar un poco de espacio
        cout << endl;
    }
}

void copiarFilaDeContacto (char filaFuente[][TAMANIO_COLUMNA], char filaDestino[][TAMANIO_COLUMNA], int cantidadColumnas)
{
    for (int i = 0; i < cantidadColumnas; i++)
    {
        // Como son arrays de caracteres terminados con un '\0' (se agrega automáticamente al usar cin), podemos usar strcpy() para copiar de uno a otro
        strcpy(filaDestino[i], filaFuente[i]);
    }
}

void ordenarPorCodigoPostalCreciente (char contactos[][4][TAMANIO_COLUMNA], int cantidadContactos)
{
    int i, j, comparacionCodigosPostales;
    // Tip: Necesitamos una "fila de contacto" auxiliar para ir copiando los contactos cuando haya que ordenar
    char contactoAuxiliar[4][TAMANIO_COLUMNA];
    for (i = 0; i < (cantidadContactos - 1); i++)
    {
        for (j = 0; j < (cantidadContactos - 1); j++)
        {
            // Tip: Usamos strcmp(char cadena1[], char cadena2[]) para comparar dos arrays de caracteres lexicograficamente: https://cplusplus.com/reference/cstring/strcmp/
            // El resultado será negativo si la cadena1 viene primero en el alfabeto, positivo si la cadena2 viene primero en el alfabeto, o 0 si son iguales
            comparacionCodigosPostales = strcmp(contactos[j+1][3], contactos[j][3]);
            if (comparacionCodigosPostales < 0)
            {
                copiarFilaDeContacto(contactos[j], contactoAuxiliar, 4);
                copiarFilaDeContacto(contactos[j+1], contactos[j], 4);
                copiarFilaDeContacto(contactoAuxiliar, contactos[j+1], 4);
            }
        }
    }
}

int main()
{
    // Tip: La agenda es una tabla de cadenas de caracteres, las cuales son arrays, lo cual la convierte en una matriz de caracteres
    char agenda[CANTIDAD_CONTACTOS][4][TAMANIO_COLUMNA];
    inicializarAgenda(agenda, CANTIDAD_CONTACTOS);

    ordenarPorCodigoPostalCreciente(agenda, CANTIDAD_CONTACTOS);
    cout << endl << endl << "****AGENDA ORDENADA POR CODIGO POSTAL CRECIENTE****" << endl << endl;
    cout << "APELLIDO Y NOMBRE                                 |";
    cout << " DIRECCION                                        |";
    cout << " TELEFONO                                         |";
    cout << " CODIGO POSTAL" << endl;
    for(int i = 0; i < CANTIDAD_CONTACTOS; i++)
    {
        // Tip: Usamos left y setw(n) para que lo impreso por cout tenga un ancho fijo de 49 caracteres, agregando espacios en blanco a la derecha para completar
        cout << left << setw(49) << agenda[i][0];
        cout << " | " << left << setw(48) << agenda[i][1];
        cout << " | " << left << setw(48) << agenda[i][2];
        // Tip: Para la última columna no es necesario usar ancho fijo, ya que no tiene una barra que delimite
        cout << " | " << agenda[i][3] << endl;
    }
    return 0;
}
