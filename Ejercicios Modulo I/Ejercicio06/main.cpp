#include <iostream>

///---------Ej.MI-6---------
/// Dadas dos fechas informar cual es la más reciente. Determine cuales serían los
/// datos de entrada y las leyendas a informar de acuerdo al proceso solicitado.

using namespace std;

int main()
{
    // Decisión: Para usar enteros y pedir un formato de entrada un poco más sencillo que el "AAAAMMDD" de otros ejercicios,
    // le pedimos al usuario que ingrese cada componente de cada fecha por separado, uno a la vez.
    int dia1, mes1, agno1, dia2, mes2, agno2;
    cout << "Ingrese la primer fecha en numeros enteros: primero el dia, luego el mes y luego el año" << endl;
    cin >> dia1 >> mes1 >> agno1;
    cout << "Ingrese la segunda fecha en numeros enteros: primero el dia, luego el mes y luego el año" << endl;
    cin >> dia2 >> mes2 >> agno2;

    if (agno1 == agno2)
    {
        if (mes1 == mes2)
        {
            if (dia1 == dia2)
            {
                cout << "Ambas fechas son iguales" << endl;
            }
            else if (dia1 < dia2)
            {
                cout << "La segunda fecha es la mas reciente" << endl;
            }
            else
            {
                cout << "La primer fecha es la mas reciente" << endl;
            }
        }
        else if (mes1 < mes2)
        {
            cout << "La segunda fecha es la mas reciente" << endl;
        }
        else
        {
            cout << "La primer fecha es la mas reciente" << endl;
        }
    }
    else if (agno1 < agno2)
    {
        cout << "La segunda fecha es la mas reciente" << endl;
    }
    else
    {
        cout << "La primer fecha es la mas reciente" << endl;
    }

    return 0;
}
