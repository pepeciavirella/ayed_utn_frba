#include <iostream>
#include <float.h>

// Tip: Usamos constantes simbólicas para definir las cotas del rango [-17.3, 26.9] (https://meramind.com/c-programming/symbolic-constants-c/)
#define COTA_INFERIOR_RANGO -17.3
#define COTA_SUPERIOR_RANGO 26.9

/// ---------Ej.MI-23---------
/// Dado un conjunto de valores, que finaliza con un valor nulo, determinar e
/// imprimir (si hubo valores):
///     a) El valor máximo negativo
///     b) El valor mínimo positivo
///     c) El valor mínimo dentro del rango -17.3 y 26.9
///     d) El promedio de todos los valores.

using namespace std;

int main()
{
    float valorIngresado;
    // Tip: Lo inicializamos como el opuesto de FLT_MAX para que sea el valor "más negativo posible", que sería un mínimo negativo; cualquier otro negativo será mayor que este
    float maximoNegativo = -FLT_MAX;
    // Tip: Lo inicializamos como FLT_MAX para que sea el valor "más positivo posible", que sería un máximo positivo; cualquier otro positivo será menor que este
    float minimoPositivo = FLT_MAX;
    // Tip: Lo inicializamos como un valor mayor a la cota superior del rango, que sería mayor a cualquier valor que pueda estar dentro del rango
    float minimoDelRango = 27;
    // Tip: Usamos booleanos en vez de cantidades de valores negativos, positivos y del rango, ya que sólo queremos saber si los hubo para informar los máximos/mínimos entre ellos
    bool hayNegativos = false;
    bool hayPositivos = false;
    bool hayEnElRango = false;
    float sumatoria = 0;
    int cantidad = 0;

    cout << "Ingrese un valor, o 0 para terminar" << endl;
    cin >> valorIngresado;
    while (valorIngresado != 0)
    {
        cantidad++;
        sumatoria += valorIngresado;
        if (valorIngresado < 0)
        {
            hayNegativos = true;
            if (valorIngresado > maximoNegativo)
            {
                maximoNegativo = valorIngresado;
            }
            if (valorIngresado > COTA_INFERIOR_RANGO && valorIngresado < minimoDelRango)
            {
                hayEnElRango = true;
                minimoDelRango = valorIngresado;
            }
        }
        // Tip: Es implícito que el valor es mayor a 0; no es menor a 0 y, si está en un ciclo del while, sin dudas ya es distinto de 0
        else
        {
            hayPositivos = true;
            if (valorIngresado < minimoPositivo)
            {
                minimoPositivo = valorIngresado;
            }
            if (valorIngresado < COTA_SUPERIOR_RANGO && valorIngresado < minimoDelRango)
            {
                hayEnElRango = true;
                minimoDelRango = valorIngresado;
            }
        }
        cout << "Ingrese un valor, o 0 para terminar" << endl;
        cin >> valorIngresado;
    }
    // Tip: Para dejar un poco de espacio
    cout << endl;
    if (cantidad == 0)
    {
        cout << "No se ingresaron valores no nulos" << endl;
    }
    else
    {
        if (hayNegativos)
        {
            cout << "El valor maximo negativo fue " << maximoNegativo << endl;
        }
        else
        {
            cout << "No se ingresaron valores negativos" << endl;
        }

        if (hayPositivos)
        {
            cout << "El valor minimo positivo fue " << minimoPositivo << endl;
        }
        else
        {
            cout << "No se ingresaron valores positivos" << endl;
        }

        if (hayEnElRango)
        {
            cout << "El valor minimo del rango [-17.3, 26.9] fue " << minimoDelRango << endl;
        }
        else
        {
            cout << "No se ingresaron valores del rango [-17.3, 26.9]" << endl;
        }

        cout << "El promedio de todos los valores ingresados fue " << sumatoria/cantidad << endl;
    }
    return 0;
}
