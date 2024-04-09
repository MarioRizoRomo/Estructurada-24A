#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

bool esPalindromo(const string& palabra) {
    // Crear una copia de la palabra sin espacios y en minúsculas
    string palabraSinEspacios;
    for (char c : palabra) {
        if (isalnum(c)) {
            palabraSinEspacios += tolower(c);
        }
    }

    // Verificar si la palabra es igual a su reversa
    string reversa = palabraSinEspacios;
    reverse(reversa.begin(), reversa.end());
    return palabraSinEspacios == reversa;
}

int main() {
    string entrada1, entrada2;
    cout << "Ingrese una palabra o frase: ";
    getline(cin, entrada1);

    int vocales = 0, consonantes = 0, espacios = 0;
    for (char c : entrada1) {
        if (isspace(c)) {
            espacios++;
        } else if (isalpha(c)) {
            if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
                vocales++;
            } else {
                consonantes++;
            }
        }
    }

    cout << "Cantidad de vocales: " << vocales << endl;
    cout << "Cantidad de consonantes: " << consonantes << endl;
    cout << "Cantidad de espacios: " << espacios << endl;

    if (esPalindromo(entrada1)) {
        cout << "La palabra o frase es un palíndromo" << endl;
    } else {
        cout << "La palabra o frase no es un palíndromo" << endl;
    }

    // Convertir a mayúsculas
    string mayusculas = entrada1;
    transform(mayusculas.begin(), mayusculas.end(), mayusculas.begin(), ::toupper);
    cout << "En mayúsculas: " << mayusculas << endl;

    // Convertir a minúsculas
    string minusculas = entrada1;
    transform(minusculas.begin(), minusculas.end(), minusculas.begin(), ::tolower);
    cout << "En minúsculas: " << minusculas << endl;

    // Solicitar otra palabra o frase y concatenar
    cout << "Ingrese otra palabra o frase: ";
    getline(cin, entrada2);
    string concatenada = entrada1 + " " + entrada2;
    cout << "Concatenación: " << concatenada << endl;

    return 0;
}
