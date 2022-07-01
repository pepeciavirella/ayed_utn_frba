#include <iostream>
// Tip: Incluido para poder usar la función strcpy()
#include <cstring>
// Tip: Incluido para poder usar la función strtof()
#include <cstdlib>
// Tip: Incluido para usar la función setw()
#include <iomanip>

// Tip: Definimos la cantidad de filas y de columnas en constantes, para ir acorde al enunciado
#define M 3
#define N 4
#define TAMANIO_COLUMNA 50

///---------Ej.10---------
/// Dada una matriz de MxN con datos de clientes (apellido y
/// nombre, dirección, edad y saldos) se pide ordenarla por saldos.
/// Considere que cada dato es una columna de la tabla y cada cliente es
/// una fila.

using namespace std;

void inicializarMatrizDeClientes (char matriz[][N][TAMANIO_COLUMNA], int cantidadClientes)
{
    for (int i = 0; i < cantidadClientes; i++)
    {
        cout << "****CONTACTO " << i + 1 << "****" << endl;
        cout << "Apellido y nombre: ";
        // Tip: Usamos cin.getline para tomar lineas enteras, con y sin espacios; como no estamos usando cin >> para la entrada, no es necesario usar cin.ignore()
        cin.getline(matriz[i][0], TAMANIO_COLUMNA);
        cout << "Dirección: ";
        cin.getline(matriz[i][1], TAMANIO_COLUMNA);
        cout << "Edad: ";
        cin.getline(matriz[i][2], TAMANIO_COLUMNA);
        cout << "Saldo: $";
        cin.getline(matriz[i][3], TAMANIO_COLUMNA);
        // Tip: Sólo por estética, para dejar un poco de espacio
        cout << endl;
    }
}

void copiarFilaDeCliente (char filaFuente[][TAMANIO_COLUMNA], char filaDestino[][TAMANIO_COLUMNA], int cantidadColumnas)
{
    for (int i = 0; i < cantidadColumnas; i++)
    {
        // Como son arrays de caracteres terminados con un '\0' (se agrega automáticamente al usar cin), podemos usar strcpy() para copiar de uno a otro
        strcpy(filaDestino[i], filaFuente[i]);
    }
}

void ordenarPorSaldoDecreciente (char matriz[][N][TAMANIO_COLUMNA], int cantidadClientes)
{
    int i, j, comparacionCodigosPostales;
    // Tip: Necesitamos una "fila de contacto" auxiliar para ir copiando los contactos cuando haya que ordenar
    char clienteAuxiliar[N][TAMANIO_COLUMNA];
    for (i = 0; i < (cantidadClientes - 1); i++)
    {
        for (j = 0; j < (cantidadClientes - 1); j++)
        {
            // Tip: Usamos la función strtof(char cadena[], char** puntero) para convertir una cadena de caracteres en un float (https://cplusplus.com/reference/cstdlib/strtof/)
            // De momento, sólo le pasamos NULL como puntero; vamos a ver el porqué de esto más adelante en el año
            float saldo = strtof(matriz[j][3], NULL);
            float saldoSiguiente = strtof(matriz[j+1][3], NULL);
            if (saldoSiguiente > saldo)
            {
                copiarFilaDeCliente(matriz[j], clienteAuxiliar, N);
                copiarFilaDeCliente(matriz[j+1], matriz[j], N);
                copiarFilaDeCliente(clienteAuxiliar, matriz[j+1], N);
            }
        }
    }
}

int main()
{
    // Tip: La matriz de clientes es una tabla de cadenas de caracteres, las cuales son arrays, lo cual la convierte en una matriz de caracteres
    char clientes[M][N][TAMANIO_COLUMNA];
    inicializarMatrizDeClientes(clientes, M);

    ordenarPorSaldoDecreciente(clientes, M);
    cout << endl << endl << "****AGENDA ORDENADA POR CODIGO POSTAL CRECIENTE****" << endl << endl;
    cout << "APELLIDO Y NOMBRE                                 |";
    cout << " DIRECCION                                        |";
    cout << " EDAD                                             |";
    cout << " SALDO" << endl;
    for(int i = 0; i < M; i++)
    {
        // Tip: Usamos left y setw(n) para que lo impreso por cout tenga un ancho fijo de 49 caracteres, agregando espacios en blanco a la derecha para completar
        cout << left << setw(49) << clientes[i][0];
        cout << " | " << left << setw(48) << clientes[i][1];
        cout << " | " << left << setw(48) << clientes[i][2];
        // Tip: Para la última columna no es necesario usar ancho fijo, ya que no tiene una barra que delimite
        cout << " | $" << clientes[i][3] << endl;
    }
    return 0;
}

