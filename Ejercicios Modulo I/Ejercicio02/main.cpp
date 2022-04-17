#include <iostream>

///---------Ej.MI-2---------
/// Dada una terna de números naturales que representan al día, al mes y al año de una
/// determinada fecha informarla como un solo número natural de 8 dígitos con la forma
/// (AAAAMMDD)

using namespace std;

int main()
{
    // Tip: Declaramos la variable como "agno" (o "anio") en lugar de "año" porque los identificadores no pueden contener el caracter "ñ"
    int dia, mes, agno;
    cout << "Ingrese el dia" << endl;
    cin >> dia;
    cout << "Ingrese el mes" << endl;
    cin >> mes;
    // Tip: Imprimimos la cadena como "anio" (en lugar de "año") ya que la consola donde se mostrará podría sólo interpretar caracteres ASCII (como es el caso de Windows)
    cout << "Ingrese el anio" << endl;
    cin >> agno;
    int fechaConFormato;
    fechaConFormato = agno * 10000 + mes * 100 + dia;
    cout << "La fecha en formato AAAAMMDD es " << fechaConFormato;
    return 0;
}
