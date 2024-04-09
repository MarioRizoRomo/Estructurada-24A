/*************************************************************
"Nombre: Mario Rizo Romo"
"Fecha: 19 de Marzo de 2024"
"Programa: Actividad de programación 11"
"Centro Universitario de los Altos"
"Ingeniería en Computación/2do Semestre"
"Profesor: Sergio Franco Casillas"
"Descripción: Un arreglo de punteros (max 50 valores)
Los datos, solo serán numéricos
Los valores que se inserten se van a ir acomodando de menor a mayor
Si el valor ya está insertado, enviar mensaje de que ya existe
Los valores se van a insertar cada que el usuario lo decida
Utilizar funciones y librerías"
*************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE 50

// Función para buscar un valor en el arreglo
bool findValue(vector<int*>& arr, int value) {
    for (int* ptr : arr) {
        if (*ptr == value)
            return true;
    }
    return false;
}

// Función para insertar un nuevo valor en el arreglo
void insertValue(vector<int*>& arr, int value) {
    if (arr.size() >= MAX_SIZE) {
        cout << "Error: El arreglo está lleno." << endl;
        return;
    }

    if (findValue(arr, value)) {
        cout << "El valor " << value << " ya existe en el arreglo." << endl;
        return;
    }

    int* newPtr = new int(value);
    arr.push_back(newPtr);
    sort(arr.begin(), arr.end(), [](int* a, int* b) { return *a < *b; });
}

// Función para imprimir el arreglo
void printArray(vector<int*>& arr) {
    cout << "Arreglo: ";
    for (int* ptr : arr) {
        cout << *ptr << " ";
    }
    cout << endl;
}

int main() {
    vector<int*> arr;
    int choice, value;

    do {
        cout << "1. Insertar valor" << endl;
        cout << "2. Imprimir arreglo" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su elección: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Ingrese el valor a insertar: ";
                cin >> value;
                insertValue(arr, value);
                break;
            case 2:
                printArray(arr);
                break;
            case 3:
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (choice != 3);

    // Liberar la memoria dinámica
    for (int* ptr : arr) {
        delete ptr;
    }

    return 0;
}