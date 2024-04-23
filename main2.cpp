#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void LimpiarPantalla();
void JugarPartida();
void Dibujar();
bool esVocal(char letra);

char eleccion;
string palabras[] = {
        "hitler", "stalin", "castro", "mussolini", "pinochet", "kimjongun", "trujillo", "peron", "mugabe", "gaddafi",
        "duvalier", "somoza", "ceausescu", "milosevic", "pahlavi", "pot", "mobutu", "chavez", "noriega", "aoun"
};
string palabra , fallidas;
int nA;
int vida;
int intentos;
bool correcta, completa;

void LimpiarPantalla(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main(){
    while(true){
        LimpiarPantalla();
        vida = 6;
        intentos = 0;
        fallidas = "";
        JugarPartida();
        cout<<"\n¿Quieres jugar otra vez? (s/n): ";
        cin>>eleccion;
        if(eleccion != 's' && eleccion != 'S'){
            break;
        }
    }
    return 0;
}

void JugarPartida(){
    srand((unsigned int)time(NULL));
    nA = rand() % 20;

    palabra = palabras[nA];
    string palabraAdivinada(palabra.length(), '-');

    while(vida > 0){
        LimpiarPantalla();
        cout<<"\t::: A H O R C A D O :::"<<endl;
        Dibujar();
        cout<<"Fallos: "<<fallidas<<endl;
        cout<<"Progreso: "<<palabraAdivinada<<endl;
        cout<<"Intentos restantes: "<<vida<<endl;
        cout<<"Ingrese una letra(minuscula): ";
        cin>>eleccion;

        intentos++;

        if(esVocal(eleccion)){
            vida--;
            fallidas += eleccion;
            cout<<"Penalizacion! Elegiste una vocal. Te quedan "<<vida<<" vidas."<<endl;
            continue;
        }

        correcta = false;
        for(int i = 0; i < (int)palabra.length(); i++){
            if(palabra[i] == eleccion){
                palabraAdivinada[i] = eleccion;
                correcta = true;
            }
        }
        if(!correcta){
            vida--;
            fallidas += eleccion;
        }

        completa = true;
        for(int i = 0; i < (int)palabraAdivinada.length(); i++){
            if(palabraAdivinada[i] == '-'){
                completa = false;
            }
        }
        if(completa){
            LimpiarPantalla();
            cout<<"\t::: A H O R C A D O :::"<<endl;
            Dibujar();
            cout<<"Felicidades! Has adivinado la palabra!"<<endl;
            cout<<"La palabra era: "<<palabra<<endl;
            cout<<"Numero de intentos: "<<intentos<<endl;
            return;
        }
    }
    LimpiarPantalla();
    cout<<"\t::: A H O R C A D O :::"<<endl;
    Dibujar();
    cout<<"Oh no! Te has quedado sin intentos."<<endl;
    cout<<"La palabra era: "<<palabra<<endl;
    cout<<"Numero de intentos: "<<intentos<<endl;
}

void Dibujar(){
    switch(vida){
        case 6:
            cout<<"  --------"<<endl;
            cout<<"  |      |"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<" ---"<<endl;
            break;
        case 5:
            cout<<"  --------"<<endl;
            cout<<"  |      |"<<endl;
            cout<<"  |      O"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<" ---"<<endl;
            break;
        case 4:
            cout<<"  --------"<<endl;
            cout<<"  |      |"<<endl;
            cout<<"  |      O"<<endl;
            cout<<"  |      |"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<" ---"<<endl;
            break;
        case 3:
            cout<<"  --------"<<endl;
            cout<<"  |      |"<<endl;
            cout<<"  |      O"<<endl;
            cout<<"  |     /|"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<" ---"<<endl;
            break;
        case 2:
            cout<<"  --------"<<endl;
            cout<<"  |      |"<<endl;
            cout<<"  |      O"<<endl;
            cout<<"  |     /|\\"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<" ---"<<endl;
            break;
        case 1:
            cout<<"  --------"<<endl;
            cout<<"  |      |"<<endl;
            cout<<"  |      O"<<endl;
            cout<<"  |     /|\\"<<endl;
            cout<<"  |     /"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<" ---"<<endl;
            break;
        case 0:
            cout<<"  --------"<<endl;
            cout<<"  |      |"<<endl;
            cout<<"  |      O"<<endl;
            cout<<"  |     /|\\"<<endl;
            cout<<"  |     / \\"<<endl;
            cout<<"  |"<<endl;
            cout<<"  |"<<endl;
            cout<<" ---"<<endl;
            break;
    }
}

bool esVocal(char letra){
    return (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u');
}

