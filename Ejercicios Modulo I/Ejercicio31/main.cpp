#include <iostream>

/// ---------Ej.MI-31---------
/// El gobierno de la Ciudad de Buenos Aires realiza una encuesta en casas de
/// familia. De cada familia conoce: domicilio, tipo de vivienda (‘C’:casa, ‘D’:departamento), y
/// cantidad de integrantes.
/// De cada integrante de la familia se conoce: nombre y apellido, edad, sexo (‘F’, ‘M’), nivel de
/// estudios alcanzados (‘N’: no posee, ‘P’: primario, ‘S’: secundario, ‘T’: terciario, ‘U’:
/// universitario), y un indicador (‘I’: incompleto, ‘C’: completo) que se refiere al ítem anterior.
/// Los datos finalizan cuando la cantidad de integrantes sea igual a cero.
/// Se pide emitir un listado con los resultados:
///     a) los datos de los encuestados que hayan completado los estudios primarios
///     b) el porcentaje de analfabetismo en la ciudad (se considera analfabetos a los mayores de
///        10 años que no posean estudios)
///     c) el domicilio de la familia con mayor cantidad de integrantes que viven en
///        departamento
///     d) edad promedio de cada familia y de la ciudad
///     e) cantidad de encuestados en cada tipo de nivel de estudios alcanzados incompletos.
///     f) porcentaje de encuestados de sexo femenino y masculino.

using namespace std;

int main()
{
    string domicilio, nombre, apellido;
    char tipoDeVivienda, sexo, nivelDeEstudios, estadoEstudios;
    unsigned int cantidadDeIntegrantes, edad;
    int i, sumatoriaEdadesFamilia;
    int cantidadAnalfabetos = 0;
    int cantidadEncuestados = 0;
    string domicilioDeptoMasIntegrantes = "";
    int integrantesDeptoMasHabitado = 0;
    int sumatoriaEdadesCiudad = 0;
    int cantidadPrimarioIncompleto = 0;
    int cantidadSecundarioIncompleto = 0;
    int cantidadTerciarioIncompleto = 0;
    int cantidadUniversitarioIncompleto = 0;
    int cantidadMujeres = 0;
    int cantidadHombres = 0;

    cout << "***************" << endl;
    cout << "Domicilio de la familia: ";
    // Tip: Usamos getline para tomar los espacios en blanco como parte de la cadena ingresada
    getline(cin, domicilio);
    cout << "Tipo de vivienda ('C' o 'D'): ";
    cin >> tipoDeVivienda;
    cout << "Cantidad de integrantes de la familia: ";
    cin >> cantidadDeIntegrantes;

    while(cantidadDeIntegrantes != 0)
    {
        sumatoriaEdadesFamilia = 0;
        if (tipoDeVivienda == 'D' && cantidadDeIntegrantes > integrantesDeptoMasHabitado)
        {
            domicilioDeptoMasIntegrantes = domicilio;
            integrantesDeptoMasHabitado = cantidadDeIntegrantes;
        }
        for (i = 1; i <= cantidadDeIntegrantes; i++)
        {
            cout << "***INTEGRANTE " << i << "***" << endl;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Apellido: ";
            cin >> apellido;
            cout << "Edad: ";
            cin >> edad;
            sumatoriaEdadesFamilia += edad;
            cout << "Sexo ('F' o 'M'): ";
            cin >> sexo;
            switch (sexo)
            {
                case 'F':
                    cantidadMujeres++;
                    break;
                case 'M':
                    cantidadHombres++;
                    break;
            }
            cout << "Nivel de estudios alcanzado ('N', 'P', 'S', 'T' o 'U'): ";
            cin >> nivelDeEstudios;
            if (nivelDeEstudios != 'N')
            {
                cout << "Estado del nivel de estudios ('I' o 'C'): ";
                cin >> estadoEstudios;
                switch (nivelDeEstudios)
                {
                    case 'P':
                        if (estadoEstudios == 'C')
                        {
                            cout << "Felicidades por completar el primario, " << nombre << "!" << endl;
                        }
                        else
                        {
                            cantidadPrimarioIncompleto++;
                        }
                        break;
                    case 'S':
                        cout << "Felicidades por completar el primario, " << nombre << "!" << endl;
                        if (estadoEstudios == 'I')
                        {
                            cantidadSecundarioIncompleto++;
                        }
                        break;
                    case 'T':
                        cout << "Felicidades por completar el primario, " << nombre << "!" << endl;
                        if (estadoEstudios == 'I')
                        {
                            cantidadTerciarioIncompleto++;
                        }
                        break;
                    case 'U':
                        cout << "Felicidades por completar el primario, " << nombre << "!" << endl;
                        if (estadoEstudios == 'I')
                        {
                            cantidadUniversitarioIncompleto++;
                        }
                        break;
                }
            }
            else if (edad > 10)
            {
                cantidadAnalfabetos++;
            }
        }

        if (cantidadDeIntegrantes > 0)
        {
            cantidadEncuestados += cantidadDeIntegrantes;
            sumatoriaEdadesCiudad += sumatoriaEdadesFamilia;
            cout << endl << "Edad promedio de la familia: " << (float) sumatoriaEdadesFamilia/cantidadDeIntegrantes << " anios" << endl;
        }
        else
        {
            cout << endl << "Cantidad de integrantes invalida, familia no registrada" << endl;
        }

        cout << endl << "***************" << endl;
        // Tip: Limpiamos el buffer de cualquier caracter que los anteriores cin >> hayan dejado
        cin.ignore();
        cout << "Domicilio de la familia: ";
        getline(cin, domicilio);
        cout << "Tipo de vivienda ('C' o 'D'): ";
        cin >> tipoDeVivienda;
        cout << "Cantidad de integrantes de la familia: ";
        cin >> cantidadDeIntegrantes;
    }

    cout << endl << endl << "*******RESULTADOS DE LA ENCUESTA*******" << endl << endl;
    if (cantidadEncuestados > 0)
    {
        cout << "Se encuesto a " << cantidadEncuestados << " personas" << endl;
        float proporcionAnalfabetos = (float) cantidadAnalfabetos / cantidadEncuestados;
        cout << "La ciudad tiene un analfabetismo del " << proporcionAnalfabetos * 100 << "%" << endl;
        cout << "El departamento con mayor cantidad de integrantes (" << integrantesDeptoMasHabitado << ") esta en el domicilio " << domicilioDeptoMasIntegrantes << endl;
        cout << "Edad promedio de la ciudad: " << (float) sumatoriaEdadesCiudad/cantidadEncuestados << " anios" << endl;
        cout << "Ciudadanos con el primario incompleto: " << cantidadPrimarioIncompleto << endl;
        cout << "Ciudadanos con el secundario incompleto: " << cantidadSecundarioIncompleto << endl;
        cout << "Ciudadanos con el terciario incompleto: " << cantidadTerciarioIncompleto << endl;
        cout << "Ciudadanos con el universitario incompleto: " << cantidadUniversitarioIncompleto << endl;
        float proporcionMujeres = (float) cantidadMujeres / cantidadEncuestados;
        cout << "Porcentaje femenino de la poblacion: " << proporcionMujeres * 100 << "%" << endl;
        float proporcionHombres = (float) cantidadHombres / cantidadEncuestados;
        cout << "Porcentaje masculino de la poblacion: " << proporcionHombres * 100 << "%" << endl;
    }
    else
    {
        cout << "No se encuesto a nadie" << endl;
    }
    return 0;
}
