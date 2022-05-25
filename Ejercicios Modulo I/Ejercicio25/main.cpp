#include <iostream>

/// ---------Ej.MI-25---------
/// Dada una serie de M pares {color, número} que corresponden a los tiros de una
/// ruleta. Se pide informar:
///     a) cuántas veces salió el número cero y el número anterior a cada cero
///     b) cuántas veces seguidas llegó a repetirse el color negro
///     c) cuántas veces seguidas llegó a repetirse el mismo número y cuál fue
///     d) el mayor número de veces seguidas que salieron alternados el rojo y el negro
///     e) el mayor número de veces seguidas que se negó la segunda docenas

using namespace std;

int main()
{
    int i, m, numeroIngresado, numeroAnterior, numeroMasConsecutivo;
    char colorIngresado, colorAnterior;
    int cantidadCeros = 0;
    int negrosConsecutivos = 0;
    int maximoNegrosConsecutivos = 0;
    int repeticionesNumeroActual = 0;
    int maximoRepeticionesNumero = 0;
    int coloresAlternadosActual = 0;
    int maximoColoresAlternados = 0;
    int segundasDocenasNegadas = 0;
    int maximoNegaciones = 0;

    cout << "Ingrese la cantidad de pares a informar: ";
    cin >> m;
    for (i = 1; i <= m; i++)
    {
        cout << "****PAR " << i << "*****" << endl;
        cout << "Color ('N' o 'R'): " << endl;
        cin >> colorIngresado;
        cout << "Numero: " << endl;
        cin >> numeroIngresado;

        if (numeroIngresado == 0)
        {
            cantidadCeros++;
            if (i > 1)
            {
                cout << "Se ingreso un 0! El numero anterior fue " << numeroAnterior << endl;
            }
        }

        if (colorIngresado == 'N')
        {
            negrosConsecutivos++;
            if (negrosConsecutivos > maximoNegrosConsecutivos)
            {
                maximoNegrosConsecutivos = negrosConsecutivos;
            }
        }
        else
        {
            negrosConsecutivos = 0;
        }

        if (numeroIngresado == numeroAnterior)
        {
            repeticionesNumeroActual++;
            if (repeticionesNumeroActual > maximoRepeticionesNumero)
            {
                maximoRepeticionesNumero = repeticionesNumeroActual;
                numeroMasConsecutivo = numeroIngresado;
            }
        }
        else
        {
            repeticionesNumeroActual = 1;
        }

        // Tip: Chequeamos que no sea la primera iteracion ya que ahi no hay color anterior con el cual comparar
        if ((colorIngresado != colorAnterior) && (i != 1))
        {
            coloresAlternadosActual++;
            if (coloresAlternadosActual > maximoColoresAlternados)
            {
                maximoColoresAlternados = coloresAlternadosActual;
            }
        }
        else
        {
            coloresAlternadosActual = 0;
        }

        if ((numeroIngresado < 13) || (numeroIngresado > 24))
        {
            segundasDocenasNegadas++;
            if (segundasDocenasNegadas > maximoNegaciones)
            {
                maximoNegaciones = segundasDocenasNegadas;
            }
        }
        else
        {
            segundasDocenasNegadas = 0;
        }

        numeroAnterior = numeroIngresado;
        colorAnterior = colorIngresado;
    }

    cout << endl << "******FIN DEL INGRESO******" << endl;
    if (cantidadCeros == 0)
    {
        cout << "El numero 0 no salio nunca" << endl;
    }
    else if (cantidadCeros == 1)
    {
        cout << "El numero 0 salio una sola vez" << endl;
    }
    else
    {
        cout << "El numero 0 salio " << cantidadCeros << " veces" << endl;
    }
    if (maximoNegrosConsecutivos == 0)
    {
        cout << "El color negro no salio nunca" << endl;
    }
    else if (maximoNegrosConsecutivos == 1)
    {
        cout << "El color negro siempre salio aislado" << endl;
    }
    else
    {
        cout << "El color negro llego a repetirse " << maximoNegrosConsecutivos << " veces seguidas" << endl;
    }
    if (maximoRepeticionesNumero <= 1)
    {
        cout << "Ningnun numero salio repetido mas de una vez seguida" << endl;
    }
    else
    {
        cout << "El numero mas consecutivo fue el " << numeroMasConsecutivo << ", que salio " << maximoRepeticionesNumero << " veces seguidas" << endl;
    }
    if (maximoColoresAlternados == 0)
    {
        cout << "El rojo y el negro no se alternaron nunca" << endl;
    }
    else if (maximoColoresAlternados == 1)
    {
        cout << "El rojo y el negro no se alternaron mas de una vez seguida" << endl;
    }
    else
    {
        cout << "El rojo y el negro llegaron a alternarse " << maximoColoresAlternados << " veces seguidas" << endl;
    }
    if (maximoNegaciones == 0)
    {
        cout << "La segunda docena no se nego nunca" << endl;
    }
    else if (maximoNegaciones == 1)
    {
        cout << "La segunda docena solo se nego en tiros aislados" << endl;
    }
    else
    {
        cout << "La segunda docena llego a negarse " << maximoNegaciones << " veces seguidas" << endl;
    }
    return 0;
}
