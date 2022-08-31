#include <iostream>

#define LARGO_NOMBRE 20
#define LARGO_APELLIDO 50

///---------Ej. 6---------
/// Escriba un programa que guarde en un archivo tres alumnos y luego los liste. El alumno es una
/// estructura que contiene:
///     Nombre
///     Apellido
///     Legajo
///     DNI
///     Fecha de nacimiento

using namespace std;

struct Alumno
{
    char nombre[LARGO_NOMBRE];
    char apellido[LARGO_APELLIDO];
    long legajo;
    long dni;
    // Tip: Vamos a guardarlas en formato AAAAMMDD
    long fechaDeNacimiento;
};

void cargarAlumnos (FILE* flujo)
{
    Alumno a;
    cout << "****Carga de almunos****" << endl;
    for (int i = 1; i <= 3; i++)
    {
        cout << endl << "**Alumno " << i << "**" << endl;
        cout << "Nombre: ";
        cin.getline(a.nombre, LARGO_NOMBRE);
        cout << "Apellido: ";
        cin.getline(a.apellido, LARGO_APELLIDO);
        cout << "Legajo: ";
        cin >> a.legajo;
        cout << "DNI: ";
        cin >> a.dni;
        cout << "Fecha de nacimiento (AAAAMMDD): ";
        cin >> a.fechaDeNacimiento;
        // Tip: Como usamos cin >> para ingresar algunos campos y luego vamos a usar cin.getline(), debemos dejar limpio el búfer con cin.ignore()
        cin.ignore();
        fwrite(&a, sizeof(Alumno), 1, flujo);
    }
}

void mostrarAlumnos (FILE* flujo)
{
    Alumno a;
    int i = 1;
    // Tip: Movemos el puntero del flujo al principio del archivo antes de leer su contenido
    fseek(flujo, 0, SEEK_SET);

    while (fread(&a, sizeof(Alumno), 1, flujo))
    {
        cout << endl << "**Alumno " << i << "**" << endl;
        cout << "Nombre: " << a.nombre << endl;
        cout << "Apellido: " << a.apellido << endl;
        cout << "Legajo: " << a.legajo << endl;
        cout << "DNI: " << a.dni << endl;
        cout << "Fecha de nacimiento (AAAAMMDD): " << a.fechaDeNacimiento << endl;
        i++;
    }
}

int main()
{
    FILE* f;

    // Tip: Abrimos el archivo en modo wb+ ya que, aparte de también poder leer, queremos re-crearlo en cada ejecución del programa
    f = fopen("alumnos.bin", "wb+");
    if (f == NULL)
    {
        cout << "Error: No se pudo crear el archivo" << endl;
        return 1;
    }

    cargarAlumnos(f);
    cout << endl << endl << "****Alumnos cargados****" << endl;
    mostrarAlumnos(f);

    fclose(f);
    return 0;
}
