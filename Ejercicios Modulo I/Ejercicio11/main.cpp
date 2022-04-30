#include <iostream>

/// ---------Ej.MI-11---------
/// Se ingresa una edad, mostrar por pantalla alguna de las siguientes leyendas:
/// - ‘menor’ si la edad es menor o igual a 12
/// - ‘cadete’ si la edad está comprendida entre 13 y 18
/// - ‘juvenil’ si la edad es mayor que 18 y no supera los 26
/// - ‘mayor’ en el caso que no cumpla ninguna de las condiciones anteriores

using namespace std;

int main()
{
    unsigned int edad;
    cout << "Ingrese una edad" << endl;
    cin >> edad;
    if (edad <= 12)
    {
        cout << "menor" << endl;
    }
    else if (edad <= 18)
    {
        cout << "cadete" << endl;
    }
    else if (edad <= 26)
    {
        cout << "juvenil" << endl;
    }
    else
    {
        cout << "mayor" << endl;
    }
    return 0;
}
