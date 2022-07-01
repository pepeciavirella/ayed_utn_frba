#include <iostream>

#define M 3
#define N 2
#define P 3
#define TAM_VECTOR 18

///---------Ej.11---------
/// Dada un matriz tridimensional de N x M x P se pide ordenarla de
/// menor a mayor.

using namespace std;

void inicializarMatriz (float matrizTridimensional[][N][P], int dimension1)
{
    int i, j, k;
    for (i = 0; i < dimension1; i++)
    {
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < P; k++)
            {
                cout << "Elemento (" << i + 1 << ", " << j + 1 << ", " << k + 1 << "): ";
                cin >> matrizTridimensional[i][j][k];
            }
        }
    }
}

// Tip: Necesitamos una función para "aplanar" la matriz tridimensional en un vector unidimensional, que es más fácil de ordenar
void vectorizarMatriz (float matrizTridimensional[][N][P], int dimension1, float vectorResultante[])
{
    int i, j, k, indiceEnVector;
    for (i = 0; i < dimension1; i++)
    {
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < P; k++)
            {
                indiceEnVector = (i * (N * P)) + (j * P) + k;
                vectorResultante[indiceEnVector] = matrizTridimensional[i][j][k];
            }
        }
    }
}

void ordenarDeMenorAMayor (float vec[], int tamanio)
{
    int i, j;
    float auxiliar;
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

void matrificarVector (float vec[], float matrizTridimensional[][N][P], int dimension1Matriz)
{
    int i, j, k, indiceEnVector;
    for (i = 0; i < dimension1Matriz; i++)
    {
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < P; k++)
            {
                indiceEnVector = (i * (N * P)) + (j * P) + k;
                matrizTridimensional[i][j][k] = vec[indiceEnVector];
            }
        }
    }
}

void mostrarMatriz (float matrizTridimensional[][N][P], int dimension1)
{
    int i, j, k;
    for (i = 0; i < dimension1; i++)
    {
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < P; k++)
            {
                cout << "Elemento (" << i + 1 << ", " << j + 1 << ", " << k + 1 << "): " << matrizTridimensional[i][j][k] << endl;
            }
        }
    }
}

int main()
{
    float matriz[M][N][P];
    float vecAuxiliar[TAM_VECTOR];
    cout << "**Inicializar matriz**" << endl;
    inicializarMatriz(matriz, M);

    vectorizarMatriz(matriz, M, vecAuxiliar);
    ordenarDeMenorAMayor(vecAuxiliar, TAM_VECTOR);
    matrificarVector(vecAuxiliar, matriz, M);
    cout << endl << "**Matriz ordenada de menor a mayor**" << endl;
    mostrarMatriz(matriz, M);
    return 0;
}
