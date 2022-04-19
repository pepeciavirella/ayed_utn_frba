#include <iostream>

///---------Ej.MI-5---------
/// Dados dos valores enteros y distintos, emitir una leyenda apropiada que informe cuál es el
/// mayor entre ellos.

using namespace std;

int main()
{
    int unEntero, otroEntero;
    cout << "Ingrese dos enteros distintos" << endl;
    // Tip: Podemos leer varias líneas del flujo de entrada (es decir, la terminal al escribir con el teclado, apretando Enter entre cada una)
    // si usamos varias veces el >> (también conocido como "operador de extracción")
    cin >> unEntero >> otroEntero;
    if (unEntero > otroEntero)
    {
        cout << "El mayor entre ambos es " << unEntero << endl;
    }
    else if (otroEntero > unEntero)
    {
        cout << "El mayor entre ambos es " << otroEntero << endl;
    }
    else
    {
        cout << "Ambos enteros son iguales" << endl;
    }
    return 0;
}
