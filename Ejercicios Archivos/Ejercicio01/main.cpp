#include <iostream>

///---------Ej. 1---------
/// Escriba un programa que permita a un usuario ingresar n valores float y se guarden en un
/// archivo, el número n lo informa al comienzo del programa. Al finalizar el programa debe listar
/// todos los números guardados en el archivo.

using namespace std;

int main()
{
    int n;
    float valorIngresado, valorLeido;
    FILE* f;

    f = fopen("floats.bin", "wb");
    if (f == NULL)
    {
        cout << "ERROR: No se pudo crear el archivo donde escribir los valores" << endl;
        return 1;
    }

    cout << "Ingrese la cantidad de valores a ingresar: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Valor " << i + 1 << ": ";
        cin >> valorIngresado;
        // Tip: Cada vez que se ingresa un valor, también lo escribimos como 1 bloque del tamaño de un float en el archivo manejado por el flujo f
        fwrite(&valorIngresado, sizeof(float), 1, f);
    }
    fclose(f);

    f = fopen("floats.bin", "rb");
    if (f == NULL)
    {
        cout << "ERROR: No se pudo abrir el archivo de donde leer los valores" << endl;
        return 2;
    }

    cout << endl << "****Valores ingresados****" << endl;
    fseek(f, 0, SEEK_SET);
    // Tip: Podemos usar un for para llamar n veces a fread, ya que sabemos cuántos bloques debemos leer (n)
    for (int j = 0; j < n; j++)
    {
        fread(&valorLeido, sizeof(float), 1, f);
        cout << "Valor " << j + 1 << ": " << valorLeido << endl;
    }
    fclose(f);
    return 0;
}
