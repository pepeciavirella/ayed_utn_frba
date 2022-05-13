#include <iostream>

/// ---------Ej.MI-16---------
/// Ingresar e informar valores, mientras que el valor ingresado no sea negativo.
/// Informar la cantidad de valores ingresados.

using namespace std;

int main()
{
    int valorIngresado;
    int cantidadDeValores = 0;
    cout << "Ingrese un valor no negativo para contar, o uno negativo para finalizar" << endl;
    cin >> valorIngresado;
    while (valorIngresado >= 0)
    {
        cout << "Se ingreso el valor " << valorIngresado << endl;
        cantidadDeValores++;
        cout << "Ingrese un valor no negativo para contar, o uno negativo para finalizar" << endl;
        cin >> valorIngresado;
    }
    // Tip: El último valor ingresado, negativo o no, debe contarse para el informe al final, así que lo sumamos (la lógica del while no lo hará en ese caso)
    cout << endl << "Cantidad de valores ingresados: " << cantidadDeValores + 1 << endl;
    return 0;
}
