#include <iostream>
// Tip: Incluido para poder usar las funciones pow y sqrt
#include <cmath>

///---------Ej. 5---------
/// Realice una función que reciba los coeficientes de un polinomio de grado 2 y devuelva las
/// raíces del mismo siempre y cuando sean raíces reales.

using namespace std;

bool raicesReales (float a, float b, float c, float &r1, float &r2)
{
    float discriminante = pow(b, 2) - (4 * a * c);
    // Tip: Cuando el discriminante de la fórmula de Bhaskara es negativo, las raíces del polinomio son imaginarias.
    // Hacemos que la función retorne true si hay raíces reales, o false en caso contrario
    if (discriminante < 0)
    {
        return false;
    }

    // Tip: La función sqrt(float n) nos permite hallar la raíz cuadrada de cierto número n
    float raizDelDiscriminante = sqrt(discriminante);
    r1 = (b * (-1) + raizDelDiscriminante) / (2 * a);
    r2 = (b * (-1) - raizDelDiscriminante) / (2 * a);
    return true;
}

int main()
{
    float coeficienteCuadratico, coeficienteLineal, terminoIndependiente, raiz1, raiz2;
    bool hayRaicesReales;
    cout << "Ingrese los coeficientes del polinomio de forma A.x^2 + B.x + C" << endl;
    cout << "A = ";
    cin >> coeficienteCuadratico;
    cout << "B = ";
    cin >> coeficienteLineal;
    cout << "C = ";
    cin >> terminoIndependiente;

    hayRaicesReales = raicesReales(coeficienteCuadratico, coeficienteLineal, terminoIndependiente, raiz1, raiz2);
    if (hayRaicesReales)
    {
        cout << endl << "Las raices reales del polinomio son " << raiz1 << " y " << raiz2 << endl;
    }
    else
    {
        cout << endl << "El polinomio no tiene raices reales" << endl;
    }
    return 0;
}
