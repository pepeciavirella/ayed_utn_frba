#include <iostream>

///---------Ej.MI-41 (bis)---------
/// De un censo realizado en una población se conocen los siguientes datos:
///     - Día de nacimiento (2 dig.)
///     - Mes (2 dig.)
///     - Año (4 dig.)
///     - Sexo ('M'=masc. 'F'=fem.)
/// Con estos datos de cada habitante se forma un lote finalizado con un día cero. Desarrollar el
/// programa que determine e imprima:
///     1) Cuántos nacimientos hubo en el mes de octubre de todos los años.
///     2) Cuántos nacimientos hubo antes del 9 de julio de 1990.
///     3) Cuántos nacimientos de mujeres hubo en la primavera del 1982.
///     4) Sexo de la persona más vieja (solo existe una).

using namespace std;

long obtenerFecha (int dia, int mes, int agno)
{
    long fecha = (agno * 10000) + (mes * 100) + dia;
    return fecha;
}

bool fueEnPrimavera1982 (long fecha)
{
    long inicioPrimavera1982 = obtenerFecha(21, 9, 1982);
    long finPrimavera1982 = obtenerFecha(21, 12, 1982);
    if (fecha >= inicioPrimavera1982 && fecha < finPrimavera1982)
    {
        return true;
    }
    return false;
}

int main()
{
    unsigned int diaNacimiento, mesNacimiento, agnoNacimiento;
    char sexo, sexoPersonaMasVieja;
    long fechaNacimiento;

    int cantidadNacimientosOctubre = 0;
    long fecha9Julio1990 = obtenerFecha(9, 7, 1990);
    int cantidadNacimientosAntesDe9Julio1990 = 0;
    int cantidadMujeresNacidasPrimavera1982 = 0;
    // Tip: Lo inicializamos en el numero de 8 dígitos (AAAAMMDD) más alto posible
    long nacimientoPersonaMasVieja = 99999999;

    cout << "Ingrese el dia de nacimiento, o 0 para finalizar: ";
    cin >> diaNacimiento;
    while (diaNacimiento != 0)
    {
        cout << "Ingrese el numero de mes de nacimiento: ";
        cin >> mesNacimiento;
        cout << "Ingrese el anio de nacimiento: ";
        cin >> agnoNacimiento;
        cout << "Ingrese el sexo ('M' o 'F'): ";
        cin >> sexo;
        fechaNacimiento = obtenerFecha(diaNacimiento, mesNacimiento, agnoNacimiento);

        if (mesNacimiento == 10)
        {
            cantidadNacimientosOctubre++;
        }
        if (fechaNacimiento < fecha9Julio1990)
        {
            cantidadNacimientosAntesDe9Julio1990++;
        }
        if (sexo == 'F' && fueEnPrimavera1982(fechaNacimiento))
        {
            cantidadMujeresNacidasPrimavera1982++;
        }
        if (fechaNacimiento < nacimientoPersonaMasVieja)
        {
            nacimientoPersonaMasVieja = fechaNacimiento;
            sexoPersonaMasVieja = sexo;
        }

        cout << endl << "Ingrese el dia de nacimiento, o 0 para finalizar: ";
        cin >> diaNacimiento;
    }

    cout << endl << endl << "****FIN DEL INGRESO DE PERSONAS CENSADAS****" << endl;
    // Tip: Esta variable sólo sera modificada si se ingresa al menos una persona; de lo contrario, permanecerá como se la inicializó
    if (nacimientoPersonaMasVieja == 99999999)
    {
        cout << "No se ingresaron datos de personas censadas" << endl;
    }
    else
    {
        cout << "Personas nacidas en el mes de octubre: " << cantidadNacimientosOctubre << endl;
        cout << "Personas nacidas antes del 9 de julio de 1990: " << cantidadNacimientosAntesDe9Julio1990 << endl;
        cout << "Mujeres nacidas en la primavera de 1982: " << cantidadMujeresNacidasPrimavera1982 << endl;
        cout << "Sexo de la persona mas vieja: " << sexoPersonaMasVieja << endl;
    }
    return 0;
}
