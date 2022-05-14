#include <iostream>

/// ---------Ej.MI-19 (MI-18)---------
/// Dado un valor M determinar y emitir un listado con los M primeros múltiplos de
/// 3 que no lo sean de 5, dentro del conjunto de los números naturales.
/// ESCRIBIR UTILIZANDO CICLOS 1-N.

using namespace std;

int main()
{
    unsigned int m;
    int multiplosEncontrados = 0;
    // Tip: Lo inicializamos en 0, ya que en la primera iteración le vamos a sumar 3 y así hallar 3, que es un múltiplo natural
    int multiploDe3 = 0;
    cout << "Ingrese la cantidad de multiplos a imprimir" << endl;
    cin >> m;
    cout << endl << "******MULTIPLOS DE 3 PERO NO DE 5******" << endl;
    do
    {
        multiploDe3 += 3;
        if ((multiploDe3 % 5) != 0)
        {
            cout << multiploDe3 << endl;
            multiplosEncontrados++;
        }
    } while (multiplosEncontrados < m);
    return 0;
}
