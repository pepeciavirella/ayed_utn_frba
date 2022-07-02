#include <iostream>
// Tip: Incluido para poder usar las funciones strcmp() y strcpy()
#include <cstring>

#define LARGO_APELLIDO_NOMBRE 40
// Tip: Lo definimos como un numero bastante alto, pero el ingreso de datos realmente se cortará al ingresar a "Roberto Wolf"
#define MAX_CANTIDAD_ALUMNOS 100

///---------Ej. 12---------
/// Se leen datos de notas obtenidas por los alumnos de una cátedra y se
/// desea informar
///     − el promedio de las notas obtenidas por los alumnos
///     − el nombre, tipo y número de documento y número de legajo
///       (padrón) de los alumnos que hayan aprobado con nota igual o mayor
///       que siete.
///     − Los datos del/los alumnos con peor nota.
/// La secuencia finaliza con el alumno Wolf Roberto que debe ser
/// procesado

using namespace std;

struct Estudiante
{
    char apellidoNombre[40];
    // Tip: Debería ser algo como "DNI", "LC", "LE", "CI", etc.
    char tipoDeDocumento[4];
    long numeroDeDocumento;
    int numeroDeLegajo;
    float nota;
};

void cargarEstudiante (Estudiante &e)
{
    cout << "Apellido y nombre: ";
    cin.getline(e.apellidoNombre, LARGO_APELLIDO_NOMBRE);
    cout << "Tipo de documento: ";
    cin >> e.tipoDeDocumento;
    cout << "Numero de documento: ";
    cin >> e.numeroDeDocumento;
    cout << "Numero de legajo: ";
    cin >> e.numeroDeLegajo;
    cout << "Nota obtenida: ";
    cin >> e.nota;
    // Tip: Como estamos usando cin >> para ingresar datos y en otra iteracion podriamos usar cin.getline(), debemos dejar limpio el búfer con cin.ignore()
    cin.ignore();
    // Tip: Fines estéticos, para separar una carga de otra
    cout << endl;
}

void mostrarAprobadosConMasDeSiete (Estudiante estudiantes[], int cantidadAlumnos)
{
    cout << endl << "**Alumnos aprobados con 7 o mas**" << endl;
    for (int i = 0; i < cantidadAlumnos; i++)
    {
        if (estudiantes[i].nota >= 7)
        {
            cout << "- " << estudiantes[i].apellidoNombre;
            cout << ". " << estudiantes[i].tipoDeDocumento << " " << estudiantes[i].numeroDeDocumento;
            cout << ". Legajo " << estudiantes[i].numeroDeLegajo << endl;
        }
    }
}

void mostrarEstudiantesConPeorNota (Estudiante estudiantes[], int cantidadAlumnos, float notaMasBaja)
{
    cout << endl << "La peor nota fue " << notaMasBaja << ", y fue obtenida por los alumnos:" << endl;
    for (int i = 0; i < cantidadAlumnos; i++)
    {
        if (estudiantes[i].nota == notaMasBaja)
        {
            cout << "- " << estudiantes[i].apellidoNombre;
            cout << ". " << estudiantes[i].tipoDeDocumento << " " << estudiantes[i].numeroDeDocumento;
            cout << ". Legajo " << estudiantes[i].numeroDeLegajo << endl;
        }
    }
}

int main()
{
    Estudiante alumnos[MAX_CANTIDAD_ALUMNOS];
    int comparacionApellidoNombre;
    int i = 0;
    float sumatoriaNotas = 0;
    // Tip: Inicializamos en algo más alto que la nota más alta posible, para que todas sean más bajas. Suponemos que la más alta es un 10.
    float peorNota = 10.1;
    float promedioNotas;

    do
    {
        cout << "***DATOS ESTUDIANTE " << i + 1 << "***" << endl;
        cargarEstudiante(alumnos[i]);
        // Tip: strcmp(s1, s2) retornará 0 si s1 y s2 son la misma cadena, u otro valor si son distintas
        comparacionApellidoNombre = strcmp(alumnos[i].apellidoNombre, "Wolf Roberto");
        sumatoriaNotas += alumnos[i].nota;
        if (alumnos[i].nota < peorNota)
        {
            peorNota = alumnos[i].nota;
        }
        i++;
    } while ((comparacionApellidoNombre != 0) && (i < MAX_CANTIDAD_ALUMNOS));

    promedioNotas = sumatoriaNotas / i;
    cout << endl << endl << "****RESULTADOS****" << endl;
    cout << "El promedio de todas las notas fue " << promedioNotas << endl;
    mostrarAprobadosConMasDeSiete(alumnos, i);
    mostrarEstudiantesConPeorNota(alumnos, i, peorNota);
    return 0;
}
