#include <iostream>

///---------Ej.MI-41---------
/// Una bodega quiere lanzar una oferta para terminar con el stock de dos productos.
/// Para ello cuenta con B cantidad de cajas de vino blanco y T cantidad de cajas de vino tinto.
/// Desea armar la mayor cantidad posible de paquetes con la oferta y que todos los paquetes
/// tengan igual cantidad de cajas de vino blanco y de vino tinto.
/// Se pide informar cuántos paquetes se podrán armar como máximo, y cuántas cajas de vino
/// blanco y cuantas de vino tinto contendrán cada uno.
/// Utilice la funciones desarrolladas en ejercicios anteriotes

using namespace std;

// Tip: Tal y como se hizo para el ejercicio MI-36
int mcd (int a, int b)
{
    int r = a % b;
    if (r == 0)
    {
        return b;
    }
    return mcd(b, r);
}

int main()
{
    int b, t, cantidadDePaquetes, cajasVinoBlancoPorPaquete, cajasVinoTintoPorPaquete;
    cout << "Cantidad de cajas de vino blanco: ";
    cin >> b;
    cout << "Cantidad de cajas de vino tinto: ";
    cin >> t;
    // Hipótesis: "que todos los paquetes tengan igual cantidad de cajas de vino blanco y de vino tinto" implica que haya igual cantidad de cada variedad entre paquete, pero no entre sí
    // Por ejemplo: Si hay 15 cajas de vino blanco y 21 de vino tinto, puedo armar 3 cajas, cada una con 5 vinos blancos y 7 vinos tintos
    cantidadDePaquetes = mcd(b, t);
    cajasVinoBlancoPorPaquete = b / cantidadDePaquetes;
    cajasVinoTintoPorPaquete = t / cantidadDePaquetes;
    cout << endl << "Se podran armar, como maximo, " << cantidadDePaquetes << " paquetes" << endl;
    cout << "Cada paquete tendra " << cajasVinoBlancoPorPaquete << " cajas de vino blanco y " << cajasVinoTintoPorPaquete << " cajas de vino tinto" << endl;
    return 0;
}
