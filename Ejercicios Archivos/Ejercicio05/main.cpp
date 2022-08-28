#include <iostream>

///---------Ej. 5---------
/// Dados dos archivos de enteros, previamente ordenados ascendentemente, confeccione un
/// programa que guarde en un tercer archivo el contenido de ambos ordenado
/// descendentemente.

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

// Tip: Adaptada del algoritmo de apareo (desarrollado en ejercicio 4 de Archivos)
void aparearDescendentemente (FILE* f1, int tamanio1, FILE* f2, int tamanio2, FILE* fFinal)
{
    int i = tamanio1;
    int j = tamanio2;
    int k, leido1, leido2;

    // Tip: A diferencia del apareo tradicional, vamos a leer los bloques de atrás hacia adelante, ya que los mayores números están al final
    while (i > 0 && j > 0)
    {
        // Tip: Sí o sí tenemos que leer un entero de cada archivo para poder compararlos y ver cuál escribir (el mayor)
        // Tip: Pero primero nos posicionamos antes del bloque a leer, ya que el fread sólo permite leer hacia adelante
        fseek(f1, (i - 1) * sizeof(int), SEEK_SET);
        fseek(f2, (j - 1) * sizeof(int), SEEK_SET);
        fread(&leido1, sizeof(int), 1, f1);
        fread(&leido2, sizeof(int), 1, f2);

        if (leido1 > leido2)
        {
            fwrite(&leido1, sizeof(int), 1, fFinal);
            i--;
        }
        else
        {
            fwrite(&leido2, sizeof(int), 1, fFinal);
            j--;
        }
    }

    // Tip: Leemos y escribimos los bloques del archivo que no terminamos de leer, también de atrás hacia adelante
    for (k = i; k > 0; k--)
    {
        fseek(f1, (k - 1) * sizeof(int), SEEK_SET);
        fread(&leido1, sizeof(int), 1, f1);
        fwrite(&leido1, sizeof(int), 1, fFinal);
    }
    for (k = j; k > 0; k--)
    {
        fseek(f2, (k - 1) * sizeof(int), SEEK_SET);
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
    aparearDescendentemente(f1, cantidadEnteros1, f2, cantidadEnteros2, f3);

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
