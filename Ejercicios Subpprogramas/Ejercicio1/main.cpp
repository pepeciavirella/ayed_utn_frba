#include <iostream>

///---------Ej. 1---------
/// Confeccione una función que , dado un valor por parámetro, devuelva el módulo de dicho
/// valor a través de su invocación. Que devuelva un valor a través de su invocación quiere decir
/// que tiene que tiene que devolver dicho valor a través del return.

using namespace std;

float modulo (float numero)
{
    if (numero < 0)
    {
        return numero * (-1);
    }
    return numero;
}

int main()
{
    float valorIngresado, moduloDelValor;
    cout << "Ingrese un valor: ";
    cin >> valorIngresado;
    moduloDelValor = modulo(valorIngresado);
    cout << "Su modulo es " << moduloDelValor << endl;
    return 0;
}
