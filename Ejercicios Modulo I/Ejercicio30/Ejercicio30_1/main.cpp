#include <iostream>

/// ---------Ej.MI-30-1)---------
/// Dado un conjunto de valores enteros, calcular e informar a) cuántos valores cero
/// hubo, b) promedio de valores positivos, c) sumatoria de valores negativos.
/// Resolver el ejercicio para los siguientes lotes de datos:
///     1) 167 valores enteros

using namespace std;

int main()
{
    int i, valorIngresado;
    int cantidadDeCeros = 0;
    int sumatoriaDePositivos = 0;
    int cantidadDePositivos = 0;
    int sumatoriaDeNegativos = 0;
    for (i = 1; i <= 167; i++)
    {
        cout << "Valor " << i << ": ";
        cin >> valorIngresado;

        if (valorIngresado == 0)
        {
            cantidadDeCeros++;
        }
        else if (valorIngresado > 0)
        {
            cantidadDePositivos++;
            sumatoriaDePositivos += valorIngresado;
        }
        else
        {
            sumatoriaDeNegativos += valorIngresado;
        }
    }
    cout << endl << "****RESULTADOS****" << endl;
    cout << "Cantidad de ceros: " << cantidadDeCeros << endl;
    if (cantidadDePositivos > 0)
    {
        cout << "Promedio de valores positivos: " << (float) sumatoriaDePositivos/cantidadDePositivos << endl;
    }
    else
    {
        cout << "No se ingresaron valores positivos" << endl;
    }
    cout << "Sumatoria de valores negativos: " << sumatoriaDeNegativos << endl;
    return 0;
}
