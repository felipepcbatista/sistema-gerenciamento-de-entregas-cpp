#include "ManagerLocais.h"
#include "Local.h"
#include "Validador.h"
#include <iostream>
#include <cstring>
using namespace std;

void ManagerLocais::cadastrarLocal() {
    if (totalLocais >= MAX) {
        cout << "Limite de locais cadastrados atingido.\n";
        return;
    }

    char endereco[300];
    double coordenadaX;
    double coordenadaY;

    cout << "Endereco do local: ";
    cin.getline(endereco, 300);

    if (Validador::stringVazia(endereco)) {
        cout << "Entrada invalida. Endereco nao pode ser vazio.\n";
        return;
    }

    if (Validador::nomeLocalRepetido(endereco, locais, totalLocais)) {
        cout << "Este local ja foi cadastrado.\n";
        return;
    }

    coordenadaX = Validador::lerDouble("Coordenada X: ");
    coordenadaY = Validador::lerDouble("Coordenada Y: ");

    locais[totalLocais] = Local(endereco, coordenadaX, coordenadaY);
    totalLocais++;

    cout << "Local cadastrado com sucesso!" << endl;
}

void ManagerLocais::atualizarLocal() {
    char tempEndereco[300];
    double tempCoordenadaX;
    double tempCoordenadaY;
    int id;

    cout << "Digite o [ID] do local a ser atualizado:\n";
    listaLocais();
    id = Validador::lerInteiro("ID: ", 1, totalLocais);

    cout << "Novo endereco: ";
    cin.ignore();  // garante leitura correta se houve getline antes
    cin.getline(tempEndereco, 300);

    if (Validador::stringVazia(tempEndereco)) {
        cout << "Entrada invalida. Endereco nao pode ser vazio.\n";
        return;
    }

    cout << "Novas coordenadas:\n";
    tempCoordenadaX = Validador::lerDouble("X: ");
    tempCoordenadaY = Validador::lerDouble("Y: ");

    locais[id - 1] = Local(tempEndereco, tempCoordenadaX, tempCoordenadaY);
    cout << "Local atualizado com sucesso!" << endl;
}

void ManagerLocais::listaLocais() {
    if (totalLocais == 0) {
        cout << "Nenhum local cadastrado.\n";
        return;
    }

    for (int i = 0; i < totalLocais; i++) {
        cout << "[" << i + 1 << "]"
             << " | Endereco: " << locais[i].getEndereco()
             << " | Coordenada X: " << locais[i].getCoordenadaX()
             << " | Coordenada Y: " << locais[i].getCoordenadaY()
             << endl;
    }
}

void ManagerLocais::removerLocal() {
    int id;
    cout << "Digite o [ID] do local a ser removido:\n";
    listaLocais();
    id = Validador::lerInteiro("ID: ", 1, totalLocais);

    for (int i = id - 1; i < totalLocais - 1; i++) {
        locais[i] = locais[i + 1];
    }

    totalLocais--;
    cout << "Local removido com sucesso!" << endl;
}

const char* ManagerLocais::getEnderecoByID(int id) {
    return locais[id - 1].getEndereco();
}
int ManagerLocais::getIDporEndereco(const char* endereco) {
    for (int i = 0; i < totalLocais; i++) {
        if (strcmp(endereco, locais[i].getEndereco()) == 0)
            return i;
    }
    return -1;
}
void ManagerLocais::setTotalLocais(int total) { totalLocais = total; }
double ManagerLocais::getCoordenadaXporID(int id) const { return locais[id].getCoordenadaX(); }
double ManagerLocais::getCoordenadaYporID(int id) const { return locais[id].getCoordenadaY(); }
int ManagerLocais::getTotalLocais() const { return totalLocais; }
Local* ManagerLocais::getArrayLocais() const { return (Local*) locais; }
