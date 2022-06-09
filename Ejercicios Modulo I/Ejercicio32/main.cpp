#include <iostream>

/// ---------Ej.MI-32---------
/// Una compañía aérea desea emitir un listado con los movimientos mensuales de
/// sus M vuelos al exterior. Para ello cuenta con la siguiente información. De cada vuelo
/// realizado el número de vuelo, destino, y cantidad de asientos. De cada pasajero el número de
/// pasaporte y el importe que abonó por el pasaje en dólares.
/// La información finaliza con un número de pasaporte igual a cero. Se pide emitir el siguiente
/// listado:
///     Total recaudado del vuelo: 99999.99
///     % de Asientos Libres del vuelo 999.99
///     % de Asientos Ocupados del vuelo 999.99
///     Total recaudado en el mes 999999.99
///     Cantidad de veces seguidas que se dieron vuelos completos 99
///     El número de vuelo que más recaudó 9999

using namespace std;

int main()
{
    int i, m, numeroDeVuelo, cantidadDeAsientos, asientosOcupados, asientosLibres;
    bool vueloLleno;
    string destino;
    long numeroDePasaporte;
    float importePasaje, totalRecaudadoVuelo, proporcionAsientosLibres, proporcionAsientosOcupados;
    float totalRecaudadoMes = 0;
    int vuelosSeguidosCompletosActual = 0;
    int maxVuelosSeguidosCompletos = 0;
    int vueloQueMasRecaudo = -1;
    // Tip: Lo inicializamos en un valor negativo, ya que un vuelo que no venda nada sería más apropiado como vuelo que más recaudó
    float mayorRecaudacionVuelo = -1;
    cout << "Ingrese la cantidad de vuelos del mes: ";
    cin >> m;

    for (i = 1; i <= m; i++)
    {
        totalRecaudadoVuelo = 0;
        asientosOcupados = 0;
        vueloLleno = false;
        // Tip: Lo inicializamos en algo distinto a 0, para que pueda ingresarse uno en la primera iteración del while
        numeroDePasaporte = -1;
        cout << endl << endl << "******VUELO " << i << "******" << endl;
        cout << "Numero de vuelo: ";
        cin >> numeroDeVuelo;
        cout << "Destino: ";
        // Tip: Usamos getline para tomar los espacios en blanco como parte de la cadena ingresada, y previamente limpiamos el buffer de cualquier cin >> anterior
        cin.ignore();
        getline(cin, destino);
        cout << "Cantidad de asientos: ";
        cin >> cantidadDeAsientos;

        if (cantidadDeAsientos > 0)
        {
            cout << "***Pasajero 1***" << endl;
            cout << "Numero de pasaporte: ";
            cin >> numeroDePasaporte;
            while (!vueloLleno && numeroDePasaporte != 0)
            {
                cout << "Importe del pasaje: u$s ";
                cin >> importePasaje;
                asientosOcupados++;
                totalRecaudadoVuelo += importePasaje;
                // Tip: Evaluamos esta condición acá y no en el while para que no se pida el ingreso de un pasajero adicional (el cual nunca será contabilizado)
                // Sólo se deben contabilizar asientos como ocupados cuando se ingresa un pasaporte que no es 0; pero no queremos que se ingrese uno de más
                if (asientosOcupados < cantidadDeAsientos)
                {
                    cout << "***Pasajero " << asientosOcupados + 1 << "***" << endl;
                    cout << "Numero de pasaporte: ";
                    cin >> numeroDePasaporte;
                }
                else
                {
                    vueloLleno = true;
                }
            }

            if (totalRecaudadoVuelo > mayorRecaudacionVuelo)
            {
                mayorRecaudacionVuelo = totalRecaudadoVuelo;
                vueloQueMasRecaudo = numeroDeVuelo;
            }
            totalRecaudadoMes += totalRecaudadoVuelo;

            if (vueloLleno)
            {
                vuelosSeguidosCompletosActual++;
                if (vuelosSeguidosCompletosActual > maxVuelosSeguidosCompletos)
                {
                    maxVuelosSeguidosCompletos = vuelosSeguidosCompletosActual;
                }
            }
            else
            {
                vuelosSeguidosCompletosActual = 0;
            }

            asientosLibres = cantidadDeAsientos - asientosOcupados;
            proporcionAsientosLibres = (float) asientosLibres / cantidadDeAsientos;
            proporcionAsientosOcupados = 1 - proporcionAsientosLibres;
            cout << endl << "Total recaudado del vuelo: u$s " << totalRecaudadoVuelo << endl;
            cout << "% de Asientos Libres del vuelo: " << proporcionAsientosLibres * 100 << endl;
            cout << "% de Asientos Ocupados del vuelo: " << proporcionAsientosOcupados * 100 << endl;

        }
        else
        {
            vuelosSeguidosCompletosActual = 0;
            cout << endl << "El vuelo no tuvo asientos" << endl;
        }
    }

    if (m > 0)
    {
        cout << endl << endl << "Total recaudado en el mes: u$s " << totalRecaudadoMes << endl;
        cout << "Cantidad de veces seguidas que se dieron vuelos completos: " << maxVuelosSeguidosCompletos << endl;
        cout << "El número de vuelo que más recaudó: " << vueloQueMasRecaudo << endl;
    }
    else
    {
        cout << endl << "No se ingresaron vuelos" << endl;
    }

    return 0;
}
