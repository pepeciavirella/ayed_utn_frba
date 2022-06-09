#include <iostream>

/// ---------Ej.MI-35---------
/// Dada una serie de números enteros, informar:
///     a) su factorial
///     b) cuantos múltiplos de 3
///     c) cuantos múltiplos de 5
///     d) cuantos múltiplos de 3 y de 5
/// Utilice las funciones de ejercicios anteriores.

using namespace std;

long factorial (unsigned int x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return x * factorial(x - 1);
    }
}

bool esMultiploDe (int a, int b)
{
    int resto = a % b;
    if (resto == 0)
    {
        return true;
    }
    // Tip: No hace falta poner esta sentencia en un else, ya que sólo se ejecutará si la condición del if no se cumple, y es la última del subprograma
    return false;
}

int main()
{
    int i, cantidadDeNumeros, numeroIngresado;
    bool multiploDe3, multiploDe5;
    int cantidadMultiplosDe3 = 0;
    int cantidadMultiplosDe5 = 0;
    int cantidadMultiplosDeAmbos = 0;
    cout << "Ingrese la cantidad de enteros a ingresar: ";
    cin >> cantidadDeNumeros;

    for (i = 1; i <= cantidadDeNumeros; i++)
    {
        cout << endl << "Numero " << i << ": ";
        cin >> numeroIngresado;
        cout << "Su factorial es " << factorial(numeroIngresado) << endl;
        multiploDe3 = esMultiploDe(numeroIngresado, 3);
        multiploDe5 = esMultiploDe(numeroIngresado, 5);
        if (multiploDe3)
        {
            cantidadMultiplosDe3++;
            if (multiploDe5)
            {
                cantidadMultiplosDeAmbos++;
            }
        }
        if (multiploDe5)
        {
            cantidadMultiplosDe5++;
        }
    }

    cout << endl << "****RESULTADOS****" << endl;
    cout << "Cantidad de multiplos de 3: " << cantidadMultiplosDe3 << endl;
    cout << "Cantidad de multiplos de 5: " << cantidadMultiplosDe5 << endl;
    cout << "Cantidad de multiplos de 3 y de 5: " << cantidadMultiplosDeAmbos << endl;
    return 0;
}
