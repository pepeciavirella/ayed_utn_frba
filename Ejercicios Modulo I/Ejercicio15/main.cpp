#include <iostream>

/// ---------Ej.MI-15---------
/// Se realiza una inspección en una fábrica de pinturas, y se detectaron 20
/// infracciones. De cada infracción se tomó nota de los siguientes datos:
///     - Tipo de Infracción (1, 2, 3, ó 4)
///     - Motivo de la infracción
///     - Valor de la multa
///     - Gravedad de la infracción (‘L’,‘M’, ‘G’)
/// Se pide informar al final del proceso:
///     - Los valores totales de la multa a pagar de acuerdo al tipo de gravedad.
///     - La leyenda “Clausurar fábrica” si la cantidad de infracciones 3 y 4 con gravedad “G” sean
///       mayor a 3.

using namespace std;

int main()
{
    int i, tipo;
    unsigned int valorMulta;
    string motivo;
    char gravedad;
    unsigned int totalMultasGravedadL = 0;
    unsigned int totalMultasGravedadM = 0;
    unsigned int totalMultasGravedadG = 0;
    int cantidadInfracciones3G = 0;
    int cantidadInfracciones4G = 0;
    for (i = 1; i <= 20; i++)
    {
        cout << "********INFRACCION " << i << "********" << endl;
        cout << "Tipo de Infraccion (1, 2, 3, o 4): ";
        cin >> tipo;
        cout << "Motivo de la infraccion: ";
        cin >> motivo;
        cout << "Valor de la multa: $";
        cin >> valorMulta;
        cout << "Gravedad de la infraccion ('L','M' o 'G'): ";
        cin >> gravedad;
        switch (gravedad)
        {
            case 'L':
                totalMultasGravedadL += valorMulta;
                break;
            case 'M':
                totalMultasGravedadM += valorMulta;
                break;
            case 'G':
                totalMultasGravedadG += valorMulta;
                if (tipo == 3)
                {
                    cantidadInfracciones3G++;
                }
                else if (tipo == 4)
                {
                    cantidadInfracciones4G++;
                }
                break;
        }
    }
    cout << endl << "********RESULTADOS********" << endl;
    cout << "Total de multas por infracciones de gravedad L: $" << totalMultasGravedadL << endl;
    cout << "Total de multas por infracciones de gravedad M: $" << totalMultasGravedadM << endl;
    cout << "Total de multas por infracciones de gravedad G: $" << totalMultasGravedadG << endl;
    if (cantidadInfracciones3G > 3 && cantidadInfracciones4G > 3)
    {
        cout << "Clausurar fabrica" << endl;
    }
    return 0;
}
