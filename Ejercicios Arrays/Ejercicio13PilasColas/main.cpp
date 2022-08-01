#include <iostream>

#define TAMANIO_COLA 20
#define VACIO -999999

///---------Ej. 13---------
/// Dado un vector de 20 posiciones (números enteros), genere un
/// programa que permita realizar las siguientes operaciones.
///     − Ingresar un elemento al final de la cola (primera posición libre
///       del vector), comprobando antes del ingreso que existe una
///       posición libre, sino colocar un mensaje de aviso.
///     − Sacar el elemento que se encuentre en la primera posición (si
///       no lo hubiera colocar un mensaje de aviso), corriendo luego los
///       demás en la cola una posición hacia delante.
///     − Listar en cualquier momento el contenido de la cola del primero
///       al último.

using namespace std;

// Tip: Usamos un valor vacío lógico para indicar que una posición de la cola está libre
void inicializarCola(int cola[])
{
    for (int i = 0; i < TAMANIO_COLA; i++)
    {
        cola[i] = VACIO;
    }
}

void ingresarElementoAlFinal(int cola[], int &primeraPosicionLibre)
{
    if (primeraPosicionLibre < TAMANIO_COLA)
    {
        cout << endl << "Valor a ingresar: ";
        cin >> cola[primeraPosicionLibre];
        primeraPosicionLibre++;
    }
    else
    {
        cout << endl << "La cola esta llena, no pueden ingresarse valores" << endl;
    }

}

void sacarPrimerElemento(int cola[], int &primeraPosicionLibre)
{
    if (cola[0] == VACIO)
    {
        cout << endl << "No hay valores en la cola" << endl;
        return;
    }

    int primerElemento = cola[0];
    for (int i = 0; i < (primeraPosicionLibre - 1); i++)
    {
        cola[i] = cola[i+1];
    }
    primeraPosicionLibre--;
    cola[primeraPosicionLibre] = VACIO;
    cout << endl << "Se extrajo un " << primerElemento << " de la primera posicion" << endl;
}

void listarCola(int cola[], int primeraPosicionLibre)
{
    // Tip: Solo para fines esteticos
    cout << endl;
    if (cola[0] == VACIO)
    {
        cout << "La cola esta vacia" << endl;
        return;
    }

    for (int i = 0; i < primeraPosicionLibre; i++)
    {
        cout << "Elemento " << i + 1 << ": " << cola[i] << endl;
    }
}

int main()
{
    int cola[TAMANIO_COLA];
    char opcionElegida;
    int primeraPosicionLibre = 0;
    inicializarCola(cola);

    do
    {
        switch (opcionElegida)
        {
            case '1':
                ingresarElementoAlFinal(cola, primeraPosicionLibre);
                break;
            case '2':
                sacarPrimerElemento(cola, primeraPosicionLibre);
                break;
            case '3':
                listarCola(cola, primeraPosicionLibre);
                break;
        }

        cout << endl << "Presione una de las siguientes opciones, y luego presione Enter" << endl;
        cout << "1 - Ingresar elemento al final de la cola" << endl;
        cout << "2 - Sacar elemento de la primera posicion de la cola" << endl;
        cout << "3 - Listar contenido de la cola" << endl;
        cout << "0 - Salir" << endl;
        cin >> opcionElegida;
    } while (opcionElegida != '0');
    return 0;
}
