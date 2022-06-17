#include <iostream>

///---------Ej.MI-40---------
/// Desarrollar el procedimiento string Tendencia(int A, int B)
/// que dados dos valores A y B, retorne una cadena de acuerdo al siguiente cuadro:
/// B - A < 0           Decreciente   |  B - A < 2% de A     Estable
/// B - A < 5% de A     Leve ascenso  |  Resto               En ascenso

using namespace std;

// Hipótesis: El enunciado habla de procedimiento, pero también nos muestra el prototipo esperado para la función; respetamos este último
string Tendencia(int A, int B)
{
    int diferencia = B - A;
    if (diferencia < 0)
    {
        return "Decreciente";
    }
    else if (diferencia < (A * 0.02))
    {
        return "Estable";
    }
    else if (diferencia < (A * 0.05))
    {
        return "Leve ascenso";
    }
    return "En ascenso";
}

int main()
{
    int valorInicial, valorFinal;
    string tendenciaEntreValores;
    cout << "Ingrese el valor inicial: ";
    cin >> valorInicial;
    cout << "Ingrese el valor final: ";
    cin >> valorFinal;
    tendenciaEntreValores = Tendencia(valorInicial, valorFinal);
    cout << endl << "Del valor inicial al valor final hay una tendencia " << tendenciaEntreValores << endl;
    return 0;
}
