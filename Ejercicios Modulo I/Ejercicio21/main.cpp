#include <iostream>
// Header con valores muy útiles para máximos y mínimos del tipo float: https://en.cppreference.com/w/c/types/limits#Limits_of_floating_point_types
#include <float.h>

/// ---------Ej.MI-21---------
/// Dados N valores informar el mayor, el menor y en que posición del conjunto
/// fueron ingresados.

using namespace std;

int main()
{
    int n, i;
    float valorIngresado;
    // Tip: FLT_MAX es el mayor valor absoluto que puede tener un float, y lo podemos usar al incluir el header float.h
    // Conviene usarlo como menor valor inicial, así cualquier número que se ingrese luego pasa a ser menor; lo mismo con su opuesto como mayor valor inicial
    float menorValor = FLT_MAX;
    float mayorValor = -FLT_MAX;
    int posicionMenor = 0;
    int posicionMayor = 0;
    cout << "Ingrese la cantidad de valores a ingresar: ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cout << "Ingrese un valor: ";
        cin >> valorIngresado;
        if (valorIngresado > mayorValor)
        {
            mayorValor = valorIngresado;
            posicionMayor = i;
        }
        if (valorIngresado < menorValor)
        {
            menorValor = valorIngresado;
            posicionMenor = i;
        }
    }
    cout << endl << "El mayor valor ingresado fue " << mayorValor << ", en la posicion " << posicionMayor << endl;
    cout << "El menor valor ingresado fue " << menorValor << ", en la posicion " << posicionMenor << endl;
    return 0;
}
