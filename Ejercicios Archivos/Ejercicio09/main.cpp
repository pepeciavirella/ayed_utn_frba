#include <iostream>

#define LARGO_NOMBRE 20
#define LARGO_APELLIDO 50
#define LARGO_CODIGO_CURSO 5

///---------Ej. 9---------
/// Se extiende el programa anterior con un manejo de archivo de cursadas. El programa debe
/// permitir ingresar una cursada de un alumno a una materia utilizando la siguiente estructura:
///     Código materia
///     Código materia
///     Año
///     Cuatrimestre
///     Legajo alumno
///     Nota final
///     Borrado: true/false
/// Extienda el menú para poder ingresar la cursada de un alumno. Si el alumno no existe, el programa
/// debe mostrar un mensaje de error “Alumno inexistente en archivo”.
/// Además debe también listar todas las cursadas de un alumno dado.

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

struct Cursada
{
    long codigoMateria;
    char codigoCurso[LARGO_CODIGO_CURSO];
    int agno;
    int cuatrimestre;
    long legajoAlumno;
    float notaFinal;
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
        cout << endl << "ERROR: No se pudo abrir el archivo de alumnos" << endl;
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
        cout << endl << "ERROR: No se pudo abrir el archivo de alumnos" << endl;
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
        cout << endl << "ERROR: No se pudo abrir el archivo de alumnos" << endl;
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
        cout << endl << "ERROR: No se pudo abrir el archivo de alumnos" << endl;
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
        cout << endl << "ERROR: No se pudo abrir el archivo de alumnos" << endl;
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
        cout << endl << "ERROR: No se pudo abrir el archivo de alumnos" << endl;
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
        cout << endl << "ERROR: No se pudo abrir el archivo de alumnos" << endl;
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

bool alumnoExiste(long legajo)
{
    Alumno a;
    FILE* f = fopen("alumnos.bin", "rb");
    if (f == NULL)
    {
        cout << endl << "ERROR: No se pudo abrir el archivo de alumnos" << endl;
        // Tip: Si no se puede abrir el archivo, no podemos asumir que el alumno existe
        return false;
    }

    while (fread(&a, sizeof(Alumno), 1, f))
    {
        // Tip: Ignoramos los alumnos borrados en la búsqueda
        if (!a.borrado && a.legajo == legajo)
        {
            fclose(f);
            return true;
        }
    }

    fclose(f);
    cout << "Alumno inexistente en archivo" << endl;
    return false;
}

void ingresarCursada()
{
    long legajoObjetivo;
    cout << endl << "Legajo del alumno: ";
    cin >> legajoObjetivo;

    if (!alumnoExiste(legajoObjetivo))
    {
        return;
    }

    Cursada c;
    FILE* f = fopen("cursadas.bin", "ab");
    if (f == NULL)
    {
        cout << "ERROR: No se pudo abrir el archivo de cursadas" << endl;
        return;
    }

    c.legajoAlumno = legajoObjetivo;
    c.borrado = false;
    cout << endl << "Codigo de materia: ";
    cin >> c.codigoMateria;
    cout << "Codigo de curso: ";
    cin >> c.codigoCurso;
    cout << "Anio: ";
    cin >> c.agno;
    cout << "Cuatrimestre: ";
    cin >> c.cuatrimestre;
    cout << "Nota final: ";
    cin >> c.notaFinal;

    fwrite(&c, sizeof(Cursada), 1, f);
    fclose(f);
}

void listarCursadas()
{
    long legajoObjetivo;
    cout << endl << "Legajo del alumno: ";
    cin >> legajoObjetivo;

    if (!alumnoExiste(legajoObjetivo))
    {
        return;
    }

    Cursada c;
    int i = 1;
    // Tip: Abrimos el archivo en modo ab+ para que, en caso de no existir, este sea creado
    FILE* f = fopen("cursadas.bin", "ab+");
    if (f == NULL)
    {
        cout << "ERROR: No se pudo abrir el archivo de cursadas" << endl;
        return;
    }

    // Tip: Movemos el cursor al principio del archivo antes de comenzar a leer
    fseek(f, 0, SEEK_SET);
    while (fread(&c, sizeof(Cursada), 1, f))
    {
        // Tip: Ignoramos las cursadas borradas en la búsqueda
        if (!c.borrado && c.legajoAlumno == legajoObjetivo)
        {
            cout << endl << "**Cursada " << i << "**" << endl;
            cout << "Codigo de materia: " << c.codigoMateria << endl;
            cout << "Codigo de curso: " << c.codigoCurso << endl;
            cout << "Anio: " << c.agno << endl;
            cout << "Cuatrimestre: " << c.cuatrimestre << endl;
            cout << "Nota final: " << c.notaFinal << endl;
            i++;
        }
    }

    fclose(f);
}

void borrarCursada()
{
    long legajoObjetivo;
    cout << endl << "Legajo del alumno: ";
    cin >> legajoObjetivo;

    if (!alumnoExiste(legajoObjetivo))
    {
        return;
    }

    Cursada c;
    // Tip: No usamos ab+ sino rb+, ya que con ab y ab+ la escritura es SIEMPRE al final, por más que hagamos un fseek
    // (Y vamos a necesitar un fseek para marcar la Cursada encontrada como borrada). Si no existe, lo creamos con wb+
    FILE* f = fopen("cursadas.bin", "rb+");
    if (f == NULL)
    {
        f = fopen("cursadas.bin", "wb+");
        if (f == NULL)
        {
            cout << "ERROR: No se pudo abrir el archivo de cursadas" << endl;
            return;
        }
    }

    long codigoMateriaObjetivo;
    int agnoObjetivo;
    int cuatrimestreObjetivo;
    cout << endl << "Codigo de materia cursada a eliminar: ";
    cin >> codigoMateriaObjetivo;
    cout << "Anio de cursada a eliminar: ";
    cin >> agnoObjetivo;
    cout << "Cuatrimestre de cursada a eliminar: ";
    cin >> cuatrimestreObjetivo;

    // Tip: Movemos el cursor al principio del archivo antes de comenzar a leer
    fseek(f, 0, SEEK_SET);
    while (fread(&c, sizeof(Cursada), 1, f))
    {
        // Tip: Ignoramos las cursadas ya borrados en la búsqueda
        if (!c.borrado && c.codigoMateria == codigoMateriaObjetivo && c.agno == agnoObjetivo && c.cuatrimestre == cuatrimestreObjetivo)
        {
            // Tip: Nos movemos un bloque atrás para poder escribir la Cursada con los nuevos datos
            fseek(f, (-1) * sizeof(Cursada), SEEK_CUR);
            c.borrado = true;
            fwrite(&c, sizeof(Cursada), 1, f);
            fclose(f);

            cout << "¡¡Cursada borrada!!" << endl;
            return;
        }
    }

    fclose(f);
    cout << "No se encontro ninguna cursada de la materia, anio y cuatrimestre indicados" << endl;
}

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
            case '8':
                ingresarCursada();
                break;
            case '9':
                listarCursadas();
                break;
            case 'A': case 'a':
                borrarCursada();
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
        cout << "8 - Agregar una cursada de alumno" << endl;
        cout << "9 - Listar cursadas de un alumno" << endl;
        cout << "A - Borrar una cursada de alumno" << endl;
        cout << "0 - Salir" << endl;
        cin >> opcionElegida;
    } while (opcionElegida != '0');

    return 0;
}
