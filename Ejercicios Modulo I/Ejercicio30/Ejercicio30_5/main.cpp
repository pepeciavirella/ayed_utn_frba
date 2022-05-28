#include <iostream>

/// ---------Ej.MI-30-5)---------
/// Dado un conjunto de valores enteros, calcular e informar a) cuántos valores cero
/// hubo, b) promedio de valores positivos, c) sumatoria de valores negativos.
/// Resolver el ejercicio para los siguientes lotes de datos:
///     5) Se dan N valores, pero el proceso deberá finalizar si se cumple alguna de las
///     condiciones de 4) o si el promedio de positivos resulta mayor que seis.

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
    // Tip: Lo inicializamos así, menor a 6, para que pase la condición de corte del while antes de la primera iteración
    float promedioDePositivos = 0;
    cout << "Ingrese la cantidad de valores a ingresar: ";
    cin >> n;

    while ((i <= n) && (cantidadDeCeros <= 4) && (promedioDePositivos <= 6))
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
            promedioDePositivos = (float) sumatoriaDePositivos/cantidadDePositivos;
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
            cout << "Promedio de valores positivos: " << promedioDePositivos << endl;
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
