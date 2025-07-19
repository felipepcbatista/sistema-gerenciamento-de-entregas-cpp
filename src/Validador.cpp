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

void Validador::limparEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Validador::lerInteiro(const char* mensagem, int min, int max) {
    int valor;
    while (true) {
        cout << mensagem;
        cin >> valor;
        if (cin.fail() || valor < min || valor > max) {
            cout << "Entrada invalida. Tente um numero entre " << min << " e " << max << "\n";
            limparEntrada();
        } else {
            limparEntrada();
            return valor;
        }
    }
}

double Validador::lerDouble(const char* mensagem) {
    double valor;
    while (true) {
        cout << mensagem;
        cin >> valor;
        if (cin.fail()) {
            cout << "Entrada invalida. Digite um valor numerico.\n";
            limparEntrada();
        } else {
            limparEntrada();
            return valor;
        }
    }
}

bool Validador::stringVazia(const char* texto) {
    return strlen(texto) == 0;
}

bool Validador::localRepetido(const char* endereco, Local locais[], int totalLocais) {
    for (int i = 0; i < totalLocais; i++) {
        if (stricmp(locais[i].getEndereco(), endereco) == 0) {
            return true;
        }
    }
    return false;
}

bool Validador::placaRepetida(const char* placa, Veiculo veiculos[], int totalVeiculos) {
    for (int i = 0; i < totalVeiculos; i++) {
        if (stricmp(veiculos[i].getPlaca(), placa) == 0) {
            return true;
        }
    }
    return false;
}

bool Validador::placaInvalida(const char* placa) {
    return strlen(placa) != 7;
}
