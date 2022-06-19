#include <iostream>
// Tip: Incluido para usar la función abs
#include <cmath>

// Tip: 27 es el código ASCII de la tecla Escape
#define ESCAPE_KEY 27

///---------Ej. 6---------
/// Realice un programa que lea dos números enteros n1 y n2 y luego muestre un menú con las
/// opciones:
///     a – Sumar los números
///     b – Restar los números
///     c – Multiplicarlos
///     d – Realizar la división n1/n2
///     Esc - Salir

using namespace std;

void operacionMenu (float n1, float n2, char opcionMenu)
{
    switch (opcionMenu)
    {
        case 'A': case 'a':
            cout << endl << "Su suma es " << n1 + n2 << endl;
            break;
        case 'B': case 'b':
            cout << endl << "Su diferencia es " << abs(n1 - n2) << endl;
            break;
        case 'C': case 'c':
            cout << endl << "Su producto es " << n1 * n2 << endl;
            break;
        case 'D': case 'd':
            cout << endl << "El cociente entre el primero y el segundo es " << n1 / n2 << endl;
            break;
    }
}

int main()
{
    float n1, n2;
    // Tip: La inicializamos a algo que no sea ninguna de las opciones, para que no haga nada indebido en la primera iteración
    char opcionElegida = 0;
    cout << "Ingrese dos enteros, uno tras otro" << endl;
    cin >> n1 >> n2;
    do
    {
        operacionMenu(n1, n2, opcionElegida);
        cout << endl << "Presione una de las siguientes opciones, y luego presione Enter" << endl;
        cout << "a - Sumar los numeros" << endl << "b - Restar los numeros" << endl << "c - Multiplicarlos" << endl << "d - Realizar la division n1/n2" << endl << "Esc - Salir" << endl;
        cin >> opcionElegida;
    } while (opcionElegida != ESCAPE_KEY);
    return 0;
}
