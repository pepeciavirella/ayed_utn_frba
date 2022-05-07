#include <iostream>

/// ---------Ej.MI-14---------
/// Dados 50 números enteros, informar el promedio de los mayores que 100 y la
/// suma de los menores que –10.

using namespace std;

int main()
{
    int i, enteroIngresado;
    float promedioMayoresQue100;
    int cantidadMayoresQue100 = 0;
    int sumaMayoresQue100 = 0;
    int sumaMenoresQueMenos10 = 0;
    for (i = 1; i <= 50; i++)
    {
        cout << "Ingrese el entero numero " << i << ": ";
        cin >> enteroIngresado;
        if (enteroIngresado > 100)
        {
            cantidadMayoresQue100 += 1;
            sumaMayoresQue100 += enteroIngresado;
        }
        else if (enteroIngresado < -10)
        {
            sumaMenoresQueMenos10 += enteroIngresado;
        }
    }
    promedioMayoresQue100 = (float) sumaMayoresQue100 / cantidadMayoresQue100;
    cout << endl << "El promedio de enteros mayores que 100 es " << promedioMayoresQue100 << endl;
    cout << "La suma de enteros menores que -10 es " << sumaMenoresQueMenos10 << endl;
    return 0;
}
