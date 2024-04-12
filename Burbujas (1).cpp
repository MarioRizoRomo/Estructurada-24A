#include <iostream>
using namespace std;
int espacios;
int i,j,aux;
//Metodo burbuja
int main() {
    cout << "Ingrese los espacios a usar:" << endl;
    cin >> espacios;
    int ordenar[espacios];
    cout << "ingresa el numero los numeros a ordenar" << endl;
    for (int i = 0; i < espacios; ++i) {
        cout << "elemento" << i + 1 << ":";
        cin >> ordenar[i];
    }//Algoritmo del metodo burbuna
    for (i = 0; i < espacios; ++i) {
        for (j = 0; j < espacios; ++j) {
            if (ordenar[j] > ordenar[j + i]) {
                aux = ordenar[j];
                ordenar[j] = ordenar[j + 1];
                {
                    ordenar[j + 1] = aux;
                }
            }
        }//fin del metodo burbuja
        cout << "Array ingresado: [";
        for (int i = 0; i < espacios; ++i){
            cout<<ordenar[i];
            if (i < espacios -1){
                cout << ", ";
                }
            }
            cout << "]" << endl;

            return 0;
        }
    }
