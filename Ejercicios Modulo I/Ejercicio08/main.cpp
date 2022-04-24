#include <iostream>

/// ---------Ej.MI-8---------
/// Dado un triángulo representado por sus lados L1, L2, L3, determinar e imprimir
/// una leyenda según sea: equilátero, isósceles o escálenos.

using namespace std;

int main()
{
    float l1, l2, l3;
    cout << "Ingrese la longitud de los tres lados, una tras otra" << endl;
    cin >> l1 >> l2 >> l3;
    if (l1 == l2)
    {
        if (l2 == l3)
        {
            cout << "Es un triangulo equilatero" << endl;
        }
        else
        {
            cout << "Es un triangulo isosceles" << endl;
        }
    }
    else if (l2 == l3 || l1 == l3)
    {
        cout << "Es un triangulo isosceles" << endl;
    }
    else
    {
        cout << "Es un triangulo escaleno" << endl;
    }
    return 0;
}
