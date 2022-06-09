#include <iostream>

/// ---------Ej.MI-34---------
/// Desarrollar una función tal que dado un número entero positivo calcule y retorne
/// su factorial.

using namespace std;

// Tip: La formula del factorial de un numero N (N!) es
// N! = 1           si N = 0
// N! = N * (N-1)!  si N > 0
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

int main()
{
    unsigned int unNumero;
    cout << "Ingrese un numero natural: ";
    cin >> unNumero;
    cout << "Su factorial es " << factorial(unNumero) << endl;
    return 0;
}
