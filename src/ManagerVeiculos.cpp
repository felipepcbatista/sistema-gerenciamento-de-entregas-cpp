#include "ManagerVeiculos.h"
#include "Validador.h"
#include "ManagerLocais.h"
#include <iostream>
#include <cstring>
using namespace std;

//Cadastrar Veículo
void ManagerVeiculos::cadastrarVeiculo(ManagerLocais& gerLocais) {

    //Validador: limite de veículos
    if (totalVeiculos >= MAX) {
        cout << "Limite de veiculos cadastrados atingido.\n";
        return;
    }

    //Exibe e retorna se não houver locais cadastrados -> Veículo depende de local
    if(gerLocais.getTotalLocais()==0){
        gerLocais.listaLocais();
        return;
    }

    char marca[100], modelo[100], placa[8], localAtual[300];
    int id_localAtual;

    cout << "\nDigite o ID da localizacao atual do veiculo:\n";
    gerLocais.listaLocais();

    //Validador: entrada não numérica
    id_localAtual = Validador::lerInteiro("\nID: ", 1, gerLocais.getTotalLocais());

    cout << "Marca do veiculo: ";
    cin.getline(marca, 100);

    //Validador: Marca vazia
    if (Validador::stringVazia(marca)) {
        cout << "Entrada invalida. Marca nao pode ser vazia.\n";
        return;
    }

    cout << "Modelo do veiculo: ";
    cin.getline(modelo, 100);

    //Validador: Modelo vazio
    if (Validador::stringVazia(modelo)) {
        cout << "Entrada invalida. Modelo nao pode ser vazio.\n";
        return;
    }

    cout << "Placa do veiculo (7 caracteres): ";
    cin.getline(placa, 100);

    //Validador: Placa inválida (Difere de 7 caracteres)
    if (!Validador::placaValida(placa)) {
        cout << "Entrada invalida. Placa deve conter exatamente 7 caracteres.\n";
        return;
    }

    //Validador: Placa repetida
    if (Validador::placaRepetida(placa, veiculos, totalVeiculos)) {
        cout << "Ja existe um veiculo com essa placa.\n";
        return;
    }

    strcpy(localAtual, gerLocais.getEnderecoByID(id_localAtual));
    veiculos[totalVeiculos] = Veiculo(marca, modelo, placa, localAtual, true);
    totalVeiculos++;

    cout<< "Veiculo cadastrado com sucesso!" <<endl;
}

//Atualizar Veículo
void ManagerVeiculos::atualizarVeiculo(ManagerLocais& gerLocais) {

    //Exibe e retorna se não houver veículos cadastrados
    if (totalVeiculos == 0) {
        listaVeiculos();
        return;
    }

    //Exibe e retorna se não houver locais cadastrados -> Veículo depende de local
    if(gerLocais.getTotalLocais()==0){
        gerLocais.listaLocais();
        return;
    }

    int id;
    char tempMarca[100], tempModelo[100], tempPlaca[8], tempLocalAtual[300];
    int id_tempLocalAtual;

    cout << "Digite o [ID] do veiculo a ser atualizado:\n";
    listaVeiculos();

    //Validador: entrada não numérica
    id = Validador::lerInteiro("\nID: ", 1, totalVeiculos);

    cout<<"Dados a serem atualizados:\n";
    cout << "Marca: ";
    cin.getline(tempMarca, 100);

    //Validador: Marca vazia
    if (Validador::stringVazia(tempMarca)) {
        cout << "Entrada invalida. Marca nao pode ser vazia.\n";
        return;
    }

    cout << "Modelo: ";
    cin.getline(tempModelo, 100);

    //Validador: Modelo vazio
    if (Validador::stringVazia(tempModelo)) {
        cout << "Entrada invalida. Modelo nao pode ser vazio.\n";
        return;
    }

    cout << "Placa: ";
    cin.getline(tempPlaca, 8);

    //Validador: Placa inválida (difere de 7 caracteres)
    if (!Validador::placaValida(tempPlaca)) {
        cout << "Entrada invalida. Placa deve conter exatamente 7 caracteres.\n";
        return;
    }

    //Validador: Placa repetida
    if (Validador::placaRepetida(tempPlaca, veiculos, totalVeiculos)) {
        cout << "Ja existe um veiculo com essa placa.\n";
        return;
    }

    cout << "\nDigite o [ID] da nova localizacao do veiculo:\n";
    gerLocais.listaLocais();

    //Validador: entrada não numérica
    id_tempLocalAtual = Validador::lerInteiro("\nID: ", 1, gerLocais.getTotalLocais());
    strcpy(tempLocalAtual, gerLocais.getEnderecoByID(id_tempLocalAtual));

    veiculos[id - 1] = Veiculo(tempMarca, tempModelo, tempPlaca, tempLocalAtual, true);

    cout<<"Veiculo atualizado com sucesso!"<<endl;
}

//Exibir lista de veículos cadastrados
void ManagerVeiculos::listaVeiculos() {
    cout<<"\n---Veiculos cadastrados:---\n";

    //Exibe e retorna se não houver veículos cadastrados
    if (totalVeiculos == 0) {
        cout << "Nenhum veiculo cadastrado.\n";
        return;
    }

    for (int i = 0; i < totalVeiculos; i++) {
        cout << "[" << i + 1 << "]"
             << " | Marca: " << veiculos[i].getMarca()
             << " | Modelo: " << veiculos[i].getModelo()
             << " | Placa: " << veiculos[i].getPlaca()
             << " | Localizacao: " << veiculos[i].getLocalAtual()
             << " | Disponivel? " << (veiculos[i].getDisponivel() ? "Sim" : "Nao")
             << endl;
    }
}

//Remover veículo
void ManagerVeiculos::removerVeiculo() {

    //Exibe e retorna se não houver veículos cadastrados
    if (totalVeiculos == 0) {
        listaVeiculos();
        return;
    }

    int id;
    cout << "\nDigite o [ID] do veiculo a ser removido:\n";
    listaVeiculos();

    //Validador: entrada não numérica
    id = Validador::lerInteiro("\nID: ", 1, totalVeiculos);

    for (int i = id - 1; i < totalVeiculos - 1; i++) {
        veiculos[i] = veiculos[i + 1];
    }
    totalVeiculos--;

    cout << "Veiculo removido com sucesso!" << endl;
}

//Setters
void ManagerVeiculos::setTotalVeiculos(int total) { totalVeiculos = total; }

//Getters
int ManagerVeiculos::getTotalVeiculos() const { return totalVeiculos; }
Veiculo ManagerVeiculos::getVeiculo(int id) const { return veiculos[id]; }
Veiculo* ManagerVeiculos::getArrayVeiculos() { return veiculos; }
