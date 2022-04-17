#include <iostream>

///---------Ej.MI-4---------
/// A partir de un valor entero ingresado por teclado, se pide informar:
///     a) La quinta parte de dicho valor
///     b) El resto de la división por 5
///     c) La séptima parte del resultado del punto a)

using namespace std;

int main()
{
    int valorIngresado;
    cout << "Ingrese un entero" << endl;
    cin >> valorIngresado;
    // Tip: Casteamos (forzamos) el resultado al tipo float, ya que en la división entera los int tienen precedencia
    float quintaParte = (float) valorIngresado / 5;
    int restoDeDivision = valorIngresado % 5;
    float septimaParteDeQuintaParte = quintaParte / 7;
    cout << "La quinta parte es " << quintaParte << endl;
    cout << "El resto de dividir por 7 es " << restoDeDivision << endl;
    cout << "La septima parte de la quinta parte es " << septimaParteDeQuintaParte << endl;
    return 0;
}
