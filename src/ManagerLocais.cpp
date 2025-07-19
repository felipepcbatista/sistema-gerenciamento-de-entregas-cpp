#include 'ManagerLocais.h'
#include <iostream>
#define MAX 100
using namespace std;

ManagerLocais::cadastrarLocal(){
    if(totalLocais>=MAX){
        cout<<"Limite de locais cadastrados atingido.\n";
        return;
    }

    char endereco[300];
    double coordenadaX;
    double coordenadaY;

    cout<<"Endereco do local: ";
    cin.getline(endereco, 300);
    if(Validador::stringVazia(endereco)){
        cout<<"Entrada invalida. Endereco nao pode ser vazio.\n";
        return;
    }
    if(Validador::nomeLocalRepetido(endereco, locais, totalLocais)){
        cout<<"Este local ja foi cadastrado.\n";
        return;
    }

    coordenadaX = Validador::lerDouble("Coordenada X: ");
    coordenadaY = Validador::lerDouble("Coordenada Y: ");

    locais[totalLocais]=Local(endereco, coordenadaX, coordenadaY);
    totalLocais++;

    cout<<"Local cadastrado com sucesso!"<<endl;
}

ManagerLocais::atualizarLocal(){
    char tempEndereco[300];
    double tempCoordenadaX;
    double tempCoordenadaY;
    int id;

    cout<<"Digite o [ID] do local a ser atualizado:\n";
    listaLocais();
    id = Validador::lerInteiro("ID: ", 1, totalLocais);
    cout<<"Novo endereco: ";
    cin.getline(tempEndereco, 300);
    if(Validador::stringVazia(tempEndereco)){
        cout<<"Entrada invalida. Endereco nao pode ser vazio.\n";
        return;
    }
    cout<<"Novas coordenadas:\n";
    tempCoordenadaX = Validador::lerDouble("X: ");
    tempCoordenadaY = Validador::lerDouble("Y: ");

    locais[id-1]=Local(tempEndereco, tempCoordenadaX, tempCoordenadaY);

    cout<<"Local atualizado com sucesso!"<<endl;
}

ManagerLocais::listaLocais(){
    if(totalLocais==0){
        cout<<"Nenhum local cadastrado.\n";
        return;
    }

    for (int i=0; i<totalLocais; i++){
        cout<<"["<<i+1<<"]"
        <<" | Endereco: "<<locais[i].getEndereco()
        <<" | Coordenada X: "<<locais[i].getCoordenadaX()
        <<" | Coordenada Y: "<<locais[i].getCoordenadaY()
        <<endl;
    }
}

ManagerLocais::removerLocal(){
    int id;

    cout<<"Digite o [ID] do local a ser removido:\n";
    listaLocais();
    id = Validador::lerInteiro("ID: ", 1, totalLocais);

    for (int i=id-1; i<totalLocais-1; i++){
        locais[i]=locais[i+1];
    }
    totalLocais--;

    cout<<"Local removido com sucesso!"<<endl;
}

ManagerLocais::getEnderecoByID(int id){ return locais[id-1].getEndereco(); }
ManagerLocais::getIDporEndereco(const char* endereco){
        for (int i=0; i<totalLocais; i++){
            if(strcmp(endereco, locais[i].getEndereco())==0)
                return i;
        }
        return -1;
    }
ManagerLocais::setTotalLocais(int total){ totalLocais=total; }
ManagerLocais::getCoordenadaXporID(int id)const{ return locais[id].getCoordenadaX(); }
ManagerLocais::getCoordenadaYporID(int id)const{ return locais[id].getCoordenadaY(); }
ManagerLocais::getTotalLocais()const{ return totalLocais; }
ManagerLocais::getArrayLocais()const{ return locais; }
