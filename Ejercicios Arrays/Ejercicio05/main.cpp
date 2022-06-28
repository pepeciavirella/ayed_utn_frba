#include <iostream>

///---------Ej.5---------
/// Hacer un programa que permita realizar la suma y el producto de dos
/// vectores. El usuario deberá poder elegir el tamaño del vector (entre 2 y 10
/// valores).

using namespace std;

void inicializarVectores (float vector1[], float vector2[], int tamanio)
{
    cout << endl << "**Inicializar primer vector**" << endl;
    for (int i = 0; i < tamanio; i++)
    {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vector1[i];
    }
    cout << "**Inicializar segundo vector**" << endl;
    for (int i = 0; i < tamanio; i++)
    {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vector2[i];
    }
}

void sumarVectores (float vector1[], float vector2[], int tamanio, float vectorResultante[])
{
    for (int i = 0; i < tamanio; i++)
    {
        vectorResultante[i] = vector1[i] + vector2[i];
    }
}

// Hipótesis: Queremos hacer un producto escalar, multiplicando componente a componente y sumando para el resultado
float productoDeVectores (float vector1[], float vector2[], int tamanio)
{
    float productoEntreComponentes;
    float productoEscalar = 0;
    for (int i = 0; i < tamanio; i++)
    {
        productoEntreComponentes = vector1[i] * vector2[i];
        productoEscalar += productoEntreComponentes;
    }
    return productoEscalar;
}

void mostrarResultados (float vectorSuma[], float productoEscalar, int tamanioVector)
{
    cout << endl << endl << "**Vector suma**" << endl;
    for (int i = 0; i < tamanioVector; i++)
    {
        cout << "Elemento " << i + 1 << ": " << vectorSuma[i] << endl;
    }
    cout << endl << "Producto entre ambos vectores = " << productoEscalar << endl;
}

int main()
{
    int tamanioVectores;
    float productoEscalar;
    cout << "Ingrese el tamanio de los vectores (entre 2 y 10): ";
    cin >> tamanioVectores;
    switch(tamanioVectores)
    {
        // Tip: Definimos las sentencias de cada caso entre llaves para definir un bloque, y que las variables declaradas (vector1, vector2 y vectorSuma) sean locales
        // Si no definimos este bloque, no podemos declarar variables con el mismo nombre en los demás casos; tendríamos un total de 27 variables distintas
        case 2:
        {
            float vector1[2];
            float vector2[2];
            float vectorSuma[2];
            inicializarVectores(vector1, vector2, 2);
            sumarVectores(vector1, vector2, 2, vectorSuma);
            productoEscalar = productoDeVectores(vector1, vector2, 2);
            mostrarResultados(vectorSuma, productoEscalar, 2);
            break;
        }
        case 3:
        {
            float vector1[3];
            float vector2[3];
            float vectorSuma[3];
            inicializarVectores(vector1, vector2, 3);
            sumarVectores(vector1, vector2, 3, vectorSuma);
            productoEscalar = productoDeVectores(vector1, vector2, 3);
            mostrarResultados(vectorSuma, productoEscalar, 3);
            break;
        }
        case 4:
        {
            float vector1[4];
            float vector2[4];
            float vectorSuma[4];
            inicializarVectores(vector1, vector2, 4);
            sumarVectores(vector1, vector2, 4, vectorSuma);
            productoEscalar = productoDeVectores(vector1, vector2, 4);
            mostrarResultados(vectorSuma, productoEscalar, 4);
            break;
        }
        case 5:
        {
            float vector1[5];
            float vector2[5];
            float vectorSuma[5];
            inicializarVectores(vector1, vector2, 5);
            sumarVectores(vector1, vector2, 5, vectorSuma);
            productoEscalar = productoDeVectores(vector1, vector2, 5);
            mostrarResultados(vectorSuma, productoEscalar, 5);
            break;
        }
        case 6:
        {
            float vector1[6];
            float vector2[6];
            float vectorSuma[6];
            inicializarVectores(vector1, vector2, 6);
            sumarVectores(vector1, vector2, 6, vectorSuma);
            productoEscalar = productoDeVectores(vector1, vector2, 6);
            mostrarResultados(vectorSuma, productoEscalar, 6);
            break;
        }
        case 7:
        {
            float vector1[7];
            float vector2[7];
            float vectorSuma[7];
            inicializarVectores(vector1, vector2, 7);
            sumarVectores(vector1, vector2, 7, vectorSuma);
            productoEscalar = productoDeVectores(vector1, vector2, 7);
            mostrarResultados(vectorSuma, productoEscalar, 7);
            break;
        }
        case 8:
        {
            float vector1[8];
            float vector2[8];
            float vectorSuma[8];
            inicializarVectores(vector1, vector2, 8);
            sumarVectores(vector1, vector2, 8, vectorSuma);
            productoEscalar = productoDeVectores(vector1, vector2, 8);
            mostrarResultados(vectorSuma, productoEscalar, 8);
            break;
        }
        case 9:
        {
            float vector1[9];
            float vector2[9];
            float vectorSuma[9];
            inicializarVectores(vector1, vector2, 9);
            sumarVectores(vector1, vector2, 9, vectorSuma);
            productoEscalar = productoDeVectores(vector1, vector2, 9);
            mostrarResultados(vectorSuma, productoEscalar, 9);
            break;
        }
        case 10:
        {
            float vector1[10];
            float vector2[10];
            float vectorSuma[10];
            inicializarVectores(vector1, vector2, 10);
            sumarVectores(vector1, vector2, 10, vectorSuma);
            productoEscalar = productoDeVectores(vector1, vector2, 10);
            mostrarResultados(vectorSuma, productoEscalar, 10);
            break;
        }
        default:
            cout << "El tamano ingresado no esta entre 2 y 10" << endl;
            break;
    }
    return 0;
}
