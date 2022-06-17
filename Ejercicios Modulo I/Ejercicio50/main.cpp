#include <iostream>
// Tip: Incluido para usar INT_MAX
#include <climits>
// Tip: Incluido para usar strcpy
#include <cstring>
// Tip: Incluido para usar round
#include <cmath>

///---------Ej.MI-50---------
/// Desarrollar:
///     a) Una función que reciba un número natural de 4 dígitos en formato de HHMM que
///        corresponde a un tiempo determinado en horas y minutos, retorne ese tiempo en
///        minutos.
///     b) Un procedimiento que reciba el costo en pesos de un abono telefónico, la cantidad de
///        minutos libres que incluye el abono, el cargo en pesos por minuto excedente y la
///        cantidad de minutos utilizados por un abonado, retorne la cantidad de minutos
///        excedidos y el monto en pesos a abonar (costo del abono más minutos excedidos por
///        el costo de minutos excedidos) más el 21% del valor del IVA
/// Desarrolle un algoritmo que resuelva la siguiente situación problemática: Todos los fines de
/// mes, una empresa de telefonía celular debe confeccionar las facturas con los consumos de
/// todos sus abonados, que se realizan en tres turnos de trabajo: Mañana, Tarde y Noche.
/// Para ello se ingresará por teclado la siguiente información de cada celular:
///     - Número de celular 9 dígitos ( 0 indica cambio de turno)
///     - Nombre del abonado 20 caracteres
///     - Dirección del abonado 25 caracteres
///     - Tiempo utilizado 4 dígitos en formato HHMM
///     - Tipo de abono (carácter, A, B, C, D o E)
/// Dependiendo del tipo de abono que se tenga, el usuario tiene cierta cantidad de minutos
/// libres, por los cuales no abona cargo extra, pero por cada minuto que se exceda debe
/// abonar una suma extra según la siguiente tabla:
///     Plan                        A       B       C       D       E
///     Costo                       $70     $55     $40     $28     $19
///     Minutos Libres              300     200     100     60      40
///     Cargo por minuto excedente  $0.09   $0.15   $0.21   $0.29   $0.37
/// Emitir el siguiente listado por cada turno:
///     Turno Mañana
///         Nombre del Abonado  Dirección   Minutos libres  Minutos Excedidos   Monto Total a Abonar
///         xxxxxxxxxxxx        xxxxxxxxx   99999           99999               $ 9999.99
///         xxxxxxxxxxxx        xxxxxxxxx   99999           99999               $ 9999.99
///         xxxxxxxxxxxx        xxxxxxxxx   99999           99999               $ 9999.99
///     .............................................................................................
///     Turno Tarde
///     .............................................................................................
///     Turno Noche
///     .............................................................................................
/// Informar por cada turno de trabajo:
///     - El nombre del abonado que debe abonar la factura más costosa y el monto de ésta.
///     - El nombre y el número de celular de la persona que realizó la mayor cantidad de minutos
///       excedentes, indicando cuántos fueron.
/// Al final del día informar:
///     - El monto total facturado
///     - En que turno y en que orden dentro del turno apareció el abonado que utilizó la menor cantidad
///       de minutos en el mes.
/// Utilice los subprogramas a) y b).

using namespace std;

int cantidadDeMinutos (int tiempoHHMM)
{
    int minutos = tiempoHHMM % 100;
    int horas = tiempoHHMM / 100;
    return minutos + (horas * 60);
}

void calcularExcedenteYMonto (float costoAbono, int minutosLibres, float cargoMinutoExcedente, int minutosUtilizados, int &minutosExcedidos, float &montoConIVA)
{
    int diferenciaDeMinutos = minutosUtilizados - minutosLibres;
    if (diferenciaDeMinutos > 0)
    {
        minutosExcedidos = diferenciaDeMinutos;
    }
    else
    {
        minutosExcedidos = 0;
    }

    float montoPorExcedente = cargoMinutoExcedente * minutosExcedidos;
    float montoSinIVA = costoAbono + montoPorExcedente;
    float montoConIVASinRedondeo = montoSinIVA * 1.21;
    // Tip: Usamos round y dividimos por 100 (es decir, 10^2) para que tenga 2 lugares decimales
    montoConIVA = round(montoConIVASinRedondeo * 100) / 100.0;
}

void ingresarDatosTurno (string turno, float &montoTotal, int &minimoMinutosUtilizados, string &turnoMenosMinutos, int &ordenMenosMinutos)
{
    long numeroDeCelular;
    // Tip: Usamos arrays de caracteres en lugar de strings porque necesitamos que tengan cierta longitud, y consideramos un caracter más para la finalización ('\0')
    char nombreAbonado[21];
    char direccionAbonado[26];
    int tiempoUtilizadoHHMM, tiempoUtilizadoMinutos, minutosExcedidos;
    float montoAAbonar;
    char tipoAbono;

    int abonadosIngresados = 0;
    float facturaMasCostosa = 0;
    char abonadoFacturaMasCostosa[21];
    int mayorCantidadMinutosExcedentes = 0;
    char abonadoMasMinutosExcedentes[21];
    long celularMasMinutosExcedentes;

    cout << "Numero de celular (0 para terminar): ";
    cin >> numeroDeCelular;
    while (numeroDeCelular != 0)
    {
        abonadosIngresados++;
        cout << "Nombre del abonado (20 caracteres): ";
        cin >> nombreAbonado;
        cout << "Direccion del abonado (25 caracteres): ";
        cin >> direccionAbonado;
        cout << "Tiempo utilizado (formato HHMM): ";
        cin >> tiempoUtilizadoHHMM;
        cout << "Tipo de abono ('A', 'B', 'C', 'D' o 'E'): ";
        cin >> tipoAbono;

        // Tip: Para sólo calcular y considerar el ingreso si se indicó un tipo de abono válido; esto nos ahorra poner un caso default en el switch
        if (tipoAbono >= 'A' && tipoAbono <= 'E')
        {
            tiempoUtilizadoMinutos = cantidadDeMinutos(tiempoUtilizadoHHMM);
            switch (tipoAbono)
            {
                case 'A':
                    calcularExcedenteYMonto(70, 300, 0.09, tiempoUtilizadoMinutos, minutosExcedidos, montoAAbonar);
                    cout << "Minutos libres: 300  |  Minutos excedidos: " << minutosExcedidos << "  |  Monto total a abonar: $" << montoAAbonar << endl << endl;
                    break;
                case 'B':
                    calcularExcedenteYMonto(55, 200, 0.15, tiempoUtilizadoMinutos, minutosExcedidos, montoAAbonar);
                    cout << "Minutos libres: 200  |  Minutos excedidos: " << minutosExcedidos << "  |  Monto total a abonar: $" << montoAAbonar << endl << endl;
                    break;
                case 'C':
                    calcularExcedenteYMonto(40, 100, 0.21, tiempoUtilizadoMinutos, minutosExcedidos, montoAAbonar);
                    cout << "Minutos libres: 100  |  Minutos excedidos: " << minutosExcedidos << "  |  Monto total a abonar: $" << montoAAbonar << endl << endl;
                    break;
                case 'D':
                    calcularExcedenteYMonto(28, 60, 0.29, tiempoUtilizadoMinutos, minutosExcedidos, montoAAbonar);
                    cout << "Minutos libres: 60  |  Minutos excedidos: " << minutosExcedidos << "  |  Monto total a abonar: $" << montoAAbonar << endl << endl;
                    break;
                case 'E':
                    calcularExcedenteYMonto(19, 40, 0.37, tiempoUtilizadoMinutos, minutosExcedidos, montoAAbonar);
                    cout << "Minutos libres: 40  |  Minutos excedidos: " << minutosExcedidos << "  |  Monto total a abonar: $" << montoAAbonar << endl << endl;
                    break;
            }

            montoTotal += montoAAbonar;
            if (montoAAbonar > facturaMasCostosa)
            {
                facturaMasCostosa = montoAAbonar;
                strcpy(abonadoFacturaMasCostosa, nombreAbonado);
            }

            if (tiempoUtilizadoMinutos < minimoMinutosUtilizados)
            {
                minimoMinutosUtilizados = tiempoUtilizadoMinutos;
                turnoMenosMinutos = turno;
                ordenMenosMinutos = abonadosIngresados;
            }
            if (minutosExcedidos > mayorCantidadMinutosExcedentes)
            {
                mayorCantidadMinutosExcedentes = minutosExcedidos;
                strcpy(abonadoMasMinutosExcedentes, nombreAbonado);
                celularMasMinutosExcedentes = numeroDeCelular;
            }
        }
        else
        {
            cout << "Se ingreso un tipo de abono no valido. Abonado no procesado" << endl << endl;
        }

        cout << "Numero de celular (9 digitos; 0 para terminar): ";
        cin >> numeroDeCelular;
    }

    cout << endl << "**FIN DE CARGA DEL TURNO**" << endl;
    if (facturaMasCostosa > 0)
    {
        cout << abonadoFacturaMasCostosa << " debe abonar la factura mas costosa, por un monto de $" << facturaMasCostosa << endl;
        if (mayorCantidadMinutosExcedentes > 0)
        {
            cout << "El celular " << celularMasMinutosExcedentes << ", a nombre de " << abonadoMasMinutosExcedentes << ", fue el que minutos se excedidos (" << mayorCantidadMinutosExcedentes << ")" << endl;
        }
        else
        {
            cout << "Ningun abonado registro minutos excedentes respecto a su abono" << endl;
        }
    }
    else
    {
        cout << "No se ingresaron abonados en este turno" << endl;
    }
}

int main()
{
    float montoTotalFacturado = 0;
    // Tip: Lo inicializamos al mayor numero de minutos utilizados posible, para que siempre se halle algo menor
    int menorCantidadMinutosUtilizados = INT_MAX;
    string turnoAbonadoMenosMinutos = "";
    int ordenAbonadoMenosMinutos = 0;

    cout << "****TURNO MANIANA****" << endl << endl;
    ingresarDatosTurno("Maniana", montoTotalFacturado, menorCantidadMinutosUtilizados, turnoAbonadoMenosMinutos, ordenAbonadoMenosMinutos);
    cout << endl << endl << "****TURNO TARDE****" << endl << endl;
    ingresarDatosTurno("Tarde", montoTotalFacturado, menorCantidadMinutosUtilizados, turnoAbonadoMenosMinutos, ordenAbonadoMenosMinutos);
    cout << endl << endl << "****TURNO NOCHE****" << endl << endl;
    ingresarDatosTurno("Noche", montoTotalFacturado, menorCantidadMinutosUtilizados, turnoAbonadoMenosMinutos, ordenAbonadoMenosMinutos);

    cout << endl << endl << endl << "****FIN DEL INGRESO DE FACTURAS****" << endl;
    cout << "Monto total facturado: $" << montoTotalFacturado << endl;
    if (menorCantidadMinutosUtilizados < INT_MAX)
    {
        cout << "El abonado " << ordenAbonadoMenosMinutos << " cargado en el Turno " << turnoAbonadoMenosMinutos << " fue quien utilizo menos minutos en el mes: " << menorCantidadMinutosUtilizados << endl;
    }
    else
    {
        // Tip: El mínimo no será sobreescrito sólo si no se ingresan abonados en ninguno de los tres turnos
        cout << "No se cargaron abonados en ninguno de los tres turnos" << endl;
    }
    return 0;
}
