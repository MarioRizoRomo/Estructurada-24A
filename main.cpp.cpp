#include <iostream> // Incluimos el encabezado iostream para poder utilizar las funciones de entrada y salida estándar
using namespace std; // Utilizamos la directiva using para no tener que escribir std:: antes de cada uso de objetos del espacio de nombres std

int main() {
    //variables
    bool ciclo = true;
    int ar[10];
    char op;//opciones del manu
    int val;//valores del usuario
    int pos = 0;
    int suma = 0;
    //iniciar ciclo retorno de programa
    while (ciclo) {
        cout << "1.insertar valor" << endl;
        cout << "2.sumar valores" << endl;
        cout << "3.Listar valores" << endl;
        cout << "4.insertar valor" << endl;
        cout << "5.Elige una opción:" << endl;
        cin >> op;

        switch (op) {
            case '1': {
                if (pos == 10) {
                    cout << "introduce un valor;";
                } else {
                    cout << "introudce un valor:";
                    cin >> val;//pedir valor a usuario
                    ar[pos] = val; //ingresar el valor en la posición
                    pos++; // incremento la posición
                    break;
                }//fin case 1
                case '2': {
                    for (int i = 0; i < pos; i++) {
                        suma = suma + ar[i];
                    }//fin de for
                    cout << "El total del arreglo es de : " << suma << endl;
                    break;
                }//fin case 2
                case '3': {
                    for (int i = 0; i < pos; i++) {
                        cout << "[" << ar[i] << " }.";
                    } //fin de for
                    break;
                }//fin de case 3
                case '4': { //salir del programa
                    ciclo = false;
                    break;
                }//fin de case 4
                default:{

                }

            }//fin de switch


        }//fin de cilo de while del retorno del programa

        return 0; // Indicamos que el programa finalizó exitosamente


    }
}