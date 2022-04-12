#include <iostream>

///---------Ej.MI-3---------
/// Dada un numero entero de la forma (AAAAMMDD), que representa una fecha
/// valida mostrar el dia, mes y año que representa.

using namespace std;

int main()
{
    long fechaConFormato;
    cout << "Ingrese una fecha en formato AAAAMMDD" << endl;
    cin >> fechaConFormato;
    int dia, mes, agno;
    agno = fechaConFormato / 10000;
    // Tip: Para "recortar" N números desde la izquierda, podemos hallar el resto de dividir el número por 10^N, ya que esto es como correrlo N lugares a la izquierda
        // Ej: 15631 % 100 => __631 => 631
    // Tip: Para "recortar" M números desde la derecha, podemos hallar el cociente entero de dividir el número por 10^M, ya que esto es como correrlo M lugares a la derecha
        // Ej: 48215 / 100 => 482__ => 482
    mes = (fechaConFormato % 10000) / 100;
    dia = fechaConFormato % 100;
    cout << "La fecha corresponde al día " << dia << " del mes " << mes << " del año " << agno;
    return 0;
}
