#include <iostream>

///---------Ej.MI-1---------
/// Dados dos valores enteros A y B, informar la suma, la resta y el producto

using namespace std;

int main()
{
    int a, b, suma, resta1, resta2, producto;
    cout << "Ingrese el primer número" << endl;
    cin >> a;
    cout << "Ingrese el segundo número" << endl;
    cin >> b;
    suma = a + b;
    resta1 = a - b;
    resta2 = b - a;
    producto = a * b;
    cout << "La suma de ambos números es " << suma << endl;
    cout << "La resta del primero menos el segundo es " << resta1 << endl;
    cout << "La resta del segundo menos el primero es " << resta2 << endl;
    cout << "Y el producto entre ambos números es " << producto << endl;
    return 0;
}
