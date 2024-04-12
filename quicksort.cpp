// Incluir bibliotecas necesarias
#include <iostream>

using namespace std;

void quicksort(int ordenar[],int inicio, int fin){
    int izquierda = inicio, derecha = fin;
    int pivote = ordenar[(izquierda + derecha)/2];

    do{
        while(ordenar[izquierda] < pivote && izquierda < fin){
            izquierda++;
        }
        while(ordenar[derecha]>pivote && derecha > inicio){
            derecha--;
        }
        if(izquierda <= derecha){
            swap(ordenar[izquierda],ordenar[derecha]);
            izquierda++;
            derecha--;
        }
    }while(izquierda <= derecha);
    if(inicio<=derecha){
        quicksort(ordenar, inicio, derecha);
    }
    if(fin > izquierda){
        quicksort(ordenar, inicio, derecha);
    }
}

int main(){
    int espacios;
    cout<<"Ingrese los espacios a usar"<<endl;
    cin>>espacios;

    int ordenar[espacios];

    int tam = sizeof (ordenar)/sizeof(ordenar[0]);
    cout<<"Ingresa los numeros a ordenar"<<endl;

    for(int i=0; i<espacios;++i){
        cout<<"elemnto"<<i+1<<":";
        cin>>ordenar[i];
    }
    quicksort(ordenar,0,tam-1);
    cout<<"Array ordenado: [";
    for(int i=0; i<espacios; ++i){
        cout<<ordenar[i];
        if(i<espacios-1){
            cout<< ", ";

        }
    }
    cout<<"]"<<endl;
     return 0;
}