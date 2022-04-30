#include <iostream>

/// ---------Ej.MI-9---------
/// Dados un mes y el año correspondiente informar cuantos días tiene el mes.

using namespace std;

int main()
{
    int mes, agno;
    cout << "Ingrese el anio" << endl;
    cin >> agno;
    cout << "Ingrese el numero de mes" << endl;
    cin >> mes;
    switch (mes)
    {
        // Enero, Marzo, Mayo, Julio, Agosto, Octubre y Diciembre siempre tienen 31 días
        case 1: case 3:
        case 5: case 7:
        case 8: case 10: case 12:
            cout << "Tiene 31 dias" << endl;
            break;
        // Abril, Junio, Septiembre y Noviembre siempre tienen 31 días
        case 4:
        case 6:
        case 9:
        case 11:
            cout << "Tiene 30 dias" << endl;
            break;
        // Febrero tiene 29 días si el año es bisiesto, y 28 si no lo es.
        // Un año bisiesto es "todo año divisible por 4, siempre y cuando no sea secular (divisible por 100), a menos que también sea divisible por 400"
        // Por ejemplo, 2004, 2008 y 2012 son bisiestos; 2000 también lo es (divisible por 400), pero 1900 no lo es (divisible por 100 pero no por 400)
        case 2:
            if (
                (agno % 400 == 0)
                || ((agno % 100 != 0) && (agno % 4 == 0))
            )
            {
                cout << "Tiene 29 dias" << endl;
            }
            else {
                cout << "Tiene 28 dias" << endl;
            }
            break;
        default:
            cout << "El numero no corresponde a ningun mes" << endl;
            break;
    }
    return 0;
}
