#include <iostream>

/// ---------Ej.MI-7---------
/// Dado tres valores determinar e imprimir una leyenda según sea: “Forman
/// triangulo” o “No forman triangulo”.

using namespace std;

int main()
{
    float lado1, lado2, lado3;
    cout << "Ingrese la longitud de los tres lados, una tras otra" << endl;
    cin >> lado1 >> lado2 >> lado3;
    // Tip: Podemos usar el Teorema de Desigualdad Triangular: la suma de cada par de lados debe ser mayor al otro, pero la resta debe ser menor
    // No es necesario chequear esto para los 3 pares de lados: si despejaramos estas 4 desigualdades, llegaríamos a las dos restantes
    if (
        (lado1 + lado2) > lado3
        && abs(lado1 - lado2) < lado3
        && (lado1 + lado3) > lado2
        && abs(lado1 - lado3) < lado2
    )
    {
        cout << "Forman triangulo" << endl;
    }
    else {
        cout << "No forman triangulo" << endl;
    }
    return 0;
}
