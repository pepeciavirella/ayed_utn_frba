#include <iostream>

///---------Ej. 4---------
/// Realice una función para ordenar una lista por método de burbuja aplicando el mismo
/// concepto visto para arrays.

using namespace std;

struct Nodo
{
    float valor;
    Nodo* sgte = NULL;
};

Nodo* obtenerUltimoNodo (Nodo* lista)
{
    while (lista && lista->sgte)
    {
        lista= lista->sgte;
    }
    return lista;
}

void insertarAlFinal (Nodo* &inicio, float nuevoValor)
{
    Nodo* paux = NULL;

    if (inicio)
    {
        paux = obtenerUltimoNodo(inicio);
        paux->sgte = new Nodo();
        paux->sgte->valor = nuevoValor;
        paux->sgte->sgte = NULL;
    }
    else
    {
        inicio = new Nodo();
        inicio->valor = nuevoValor;
        inicio->sgte = NULL;
    }
}

void mostrarValores(Nodo* lista)
{
    cout << endl << "Lista ordenada: ";
    while (lista)
    {
        cout << lista->valor << " ";
        lista = lista->sgte;
    }
    cout << endl;
}

void ordenarPorBurbuja(Nodo* &lista)
{
    // Tip: Creamos un Nodo "dummy", que será temporalmente el primero de la lista, para poder usar el algoritmo del bucle
    // Si no usáramos este Nodo, tendríamos que distinguir el caso en el que cambiamos el primer Nodo (para reapuntar el inicio de la lista)
    Nodo* dummy = new Nodo();
    dummy->sgte = lista;
    lista = dummy;

    // Tip: Usamos un puntero auxiliar para el while "exterior" del algoritmo de burbuja; recorrerá hasta el anteúltimo Nodo
    Nodo* pauxExterior = dummy;
    // Tip: Vamos a usar tres punteros auxiliares para los while "interiores", para cuando debamos reordenar los Nodos
    Nodo *anterior, *paux, *proximo;

    while (pauxExterior && pauxExterior->sgte)
    {
        // Tip: En cada ciclo interior queremos recorrer toda la lista, así que siempre arrancamos desde el Nodo siguiente al "dummy"
        anterior = dummy;
        paux = dummy->sgte;
        proximo = dummy->sgte->sgte;

        while (paux && proximo)
        {
            if (proximo->valor < paux->valor)
            {
                // Tip: Si proximo tiene un valor menor a paux, reordenamos de la forma: anterior -> proximo -> paux
                anterior->sgte = proximo;
                paux->sgte = proximo->sgte;
                proximo->sgte = paux;
            }

            // Tip: Desplazamos anterior, y reasignamos paux y proximo a los dos Nodos siguientes al nuevo anterior
            // Si en lugar de hacer esto simplemente desplazamos cada puntero, podríamos saltearnos Nodos
            anterior = anterior->sgte;
            paux = anterior->sgte;
            proximo = paux->sgte;
        }

        pauxExterior = pauxExterior->sgte;
    }

    // Tip: Eliminamos el Nodo "dummy", y hacemos que el puntero inicial apunte al nuevo primer Nodo (ya ordenado)
    lista = lista->sgte;
    delete dummy;
}

int main()
{
    float nuevoValor;
    Nodo* lista = NULL;

    cout << "Ingrese los valores numericos de la lista, o 0 para terminarla:" << endl;
    cin >> nuevoValor;
    while (nuevoValor != 0)
    {
        insertarAlFinal(lista, nuevoValor);
        cin >> nuevoValor;
    }

    ordenarPorBurbuja(lista);
    mostrarValores(lista);
    return 0;
}
