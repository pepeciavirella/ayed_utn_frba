#include <iostream>

///---------Ej. 2---------
/// Realice un procedimiento o función que al recibir dos listas como parámetro, devuelva
/// una tercer lista que concatene las mismas.

using namespace std;

struct Nodo
{
    float valor;
    Nodo* sgte;
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

    // Si la lista no está vacía, hay que agregar un nuevo Nodo al final
    if (inicio)
    {
        paux = obtenerUltimoNodo(inicio);
        paux->sgte = new Nodo();
        paux->sgte->valor = nuevoValor;
        paux->sgte->sgte = NULL;
    }
    // Si la lista está vacía, el final es el comienzo
    else
    {
        inicio = new Nodo();
        inicio->valor = nuevoValor;
        inicio->sgte = NULL;
    }
}

Nodo* concatenarListas (Nodo* inicio1, Nodo* inicio2)
{
    // Tip: Esta será la raíz o inicio de la lista concatenada, y debe tener el mismo primer Nodo que la primer lista
    Nodo* nuevaRaiz = inicio1;

    // Tip: Obtenemos el último Nodo de la primer lista
    Nodo* final1 = inicio1;
    while (final1 && final1->sgte)
    {
        final1 = final1->sgte;
    }

    // Tip: Hacemos que el último Nodo de la primer lista tenga como siguiente al primer Nodo de la segunda lista
    final1->sgte = inicio2;
    return nuevaRaiz;
}

void mostrarValores(Nodo* lista)
{
    while (lista)
    {
        cout << lista->valor << " ";
        lista = lista->sgte;
    }
}

int main()
{
    float nuevoValor;
    Nodo* lista1 = NULL;
    Nodo* lista2 = NULL;

    cout << "Ingrese los valores numericos de la primera lista, o 0 para terminarla:" << endl;
    cin >> nuevoValor;
    while (nuevoValor != 0)
    {
        insertarAlFinal(lista1, nuevoValor);
        cin >> nuevoValor;
    }

    cout << endl << "Ingrese los valores numericos de la segunda lista, o 0 para terminarla:" << endl;
    cin >> nuevoValor;
    while (nuevoValor != 0)
    {
        insertarAlFinal(lista2, nuevoValor);
        cin >> nuevoValor;
    }

    Nodo* listaConcatenada = concatenarListas(lista1, lista2);
    cout << endl << "El resultado de concatenar la segunda lista a la primera es:" << endl;
    mostrarValores(listaConcatenada);
    return 0;
}
