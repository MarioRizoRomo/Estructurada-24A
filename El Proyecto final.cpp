/*********************

NOMBRE: Roberto perez Zamora, Juan Pablo Gonzalez Jimenez, Eric Eduardo Angel Angel,  Mario Rizo Romo.
FECHA: 14/05/24
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas

DESCRIPCION: Una institución educativa universitaria de prestigio desea tener un programa donde tenga el registro de sus estudiantes, datos de contacto de sus familiares y el registro de calificaciones de cinco materias.
Se podrán consultar los datos de manera individual por estudiante, o de manera general, por grupo o por materia
Se podrán crear, modificar o eliminar estudiantes con sus respectivos datos.
Los datos deben ser guardados en archivos de texto para que cuando se vuelva a ejecutar el programa, haya datos.
En las calificaciones deberá tener el número de cada materia y el promedio, 
El promedio debe tener la leyenda siguiente: <= 59 Reprobado; 60 a 79: Regular; 80 a 89:  Muy bien y de 90 a 100: Excelente
*********************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

//Estructura de datos donde estaremos manejando las variables del los registros
struct Alumno {
    string matricula;
    string nombre;
    string apellido;
    string carrera;
    string contacto; 
    vector<string> materias;
    vector<float> calificaciones;
};

//Verifica que no se repita la matricula
bool matriculaExistente(const string& matricula) {
    ifstream archivo("Alumnos.txt");
    string linea;

    //Guarda la linea del txt en la variable linea
    while (getline(archivo, linea)) {

        //Convertimos linea en stringstream para poder fragmentar la linea
        stringstream ss(linea);
        //Declaramos la variable donde guardaremos cada fragmento de la linea
        string fragmento;

        //La linea guardada en ss fragmentara todo el string cada que haya una coma ","
        //y guardara cada parte en fragmento para despues hacer la comprobacion 
        getline(ss, fragmento, ',');
        if (fragmento == matricula) {
            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}//Finalizamos la funcion Matricula existente
//Verificamso que los datos ingresados sean numeros, estos pueden tener decimales
bool esNumeroValido(const string& str) {
    // Verifica si la cadena está vacía
    if (str.empty()) {
        return false;
    }

    // Itera sobre cada carácter de la cadena
    for (char c : str) {
        // Si el carácter no es un dígito, retorna false
        if (!isdigit(c) && c != '.') {
            return false;
        }
    }

    // Si todos los caracteres son dígitos o hay un punto decimal, retorna true
    return true;
}
//Verifica que los datos ingresados sean solo letras
bool soloLetras(const string& str) {
    for (char c : str) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}
//Verificamos que los datos ingresados son solo numeros
bool soloNumeros(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
//Funcion que permite agregar los datos a nuestro archivo .txt
void AgregarDatos(Alumno& Alumno) {
    //Declaramos la variable donde guardaremos cada fragmento de la linea y lo almacenaremos
    cout << "Ingrese la matricula del alumno: ";
    getline(cin, Alumno.matricula);

    //Usamos la funcion para comprobar la matricula, si hay una matricula igual no se ejecuta la funcion
    if (matriculaExistente(Alumno.matricula)) {
        cout << "La matricula ya existe. No se puede agregar el alumno." << endl;
        return;
    }

    cout << "Ingrese el nombre del alumno: ";
    getline(cin, Alumno.nombre);

    cout << "Ingrese los apellidos del alumno:";
    getline(cin, Alumno.apellido);

    cout << "Ingrese la carrera del alumno: ";
    getline(cin, Alumno.carrera);

    cout<< "Ingrese un nombre de contacto del alumno: ";
    getline(cin, Alumno.contacto);

    //Variables usadas para la verificacion de la entrada
    int CantMat;
    string input;

    cout << "Ingresa la cantidad de materias que deseas registrar: ";
    getline(cin, input);
    //Validamos que sea entero los datos que se ingresaron

    while (!esNumeroValido(input)) {
    cout << "Dato invalido Intente nuevamente: ";
    getline(cin, input);
    }

    //Verificamos que el numero ingresado sea mayor a 0
    if (esNumeroValido(input)){
        if (stoi(input) < 0)
        {
            while (stoi(input) < 0)
            {
                cout << "Dato invalido Intente nuevamente: ";
                getline(cin, input);
            }
        }
    }


    CantMat = stoi(input);

    //Ingresamos los datos de las 5 calificaciones con las materias
for (int i = 0; i < CantMat; i++) {
    string materia, calificaionComp;
    float calificacion;

    cout << "Ingrese el nombre de la materia " << i + 1 << endl;
    getline(cin, materia);
    Alumno.materias.push_back(materia);

    bool calificacionValida = false;

    while (!calificacionValida) {
        cout << "Ingrese la calificacion de la materia " << i + 1 << endl;
        getline(cin, calificaionComp);

        // Verifica si la entrada es un número válido
        if (esNumeroValido(calificaionComp)) {
            calificacion = stof(calificaionComp);

            // Verifica si la calificación está en el rango permitido
            if (calificacion >= 0 && calificacion <= 100) {
                calificacionValida = true;
            } else {
                cout << "La calificacion debe estar entre 0 y 100. Intente nuevamente." << endl;
            }
        } else {
            cout << "La calificacion ingresada no es un numero valido. Intente nuevamente." << endl;
        }
    }

    Alumno.calificaciones.push_back(calificacion);
}
    
    //Abrimos el archivo para editar
    ofstream ArchivoAgregar("Alumnos.txt", ios::app);

    //Escribimos las variables almacenadas separas por una coma
    ArchivoAgregar << Alumno.matricula << "," << Alumno.nombre << "," << Alumno.apellido << "," << Alumno.carrera << "," << Alumno.contacto<< ",";
    
    //Escribimos las calificaciones, separamos las materias con un | y las las calificaciones con :
    for (int i = 0; i < Alumno.materias.size(); i++)
    { 
        ArchivoAgregar << Alumno.materias[i] <<":"<<Alumno.calificaciones[i];
        ArchivoAgregar <<"|"; 
    }
    
    //Hacemos salto de linea y finalizamos funcion cerrando el archivo
    ArchivoAgregar << endl;
    ArchivoAgregar.close();
}
//Funcion que lee los datos del .txt y los muestra en pantalla
void MostrarAlumnos() {
    //Abrimos el archivo para leer
    ifstream ArchivoMostrar("Alumnos.txt");
    string linea;

        //Lee linea por linea y lo imprime
        while (getline(ArchivoMostrar, linea)) {
            Alumno AlumnoImprimir;
            stringstream ss(linea);

            //Cada coma indica una variable distinta
            getline(ss, AlumnoImprimir.matricula, ',');
            getline(ss, AlumnoImprimir.nombre, ',');
            getline(ss, AlumnoImprimir.apellido, ',');
            getline(ss, AlumnoImprimir.carrera, ',');
            getline(ss, AlumnoImprimir.contacto, ',');
            
            
            //Se lee lo que queda del la linea
            string MateriasCalificaiones;
            getline(ss, MateriasCalificaiones);

            //Se almacena la linea restante en un stringstream
            stringstream ssMC(MateriasCalificaiones);

            string fragmento;
            while (getline(ssMC, fragmento, '|')) {
                //Declaramos los strings
                string materiaStr, calificacionStr;

                //Convertimos fragmento a variable ssF tipo strinstream
                stringstream ssF(fragmento);
                
                //Separamos la materia con la calificacion por medio del :
                getline(ssF, materiaStr, ':');
                getline(ssF, calificacionStr, ':');
            
                //Convertimos calificacion a flotante
                float calificacionF = stof(calificacionStr);

                //Guarfamos en el vector la variable
                AlumnoImprimir.materias.push_back(materiaStr);
                AlumnoImprimir.calificaciones.push_back(calificacionF);

            }
            
            //Imprimimos
            cout <<endl << "---------------------------" << endl;
            cout << "Matricula: " << AlumnoImprimir.matricula << endl;
            cout << "Nombre: " << AlumnoImprimir.nombre << endl;
            cout << "Apellido: " << AlumnoImprimir.apellido << endl;
            cout << "Carrera: " << AlumnoImprimir.carrera << endl;
            cout << "Contacto: " << AlumnoImprimir.contacto << endl;

            //Imprimimos las materias con las calificaciones
            float suma = 0;
            for (int i = 0; i < AlumnoImprimir.calificaciones.size(); i++)
            {
            cout << "Materia " << i + 1 << ": " << AlumnoImprimir.materias[i] << " - Calificacion: " << AlumnoImprimir.calificaciones[i] << endl;
            suma += AlumnoImprimir.calificaciones[i];    
            }

        // Imprimimos el promedio
        float promedio = suma / AlumnoImprimir.calificaciones.size();
            cout << "Promedio: ";
        if (AlumnoImprimir.calificaciones.empty()) {
            cout << "No hay promedio existente" << endl;
        } else {
                cout << promedio << endl;
            if (promedio <= 59) {
                cout << "Reprobado" << endl;
            } else if (promedio <= 79) {
                cout << "Regular" << endl;
            } else if (promedio <= 89) {
                cout << "Muy bien" << endl;
            } else {
                cout << "Excelente" << endl;
            }
}

            
     }   
        //Cerramos archivo
        ArchivoMostrar.close();
    
}
//Funcion que busca y elimina un registro mediante su matricula
void eliminar() {
    string matriculaEliminar;
    cout << "Ingrese la matricula del alumno a eliminar: ";
    getline(cin, matriculaEliminar);

    ifstream archivoLectura("Alumnos.txt");
    ofstream archivoTemporal("temp.txt");

    string linea;
    bool encontrado = false;

    while (getline(archivoLectura, linea)) {
        stringstream ss(linea);
        string matricula;
        getline(ss, matricula, ',');

        if (matricula != matriculaEliminar) {
            archivoTemporal << linea << endl;
        } else {
            encontrado = true;
        }
    }

    archivoLectura.close();
    archivoTemporal.close();

    if (encontrado) {
        remove("Alumnos.txt");
        rename("temp.txt", "Alumnos.txt");
        cout << "Alumno eliminado correctamente." << endl;
    } else {
        remove("temp.txt");
        cout << "No se encontro la matricula del alumno." << endl;
    }
}
//Verifica que el archivo esta vacio
bool archivoVacio() {
    ifstream archivo("Alumnos.txt");
    return archivo.peek() == ifstream::traits_type::eof();
}

//====================================================================================================
//Funcion del roberto
//Funcion que busca a un alumno mediante su matricula, carrera o materias
void BuscarAlumno() {

    // Funcion del menu para modo de busqueda
    ifstream ArchivoBuscar("Alumnos.txt");
    string linea;
    char opcion;
    cout << "==================================================" << endl;
    cout << "Seleccione una opcion de busqueda:" << endl;
    cout << "1. Buscar por matricula" << endl;
    cout << "2. Buscar por materia" << endl;
    cout << "3. Buscar por carrera" << endl; // New option
    cout << "4. Salir" << endl; // New option
    cout << "Opcion: ";
    cin >> opcion;
    cout << "==================================================" << endl;
    cin.ignore();
//====================================================================================================
    // Opcion 1 con busqueda por matricula
    if (opcion == '1') {
        string matriculaBuscar;
        cout << "==================================================" << endl;
        cout << "Ingrese la matricula del alumno a buscar: ";
        cout << "==================================================" << endl;
        getline(cin, matriculaBuscar);

        bool encontrado = false; // Variable para indicar si se encontró el alumno

        while (getline(ArchivoBuscar, linea)) {
            Alumno AlumnoBuscar;
            stringstream ss(linea);

            getline(ss, AlumnoBuscar.matricula, ',');
            getline(ss, AlumnoBuscar.nombre, ',');
            getline(ss, AlumnoBuscar.apellido, ',');
            getline(ss, AlumnoBuscar.carrera, ',');
            getline(ss, AlumnoBuscar.contacto, ',');

            string MateriasCalificaiones;
            getline(ss, MateriasCalificaiones);

            stringstream ssMC(MateriasCalificaiones);

            string fragmento;
            while (getline(ssMC, fragmento, '|')) {
                string materiaStr, calificacionStr;
                stringstream ssF(fragmento);
                getline(ssF, materiaStr, ':');
                getline(ssF, calificacionStr, ':');
                float calificacionF = stof(calificacionStr);
                AlumnoBuscar.materias.push_back(materiaStr);
                AlumnoBuscar.calificaciones.push_back(calificacionF);
            }

            if (AlumnoBuscar.matricula == matriculaBuscar) {
                encontrado = true; // Se encontró el alumno

                cout << "==================================================" << endl;
                cout << "Matricula: " << AlumnoBuscar.matricula << endl;
                cout << "Nombre: " << AlumnoBuscar.nombre << endl;
                cout << "Apellido: " << AlumnoBuscar.apellido << endl;
                cout << "Carrera: " << AlumnoBuscar.carrera << endl;
                cout << "Contacto: " << AlumnoBuscar.contacto << endl;

                float suma = 0;
                for (int i = 0; i < AlumnoBuscar.calificaciones.size(); i++) {
                    cout << "Materia " << i + 1 << ": " << AlumnoBuscar.materias[i] << " - Calificacion: " << AlumnoBuscar.calificaciones[i] << endl;
                    suma += AlumnoBuscar.calificaciones[i];
                }

                float promedio = suma / AlumnoBuscar.calificaciones.size();
                cout << "Promedio: " << promedio << endl;
                cout << "==================================================" << endl;
                break; // Salir del bucle una vez encontrado el alumno
            }
        }

        if (!encontrado) {
            cout << "No se encontro ningun alumno con la matricula ingresada." << endl;
        }
    }
    //====================================================================================================
    //Funcion 2 con busqueda por materia
    else if (opcion == '2') {
        string materiaBuscar;
        cout << "Ingrese la materia del alumno a buscar: ";
        getline(cin, materiaBuscar);

        bool encontrado = false; // Variable para indicar si se encontró el alumno

        while (getline(ArchivoBuscar, linea)) {
            Alumno AlumnoBuscar;
            stringstream ss(linea);

            getline(ss, AlumnoBuscar.matricula, ',');
            getline(ss, AlumnoBuscar.nombre, ',');
            getline(ss, AlumnoBuscar.apellido, ',');
            getline(ss, AlumnoBuscar.carrera, ',');
            getline(ss, AlumnoBuscar.contacto, ',');

            string MateriasCalificaiones;
            getline(ss, MateriasCalificaiones);

            stringstream ssMC(MateriasCalificaiones);

            string fragmento;
            while (getline(ssMC, fragmento, '|')) {
                string materiaStr, calificacionStr;
                stringstream ssF(fragmento);
                getline(ssF, materiaStr, ':');
                getline(ssF, calificacionStr, ':');
                float calificacionF = stof(calificacionStr);
                AlumnoBuscar.materias.push_back(materiaStr);
                AlumnoBuscar.calificaciones.push_back(calificacionF);
            }

            for (int i = 0; i < AlumnoBuscar.materias.size(); i++) {
                if (AlumnoBuscar.materias[i] == materiaBuscar) {
                    encontrado = true; // Se encontró el alumno

                    cout << "==================================================" << endl;
                    cout << "Matricula: " << AlumnoBuscar.matricula << endl;
                    cout << "Nombre: " << AlumnoBuscar.nombre << endl;
                    cout << "Apellido: " << AlumnoBuscar.apellido << endl;
                    cout << "Carrera: " << AlumnoBuscar.carrera << endl;
                    cout << "Contacto: " << AlumnoBuscar.contacto << endl;

                    float suma = 0;
                    for (int i = 0; i < AlumnoBuscar.calificaciones.size(); i++) {
                        cout << "Materia " << i + 1 << ": " << AlumnoBuscar.materias[i] << " - Calificacion: " << AlumnoBuscar.calificaciones[i] << endl;
                        suma += AlumnoBuscar.calificaciones[i];
                    }

                    float promedio = suma / AlumnoBuscar.calificaciones.size();
                    cout << "Promedio: " << promedio << endl;
                    cout << "==================================================" << endl;
                    break; // Salir del bucle una vez encontrado el alumno
                }
            }
        }

        if (!encontrado) {
            cout << "No se encontro ningun alumno con la materia ingresada." << endl;
        }
    }
    //====================================================================================================
    else if (opcion == '3') { // Funcion 3 con busqueda por carrera
        string carreraBuscar;
        cout << "Ingrese la carrera del alumno a buscar: ";
        getline(cin, carreraBuscar);

        bool encontrado = false; // Variable para indicar si se encontró el alumno

        while (getline(ArchivoBuscar, linea)) {
            Alumno AlumnoBuscar;
            stringstream ss(linea);

            getline(ss, AlumnoBuscar.matricula, ',');
            getline(ss, AlumnoBuscar.nombre, ',');
            getline(ss, AlumnoBuscar.apellido, ',');
            getline(ss, AlumnoBuscar.carrera, ',');
            getline(ss, AlumnoBuscar.contacto, ',');

            string MateriasCalificaiones;
            getline(ss, MateriasCalificaiones);

            stringstream ssMC(MateriasCalificaiones);

            string fragmento;
            while (getline(ssMC, fragmento, '|')) {
                string materiaStr, calificacionStr;
                stringstream ssF(fragmento);
                getline(ssF, materiaStr, ':');
                getline(ssF, calificacionStr, ':');
                float calificacionF = stof(calificacionStr);
                AlumnoBuscar.materias.push_back(materiaStr);
                AlumnoBuscar.calificaciones.push_back(calificacionF);
            }

            if (AlumnoBuscar.carrera == carreraBuscar) {
                encontrado = true; // Se encontró el alumno

                cout << "==================================================" << endl;
                cout << "Matricula: " << AlumnoBuscar.matricula << endl;
                cout << "Nombre: " << AlumnoBuscar.nombre << endl;
                cout << "Apellido: " << AlumnoBuscar.apellido << endl;
                cout << "Carrera: " << AlumnoBuscar.carrera << endl;
                cout << "Contacto: " << AlumnoBuscar.contacto << endl;

                float suma = 0;
                for (int i = 0; i < AlumnoBuscar.calificaciones.size(); i++) {
                    cout << "Materia " << i + 1 << ": " << AlumnoBuscar.materias[i] << " - Calificacion: " << AlumnoBuscar.calificaciones[i] << endl;
                    suma += AlumnoBuscar.calificaciones[i];
                }

                float promedio = suma / AlumnoBuscar.calificaciones.size();
                cout << "Promedio: " << promedio << endl;
                cout << "==================================================" << endl;
                break; // Salir del bucle una vez encontrado el alumno
            }
        }

        if (!encontrado) {
            cout << "No se encontro ningun alumno con la carrera ingresada." << endl;
        }
    }
    //====================================================================================================
    else if (opcion == '4') { // Funcion 4 para salir del menu de busqueda
        cout << "Saliendo del menu de busqueda..." << endl;
    }
    else {
        cout << "Opcion invalida." << endl;
    }

    ArchivoBuscar.close();
}
//====================================================================================================


//Funcion del juan
//Funcion que permite editar los datos de un alumno
void EditarAlumno() {
    system("cls"); // Limpiar la pantalla
    string matriculaBuscar, nuevaEntrada;

    ifstream archivoLeer("Alumnos.txt");

    // Verificar si el archivo está vacío
    if (archivoLeer.peek() == ifstream::traits_type::eof()) {
        cout << "El archivo de alumnos esta vacio. No hay datos para editar." << endl;
        archivoLeer.close();
        system("pause");
        return;
    }

    // Solicitar la matrícula del alumno a editar
    cout << "Ingrese la matricula del alumno a editar: ";
    getline(cin, matriculaBuscar);

    ofstream archivoAux("Auxiliar.txt");

    string linea;
    bool encontrado = false;
    while (getline(archivoLeer, linea)) {
        Alumno alumno;
        stringstream ss(linea);
        getline(ss, alumno.matricula, ',');
        getline(ss, alumno.nombre, ',');
        getline(ss, alumno.apellido, ',');
        getline(ss, alumno.carrera, ',');
        getline(ss, alumno.contacto, ',');

        string materiasCalificaciones;
        getline(ss, materiasCalificaciones);

        stringstream ssMC(materiasCalificaciones);
        string fragmento;
        while (getline(ssMC, fragmento, '|')) {
            string materiaStr, calificacionStr;
            stringstream ssF(fragmento);
            getline(ssF, materiaStr, ':');
            getline(ssF, calificacionStr, ':');
            float calificacionF = stof(calificacionStr);
            alumno.materias.push_back(materiaStr);
            alumno.calificaciones.push_back(calificacionF);
        }

        // Si se encuentra la matricula, mostrar el menú de edición
        if (alumno.matricula == matriculaBuscar) {
            encontrado = true;
            cout << "Editando los datos del alumno con matricula: " << alumno.matricula << endl;

            bool editando = true;
            while (editando) {
                char opcion;
                cout << "Seleccione el aspecto a editar:" << endl;
                cout << "1. Nombre" << endl;
                cout << "2. Apellido" << endl;
                cout << "3. Carrera" << endl;
                cout << "4. Contacto" << endl;
                cout << "5. Materias y calificaciones" << endl;
                cout << "6. Agregar materia y calificacion" << endl;
                cout << "7. Salir" << endl;
                cout << "Opcion: ";
                cin >> opcion;
                cin.ignore();

switch (opcion) {
        case '1':
            do {
                cout << "Nombre actual: " << alumno.nombre << " - Nuevo nombre: ";
                getline(cin, nuevaEntrada);
                if (!soloLetras(nuevaEntrada)) {
                    cout << "El nombre solo debe contener letras. Intente de nuevo." << endl;
                }
            } while (!soloLetras(nuevaEntrada));
            alumno.nombre = nuevaEntrada;
            break;
        case '2':
            do {
                cout << "Apellido actual: " << alumno.apellido << " - Nuevo apellido: ";
                getline(cin, nuevaEntrada);
                if (!soloLetras(nuevaEntrada)) {
                    cout << "El apellido solo debe contener letras. Intente de nuevo." << endl;
                }
            } while (!soloLetras(nuevaEntrada));
            alumno.apellido = nuevaEntrada;
            break;
        case '3':
            cout << "Carrera actual: " << alumno.carrera << " - Nueva carrera: ";
            getline(cin, nuevaEntrada);
            alumno.carrera = nuevaEntrada;
            break;
        case '4':
            do {
                cout << "Contacto actual: " << alumno.contacto << " - Nuevo contacto: ";
                getline(cin, nuevaEntrada);
                if (!soloNumeros(nuevaEntrada)) {
                    cout << "El contacto solo debe contener numeros. Intente de nuevo." << endl;
                }
            } while (!soloNumeros(nuevaEntrada));
            alumno.contacto = nuevaEntrada;
            break;
        case '5':
            for (size_t i = 0; i < alumno.materias.size(); i++) {
                cout << "Materia " << i + 1 << " actual: " << alumno.materias[i] << " - Nueva materia: ";
                getline(cin, nuevaEntrada);
                alumno.materias[i] = nuevaEntrada;

                do {
                    cout << "Calificacion actual: " << alumno.calificaciones[i] << " - Nueva calificacion: ";
                    getline(cin, nuevaEntrada);
                    if (!soloNumeros(nuevaEntrada)) {
                        cout << "La calificacion debe ser un numero. Intente de nuevo." << endl;
                    }
                } while (!soloNumeros(nuevaEntrada));
                alumno.calificaciones[i] = stof(nuevaEntrada);
            }
            break;
                    case '6':
                        {
                            string nuevaMateria;
                            float nuevaCalificacion;

                            cout << "Ingrese el nombre de la nueva materia: ";
                            getline(cin, nuevaMateria);
                            alumno.materias.push_back(nuevaMateria);

                            cout << "Ingrese la calificación de la nueva materia: ";
                            cin >> nuevaCalificacion;
                            alumno.calificaciones.push_back(nuevaCalificacion);
                            cin.ignore();
                        }
                        break;
                    case '7':
                        editando = false;
                        break;
                    default:
                        cout << "Opcion no valida. Intente de nuevo." << endl;
                        break;
                }
            }
        }

        // Escribir los datos actualizados en el archivo auxiliar
        archivoAux << alumno.matricula << "," << alumno.nombre << "," << alumno.apellido << "," << alumno.carrera << "," << alumno.contacto << ",";
        for (size_t i = 0; i < alumno.materias.size(); i++) {
            archivoAux << alumno.materias[i] << ":" << alumno.calificaciones[i];
            if (i != alumno.materias.size() - 1) {
                archivoAux << "|";
            }
        }
        archivoAux << endl;
    }

    archivoLeer.close();
    archivoAux.close();

    // Si se encontró el alumno, reemplazar el archivo original con el archivo auxiliar
    if (encontrado) {
        remove("Alumnos.txt");
        rename("Auxiliar.txt", "Alumnos.txt");
        cout << "Datos del alumno actualizados exitosamente." << endl;
    } else {
        remove("Auxiliar.txt");
        cout << "Alumno con matricula " << matriculaBuscar << " no encontrado." << endl;
    }

    system("pause");
}



//MAIN==================================================================================================================
int main() {
    //Declaracion de variables
    bool bucle = true;
    bool ArchivoVacio;
    Alumno alumno;
    char opc;
        
    //Verifica que el archivo ya existe y si no crea uno nuevo
    ifstream ArchivoExistente("Alumnos.txt");
    if (!ArchivoExistente) {
        ofstream ArchivoNuevo("Alumnos.txt");
        ArchivoNuevo.close();
    } else {
        ArchivoExistente.close();
    }

    do {//Inicio del do while
    ArchivoVacio = archivoVacio();


        //Inicio del switch
        cout << "0.-Salir" << endl;
        cout << "1.-Agregar Nuevo Alumno" << endl;
        cout << "2.-Mostrar Alumnos" << endl;
        cout << "3.-Buscar Alumno" << endl;
        cout << "4.-Editar Alumno" << endl;
        cout << "5.-Borrar Alumno" << endl;
        cin >> opc;
        cin.ignore();

        switch (opc) {
            case '1':
                AgregarDatos(alumno);
                break;
            case '2':
                if (!ArchivoVacio)
                {
                   MostrarAlumnos(); 
                }else{
                    cout << "No hay alumnos registrados." << endl;
                }
                break;

            case '3':
                if (!ArchivoVacio)
                {
                   BuscarAlumno();
                }else{
                    cout << "No hay alumnos registrados." << endl;
                }
            break;

            case '4':
                if (!ArchivoVacio)
                {
                  EditarAlumno();
                }else{
                    cout << "No hay alumnos registrados." << endl;
                }
            
            break;

            case '5':
                if (!ArchivoVacio)
                {
                   eliminar();
                }else{
                    cout << "No hay alumnos registrados." << endl;
                }
                
            break;

            case '0':
                cout << "Saliendo del programa" << endl;
                bucle = false;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }//Fin del switch
    system("pause");
    system("cls");
    } while (bucle);

    return 0;
}
//MAIN==================================================================================================================