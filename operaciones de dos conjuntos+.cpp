
#include <iostream>
#include <vector>
#include <algorithm>

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

// Función para calcular la diferencia entre dos conjuntos
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

// Función para calcular el complemento de un conjunto
template<typename T>
vector<T> complementoConjunto(const vector<T>& conjunto, const vector<T>& universo) {
    return diferenciaConjuntos(universo, conjunto);
}

int main() {
    // Ejemplo de uso
    vector<char> conjuntoA, conjuntoB;
    // Insertar valores en conjuntoA y conjuntoB
    insertarValor(conjuntoA);
    insertarValor(conjuntoB);

    // Realizar operaciones con los conjuntos (puedes agregar más según tus necesidades)
    vector<char> unionAB = unionConjuntos(conjuntoA, conjuntoB);
    vector<char> interseccionAB = interseccionConjuntos(conjuntoA, conjuntoB);
    vector<char> diferenciaAB = diferenciaConjuntos(conjuntoA, conjuntoB);
    vector<char> complementoA = complementoConjunto(conjuntoA, universo); // Define 'universo' según tus necesidades

    // Mostrar resultados
    cout << "Unión de A y B: ";
    mostrarConjunto(unionAB);
    cout << "Intersección de A y B: ";
    mostrarConjunto(interseccionAB);
    cout << "Diferencia A - B: ";
    mostrarConjunto(diferenciaAB);
    cout << "Complemento de A: ";
    mostrarConjunto(complementoA);

    return 0;
}
