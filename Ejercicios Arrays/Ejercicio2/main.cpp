#include <iostream>
// Tip: Incluido para usar la constante FLT_MAX
#include <cfloat>
// Tip: Incluido para usar la función abs
#include <cmath>

// Tip: Guardamos el tamaño del array en una constante, para no usar "números mágicos" (https://en.wikipedia.org/wiki/Magic_number_(programming))
#define TAMVECTOR 15

///---------Ej. 2---------
/// Dado un vector 15 valores, hacer un programa que pueda obtener, y sacar
/// por pantalla:
///     − el mayor de los valores
///     − el menor de los valores
///     − el más próximo al promedio

using namespace std;

float hallarMasProximoAlPromedio (float valores[], float promedio)
{
    float distanciaActual;
    // Tip: El array ya está inicializado, el primero será el más próximo al promedio (al menos hasta que se empiece a iterar)
    float valorMasProximo = valores[0];
    float menorDistancia = abs(promedio - valorMasProximo);
    for (int i = 1; i < TAMVECTOR; i++)
    {
        distanciaActual = abs(promedio - valores[i]);
        if (distanciaActual < menorDistancia)
        {
            valorMasProximo = valores[i];
            menorDistancia = distanciaActual;
        }
    }
    return valorMasProximo;
}

int main()
{
    float valoresIngresados[TAMVECTOR];
    float promedioDeValores, valorMasProximoAlPromedio;
    // Tip: Inicializo el máximo en el valor más negativo posible, y el mínimo en el más positivo posible, respectivamente
    float mayorValor = -FLT_MAX;
    float menorValor = FLT_MAX;
    float sumaDeValores = 0;
    for (int i = 0; i < TAMVECTOR; i++)
    {
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> valoresIngresados[i];
        sumaDeValores += valoresIngresados[i];
        if (valoresIngresados[i] > mayorValor)
        {
            mayorValor = valoresIngresados[i];
        }
        if (valoresIngresados[i] < menorValor)
        {
            menorValor = valoresIngresados[i];
        }
    }

    promedioDeValores = sumaDeValores / TAMVECTOR;
    valorMasProximoAlPromedio = hallarMasProximoAlPromedio(valoresIngresados, promedioDeValores);
    cout << endl << "****RESULTADOS****" << endl;
    cout << "Mayor valor: " << mayorValor << endl;
    cout << "Menor valor: " << menorValor << endl;
    cout << "Valor mas proximo al promedio: " << valorMasProximoAlPromedio << endl;
    return 0;
}
