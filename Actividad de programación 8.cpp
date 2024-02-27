#include <iostream>
#include <vector>
#include <algorithm> // Para usar la función sort()

using namespace std;

// Función para mostrar un conjunto
template<typename T>
void mostrarConjunto(const vector<T>& conjunto) {
    cout << "{ ";
    for (const auto& elemento : conjunto) {
        cout << elemento << " ";
    }
    cout << "}" << endl;
}

// Función para insertar valores en un conjunto
template<typename T>
void insertarValor(vector<T>& conjunto) {
    T valor;
    cout << "Ingrese el valor: ";
    cin >> valor;
    conjunto.push_back(valor);
}

// Función para borrar un valor de un conjunto
template<typename T>
void borrarValor(vector<T>& conjunto) {
    T valor;
    cout << "Ingrese el valor que desea borrar: ";
    cin >> valor;
    auto it = find(conjunto.begin(), conjunto.end(), valor);
    if (it != conjunto.end()) {
        conjunto.erase(it);
        cout << "Elemento borrado correctamente." << endl;
    } else {
        cout << "El elemento no está presente en el conjunto." << endl;
    }
}

// Función para vaciar un conjunto
template<typename T>
void vaciarConjunto(vector<T>& conjunto) {
    conjunto.clear();
    cout << "Conjunto vaciado correctamente." << endl;
}

// Función para realizar la unión de dos conjuntos
template<typename T>
vector<T> unionConjuntos(const vector<T>& conjunto1, const vector<T>& conjunto2) {
    vector<T> resultado = conjunto1;
    for (const auto& elemento : conjunto2) {
        if (find(resultado.begin(), resultado.end(), elemento) == resultado.end()) {
            resultado.push_back(elemento);
        }
    }
    return resultado;
}

// Función para realizar la intersección de dos conjuntos
template<typename T>
vector<T> interseccionConjuntos(const vector<T>& conjunto1, const vector<T>& conjunto2) {
    vector<T> resultado;
    for (const auto& elemento : conjunto1) {
        if (find(conjunto2.begin(), conjunto2.end(), elemento) != conjunto2.end()) {
            resultado.push_back(elemento);
        }
    }
    return resultado;
}

// Función para realizar la diferencia entre dos conjuntos (conjunto1 - conjunto2)
template<typename T>
vector<T> diferenciaConjuntos(const vector<T>& conjunto1, const vector<T>& conjunto2) {
    vector<T> resultado;
    for (const auto& elemento : conjunto1) {
        if (find(conjunto2.begin(), conjunto2.end(), elemento) == conjunto2.end()) {
            resultado.push_back(elemento);
        }
    }
    return resultado;
}

// Función para realizar el complemento de un conjunto en otro conjunto
template<typename T>
vector<T> complementoConjunto(const vector<T>& conjuntoCompleto, const vector<T>& conjunto) {
    vector<T> resultado;
    for (const auto& elemento : conjuntoCompleto) {
        if (find(conjunto.begin(), conjunto.end(), elemento) == conjunto.end()) {
            resultado.push_back(elemento);
        }
    }
    return resultado;
}

int main() {
    vector<int> conjunto1, conjunto2;
    char opcion;

    do {
        cout << "\nMenú:" << endl;
        cout << "1. Insertar valor en conjunto 1" << endl;
        cout << "2. Insertar valor en conjunto 2" << endl;
        cout << "3. Borrar valor de conjunto 1" << endl;
        cout << "4. Borrar valor de conjunto 2" << endl;
        cout << "5. Vaciar conjunto 1" << endl;
        cout << "6. Vaciar conjunto 2" << endl;
        cout << "7. Mostrar conjuntos" << endl;
        cout << "8. Realizar la unión de los conjuntos" << endl;
        cout << "9. Realizar la intersección de los conjuntos" << endl;
        cout << "10. Realizar la diferencia entre los conjuntos" << endl;
        cout << "11. Realizar el complemento del conjunto 1 en el conjunto 2" << endl;
        cout << "12. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                insertarValor(conjunto1);
                break;
            case '2':
                insertarValor(conjunto2);
                break;
            case '3':
                borrarValor(conjunto1);
                break;
            case '4':
                borrarValor(conjunto2);
                break;
            case '5':
                vaciarConjunto(conjunto1);
                break;
            case '6':
                vaciarConjunto(conjunto2);
                break;
            case '7':
                cout << "Conjunto 1: ";
                mostrarConjunto(conjunto1);
                cout << "Conjunto 2: ";
                mostrarConjunto(conjunto2);
                break;
            case '8':
                cout << "Unión de los conjuntos: ";
                mostrarConjunto(unionConjuntos(conjunto1, conjunto2));
                break;
            case '9':
                cout << "Intersección de los conjuntos: ";
                mostrarConjunto(interseccionConjuntos(conjunto1, conjunto2));
                break;
            case '10':
                cout << "Diferencia entre los conjuntos (Conjunto 1 - Conjunto 2): ";
                mostrarConjunto(diferenciaConjuntos(conjunto1, conjunto2));
                break;
            case '11':
                cout << "Complemento del conjunto 1 en el conjunto 2: ";
                mostrarConjunto(complementoConjunto(conjunto2, conjunto1));
                break;
            case '12':
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
        }
    } while (opcion != '12');

    return 0;
}

