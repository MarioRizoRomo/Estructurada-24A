// Programa para elaborar la serie Fibonacci en C++ usando los 3 ciclos básicos

// Incluir las librerías necesarias
#include <iostream>
using namespace std;

// Función principal
int main() {
    // Declarar las variables
    int limite, ciclo, n1 = 0, n2 = 1, siguiente = 0, contador = 0, maximo = 100;

    // Pedir al usuario un valor límite
    cout << "Introduce el valor límite de la serie: ";
    cin >> limite;

    // Pedir al usuario qué ciclo quiere usar
    cout << "Elige el ciclo que quieres usar: 1. for, 2. while, 3. do-while: ";
    cin >> ciclo;

    // Usar el ciclo for
    if (ciclo == 1) {
        // Imprimir el mensaje inicial
        cout << "La serie Fibonacci usando el ciclo for es:" << endl;
        // Repetir el proceso hasta el máximo de términos o hasta alcanzar el límite
        for (int i = 0; i < maximo; i++) {
            // Imprimir el término actual
            cout << n1 << endl;
            // Calcular el siguiente término
            siguiente = n1 + n2;
            // Actualizar los valores de n1 y n2
            n1 = n2;
            n2 = siguiente;
            // Incrementar el contador
            contador++;
            // Salir del ciclo si se alcanza el límite
            if (n1 > limite) {
                break;
            }
        }
    }

        // Usar el ciclo while
    else if (ciclo == 2) {
        // Imprimir el mensaje inicial
        cout << "La serie Fibonacci usando el ciclo while es:" << endl;
        // Repetir el proceso mientras el contador sea menor que el máximo y n1 sea menor o igual que el límite
        while (contador < maximo && n1 <= limite) {
            // Imprimir el término actual
            cout << n1 << endl;
            // Calcular el siguiente término
            siguiente = n1 + n2;
            // Actualizar los valores de n1 y n2
            n1 = n2;
            n2 = siguiente;
            // Incrementar el contador
            contador++;
        }
    }

        // Usar el ciclo do-while
    else if (ciclo == 3) {
        // Imprimir el mensaje inicial
        cout << "La serie Fibonacci usando el ciclo do-while es:" << endl;
        // Repetir el proceso al menos una vez y luego mientras el contador sea menor que el máximo y n1 sea menor o igual que el límite
        do {
            // Imprimir el término actual
            cout << n1 << endl;
            // Calcular el siguiente término
            siguiente = n1 + n2;
            // Actualizar los valores de n1 y n2
            n1 = n2;
            n2 = siguiente;
            // Incrementar el contador
            contador++;
        } while (contador < maximo && n1 <= limite);
    }

        // Si el ciclo no es válido, mostrar un mensaje de error
    else {
        cout << "El ciclo que has elegido no es válido. Por favor, elige entre 1, 2 o 3." << endl;
    }

    // Terminar el programa
    return 0;
}

