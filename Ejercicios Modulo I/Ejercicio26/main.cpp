#include <iostream>

/// ---------Ej.MI-26---------
/// Un buque de carga traslada 100 contenedores a tres diferentes puertos del país.
/// Los puertos se identifican con los números 1, 2 y 3.
/// De cada contenedor que el buque traslade se registran los siguientes datos:
///     - Identificación del contenedor
///     - Peso del contenedor en kg
///     - Puerto de arribo(un valor de 1 a 3).
/// Se pide calcular e informar:
///     1) El peso total que el buque debe trasladar
///     2) La identificación del contenedor de mayor peso
///     3) La cantidad de contenedores que debe trasladar a cada puerto

using namespace std;

int main()
{
    int i, pesoContenedor, puertoDeArribo;
    string identificacionContenedor;
    int pesoTotal = 0;
    int pesoMaximo = 0;
    string identificacionMasPesado = "";
    int cantidadContenedoresPuerto1 = 0;
    int cantidadContenedoresPuerto2 = 0;
    int cantidadContenedoresPuerto3 = 0;

    for (i = 1; i <= 5; i++)
    {
        cout << "****CONTENEDOR " << i << "****" << endl;
        cout << "Identificacion: ";
        cin >> identificacionContenedor;
        cout << "Peso (en kg): ";
        cin >> pesoContenedor;
        cout << "Puerto de arribo (1, 2 o 3): ";
        cin >> puertoDeArribo;

        if (puertoDeArribo >= 1 && puertoDeArribo <= 3)
        {
            pesoTotal += pesoContenedor;
            if (pesoContenedor > pesoMaximo)
            {
                pesoMaximo = pesoContenedor;
                identificacionMasPesado = identificacionContenedor;
            }
            switch (puertoDeArribo)
            {
                case 1:
                    cantidadContenedoresPuerto1++;
                    break;
                case 2:
                    cantidadContenedoresPuerto2++;
                    break;
                case 3:
                    cantidadContenedoresPuerto3++;
                    break;
            }
        }
        // Tip: Podriamos simplemente no contarlo para ninguno de los 3 contadores pero, si no va a un puerto valido, no deberia subir al buque
        else
        {
            cout << "Puerto de arribo invalido, no se considera el contenedor" << endl;
        }
    }

    cout << endl << "******RESULTADOS******" << endl;
    // Tip: Si el máximo no cambió, es porque no se ingresó ningún contenedor que vaya a un puerto válido
    if (identificacionMasPesado == "")
    {
        cout << "El buque no trasladara ningun contenedor" << endl;
    }
    else
    {
        cout << "Peso total a trasladar: " << pesoTotal << " kg" << endl;
        cout << "Contenedor mas pesado: " << identificacionContenedor << " (" << pesoMaximo << " kg)" << endl;
        cout << "Contenedores a trasladar al puerto 1: " << cantidadContenedoresPuerto1 << endl;
        cout << "Contenedores a trasladar al puerto 2: " << cantidadContenedoresPuerto2 << endl;
        cout << "Contenedores a trasladar al puerto 3: " << cantidadContenedoresPuerto3 << endl;
    }
    return 0;
}
