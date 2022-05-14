#include <iostream>

/// ---------Ej.MI-17---------
/// Se ingresa un conjunto de valores float, cada uno de los cuales representan el
/// sueldo de un empleado, excepto el último valor que es cero e indica el fin del conjunto. Se pide
/// desarrollar un programa que determine e informe:
///     a) Cuántos empleados ganan menos $1.520.
///     b) Cuántos ganan $1.520 o más pero menos de $2.780.
///     c) Cuántos ganan $2.780 o más pero menos de $5.999.
///     d) Cuántos ganan $5.999 o más.

using namespace std;

int main()
{
    float sueldo;
    int empleadosTipoA = 0;
    int empleadosTipoB = 0;
    int empleadosTipoC = 0;
    int empleadosTipoD = 0;
    cout << "Ingrese un sueldo en pesos, o 0 para terminar" << endl;
    cin >> sueldo;
    while (sueldo != 0)
    {
        if (sueldo < 1520)
        {
            empleadosTipoA++;
        }
        else if (sueldo < 2780)
        {
            empleadosTipoB++;
        }
        else if (sueldo < 5999)
        {
            empleadosTipoC++;
        }
        else
        {
            empleadosTipoD++;
        }
        cout << "Ingrese un sueldo en pesos, o 0 para terminar" << endl;
        cin >> sueldo;
    }
    cout << endl << empleadosTipoA << " empleados ganan menos de $1520" << endl;
    cout << empleadosTipoB << " empleados ganan $1520 o mas pero menos de $2780" << endl;
    cout << empleadosTipoC << " empleados ganan $2780 o mas pero menos de $5999" << endl;
    cout << empleadosTipoD << " empleados ganan $5999 o mas" << endl;
    return 0;
}
