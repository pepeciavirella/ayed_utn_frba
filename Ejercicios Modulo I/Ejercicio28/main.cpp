#include <iostream>

/// ---------Ej.MI-28---------
/// Dada una serie de caracteres que conforman una oración, donde cada palabra está
/// separada de la siguiente por un carácter blanco y la oración finaliza con un punto. Se pide
/// informar:
///     a) cantidad de veces que apareció cada vocal
///     b) cantidad de palabras que contiene la oración
///     c) cantidad de letras que posee la palabra más larga.

using namespace std;

int main()
{
    char caracterIngresado;
    // Tip: Lo inicializamos así para que el primer caracter que no sea espacio ni punto ya cuente la primer palabra
    char caracterAnterior = ' ';
    int cantidadAes = 0;
    int cantidadEs = 0;
    int cantidadIes = 0;
    int cantidadOes = 0;
    int cantidadUes = 0;
    int cantidadPalabras = 0;
    int letrasPalabraActual = 0;
    int letrasPalabraMasLarga = 0;

    cout << "Ingrese un caracter, un espacio para separar palabras o un punto para terminar la oracion: ";
    // Tip: Como el cin >> ignora espacios en blanco, usamos la función getchar(), que está incluida en el iostream, para leer los caracteres ingresados uno por uno
    caracterIngresado = getchar();
    // Tip: getchar() considera TODOS los caracteres, espacios en blanco e incluso saltos de línea. Como cada vez que ingresamos un caracter apretamos "Enter", también
    // se ingresa un salto de línea. Para que este no se guarde en la variable caracterIngresado, llamamos a getchar() así nomás, y sólo se leerán los caracteres escritos
    getchar();
    while (caracterIngresado != '.')
    {
        switch (caracterIngresado)
        {
            case 'A': case 'a':
                cantidadAes++;
                break;
            case 'E': case 'e':
                cantidadEs++;
                break;
            case 'I': case 'i':
                cantidadIes++;
                break;
            case 'O': case 'o':
                cantidadOes++;
                break;
            case 'U': case 'u':
                cantidadUes++;
                break;
        }
        if (caracterIngresado != ' ')
        {
            if (caracterAnterior == ' ')
            {
                cantidadPalabras++;
                letrasPalabraActual = 1;
            }
            // Tip: Sólo queremos considerar letras mayúsculas y minúsculas, y aprovechamos el orden de los códigos ASCII (https://www.asciitable.com/)
            else if (
                ((caracterIngresado >= 'A') && (caracterIngresado <= 'Z'))
                || ((caracterIngresado >= 'a') && (caracterIngresado <= 'z'))
            )
            {
                letrasPalabraActual++;
                if (letrasPalabraActual > letrasPalabraMasLarga)
                {
                    letrasPalabraMasLarga = letrasPalabraActual;
                }
            }
        }
        caracterAnterior = caracterIngresado;

        cout << "Ingrese un caracter, un espacio para separar palabras o un punto para terminar la oracion: ";
        caracterIngresado = getchar();
        getchar();
    }

    cout << endl << "****FIN DE LA ORACION****" << endl;
    cout << "Se ingresaron " << cantidadAes << " aes" << endl;
    cout << "Se ingresaron " << cantidadEs << " es" << endl;
    cout << "Se ingresaron " << cantidadIes << " ies" << endl;
    cout << "Se ingresaron " << cantidadOes << " oes" << endl;
    cout << "Se ingresaron " << cantidadUes << " ues" << endl;
    cout << "La oracion contiene " << cantidadPalabras << " palabras" << endl;
    if (letrasPalabraMasLarga > 0)
    {
        cout << "La palabra mas larga posee " << letrasPalabraMasLarga << " letras" << endl;
    }
    return 0;
}
