#include <iostream>

///---------Ej.MI-38---------
/// Desarrollar la función Int EdadAGrupoEtario (int edad)
/// que retorne un valor de 1 a 8, de acuerdo al siguiente cuadro:
/// Edad            Valor   Edad            Valor
/// Hasta 14 años   1       De 15 a 21      2
/// De 22 a 28      3       De 29 a 35      4
/// De 36 a 42      5       De 43 a 49      6
/// De 50 a 63      7       Mayores de 63   8

using namespace std;

int EdadAGrupoEtario (int edad)
{
    if (edad <= 14)
    {
        return 1;
    }
    else if (edad <= 21)
    {
        return 2;
    }
    else if (edad <= 28)
    {
        return 3;
    }
    else if (edad <= 35)
    {
        return 4;
    }
    else if (edad <= 42)
    {
        return 5;
    }
    else if (edad <= 49)
    {
        return 6;
    }
    else if (edad <= 63)
    {
        return 7;
    }
    return 8;
}

int main()
{
    int edad;
    cout << "Ingrese una edad: ";
    cin >> edad;
    cout << "Pertenece al grupo etario " << EdadAGrupoEtario(edad) << endl;
    return 0;
}
