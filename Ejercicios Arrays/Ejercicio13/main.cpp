#include <iostream>
#include <cstring>

#define CANTIDAD_EMPLEADOS 25
#define LARGO_NOMBRE 40
#define LARGO_ESTADO_CIVIL 16
#define LARGO_DIRECCION 40

///---------Ej. 13---------
/// Se desea obtener cierta información correspondiente a los empleados de
/// una empresa. La misma tiene 25 empleados y los datos que tiene son: DNI,
/// nombre, estado civil, dirección, teléfono, sexo y edad. Se pide:
///     − Listado de los empleados que estén próximos a jubilarse ordenados
///       alfabéticamente.
///     − Edad promedio de los empleados.
///     − Todos los datos de un empleado. (Al seleccionar esta opción, el
///       sistema debe solicitar el DNI)
///     − El usuario deberá poder elegir la operación a realizar.

using namespace std;

struct Empleado
{
    long dni;
    char nombre[LARGO_NOMBRE];
    char estadoCivil[LARGO_ESTADO_CIVIL];
    char direccion[LARGO_DIRECCION];
    long telefono;
    char sexo;
    unsigned int edad;
};

void cargarEmpleado (Empleado &e, int &sumatoriaEdades)
{
    cout << "DNI: ";
    cin >> e.dni;
    // Tip: Como estamos usando cin >> para ingresar algunos campos y ahora vamos a usar cin.getline(), debemos dejar limpio el búfer con cin.ignore()
    cin.ignore();
    cout << "Nombre completo: ";
    cin.getline(e.nombre, LARGO_NOMBRE);
    cout << "Estado civil: ";
    cin.getline(e.estadoCivil, LARGO_ESTADO_CIVIL);
    cout << "Direccion: ";
    cin.getline(e.direccion, LARGO_DIRECCION);
    cout << "Telefono: ";
    cin >> e.telefono;
    cout << "Sexo (M o F): ";
    cin >> e.sexo;
    cout << "Edad: ";
    cin >> e.edad;
    sumatoriaEdades += e.edad;
    // Tip: Fines estéticos, para separar una carga de otra
    cout << endl;
}

// Tip: Se considera "próximo a jubilarse" a todo empleado de 60 años o más; retorna la cantidad que caen en esa categoría
int obtenerEmpleadosProximosAJubilarse (Empleado todosLosEmpleados[], Empleado proximosAJubilarse[])
{
    int i = 0;
    for (int j = 0; j < CANTIDAD_EMPLEADOS; j++)
    {
        if (todosLosEmpleados[j].edad >= 60)
        {
            proximosAJubilarse[i] = todosLosEmpleados[j];
            i++;
        }
    }
    return i;
}

void ordenarEmpleadosAlfabeticamente (Empleado empleados[], int cantidadEmpleados)
{
    int i, j;
    Empleado aux;
    for (i = 0; i < cantidadEmpleados - 1; i++)
    {
        for (j = 0; j < cantidadEmpleados - 1; j++)
        {
            // Tip: El resultado de strcmp será positivo si el primer argumento es lexicográficamente mayor (es decir, viene después en el alfabeto)
            if (strcmp(empleados[j].nombre, empleados[j+1].nombre) > 0)
            {
                aux = empleados[j+1];
                empleados[j+1] = empleados[j];
                empleados[j] = aux;
            }
        }
    }
}

void mostrarEmpleado (Empleado e)
{
    cout << "DNI: " << e.dni << endl;
    cout << "Nombre completo: " << e.nombre << endl;
    cout << "Estado civil: " << e.estadoCivil << endl;
    cout << "Direccion: " << e.direccion << endl;
    cout << "Telefono: " << e.telefono << endl;
    cout << "Sexo: " << e.sexo << endl;
    cout << "Edad: " << e.edad << " anios" << endl;
}

void mostrarEmpleados (Empleado empleados[], int cantidadEmpleados)
{
    for (int i = 0; i < cantidadEmpleados; i++)
    {
        cout << endl << "***EMPLEADO " << i + 1 << "***" << endl;
        mostrarEmpleado(empleados[i]);
    }
}

void mostrarEmpleadoPorDNI (Empleado empleados[], long dni)
{
    for (int i = 0; i < 25; i++)
    {
        if (empleados[i].dni == dni)
        {
            mostrarEmpleado(empleados[i]);
            return;
        }
    }
    cout << "No se encontro ningun empleado con ese DNI" << endl;
}

int main()
{
    Empleado empleados[CANTIDAD_EMPLEADOS];
    // Tip: Usamos el máximo tamaño posible, por si todos estuvieran próximos a jubilarse
    Empleado empleadosPorJubilarse[CANTIDAD_EMPLEADOS];
    int cantidadEmpleadosPorJubilarse;
    float edadPromedio;
    char opcionElegida;
    long dniObjetivo;
    int sumatoriaEdades = 0;

    cout << "*****CARGA DE EMPLEADOS*****" << endl << endl;
    for (int i = 0; i < CANTIDAD_EMPLEADOS; i++)
    {
        cout << "***DATOS EMPLEADO " << i + 1 << "***" << endl;
        cargarEmpleado(empleados[i], sumatoriaEdades);
    }

    cantidadEmpleadosPorJubilarse = obtenerEmpleadosProximosAJubilarse(empleados, empleadosPorJubilarse);
    ordenarEmpleadosAlfabeticamente(empleadosPorJubilarse, cantidadEmpleadosPorJubilarse);
    edadPromedio = (float) sumatoriaEdades / CANTIDAD_EMPLEADOS;

    do
    {
        switch (opcionElegida)
        {
            case '1':
                mostrarEmpleados(empleadosPorJubilarse, cantidadEmpleadosPorJubilarse);
                break;
            case '2':
                cout << endl << "El promedio de edad de los empleados es " << edadPromedio << endl;
                break;
            case '3':
                cout << endl << "DNI a buscar: ";
                cin >> dniObjetivo;
                mostrarEmpleadoPorDNI(empleados, dniObjetivo);
                break;
        }

        cout << endl << "Presione una de las siguientes opciones, y luego presione Enter" << endl;
        cout << "1 - Listado de los empleados que esten proximos a jubilarse ordenados alfabeticamente" << endl;
        cout << "2 - Edad promedio de los empleados" << endl;
        cout << "3 - Datos del empleado con cierto DNI" << endl;
        cout << "0 - Salir" << endl;
        cin >> opcionElegida;
    } while (opcionElegida != '0');
    return 0;
}
