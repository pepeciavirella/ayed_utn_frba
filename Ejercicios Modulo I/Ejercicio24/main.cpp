#include <iostream>

/// ---------Ej.MI-24---------
/// Se dispone de un lote de valores enteros positivos que finaliza con un número
/// negativo.
/// El lote está dividido en sublotes por medio de valores cero. Desarrollar un programa que
/// determine e informe:
///     a) por cada sublote el promedio de valores
///     b) el total de sublotes procesados
///     c) el valor máximo del conjunto, indicando en que sublote se encontró y la posición
///        relativa del mismo dentro del sublote
///     d) valor mínimo de cada sublote
/// Nota: el lote puede estar vacío (primer valor negativo), o puede haber uno, varios o todos los
/// sublotes vacíos (ceros consecutivos)

using namespace std;

int main()
{
    int valorIngresado, sumatoria, cantidadValoresSublote, subloteDelMaximo, posicionRelativaMaximo, minimoDelSublote;
    int cantidadDeSublotes = 0;
    // Tip: Lo inicializamos en 0, un valor que no será tenido en cuenta para ningún sublote
    int maximoDelLote = 0;
    cout << "******SUBLOTE 1******" << endl;
    cout << "Ingrese un entero positivo, 0 para terminar el sublote o uno negativo para terminar el programa: ";
    cin >> valorIngresado;

    while (valorIngresado >= 0)
    {
        cantidadDeSublotes++;
        cantidadValoresSublote = 0;
        sumatoria = 0;

        while (valorIngresado > 0)
        {
            sumatoria += valorIngresado;
            cantidadValoresSublote++;
            if (valorIngresado > maximoDelLote)
            {
                maximoDelLote = valorIngresado;
                subloteDelMaximo = cantidadDeSublotes;
                posicionRelativaMaximo = cantidadValoresSublote;
            }
            if (valorIngresado < minimoDelSublote)
            {
                minimoDelSublote = valorIngresado;
            }
            cout << "Ingrese un entero positivo, 0 para terminar el sublote o uno negativo para terminar el programa: ";
            cin >> valorIngresado;
        }

        if (cantidadValoresSublote > 0)
        {
            cout << "****RESULTADOS SUBLOTE " << cantidadDeSublotes << "****" << endl;
            cout << "Promedio: " << (float) sumatoria/cantidadValoresSublote << endl;
            cout << "Minimo: " << minimoDelSublote << endl << endl;
        }
        else
        {
            cout << "Sublote vacio" << endl << endl;
        }

        // Tip: Sólo queremos permitir que se ingrese otro sublote si el último se cortó con un 0; caso contrario, queremos dejar a valorIngresado tal como está para salir del while
        if (valorIngresado == 0)
        {
            cout << "******SUBLOTE " << cantidadDeSublotes + 1 << "******" << endl;
            cout << "Ingrese un entero positivo, 0 para terminar el sublote o uno negativo para terminar el programa: ";
            cin >> valorIngresado;
        }
    }

    cout << endl << "*******************" << endl << "PROGRAMA FINALIZADO" << endl << "*******************" << endl;
    if (cantidadDeSublotes > 0)
    {
        cout << "Cantidad de sublotes procesados: " << cantidadDeSublotes << endl;
        if (maximoDelLote != 0)
        {
            cout << "Maximo del lote: " << maximoDelLote << ", en la posicion " << posicionRelativaMaximo << " del sublote " << subloteDelMaximo << endl;
        }
        else
        {
            cout << "No se ingresaron valores no nulos" << endl;
        }
    }
    else
    {
        cout << "Lote vacio" << endl;
    }
    return 0;
}
