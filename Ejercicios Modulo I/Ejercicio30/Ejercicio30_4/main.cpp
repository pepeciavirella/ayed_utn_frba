#include <iostream>

/// ---------Ej.MI-30-4)---------
/// Dado un conjunto de valores enteros, calcular e informar a) cuántos valores cero
/// hubo, b) promedio de valores positivos, c) sumatoria de valores negativos.
/// Resolver el ejercicio para los siguientes lotes de datos:
///     4) Se dan N valores, pero el proceso deberá finalizar si se procesan todos los valores o s
///     la cantidad de ceros supera a cuatro

using namespace std;

int main()
{
    unsigned int n;
    int valorIngresado;
    unsigned int i = 1;
    int cantidadDeCeros = 0;
    int sumatoriaDePositivos = 0;
    int cantidadDePositivos = 0;
    int sumatoriaDeNegativos = 0;
    cout << "Ingrese la cantidad de valores a ingresar: ";
    cin >> n;

    while ((i <= n) && (cantidadDeCeros <= 4))
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

        i++;
    }

    cout << endl << "****RESULTADOS****" << endl;
    if (n > 0)
    {
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
    }
    else
    {
        cout << "No se ingresaron valores" << endl;
    }
    return 0;
}
