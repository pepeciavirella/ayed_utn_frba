#include <iostream>

///---------Ej. 1---------
/// Leer una lista de 10 valores enteros listarlos por pantalla en sentido inverso
/// al que ingresaron.

using namespace std;

int main()
{
    int valoresIngresados[10];
    // Tip: Declaramos el int en los paréntesis del for, ya que será la variable a utilizar como contador
    // (esto la vuelve local a sus iteraciones: puedo declarar otra i en el main, si quisiera)
    for (int i = 0; i <= 9; i++)
    {
        // Tip: Aumentamos en uno el índice al mostrar, para que se imprima un valor inteligible
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> valoresIngresados[i];
    }
    cout << endl << "Los valores ingresados fueron, de atras hacia adelante: " << endl;
    for (int j = 9; j >= 0; j--)
    {
        cout << valoresIngresados[i] << endl;
    }
    return 0;
}
