#include <iostream>

///---------Ej. 4---------
/// Elabore un procedimiento que reciba tres parámetros, n1, n2 y mayor. A través del
/// parámetro “mayor” devuelva el mayor número entre n1 y n2.

using namespace std;

void asignarMayor (float n1, float n2, float &mayor)
{
    if (n1 > n2)
    {
        mayor = n1;
    }
    else
    {
        mayor = n2;
    }
}

int main()
{
    float unValor, otroValor, valorMayor;
    cout << "Ingrese dos valores, uno tras otro" << endl;
    cin >> unValor >> otroValor;
    asignarMayor(unValor, otroValor, valorMayor);
    cout << endl << "El mayor entre ambos es " << valorMayor << endl;
    return 0;
}
