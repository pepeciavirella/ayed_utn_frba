#include <iostream>

/// ---------Ej.MI-22---------
/// Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que
/// finaliza con un Nombre = ‘FIN’, informar el nombre de la persona con mayor edad y el de la
/// más joven.

using namespace std;

int main()
{
    long fechaIngresada;
    string nombreIngresado;
    // Inicializamos el mínimo y el máximo en los valores más grande y más chico de 8 dígitos, respectivamente, para que la primera comparación ya los sobreescriba
    long fechaMasAntigua = 99999999;
    long fechaMasReciente = 0;
    // Inicializamos los nombres a mostrar, para el caso en que el primer nombre ingresado sea "FIN" (lo cual implicaría que nunca se ingrese una persona en sí)
    string nombreMayorEdad = "";
    string nombreMenorEdad = "";
    cout << "Nombre de la persona: ";
    cin >> nombreIngresado;
    while (nombreIngresado != "FIN")
    {
        cout << "Fecha de nacimiento en formato AAAAMMDD: ";
        cin >> fechaIngresada;
        if (fechaIngresada < fechaMasAntigua)
        {
            fechaMasAntigua = fechaIngresada;
            nombreMayorEdad = nombreIngresado;
        }
        if (fechaIngresada > fechaMasReciente)
        {
            fechaMasReciente = fechaIngresada;
            nombreMenorEdad = nombreIngresado;
        }
        cout << "Nombre de la persona: ";
        cin >> nombreIngresado;
    }
    if (nombreMayorEdad == "")
    {
        cout << endl << "No se ingresaron datos de personas" << endl;
    }
    else
    {
        cout << endl << "La persona de mayor edad es " << nombreMayorEdad << endl;
        cout << "La persona de menor edad es " << nombreMenorEdad << endl;
    }
    return 0;
}
