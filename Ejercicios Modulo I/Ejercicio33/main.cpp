#include <iostream>

/// ---------Ej.MI-33---------
/// Desarrollar una función que calcule el máximo común divisor de dos números
/// enteros A, B con el siguiente algoritmo:
///     1) Dividir A por B, y calcular el resto (0 < R < B)
///     2) Si R = 0, el MCD es B, si no seguir en 3)
///     3) Reemplazar A por B, B por R, y volver al paso 1)

using namespace std;

int mcd (int a, int b)
{
    int r = a % b;
    if (r == 0)
    {
        return b;
    }
    else
    {
        return mcd(b, r);
    }
}

int main()
{
    int unNumero, otroNumero, maximoComunDivisor;
    cout << "Ingrese dos enteros" << endl;
    cin >> unNumero >> otroNumero;
    maximoComunDivisor = mcd(unNumero, otroNumero);
    cout << "Su maximo comun divisor es " << maximoComunDivisor << endl;
    return 0;
}
