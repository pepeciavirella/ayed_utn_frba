#include <iostream>

///---------Ej.8---------
/// Convertir una tabla de 6 x 5 en un vector ordenado de mayor a menor.

using namespace std;

void vectorizarTabla (float tabla[][5], int cantidadFilasTabla, float vectorResultante[])
{
    int i, j, indiceEnVector;
    for (i = 0; i < cantidadFilasTabla; i++)
    {
        for (j = 0; j < 5; j++)
        {
            indiceEnVector = (i * 5) + j;
            vectorResultante[indiceEnVector] = tabla[i][j];
        }
    }
}

// Tip: Usado tal cual se hizo para ordenar descendentemente en el ejercicio 6
void ordenarDeMayorAMenor (float vec[], int tamanio)
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
}

int main()
{
    float tabla[6][5];
    float vec[30];
    int i, j, k;
    cout << "**Inicializar tabla**" << endl;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout << "Fila " << i + 1 << ", columna " << j + 1 << ": ";
            cin >> tabla[i][j];
        }
    }

    vectorizarTabla(tabla, 6, vec);
    ordenarDeMayorAMenor(vec, 30);
    cout << endl << "**Tabla convertida en un vector ordenado de mayor a menor**" << endl;
    for (k = 0; k < 30; k++)
    {
        cout << "Elemento " << k + 1 << ": " << vec[k] << endl;
    }
    return 0;
}
