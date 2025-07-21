#include "Validador.h"
#include "Local.h"
#include "Veiculo.h"
#include <iostream>
#include <cstring>
#include <limits>
#include <cctype>

#ifdef _WIN32
#define stricmp _stricmp
#endif

using namespace std;

//Limpa entrada
void Validador::limparEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//Verifica se entrada é realmente um número
int Validador::lerInteiro(const char* mensagem, int min, int max) {
    int valor;
    while (true) {
        cout << mensagem;
        cin >> valor;
        if (cin.fail() || valor < min || valor > max) {
            cout << "Entrada invalida. Tente um numero entre " << min << " e " << max << "\n";
            limparEntrada(); //Limpa a entrada
        } else {
            limparEntrada(); //Limpa a entrada
            return valor;
        }
    }
}

//Verifica se entrada é realmente um número
double Validador::lerDouble(const char* mensagem) {
    double valor;
    while (true) {
        cout << mensagem;
        cin >> valor;
        if (cin.fail()) {
            cout << "Entrada invalida. Digite um valor numerico.\n";
            limparEntrada(); //Limpa a entrada
        } else {
            limparEntrada(); //Limpa a entrada
            return valor;
        }
    }
}

//Verifica se a string não está vazia
bool Validador::stringVazia(const char* texto) {
    return strlen(texto) == 0;
}

//Verifica se o local digitado já está no sistema
bool Validador::localRepetido(const char* endereco, Local locais[], int totalLocais) {
    for (int i = 0; i < totalLocais; i++) {
        //Compara strings com case-insensitive
        if (stricmp(locais[i].getEndereco(), endereco) == 0) {
            return true;
        }
    }
    return false;
}

//Verifica se a placa digitada já está no sistema
bool Validador::placaRepetida(const char* placa, Veiculo veiculos[], int totalVeiculos) {
    for (int i = 0; i < totalVeiculos; i++) {
        //Compara strings com case-insensitive
        if (stricmp(veiculos[i].getPlaca(), placa) == 0) {
            return true;
        }
    }
    return false;
}

//Verifica se a placa digitada possui exatamente 7 caracteres
bool Validador::placaValida(const char* placa) {
    return strlen(placa) == 7;
}
