#include <iostream>

///---------Ej. 1---------
/// Modifique el programa anterior para convertir el subprograma en un procedimiento (return
/// void). El valor absoluto debe aplicarse directamente sobre el parámetro actual (pasaje por
/// referencia).

using namespace std;

void modulo (float numeroOriginal, float &moduloDelNumero)
{
    moduloDelNumero = numeroOriginal;
    if (numeroOriginal < 0)
    {
        moduloDelNumero = numeroOriginal * (-1);
    }
}

int main()
{
    float valorIngresado, moduloDelValor;
    cout << "Ingrese un valor: ";
    cin >> valorIngresado;
    modulo(valorIngresado, moduloDelValor);
    cout << "Su modulo es " << moduloDelValor << endl;
    return 0;
}
