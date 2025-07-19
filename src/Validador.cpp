#include 'Validador.h'
#include 'Local.h'
#include 'Veiculo.h'
#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

Validador::limparEntrada(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

Validador::lerInteiro(const char* mensagem, int min, int max){
    int valor;
    while(true){
        cout<<mensagem;
        cin>>valor;
        if(cin.fail() || valor<min || valor >max){
            cout<<"Entrada invalida. Tente um numero entre "<<min" e "<<max<<"\n";
            limparEntrada();
        }
        else{
            limparEntrada();
            return valor;
        }
    }
}

Validador::lerDouble(const char* mensagem){
    double valor;
    while(true){
        cout<<mensagem;
        cin>>valor;
        if(cin.fail()){
            cout<<"Entrada invalida. Digite um valor numerico.\n";
            limparEntrada();
        }
        else{
            limparEntrada();
            return valor;
        }
    }
}

Validador::stringVazia(const char* texto){
    return strlen(texto)==0;
}

Validador::nomeLocalRepetido(const char* nome, Local locais[], int totalLocais){
    for (int i=0; i<totalLocais; i++){
        if(stricmp(locais[i].getEndereco(), nome)==0){
            return true;
        }
    }
    return false;
}

Validador::placaRepetida(const char* placa, Veiculo veiculos[], int totalVeiculos){
    for (int i=0; i<totalVeiculos; i++){
        if (stricmp(veiculos[i].getPlaca(), placa)==0){
            return true;
        }
    }
    return false;
}

Validador::placaInvalida(const char* placa){
    return strlen(placa)!=7;
}
