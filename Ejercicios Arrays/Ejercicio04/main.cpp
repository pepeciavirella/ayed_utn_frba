#include <iostream>

// Guardamos el tamaño del vector en una macro, así con modificarlo acá hacemos que el programa acepte distintos tamaños
#define TAMVECTOR 6

///---------Ej.4---------
/// Diseñar un algoritmo recursivo, que permita invertir el contenido de un
/// vector. Como indica el ejemplo:
///     Vector original: 28 35 12 43 56 77
///     Vector invertido: 77 56 43 12 35 28
/// El algoritmo no podrá usar un vector auxiliar.

using namespace std;

void invertirVector (int vec[], int posicion)
{
    int valorPosicion;
    // Tip: Basta con hacer estos intercambios de elementos hasta la primera mitad del array, ya que en cada uno afectamos 2 posiciones
    if (posicion < TAMVECTOR/2)
    {
        // Tip: Intercambiamos el elemento de la posición actual con su opuesto, y usamos una variable auxiliar para el intercambio.
        // Si el vector tiene 6 elementos, el 1ro y el 6to son opuestos, el 2do y el 5to son opuestos, y el 3ro y el 4to son opuestos.
        int posicionOpuesta = TAMVECTOR - 1 - posicion;
        valorPosicion = vec[posicion];
        vec[posicion] = vec[posicionOpuesta];
        vec[posicionOpuesta] = valorPosicion;
        // Tip: Volvemos a intercambiar elementos opuestos, esta vez yendo al siguiente elemento
        invertirVector(vec, posicion + 1);
    }
}

int main()
{
    int v[TAMVECTOR];
    int i;
    cout << "Ingrese los " << TAMVECTOR << " elementos del vector:" << endl;
    for(i = 0; i < TAMVECTOR; i++)
    {
        cout << "Elemento " << i + 1 << ": ";
        cin >> v[i];
    }

    // Tip: Comenzamos la inversión recursiva con el primer elemento del vector (el que está en la posición 0)
    invertirVector(v, 0);
    cout << endl << "El vector invertido es:" << endl;
    for(i = 0; i < TAMVECTOR; i++)
    {
        cout << "Elemento " << i + 1 << ": " << v[i] << endl;
    }
    return 0;
}
