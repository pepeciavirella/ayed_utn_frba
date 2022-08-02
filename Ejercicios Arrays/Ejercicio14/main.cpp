#include <iostream>

#define TAMANIO_PILA 20
#define VACIO -999999

///---------Ej. 14---------
/// Dado un vector de 20 posiciones (números enteros), genere un
/// programa que permita realizar las siguientes operaciones.
///     − Ingresar un elemento en la última posición de la pila
///       (primera posición libre del vector), comprobando antes del
///       ingreso que existe una posición libre, sino colocar un mensaje de
///       aviso.
///     − Sacar el elemento que se encuentra en la última posición (si
///       hay, sino colocar un mensaje de aviso).
///     − Listar en cualquier momento el contenido de la pila del primero
///       al último.

using namespace std;

// Tip: Usamos un valor vacío lógico para indicar que una posición de la pila está libre
void inicializarPila(int pila[])
{
    for (int i = 0; i < TAMANIO_PILA; i++)
    {
        pila[i] = VACIO;
    }
}

void ingresarElementoAlFinal(int pila[], int &primeraPosicionLibre)
{
    if (primeraPosicionLibre < TAMANIO_PILA)
    {
        cout << endl << "Valor a ingresar: ";
        cin >> pila[primeraPosicionLibre];
        primeraPosicionLibre++;
    }
    else
    {
        cout << endl << "La pila esta llena, no pueden ingresarse valores" << endl;
    }

}

void sacarUltimoElemento(int pila[], int &primeraPosicionLibre)
{
    if (pila[0] == VACIO)
    {
        cout << endl << "No hay valores en la pila" << endl;
        return;
    }

    primeraPosicionLibre--;
    int ultimoElemento = pila[primeraPosicionLibre];
    cout << endl << "Se extrajo un " << ultimoElemento << " de la ultima posicion" << endl;
    pila[primeraPosicionLibre] = VACIO;
}

void listarPila(int pila[], int primeraPosicionLibre)
{
    // Tip: Solo para fines esteticos
    cout << endl;
    if (pila[0] == VACIO)
    {
        cout << "La pila esta vacia" << endl;
        return;
    }

    for (int i = 0; i < primeraPosicionLibre; i++)
    {
        cout << "Elemento " << i + 1 << ": " << pila[i] << endl;
    }
}

int main()
{
    int pila[TAMANIO_PILA];
    char opcionElegida;
    int primeraPosicionLibre = 0;
    inicializarPila(pila);

    do
    {
        switch (opcionElegida)
        {
            case '1':
                ingresarElementoAlFinal(pila, primeraPosicionLibre);
                break;
            case '2':
                sacarUltimoElemento(pila, primeraPosicionLibre);
                break;
            case '3':
                listarPila(pila, primeraPosicionLibre);
                break;
        }

        cout << endl << "Presione una de las siguientes opciones, y luego presione Enter" << endl;
        cout << "1 - Ingresar elemento al final de la pila" << endl;
        cout << "2 - Sacar elemento de la ultima posicion de la pila" << endl;
        cout << "3 - Listar contenido de la pila" << endl;
        cout << "0 - Salir" << endl;
        cin >> opcionElegida;
    } while (opcionElegida != '0');
    return 0;
}
