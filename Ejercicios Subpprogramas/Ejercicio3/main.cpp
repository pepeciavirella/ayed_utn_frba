#include <iostream>

///---------Ej. 3---------
/// Confeccione una función que reciba un número entero n y devuelva el factorial de dicho
/// número.

using namespace std;

long factorial (unsigned int n)
{
    int i;
    long productoria = 1;
    for (i = 1; i <= n; i++)
    {
        productoria *= i;
    }
    return productoria;
}

int main()
{
    int unNumero;
    cout << "Ingrese un numero natural: ";
    cin >> unNumero;
    cout << "Su factorial es " << factorial(unNumero) << endl;
    return 0;
}
