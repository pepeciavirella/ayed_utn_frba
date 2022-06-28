#include <iostream>
// Tip: Lo definimos como constante literal para poder cambiarlo fácilmente y probar distintos tamaños
#define TAMVECTOR 8

///---------Ej.6---------
/// Realice un subprograma que muestre el contenido de un vector en forma
/// ordenada descendentemente. El tamaño del array es informado por
/// parámetro.

using namespace std;

void ordenarDescendentemente (float vec[], int tamanio)
{
    int i, j;
    float auxiliar;
    for (i = 0; i < (tamanio - 1); i++)
    {
        for (j = 0; j < (tamanio - 1); j++)
        {
            if (vec[j+1] > vec[j])
            {
                auxiliar = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = auxiliar;
            }
        }
    }

    cout << endl << "**Vector ordenado descendentemente**" << endl;
    for (i = 0; i < tamanio; i++)
    {
        cout << "Elemento " << i + 1 << ": " << vec[i] << endl;
    }
}

int main()
{
    float vectorDeNumeros[TAMVECTOR];
    cout << "Ingrese los elementos del vector" << endl;
    for (int i = 0; i < TAMVECTOR; i++)
    {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vectorDeNumeros[i];
    }
    ordenarDescendentemente(vectorDeNumeros, TAMVECTOR);
    return 0;
}
