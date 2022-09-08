#include <iostream>

#define LARGO_NOMBRE 20
#define LARGO_APELLIDO 50

///---------Ej. 8---------
/// Agregar la funcionalidad de borrar un alumno. El borrado puede hacerse lógico, es decir
/// poniendo una bandera en el registro que esté activo
/// Recuerde agregar la opción borrar en el menú y actualizar las funciones de búsqueda y lista para
/// que no muestren registros borrados.
/// ¿Qué debería hacer si desea borrar físicamente del archivo un registro?

using namespace std;

struct Alumno
{
    char nombre[LARGO_NOMBRE];
    char apellido[LARGO_APELLIDO];
    long legajo;
    long dni;
    // Tip: Vamos a guardarlas en formato AAAAMMDD
    long fechaDeNacimiento;
    bool borrado;
};

int cantidadDeAlumnosEnArchivo (FILE* f)
{
    long tamanioEnBytes;
    int cantidadElementos;

    fseek(f, 0, SEEK_END);
    tamanioEnBytes = ftell(f);
    cantidadElementos = tamanioEnBytes / sizeof(Alumno);
    fseek(f, 0, SEEK_SET);
    return cantidadElementos;
}

void agregarAlumno ()
{
    Alumno a;
    FILE* f = fopen("alumnos.bin", "ab");
    if (f == NULL)
    {
        cout << endl << "ERROR: No se pudo abrir el archivo" << endl;
        return;
    }

    // Tip: Como usamos cin >> para ingresar algunos datos y acá vamos a usar cin.getline(), debemos dejar limpio el búfer con cin.ignore()
    cin.ignore();
    cout << endl << "Nombre: ";
    cin.getline(a.nombre, LARGO_NOMBRE);
    cout << "Apellido: ";
    cin.getline(a.apellido, LARGO_APELLIDO);
    cout << "Legajo: ";
    cin >> a.legajo;
    cout << "DNI: ";
    cin >> a.dni;
    cout << "Fecha de nacimiento (AAAAMMDD): ";
    cin >> a.fechaDeNacimiento;
    a.borrado = false;

    fwrite(&a, sizeof(Alumno), 1, f);
    fclose(f);
}

void listarAlumnos ()
{
    Alumno a;
    int i = 1;
    FILE* f = fopen("alumnos.bin", "rb");

    if (f == NULL)
    {
        cout << endl << "ERROR: No se pudo abrir el archivo" << endl;
        return;
    }

    while (fread(&a, sizeof(Alumno), 1, f))
    {
        if (!a.borrado)
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
    fclose(f);
}

void buscarPorLegajo ()
{
    Alumno a;
    FILE* f = fopen("alumnos.bin", "rb");
    if (f == NULL)
    {
        cout << endl << "ERROR: No se pudo abrir el archivo" << endl;
        return;
    }

    long legajoObjetivo;
    cout << endl << "Legajo a buscar: ";
    cin >> legajoObjetivo;

    while (fread(&a, sizeof(Alumno), 1, f))
    {
        // Tip: Ignoramos los alumnos borrados en la búsqueda
        if (!a.borrado && a.legajo == legajoObjetivo)
        {
            cout << endl << "¡¡Alumno encontrado!!" << endl;
            cout << "Nombre: " << a.nombre << endl;
            cout << "Apellido: " << a.apellido << endl;
            cout << "DNI: " << a.dni << endl;
            cout << "Fecha de nacimiento (AAAAMMDD): " << a.fechaDeNacimiento << endl;
            fclose(f);
            return;
        }
    }

    fclose(f);
    cout << "No se encontro ningun alumno con el legajo " << legajoObjetivo << endl;
}

void buscarPorDNI ()
{
    Alumno a;
    FILE* f = fopen("alumnos.bin", "rb");
    if (f == NULL)
    {
        cout << endl << "ERROR: No se pudo abrir el archivo" << endl;
        return;
    }

    long dniObjetivo;
    cout << endl << "DNI a buscar: ";
    cin >> dniObjetivo;

    while (fread(&a, sizeof(Alumno), 1, f))
    {
        // Tip: Ignoramos los alumnos borrados en la búsqueda
        if (!a.borrado && a.dni == dniObjetivo)
        {
            cout << endl << "¡¡Alumno encontrado!!" << endl;
            cout << "Nombre: " << a.nombre << endl;
            cout << "Apellido: " << a.apellido << endl;
            cout << "Legajo: " << a.legajo<< endl;
            cout << "Fecha de nacimiento (AAAAMMDD): " << a.fechaDeNacimiento << endl;
            fclose(f);
            return;
        }
    }

    fclose(f);
    cout << "No se encontro ningun alumno con el DNI " << dniObjetivo << endl;
}

void ordenarPorLegajo ()
{
    FILE* f = fopen("alumnos.bin", "rb+");
    if (f == NULL)
    {
        cout << endl << "ERROR: No se pudo abrir el archivo" << endl;
        return;
    }

    Alumno a1, a2;
    int cantidadAlumnos = cantidadDeAlumnosEnArchivo(f);

    // Tip: Hacemos un burbujeo de los bloques Alumno, ordenándolos ascendentemente por su legajo
    for (int i = 0; i < (cantidadAlumnos - 1); i++)
    {
        for (int j = 0; j < (cantidadAlumnos - 1); j++)
        {
            // Tip: Movemos el cursor del flujo justo antes de los dos bloques Alumno que queremos leer
            fseek(f, j * sizeof(Alumno), SEEK_SET);
            fread(&a1, sizeof(Alumno), 1, f);
            fread(&a2, sizeof(Alumno), 1, f);

            if (a2.legajo < a1.legajo)
            {
                // Tip: Para reordenar un par de bloques, movemos el cursor justo antes de ambos, y los escribimos al revés de como estaban
                fseek(f, j * sizeof(Alumno), SEEK_SET);
                fwrite(&a2, sizeof(Alumno), 1, f);
                fwrite(&a1, sizeof(Alumno), 1, f);
            }
        }
    }
    fclose(f);
}

void modificarPorLegajo ()
{
    Alumno a;
    FILE* f = fopen("alumnos.bin", "rb+");
    if (f == NULL)
    {
        cout << endl << "ERROR: No se pudo abrir el archivo" << endl;
        return;
    }

    long legajoObjetivo;
    cout << endl << "Legajo a buscar: ";
    cin >> legajoObjetivo;

    while (fread(&a, sizeof(Alumno), 1, f))
    {
        // Tip: Ignoramos los alumnos borrados en la búsqueda
        if (!a.borrado && a.legajo == legajoObjetivo)
        {
            cout << endl << "¡¡Alumno encontrado!! Ingrese sus nuevos datos" << endl;
            cout << "Nombre: ";
            cin >> a.nombre;
            cout << "Apellido: ";
            cin >> a.apellido;
            cout << "DNI: ";
            cin >> a.dni;
            cout << "Fecha de nacimiento (AAAAMMDD): ";
            cin >> a.fechaDeNacimiento;

            // Tip: Nos movemos un bloque atrás para poder escribir el Alumno con los nuevos datos
            fseek(f, (-1) * sizeof(Alumno), SEEK_CUR);
            fwrite(&a, sizeof(Alumno), 1, f);
            fclose(f);
            return;
        }
    }

    fclose(f);
    cout << "No se encontro ningun alumno con el legajo " << legajoObjetivo << endl;
}

void borrarPorLegajo ()
{
    Alumno a;
    FILE* f = fopen("alumnos.bin", "rb+");
    if (f == NULL)
    {
        cout << endl << "ERROR: No se pudo abrir el archivo" << endl;
        return;
    }

    long legajoObjetivo;
    cout << endl << "Legajo a buscar: ";
    cin >> legajoObjetivo;

    while (fread(&a, sizeof(Alumno), 1, f))
    {
        // Tip: Ignoramos los alumnos borrados en la búsqueda
        if (!a.borrado && a.legajo == legajoObjetivo)
        {
            // Tip: Nos movemos un bloque atrás para poder escribir el Alumno con los nuevos datos
            fseek(f, (-1) * sizeof(Alumno), SEEK_CUR);
            a.borrado = true;
            fwrite(&a, sizeof(Alumno), 1, f);
            fclose(f);

            cout << "¡¡Alumno borrado!!" << endl;
            return;
        }
    }

    fclose(f);
    cout << "No se encontro ningun alumno con el legajo " << legajoObjetivo << endl;
}

// **RESPUESTA**
// Para borrar el registro del archivo, deberíamos ejecutar los siguientes pasos:
//      1. Abrir el archivo original en modo rb
//      2. Abrir un archivo auxiliar en modo wb (será temporal, no hace falta que exista)
//      3. Mover el puntero del archivo auxiliar al principio
//      4. Leer el contenido del archivo original e ir copiándolo al archivo auxiliar, omitiendo el registro a borrar
//      5. Cerrar ambos archivos
//      6. Abrir el archivo original en modo wb (lo vamos a escribir de nuevo)
//      7. Abrir el archivo auxiliar en modo rb (lo vamos a ir leyendo ahora)
//      8. Leer el contenido del archivo auxiliar e ir copiándolo al archivo original (no tendrá el registro a borrar!)
//      9. Cerrar ambos archivos

int main()
{
    char opcionElegida;

    do
    {
        switch (opcionElegida)
        {
            case '1':
                agregarAlumno();
                break;
            case '2':
                listarAlumnos();
                break;
            case '3':
                buscarPorLegajo();
                break;
            case '4':
                buscarPorDNI();
                break;
            case '5':
                ordenarPorLegajo();
                break;
            case '6':
                modificarPorLegajo();
                break;
            case '7':
                borrarPorLegajo();
                break;
        }

        cout << endl << "Elija una de las siguientes opciones, y luego presione Enter" << endl;
        cout << "1 - Agregar un alumno" << endl;
        cout << "2 - Listar todos los alumnos" << endl;
        cout << "3 - Buscar alumno por legajo" << endl;
        cout << "4 - Buscar alumno por DNI" << endl;
        cout << "5 - Ordenar archivo por legajo" << endl;
        cout << "6 - Modificar un alumno por legajo" << endl;
        cout << "7 - Borrar un alumno por legajo" << endl;
        cout << "0 - Salir" << endl;
        cin >> opcionElegida;
    } while (opcionElegida != '0');

    return 0;
}
