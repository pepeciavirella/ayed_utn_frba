#include <iostream>

#define TAMVEC1 5
#define TAMVEC2 5
#define TAMVECFINAL 10

///---------Ej.8---------
/// Confeccionar un subprograma que, dados dos vectores de números
/// enteros liste el contenido de ambos pero en forma ordenada. Utilice el
/// algoritmo de apareo.

using namespace std;

void inicializarVector (int vec[], int tamanio)
{
    for (int i = 0; i < tamanio; i++)
    {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vec[i];
    }
}

void ordenarDeMenorAMayor (int vec[], int tamanio)
{
    int i, j;
    int auxiliar;
    for (i = 0; i < (tamanio - 1); i++)
    {
        for (j = 0; j < (tamanio - 1); j++)
        {
            if (vec[j+1] < vec[j])
            {
                auxiliar = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = auxiliar;
            }
        }
    }
}

// Tip: Este algoritmo sirve para armar un array ordenado a partir de otros dos arrays; como precondición, cada uno de estos también debe estar ordenado
void aparear (int v1[], int tamanio1, int v2[], int tamanio2, int vFinal[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    int p;

    // Tip: Recorremos ambos vectores hasta haber terminado uno de los dos primero
    while (i < tamanio1 && j < tamanio2)
    {
        // Tip: Vamos poniendo el menor de cada array en el array final, hasta terminar con uno
        if (v1[i] < v2[j])
        {
            vFinal[k] = v1[i];
            i++;
        }
        else
        {
            vFinal[k] = v2[j];
            j++;
        }
        k++;
    }

    // Tip: Agregamos los elementos del array que nos faltó terminar (hay dos for, pero sólo uno de ellos se iterará)
    for (p = i; p < tamanio1; p++)
    {
        vFinal[k] = v1[p];
        k++;
    }
    for (p = j; p < tamanio2; p++)
    {
        vFinal[k] = v2[p];
        k++;
    }
}

int main()
{
    int vec1[TAMVEC1];
    int vec2[TAMVEC2];
    int vecFinal[TAMVECFINAL];
    cout << "**Inicialice el primer vector**" << endl;
    inicializarVector(vec1, TAMVEC1);
    cout << endl << "**Inicialice el segundo vector**" << endl;
    inicializarVector(vec2, TAMVEC2);

    ordenarDeMenorAMayor(vec1, TAMVEC1);
    ordenarDeMenorAMayor(vec2, TAMVEC2);
    aparear(vec1, TAMVEC1, vec2, TAMVEC2, vecFinal);
    cout << endl << endl << "**Vectores apareados en un vector resultante**" << endl;
    for (int i = 0; i < TAMVECFINAL; i++)
    {
        cout << "Elemento " << i + 1 << ": " << vecFinal[i] << endl;
    }
    return 0;
}
