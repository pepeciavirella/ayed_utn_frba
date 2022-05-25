#include <iostream>

/// ---------Ej.MI-27---------
/// En un torneo de fútbol participan K equipos. El torneo se juega con el sistema de
/// todos contra todos. Por cada partido disputado por un equipo se dispone de la siguiente
/// información:
///     a) Nro. de equipo,
///     b) Código del resultado ('P'= Perdido, 'E'= Empatado, 'G'= Ganado).
/// Se arma un lote de datos con todos los resultados del torneo, agrupados por Nro. de equipo.
/// Desarrollar el programa que imprima:
///     Por cada equipo, su número y el puntaje total que obtuvo (suma 3 si gana, y 1 si
///     empata).

// HIPÓTESIS: Por los contenidos vistos en la materia hasta el momento, la idea es resolver esto sin arrays, e informar el puntaje de cada equipo una vez se ingresaron
// todos sus resultados. Además, la consistencia es responsabilidad del usuario: si primero dice que el equipo 1 le gano al equipo 3, luego debería decir que el equipo
// 3 perdió con el 1; hay que pensar que se cargan los resultados para cada partido de cada equipo, no sólo para cada partido que se juega.

using namespace std;

int main()
{
    int i, j, k, puntosEquipo;
    char resultado;
    cout << "Ingrese la cantidad de equipos del torneo: ";
    cin >> k;
    for (i = 1; i <= k; i++)
    {
        puntosEquipo = 0;
        cout << endl << "****PARTIDOS DEL EQUIPO " << i << "****" << endl;
        for (j = 1; j <= k; j++)
        {
            if (j != i)
            {
                cout << "Resultado vs Equipo " << j << " ('G', 'E' o 'P'): ";
                cin >> resultado;
                switch (resultado)
                {
                    case 'G': case 'g':
                        puntosEquipo += 3;
                        break;
                    case 'E': case 'e':
                        puntosEquipo += 1;
                        break;
                }
            }
        }
        cout << "TOTAL: " << puntosEquipo << " puntos" << endl;
    }
    return 0;
}
