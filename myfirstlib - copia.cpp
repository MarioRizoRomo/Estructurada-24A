#include "iostream"
using namespace std;

//Definicion de funciones
void hello(){
    cout<<"Hello to my first function"<<endl;
}

void imp(string texto){
    cout<<texto<<endl;
}

void imp(int num){
    cout<<num;
}

void impln(string texto){
    cout<<texto<<endl;
}

//Esta funcion regresa la suma de num1 y num1
//Suma int
int suma(int num1, int num2){
    return num1 + num2;
}

//Suma double
float suma(float num1, float num2){
    return num1 + num2;
}

bool valida(char caracter){
    if (caracter >= 64 && caracter <= 90)
        return true;
    else
        return false;
}

string booltotxt(bool valor){
    if (valor == true)
    {
        return "Verdadero";
    }else{
        return "Falso";
    }

}