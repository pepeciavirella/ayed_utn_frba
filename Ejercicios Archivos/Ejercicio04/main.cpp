#include <iostream>

///---------Ej. 4---------
/// Dados dos archivos de enteros, previamente ordenados ascendentemente, confeccione un
/// programa que guarde en un tercer archivo el contenido de ambos ordenado
/// ascendentemente.

// HIPÓTESIS: Se usan dos archivos binarios que contienen enteros en el siguiente orden
// archivo1.ints (7 valores): 0 1 4 4 9 10 14
// archivo2.ints (5 valores): -3 0 1 4 8

using namespace std;

int cantidadElementosArchivo (FILE* f)
{
    long tamanioEnBytes;
    int cantidadElementos;

    fseek(f, 0, SEEK_END);
    tamanioEnBytes = ftell(f);
    cantidadElementos = tamanioEnBytes / sizeof(int);
    return cantidadElementos;
}

// Tip: Adaptada del algoritmo de apareo (desarrollado en ejercicio 7 de Arrays)
void aparearAscendentemente (FILE* f1, int tamanio1, FILE* f2, int tamanio2, FILE* fFinal)
{
    int i = 0;
    int j = 0;
    int k, leido1, leido2;
    // Tip: Por las dudas, movemos los cursores de los flujos al principio de cada archivo
    fseek(f1, 0, SEEK_SET);
    fseek(f2, 0, SEEK_SET);

    while (i < tamanio1 && j < tamanio2)
    {
        // Tip: Sí o sí tenemos que leer un entero de cada archivo para poder compararlos y ver cuál escribir (el menor)
        fread(&leido1, sizeof(int), 1, f1);
        fread(&leido2, sizeof(int), 1, f2);

        if (leido1 < leido2)
        {
            fwrite(&leido1, sizeof(int), 1, fFinal);
            // Tip: Si escribimos el valor de un archivo, retrocedemos el puntero del otro en un bloque, para volver a leer el entero no escrito
            fseek(f2, (-1) * sizeof(int), SEEK_CUR);
            i++;
        }
        else
        {
            fwrite(&leido2, sizeof(int), 1, fFinal);
            // Tip: Si escribimos el valor de un archivo, retrocedemos el puntero del otro en un bloque, para volver a leer el entero no escrito
            fseek(f1, (-1) * sizeof(int), SEEK_CUR);
            j++;
        }
    }

    for (k = i; k < tamanio1; k++)
    {
        fread(&leido1, sizeof(int), 1, f1);
        fwrite(&leido1, sizeof(int), 1, fFinal);
    }
    for (k = j; k < tamanio2; k++)
    {
        fread(&leido2, sizeof(int), 1, f2);
        fwrite(&leido2, sizeof(int), 1, fFinal);
    }
}

int main()
{
    int lectura1, lectura2;
    int enteroLeido1, enteroLeido2, enteroAEscribir;
    FILE *f1, *f2, *f3;

    f1 = fopen("archivo2.ints", "rb");
    if (f1 == NULL)
    {
        cout << "ERROR: No se pudo abrir el primer archivo a leer" << endl;
    }

    f2 = fopen("archivo1.ints", "rb");
    if (f2 == NULL)
    {
        cout << "ERROR: No se pudo abrir el segundo archivo a leer" << endl;
    }

    // Tip: Lo abrimos en modo wb+ porque primero lo vamos a escribir, pero luego lo vamos a leer para mostrar por pantalla
    f3 = fopen("archivo3.ints", "wb+");
    if (f3 == NULL)
    {
        cout << "ERROR: No se pudo abrir el archivo a escribir" << endl;
    }

    int cantidadEnteros1 = cantidadElementosArchivo(f1);
    int cantidadEnteros2 = cantidadElementosArchivo(f2);
    aparearAscendentemente(f1, cantidadEnteros1, f2, cantidadEnteros2, f3);

    cout << endl << "****Archivos apareados****" << endl;
    fseek(f3, 0, SEEK_SET);
    int valor;
    int i = 1;
    while(fread(&valor, sizeof(int), 1, f3))
    {
        cout << "Valor " << i << ": " << valor << endl;
        i++;
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}
