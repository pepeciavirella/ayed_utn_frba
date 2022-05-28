#include <iostream>

/// ---------Ej.MI-30-3)---------
/// Dado un conjunto de valores enteros, calcular e informar a) cuántos valores cero
/// hubo, b) promedio de valores positivos, c) sumatoria de valores negativos.
/// Resolver el ejercicio para los siguientes lotes de datos:
///     3) El conjunto de valores termina con un valor igual al anterior

using namespace std;

int main()
{
    int i, valorIngresado, valorAnterior;
    int cantidadDeCeros = 0;
    int sumatoriaDePositivos = 0;
    int cantidadDePositivos = 0;
    int sumatoriaDeNegativos = 0;
    cout << "Ingrese un valor: ";
    cin >> valorIngresado;
    // Tip: Le sumamos 1 para que a la primera iteración sean diferentes, y la condición de corte del while no se cumpla
    valorAnterior = valorIngresado + 1;

    while (valorIngresado != valorAnterior)
    {
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

        valorAnterior = valorIngresado;
        cout << "Ingrese un valor, o repita el anterior para terminar: ";
        cin >> valorIngresado;
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
