#include <iostream>

// Tip: Lo definimos como 1 caracter más del máximo permitido para poder almacenar el null terminator ('\0') en caso de que se quieran almacenar 20 caracteres
#define TAMVECTOR 21
#define LARGOMAXPALABRA 20

///---------Ej.3---------
/// Se leen las letras de una palabra carácter a carácter. El último carácter que
/// ingresa es la barra de dividir(/), que indica que la palabra ha finalizado.
/// Escribir un programa que imprima la palabra en el orden que se ingresó y
/// en sentido inverso (por ejemplo: pera arep, la palabra podrá tener hasta 20
/// caracteres).

using namespace std;

int main()
{
    char caracterIngresado;
    char palabra[TAMVECTOR];
    int i = 0;
    cout << "Ingrese los caracteres de la palabra, uno por uno:" << endl;
    do
    {
        cin >> caracterIngresado;
        palabra[i] = caracterIngresado;
        i++;
    } while ((caracterIngresado != '/') && (i < LARGOMAXPALABRA));

    // Tip: Si la palabra terminó por un caracter '/' y no por naturaleza, reemplazamos ese caracter por un null terminator, para poder
    // tratar al array como una cadena de caracteres; no está en el índice i, ya que el do-while lo dejará una posición más adelante
    if (caracterIngresado == '/')
    {
        i--;
        palabra[i] = '\0';
    }

    cout << endl << "La palabra ingresada fue " << palabra << endl;
    cout << "Al reves, dicha palabra es ";
    for (int j = i; j >= 0; j--)
    {
        cout << palabra[j];
    }
    return 0;
}
