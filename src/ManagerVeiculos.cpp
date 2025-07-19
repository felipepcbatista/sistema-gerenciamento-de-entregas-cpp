#include 'ManagerVeiculos.h'
#include <iostream>
using namespace std;

ManagerVeiculos::cadastrarVeiculo(ManagerLocais& gerLocais){
    if(totalVeiculos>=MAX){
        cout<<"Limite de veiculos cadastrados atingido.\n";
        return;
    }

    char marca[100];
    char modelo[100];
    char placa[8];
    int id_localAtual;
    bool disponivel=true;

    cout<<"Digite o ID da localizacao atual do veiculo:\n";
    gerLocais.listaLocais();
    id_localAtual = Validador::lerInteiro("ID: ", 1, gerLocais.getTotalLocais());
    cout<<"Marca do veiculo: ";
    cin.getline(marca, 100);
    if(Validador::stringVazia(marca)){
        cout<<"Entrada invalida. Marca nao pode ser vazia.\n";
        return;
    }
    cout<<"Modelo do veiculo: ";
    cin.getline(modelo, 100);
    if(Validador::stringVazia(modelo)){
        cout<<"Entrada invalida. Modelo nao pode ser vazio.\n";
        return;
    }
    cout<<"Placa do veiculo(7 caracteres): ";
    cin.getline(placa, 8);
    if(Validador::placaInvalida(placa)){
        cout<<"Entrada invalida. Placa deve conter exatamente 7 caracteres.\n";
        return;
    }

    if(Validador::placaRepetida(placa, veiculos, totalVeiculos)){
        cout<<"Ja existe um veiculo com essa placa.\n";
        return;
    }

    char localAtual[300];
    strcpy(localAtual, gerLocais.getEnderecoByID(id_localAtual));
    veiculos[totalVeiculos]=Veiculo(marca, modelo, placa, localAtual, disponivel);
    totalVeiculos++;
}

ManagerVeiculos::atualizarVeiculo(ManagerLocais& gerLocais){
    char tempMarca[100];
    char tempModelo[100];
    char tempPlaca[8];
    int id;
    int id_tempLocalAtual=-1;
    bool tempDisponivel=true;

    cout<<"Digite o [ID] do veiculo a ser atualizado:\n";
    listaVeiculos();
    id = Validador::lerInteiro("ID: ", 1, totalVeiculos);
    cout<<"Novos dados do veiculo:\n";
    cout<<"Marca: ";
    cin.getline(tempMarca, 100);
    if(Validador::stringVazia(tempMarca)){
        cout<<"Entrada invalida. Marca nao pode ser vazia.\n";
        return;
    }
    cout<<"Modelo: ";
    cin.getline(tempModelo, 100);
    if(Validador::stringVazia(tempModelo)){
        cout<<"Entrada invalida. Modelo nao pode ser vazio.\n";
        return;
    }
    cout<<"Placa: ";
    cin.getline(tempPlaca, 8);
    if(Validador::placaInvalida(tempPlaca)){
        cout<<"Entrada invalida. Placa deve conter exatamente 7 caracteres.\n";
        return;
    }
    if(Validador::placaRepetida(tempPlaca, veiculos, totalVeiculos)){
        cout<<"Ja existe um veiculo com essa placa.\n";
        return;
    }

    cout<<"Digite o [ID] da nova localizacao do veiculo:\n";
    gerLocais.listaLocais();
    id_tempLocalAtual = Validador::lerInteiro("ID: ", 1, gerLocais.getTotalLocais());

    char tempLocalAtual[300];
    strcpy(tempLocalAtual, gerLocais.getEnderecoByID(id_tempLocalAtual));

    veiculos[id-1]=Veiculo(tempMarca, tempModelo, tempPlaca, tempLocalAtual, tempDisponivel);
}

ManagerVeiculos::void listaVeiculos(){
    if(totalVeiculos==0){
        cout<<"Nenhum veiculo cadastrado.\n";
        return;
    }

    for (int i=0; i<totalVeiculos; i++){
        cout<<"["<<i+1<<"]"
        <<" | Marca: "<<veiculos[i].getMarca()
        <<" | Modelo: "<<veiculos[i].getModelo()
        <<" | Placa: "<<veiculos[i].getPlaca()
        <<" | Localizacao: "<<veiculos[i].getLocalAtual()
        <<" | Disponibilidade: "<<veiculos[i].getDisponivel()
        <<endl;
    }
}

ManagerVeiculos::removerVeiculo(){
    int id;

    cout<<"Digite o [ID] do veiculo a ser removido:\n";
    listaVeiculos();
    id = Validador::lerInteiro("ID: ", 1, totalVeiculos);

    for(int i=id-1; i<totalVeiculos-1; i++){
        veiculos[i]=veiculos[i+1];
    }
    totalVeiculos--;

    cout<<"Veiculo removido com sucesso!"<<endl;
}

ManagerVeiculos::setTotalVeiculos(int total){ totalVeiculos=total; }
ManagerVeiculos::getTotalVeiculos()const{ return totalVeiculos; }
ManagerVeiculos::getVeiculo(int id)const{ return veiculos[id]; }
ManagerVeiculos::getArrayVeiculos()const{ return veiculos; }
