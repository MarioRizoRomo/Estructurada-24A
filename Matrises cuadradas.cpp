#include <iostream>
#include <cstdlib> // Para la generación de números aleatorios
#include <ctime> // Para inicializar la semilla del generador de números aleatorios
using namespace std;

// Función para llenar la matriz con valores aleatorios entre -100 y 100
void llenarAleatorio(int matriz[10][10], int n) {
    srand(time(NULL)); // Inicializamos la semilla del generador de números aleatorios
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = rand() % 201 - 100; // Generamos un número aleatorio entre -100 y 100
        }
    }
}

// Función para mostrar la matriz
void mostrarMatriz(int matriz[10][10], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << "\t"; // Imprimimos el elemento de la matriz en la posición [i][j]
        }
        cout << endl;
    }
}

// Función para sumar dos matrices
void sumarMatrices(int matriz1[10][10], int matriz2[10][10], int resultado[10][10], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j]; // Sumamos los elementos correspondientes de ambas matrices
        }
    }
}

// Función para restar dos matrices
void restarMatrices(int matriz1[10][10], int matriz2[10][10], int resultado[10][10], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j]; // Restamos los elementos correspondientes de ambas matrices
        }
    }
}

// Función para multiplicar dos matrices
void multiplicarMatrices(int matriz1[10][10], int matriz2[10][10], int resultado[10][10], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            resultado[i][j] = 0; // Inicializamos el elemento de la matriz resultado en la posición [i][j] como 0
            for (int k = 0; k < n; ++k) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j]; // Multiplicamos y acumulamos los productos de los elementos correspondientes de las matrices
            }
        }
    }
}

int main() {
    int n;
    cout << "Ingrese el tamaño de las matrices cuadradas (entre 2 y 10): ";
    cin >> n;

    if (n < 2 || n > 10) { // Verificamos que el tamaño de la matriz sea válido
        cout << "Tamaño de matriz inválido." << endl;
        return 1; // Salimos del programa con un código de error
    }

    int matriz1[10][10], matriz2[10][10], resultado[10][10];
    char opcion;

    cout << "¿Desea llenar las matrices con valores aleatorios? (s/n): ";
    cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        llenarAleatorio(matriz1, n); // Llenamos la matriz 1 con valores aleatorios
        llenarAleatorio(matriz2, n); // Llenamos la matriz 2 con valores aleatorios
    } else {
        cout << "Ingrese los valores para la primera matriz:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << "Ingrese el valor para la posición [" << i << "][" << j << "]: ";
                cin >> matriz1[i][j]; // Pedimos al usuario que ingrese los valores de la matriz 1
            }
        }

        cout << "Ingrese los valores para la segunda matriz:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << "Ingrese el valor para la posición [" << i << "][" << j << "]: ";
                cin >> matriz2[i][j]; // Pedimos al usuario que ingrese los valores de la matriz 2
            }
        }
    }

    cout << "Matriz 1:" << endl;
    mostrarMatriz(matriz1, n); // Mostramos la matriz 1
    cout << endl;

    cout << "Matriz 2:" << endl;
    mostrarMatriz(matriz2, n); // Mostramos la matriz 2
    cout << endl;

    cout << "Operaciones disponibles:" << endl;
    cout << "1. Sumar matrices" << endl;
    cout << "2. Restar matrices" << endl;
    cout << "3. Multiplicar matrices" << endl;
    cout << "Elija una opción: ";
    cin >> opcion;

    switch(opcion) {
        case '1':
            sumarMatrices(matriz1, matriz2, resultado, n); // Sumamos las matrices
            cout << "Resultado de la suma:" << endl;
            mostrarMatriz(resultado, n); // Mostramos el resultado de la suma
            break;
        case '2':
            restarMatrices(matriz1, matriz2, resultado, n); // Restamos las matrices
            cout << "Resultado de la resta:" << endl;
            mostrarMatriz(resultado, n); // Mostramos el resultado de la resta
            break;
        case '3':
            multiplicarMatrices(matriz1, matriz2, resultado, n); // Multiplicamos las matrices
            cout << "Resultado de la multiplicación:" << endl;
            mostrarMatriz(resultado, n); // Mostramos el resultado de la multiplicación
            break;
        default:
            cout << "Opción inválida." << endl; // Mensaje de error en caso de opción inválida
    }

    return 0; // Indicamos que el programa finalizó correctamente
}
