#include <iostream> // Incluimos el encabezado iostream para poder utilizar las funciones de entrada y salida estándar
#include <vector>
using namespace std; // Utilizamos la directiva using para no tener que escribir std:: antes de cada uso de objetos del espacio de nombres std

int main() {
    //variables
    bool ciclo = true;

    vector<int> vec;

    char op;//opciones del manu
    int val;//valores del usuario
    int pos = 0;
    int suma = 0;
    //iniciar ciclo retorno de programa
    while (ciclo) {
        vec.begin();
        vec.push_back(10); vec.push_back(15);
        cout << vec.size() << endl;
        cout << "\n1.insertar valor" << endl;
        cout << "2.sumar valores" << endl;
        cout << "3.Listar valores" << endl;
        cout << "4.insertar valor" << endl;
        cout << "5.Elige una opción:" << endl;
        cin >> op;
        switch (op) {
            case '1': {

                    cout << "introudce un valor:";
                    cin >> val;//pedir valor a usuario
                    vec.push_back(val); //ingresar el valor en la posición
                    pos++; // incremento la posición

                break;
            }//fin case 1
            case '2': {
                suma = 0;
                for (int i = 0; i < vec.size(); i++) {
                    suma = suma + vec.at(i);
                }//fin de for
                cout << "El total del arreglo es de : " << suma << endl;
                break;
            }//fin case 2
            case '3': {
                for (int i = 0; i <= vec.size(); i++) {
                    cout << "[" << vec.at(i) << "].";
                } //fin de for
                break;
            }//fin de case 3
            case '4': { //salir del programa
                cout<<"indices:";
                for (int i = 0; i < vec.size(); i++) {
                    cout << "[" << vec.at(i) << "]. " ;
                }//fin de ford3
                break;
            }//fin de case 4
            case'5': {//salir del programa
                ciclo = false;
                break;
            }
            default:{
                cout << "opcion fuera de rango"<< endl;
                break;
            }//Fin default

        }//fin de switch


    }//fin de cilo de while del retorno del programa

    return 0; // Indicamos que el programa finalizó exitosamente


}// fin main
