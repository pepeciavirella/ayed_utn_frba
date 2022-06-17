#include <iostream>
#include <cmath>

///---------Ej.MI-37---------
/// Desarrolle la función float CalcularPorcentajeDiferencia(int A ,int B)
/// que recibe dos valores y retorne el siguiente cálculo: (B-A) *100 / (A+B)

using namespace std;

float CalcularPorcentajeDiferencia (int A, int B)
{
    // Hipótesis: Si queremos hallar la diferencia, vamos a tomarla absoluta (por si primero ingresan el valor mayor)
    int diferencia = abs(A - B);
    int suma = A + B;
    float proporcionDiferencia = (float) diferencia / suma;
    return proporcionDiferencia * 100;
}

int main()
{
    int a, b;
    float porcentajeDiferencia;
    cout << "Ingrese dos enteros" << endl;
    cin >> a;
    cin >> b;
    if (a == b)
    {
        cout << endl << "Ambos numeros son iguales" << endl;
    }
    else if ((a + b) == 0)
    {
        cout << endl << "Ambos numeros suman 0" << endl;
    }
    else
    {
        porcentajeDiferencia = CalcularPorcentajeDiferencia(a, b);
        cout << endl << "La diferencia entre ambos representa el " << porcentajeDiferencia << "% de su suma" << endl;
    }
    return 0;
}
