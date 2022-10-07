#include <iostream>

///---------Ej. 3---------
/// Haga un procedimiento que reciba los mismos parámetros del punto 1 pero devuelva
/// una tercer lista con el contenido de ambas intercalado (es decir un nodo de la lista 1
/// seguido por un nodo de la lista 2, si una lista se finaliza primero quedan todos los
/// demás nodos de la otra lista consecutivos).

/// TIP: Con "punto 1" se refiere al Ejercicio 2 de la guía. La idea es intercalar en lugar de concatenar

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

// Tip: Procedimiento auxiliar para intercalar los Nodos de dos listas no vacías en una tercera lista (nueva)
void intercalarNodos (Nodo* inicio1, Nodo* inicio2, Nodo* &inicioNueva)
{
    // Tip: Con paux iremos recorriendo la nueva lista; con nuevoNodo representaremos cada Nodo que se agrega
    Nodo* paux;
    Nodo* nuevoNodo;

    // Tip: Creamos el primer Nodo de la nueva lista, con el mismo valor que el primero de la primera lista
    // Y creamos el Nodo siguiente a este, con el mismo valor que el primer Nodo de la segunda lista
    inicioNueva = new Nodo();
    inicioNueva->valor = inicio1->valor;
    inicioNueva->sgte = new Nodo();
    inicioNueva->sgte->valor = inicio2->valor;
    inicioNueva->sgte->sgte = NULL;

    // Tip: Nos desplazamos un Nodo en la primer y la segunda lista; y nos movemos al segundo Nodo de la nueva lista
    inicio1 = inicio1->sgte;
    inicio2 = inicio2->sgte;
    paux = inicioNueva->sgte;

    while (inicio1 && inicio2)
    {
        // Tip: Vamos creando nuevos Nodos y encadenándolos tras el último de la nueva lista
        nuevoNodo = new Nodo();
        nuevoNodo->valor = inicio1->valor;
        inicio1 = inicio1->sgte;
        paux->sgte = nuevoNodo;
        paux = paux->sgte;

        nuevoNodo = new Nodo();
        nuevoNodo->valor = inicio2->valor;
        inicio2 = inicio2->sgte;
        paux->sgte = nuevoNodo;
        paux = paux->sgte;
    }

    while (inicio1)
    {
        nuevoNodo = new Nodo();
        nuevoNodo->valor = inicio1->valor;
        inicio1 = inicio1->sgte;
        paux->sgte = nuevoNodo;
        paux = paux->sgte;
    }
    while (inicio2)
    {
        nuevoNodo = new Nodo();
        nuevoNodo->valor = inicio2->valor;
        inicio2 = inicio2->sgte;
        paux->sgte = nuevoNodo;
        paux = paux->sgte;
    }
}

Nodo* intercalarListas (Nodo* inicio1, Nodo* inicio2)
{
    Nodo* nuevaLista = NULL;

    if (inicio1)
    {
        // Tip: Ninguna lista está vacía
        if (inicio2)
        {
            intercalarNodos(inicio1, inicio2, nuevaLista);
            cout << endl << "Listas intercaladas con exito! RESULTADO:" << endl;
        }
        // Tip: La primera lista no está vacía, pero la segunda sí
        else
        {
            nuevaLista = inicio1;
            cout << endl << "(La segunda lista esta vacia) La lista intercalada es la primer lista:" << endl;
        }
    }
    // Tip: La segunda lista no está vacía, pero la primera sí
    else if (inicio2)
    {
        nuevaLista = inicio2;
        cout << endl << "(La primer lista esta vacia) La lista intercalada es la segunda lista:" << endl << endl;
    }
    // Tip: Ambas listas están vacías
    else
    {
        cout << endl << "(Ambas listas estan vacias. No se pudo intercalar)" << endl << endl;
    }

    return nuevaLista;
}

void mostrarValores(Nodo* lista)
{
    while (lista)
    {
        cout << lista->valor << " ";
        lista = lista->sgte;
    }
    cout << endl;
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

    Nodo* listaIntercalada = intercalarListas(lista1, lista2);
    mostrarValores(listaIntercalada);
    return 0;
}
