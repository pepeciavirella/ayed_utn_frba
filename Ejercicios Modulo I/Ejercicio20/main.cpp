#include <iostream>

/// ---------Ej.MI-20---------
/// Dados 10 valores informar el mayor

using namespace std;

int main()
{
    int i;
    float valorIngresado, mayorValor;
    // Tip: El primer valor ingresado sí o sí será el mayor, al menos durante la primera iteración; en la próxima, ya queremos compararlo
    cout << "Ingrese un valor: ";
    cin >> mayorValor;
    // Tip: Queremos hacer otras 9 iteraciones con la misma lógica, por eso usamos una sentencia iterativa con cantidad conocida de repeticiones (for)
    for (i = 1; i <= 9; i++)
    {
        cout << "Ingrese un valor: ";
        cin >> valorIngresado;
        if (valorIngresado > mayorValor)
        {
            mayorValor = valorIngresado;
        }
    }
    cout << endl << "El mayor valor ingresado fue " << mayorValor << endl;
    return 0;
}
