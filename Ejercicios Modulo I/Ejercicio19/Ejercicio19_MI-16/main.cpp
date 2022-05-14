#include <iostream>

/// ---------Ej.MI-19 (MI-16)---------
/// Ingresar e informar valores, mientras que el valor ingresado no sea negativo.
/// Informar la cantidad de valores ingresados.
/// ESCRIBIR UTILIZANDO CICLOS 1-N.

using namespace std;

int main()
{
    int valorIngresado;
    int cantidadDeValores = 0;
    do
    {
        // Tip: Queremos que se ingrese al menos un valor, y el do-while ya nos ofrece eso
        cout << "Ingrese un valor no negativo para contar, o uno negativo para finalizar" << endl;
        cin >> valorIngresado;
        // Tip: Vamos a mostrar todos los valores ingresados; podríamos filtrar los negativos, pero sería hacer un if igual a la condición del while, y no tiene sentido
        cout << "Se ingreso el valor " << valorIngresado << endl;
        cantidadDeValores++;
    } while (valorIngresado >= 0);
    cout << endl << "Cantidad de valores ingresados: " << cantidadDeValores << endl;
    return 0;
}
