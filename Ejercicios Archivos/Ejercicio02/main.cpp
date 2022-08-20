#include <iostream>

///---------Ej. 2---------
/// Agregue al código anterior la funcionalidad para poder modificar un número, solicitando al
/// usuario en qué posición está el número que quiere modificar y cuál es el nuevo valor. Los
/// cambios deben ser guardados en el archivo.

using namespace std;

void mostrarContenido (FILE* flujo)
{
    float valor;
    int i = 1;
    fseek(flujo, 0, SEEK_SET);
    while(fread(&valor, sizeof(float), 1, flujo))
    {
        cout << "Valor " << i << ": " << valor << endl;
        i++;
    }
}

int main()
{
    FILE* f;
    int posicionAModificar;
    float valorLeido, nuevoValor;

    // HIPÓTESIS: Ya hay un archivo floats.bin de base para leer y modificar; por esto último lo abrimos en modo lectura-escritura (no destructiva)
    // Inicialmente tiene 8 valores, en el siguiente orden: 10 -3 3.1 9 12 18 -5 16

    f = fopen("floats.bin", "rb+");
    if (f == NULL)
    {
        cout << "ERROR: No se pudo abrir el archivo \"floats.bin\" a modificar" << endl;
        return 1;
    }

    cout << "****Contenido actual del archivo****" << endl;
    mostrarContenido(f);

    cout << endl << "Ingrese la posicion del valor a modificar: ";
    cin >> posicionAModificar;
    // Tip: Nos movemos n-1 bloques para estar justo al comienzo del bloque n (el valor a modificar)
    fseek(f, sizeof(float) * (posicionAModificar - 1), SEEK_SET);
    if (fread(&valorLeido, sizeof(float), 1, f) == NULL)
    {
        cout << "ERROR: No hay ningun valor en la posicion indicada" << endl;
        return 2;
    }

    // Tip: Nos movemos 1 bloque hacia atrás para estar justo antes de la posición indicada (y así poder modificarla)
    fseek(f, (-1) * sizeof(float), SEEK_CUR);
    cout << "Ingrese el nuevo valor para la posicion: ";
    cin >> nuevoValor;
    fwrite(&nuevoValor, sizeof(float), 1, f);

    cout << endl << "****Nuevo contenido del archivo****" << endl;
    mostrarContenido(f);

    fclose(f);
    return 0;
}
