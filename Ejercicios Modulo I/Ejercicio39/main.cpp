#include <iostream>
#include <iomanip>

///---------Ej.MI-39---------
/// Desarrollar un procedimiento tal que dada una hora (HHMMSS) y un tiempo
/// también en formato HHMMSS devuelva la nueva hora que surge de sumar el tiempo a la hora
/// inicial, considere también si cambió el día.

using namespace std;

void sumarTiempos (int tiempoActual, int tiempoASumar, int &tiempoFinal)
{
    int segundosActuales = tiempoActual % 100;
    int minutosActuales = (tiempoActual % 10000) / 100;
    int horasActuales = tiempoActual / 10000;
    int segundosASumar = tiempoASumar % 100;
    int minutosASumar = (tiempoASumar % 10000) / 100;
    int horasASumar = tiempoASumar / 10000;

    int sumaDeSegundos = segundosActuales + segundosASumar;
    int segundosFinales = sumaDeSegundos % 60;
    int acarreoDeMinutos = sumaDeSegundos / 60;

    int sumaDeMinutos = minutosActuales + minutosASumar + acarreoDeMinutos;
    int minutosFinales = sumaDeMinutos % 60;
    int acarreoDeHoras = sumaDeMinutos / 60;

    int sumaDeHoras = horasActuales + horasASumar + acarreoDeHoras;
    int horasFinales = sumaDeHoras % 24;
    // Tip: No calculamos acarreo de horas ya que no se lleva cuenta de la unidad siguiente (días)

    tiempoFinal = (horasFinales * 10000) + (minutosFinales * 100) + segundosFinales;
}

int main()
{
    int horaActual, tiempoAAgregar, horaFinal;
    cout << "Ingrese la hora actual (en formato HHMMSS): ";
    cin >> horaActual;
    cout << "Ingrese el tiempo a agregar (en formato HHMMSS): ";
    cin >> tiempoAAgregar;
    sumarTiempos(horaActual, tiempoAAgregar, horaFinal);
    // Tip: Usamos setfill(char caracter) y setw(int largo) para que la cadena impresa llegue a cierto largo, rellenando con cierto caracter
    // Más información en https://cplusplus.com/reference/iomanip/setfill
    cout << endl << "La hora resultante es " << setfill('0') << setw(6) << horaFinal << " (en formato HHMMSS)" << endl;
    return 0;
}
