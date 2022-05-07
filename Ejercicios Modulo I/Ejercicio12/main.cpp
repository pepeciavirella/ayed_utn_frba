#include <iostream>

/// ---------Ej.MI-12---------
/// Informar los primeros 100 números naturales y su sumatoria

using namespace std;

int main()
{
    int i;
    int sumatoria = 100;
    cout << "Los primeros 100 numeros naturales son:" << endl;
    // Tip: Los números naturales son "aquellos con los que podemos contar", así que no incluimos el 0
    for (i = 1; i <= 100; i++)
    {
        cout << i << endl;
        // Tip: El operador += es un "operador de asignación", que re-asigna una variable sumándole un valor; "x += y" es equivalente a "x = x + y"
        sumatoria += i;
    }
    cout << endl << "Su sumatoria es " << sumatoria << endl;
    return 0;
}
