#include <iostream>
#include <string>

// Definición de la clase "Persona"
class Persona {
public:
    // Constructor
    Persona(const std::string& nombre, int edad) : nombre_(nombre), edad_(edad) {}

    // Método para saludar
    void saludar() {
        std::cout << "Hola, soy " << nombre_ << " y tengo " << edad_ << " años." << std::endl;
    }

private:
    std::string nombre_;
    int edad_;
};

int main() {
    // Creación de objetos basados en la clase "Persona"
    Persona persona1("Ana", 30);
    Persona persona2("Carlos", 25);

    // Llamada al método "saludar" para cada objeto
    persona1.saludar();
    persona2.saludar();

    return 0;
}
