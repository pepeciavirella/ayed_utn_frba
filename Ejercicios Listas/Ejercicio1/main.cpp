#include <iostream>

///---------Ej. 1---------
/// Utilizando las funciones de ListasSE provistas en clase haga un programa que permita
/// al usuario:
///     - Insertar un elemento ordenadamente en la lista
///     - Buscar el mayor elemento
///     - Calcular el promedio de la lista

using namespace std;

struct Nodo
{
    float valor;
    Nodo *sgte;
};

// Tip: Sólo vamos a recorrer la lista hasta encontrar el Nodo que irá antes del que contenga el nuevo valor, así que pasamos el puntero a su inicio por valor
Nodo* obtenerAnterior(Nodo* lista, float nuevoValor)
{
    while (lista->sgte && (lista->valor < nuevoValor))
    {
        lista = lista->sgte;
    }
    return lista;
}

// Tip: Hay chances de que cambiemos el puntero al primer Nodo, con lo cual debemos tomar este puntero por referencia y no por valor
void insertarElementoOrdenado(Nodo* &inicio)
{
    float nuevoValor;
    cout << endl << "Valor a insertar: ";
    cin >> nuevoValor;

    // Tip: Usamos dos punteros auxiliares al recorrer la lista: paux para el Nodo actual, y uno para el anterior
    Nodo* paux = inicio;
    Nodo* anterior = NULL;

    // Vamos moviendo ambos punteros auxiliares hasta que el actual (paux) sea mayor o igual al valor a insertar
    // De esa forma, tendremos referencias al Nodo anterior al que debemos insertar, y al siguiente (paux)
    while (paux && paux->valor < nuevoValor)
    {
        anterior = paux;
        paux = paux->sgte;
    }

    // Tip: Si paux no apunta al mismo lugar que el inicio, entonces NO insertaremos el Nodo al principio
    if (paux != inicio)
    {
        // Tip: No queremos cambiar el puntero inicial, ya que el primer Nodo seguirá siendo el que era antes
        // Por ende, creamos un nuevo Nodo con el valor, entre el apuntado por anterior y el apuntado por paux
        Nodo* nuevo = new Nodo();
        nuevo->valor = nuevoValor;
        nuevo->sgte = paux;
        anterior->sgte = nuevo;
    }
    // Tip: Si paux apunta al mismo lugar que inicio, entonces SÍ insertaremos el Nodo al principio
    else
    {
        // Tip: Reapuntamos inicio a un nuevo Nodo, que contenga el valor, y que apunte a paux: el resto de la lista, tal como existía
        inicio = new Nodo();
        inicio->valor = nuevoValor;
        inicio->sgte = paux;
    }
}

void obtenerMayorElemento(Nodo* inicio)
{
    // Tip: Podemos ir reapuntando inicio ya que, al estar pasado por valor, trabajamos con una copia (no el verdadero principio de la lista)
    while (inicio && inicio->sgte)
    {
        inicio = inicio->sgte;
    }

    // Tip: Al estar ordenados ascendentemente los valores, el mayor será el último
    cout << endl << "El mayor elemento es " << inicio->valor << endl;
}

void calcularPromedio(Nodo* inicio)
{
    float sumatoria = 0;
    int cantidad = 0;

    // Tip: Acá no nos fijamos si hay un Nodo siguiente, ya que queremos contabilizar al último Nodo (cuyo sgte es NULL) y su valor
    while (inicio)
    {
        sumatoria += inicio->valor;
        cantidad++;
        inicio = inicio->sgte;
    }

    if (cantidad)
    {
        cout << endl << "El promedio de valores de la lista es " << sumatoria/cantidad << endl;
    }
    else {
        cout << endl << "La lista esta vacia" << endl;
    }

}

int main()
{
    char opcionElegida;
    Nodo* inicio = NULL;

    do
    {
        switch (opcionElegida)
        {
            case '1':
                insertarElementoOrdenado(inicio);
                break;
            case '2':
                obtenerMayorElemento(inicio);
                break;
            case '3':
                calcularPromedio(inicio);
                break;
        }

        cout << endl << "Elija una de las siguientes opciones, y luego presione Enter" << endl;
        cout << "1 - Insertar un elemento ordenadamente en la lista" << endl;
        cout << "2 - Buscar el mayor elemento" << endl;
        cout << "3 - Calcular el promedio de la lista" << endl;
        cout << "0 - Salir" << endl;
        cin >> opcionElegida;
    } while (opcionElegida != '0');

    return 0;
}
