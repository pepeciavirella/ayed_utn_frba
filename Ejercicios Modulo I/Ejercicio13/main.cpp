#include <iostream>

/// ---------Ej.MI-13---------
/// Dados N y M números naturales, informar su producto por sumas sucesivas.

using namespace std;

int main()
{
    unsigned int n, m, contador;
    unsigned int producto = 0;
    cout << "Ingrese dos numeros naturales, uno tras otro" << endl;
    cin >> n >> m;
    // Tip: N * M equivale a sumar M veces el valor de N, o "M sumas sucesivas de N"; por ejemplo = 2 * 4 = 2 + 2 + 2 + 2 = 8, sumamos 4 ocurrencias de 2
    for (contador = 1; contador <= m; contador++)
    {
        producto += n;
    }
    cout << "El producto es " << producto << endl;
    return 0;
}
