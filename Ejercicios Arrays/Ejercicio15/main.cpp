#include <iostream>
// Tip: Incluido para usar la constante INT_MAX
#include <bits/stdc++.h>

#define TAMANIO_LISTA 20

///---------Ej. 15---------
/// Dado un vector de 20 posiciones (números enteros), genere un
/// programa que permita realizar las siguientes operaciones.
///     − Ingresar un elemento en la posición que le corresponda de la
///       lista, de manera que la misma se mantenga en orden creciente.
///       ( para lo cual desplaza los demás elementos una posición para
///       atrás). Comprobando antes del ingreso que existe una posición
///       libre, sino colocar un mensaje de aviso.
///     − Sacar de la lista el elemento que indica el usuario (si se
///       encuentra, sino colocar un mensaje de aviso).
///     − Listar en cualquier momento el contenido de la cola del primero
///       al último.

using namespace std;

// Tip: Usamos el mayor valor entero posible para indicar que una posición de la lista está libre, ya que la queremos ordenada ascendentemente (de menor a mayor)
void inicializarLista(int lista[])
{
    for (int i = 0; i < TAMANIO_LISTA; i++)
    {
        lista[i] = INT_MAX;
    }
}

void ingresarElemento(int lista[], int &primeraPosicionLibre)
{
    if (primeraPosicionLibre == TAMANIO_LISTA)
    {
        cout << endl << "La lista esta llena, no se puede ingresar elementos" << endl;
        return;
    }

    int nuevoValor;
    int i = 0;
    cout << endl << "Valor a ingresar: ";
    cin >> nuevoValor;

    for (int i = 0; i <= primeraPosicionLibre; i++)
    {
        if (nuevoValor < lista[i])
        {
            // Tip: Desplazamos el elemento actual y los posteriores en una posición
            for (int j = (primeraPosicionLibre - 1); j >= i; j--)
            {
                lista[j+1] = lista[j];
            }
            // Tip: Ponemos el nuevo valor en la posición indicada
            lista[i] = nuevoValor;
            primeraPosicionLibre++;
            return;
        }
    }
}

void sacarElemento(int lista[], int &primeraPosicionLibre)
{
    if (primeraPosicionLibre == 0)
    {
        cout << endl << "La lista esta vacia, no se puede sacar elementos" << endl;
        return;
    }

    int valorObjetivo;
    int posicionOjbetivo = 0;
    cout << endl << "Valor a extraer: ";
    cin >> valorObjetivo;

    for (int i = 0; i < primeraPosicionLibre; i++)
    {
        if (lista[i] == valorObjetivo)
        {
            // Tip: Adelantamos los elementos posteriores en una posición; no llegamos hasta la que será la nueva primera posición libre
            for (int j = i; j <= (primeraPosicionLibre - 2); j++)
            {
                lista[j] = lista[j+1];
            }
            // Tip: Dejamos "vacía" la nueva primera posición libre
            primeraPosicionLibre--;
            lista[primeraPosicionLibre] = INT_MAX;
            cout << "Elemento extraido" << endl;
            return;
        }
    }
    cout << "No se encontro el elemento en la lista" << endl;
}

void mostrarLista(int lista[], int primeraPosicionLibre)
{
    // Tip: Solo para fines esteticos
    cout << endl;
    if (primeraPosicionLibre == 0)
    {
        cout << "La lista esta vacia" << endl;
        return;
    }

    int i = 0;
    while (i < primeraPosicionLibre)
    {
        cout << "Elemento " << i + 1 << ": " << lista[i] << endl;
        i++;
    }
}

int main()
{
    int lista[TAMANIO_LISTA];
    char opcionElegida;
    int primeraPosicionLibre = 0;
    inicializarLista(lista);

    do
    {
        switch (opcionElegida)
        {
            case '1':
                ingresarElemento(lista, primeraPosicionLibre);
                break;
            case '2':
                sacarElemento(lista, primeraPosicionLibre);
                break;
            case '3':
                mostrarLista(lista, primeraPosicionLibre);
                break;
        }

        cout << endl << "Presione una de las siguientes opciones, y luego presione Enter" << endl;
        cout << "1 - Ingresar elemento ordenado en la lista" << endl;
        cout << "2 - Sacar elemento de la lista" << endl;
        cout << "3 - Listar contenido" << endl;
        cout << "0 - Salir" << endl;
        cin >> opcionElegida;
    } while (opcionElegida != '0');
    return 0;
}
