#include <iostream>

///---------Ej.MI-36---------
/// Dada la fracción P/Q, para P y Q naturales informar la mayor cantidad de
/// simplificaciones. Desarrolle y utilice una función que reciba dos números naturales y retorne el
/// menor factor común. Ej: 360/60 = 180/30 = 90/15 = 30/5 = 6/1

using namespace std;

// Tip: Tal y como se hizo para el ejercicio MI-33, solo que sin el else redundante al final
int mcd (int a, int b)
{
    int r = a % b;
    if (r == 0)
    {
        return b;
    }
    return mcd(b, r);
}

int menorFactorComun (int unNumero, int otroNumero)
{
    int i;
    int mayorFactorComun = mcd(unNumero, otroNumero);
    // Tip: No arrancamos en 1 porque es divisor universal, y no evaluamos más allá del mayor divisor que compartan
    for (i = 2; i <= mayorFactorComun; i++)
    {
        if ((unNumero % i) == 0 && (otroNumero % i == 0))
        {
            return i;
        }
    }
    return mayorFactorComun;
}

int main()
{
    int p, q, menorDivisor;
    cout << "Ingrese el numerador y el denominador de una fraccion P/Q" << endl;
    cin >> p;
    cin >> q;
    cout << endl << "Sus simplificaciones son:" << endl;
    do
    {
        cout << p << "/" << q << endl;
        menorDivisor = menorFactorComun(p,q);
        p = p/menorDivisor;
        q = q/menorDivisor;
    // Si el menor factor común entre ambos es 1, ambos números son coprimos, con lo cual llegamos a una fracción irreducible
    } while (menorDivisor != 1);
    return 0;
}
