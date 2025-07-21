#include "Data.h"
#include "ManagerLocais.h"
#include "ManagerVeiculos.h"
#include "ManagerPedidos.h"
#include <iostream>
#include <fstream>
using namespace std;

//Salva locais em arquivo binário
void Data::salvarLocais(ManagerLocais& gerLocais){
    ofstream out("locais.dat", ios::binary);

    //Exibe e retorna se deu erro ao abrir arquivo
    if(!out){
        cout<<"Erro ao abrir arquivo para backup de locais.\n";
        return;
    }
    int total = gerLocais.getTotalLocais();
    out.write((char*)&total, sizeof(total));
    out.write((char*)gerLocais.getArrayLocais(), sizeof(Local)*total);
    out.close(); //Fecha arquivo
    cout<<"Backup de locais concluido com sucesso.\n";
}

//Carrega locais de arquivo binário
void Data::carregarLocais(ManagerLocais& gerLocais){
    ifstream in("locais.dat", ios::binary);

    //Exibe e retorna se deu erro ao abrir arquivo
    if(!in){
        cout<<"Nenhum backup de locais encontrado.\n";
        return;
    }
    int total;
    in.read((char*)&total, sizeof(total));
    in.read((char*)gerLocais.getArrayLocais(), sizeof(Local)*total);
    gerLocais.setTotalLocais(total);
    in.close(); //Fecha arquivo
    cout<<"Locais restaurados do backup com sucesso.\n";
}

//Salva veículos em arquivo binário
void Data::salvarVeiculos(ManagerVeiculos& gerVeiculos){
    ofstream out("veiculos.dat", ios::binary);

    //Exibe e retorna se deu erro ao abrir arquivo
    if(!out){
        cout<<"Erro ao abrir arquivo para backup de veiculos.\n";
        return;
    }
    int total = gerVeiculos.getTotalVeiculos();
    out.write((char*)&total, sizeof(total));
    out.write((char*)gerVeiculos.getArrayVeiculos(), sizeof(Veiculo)*total);
    out.close(); //Fecha arquivo
    cout<<"Backup de veiculos concluido com sucesso.\n";
}

//Carrega veículos de arquivo binário
void Data::carregarVeiculos(ManagerVeiculos& gerVeiculos){
    ifstream in("veiculos.dat", ios::binary);

    //Exibe e retorna se deu erro ao abrir arquivo
    if(!in){
        cout<<"Nenhum backup de veiculos encontrado.\n";
        return;
    }
    int total;
    in.read((char*)&total, sizeof(total));
    in.read((char*)gerVeiculos.getArrayVeiculos(), sizeof(Veiculo)*total);
    gerVeiculos.setTotalVeiculos(total);
    in.close(); //Fecha arquivo
    cout<<"Veiculos restaurados do backup com sucesso.\n";
}

//Salva pedidos em arquivo binário
void Data::salvarPedidos(ManagerPedidos& gerPedidos){
    ofstream out("pedidos.dat", ios::binary);

    //Exibe e retorna se deu erro ao abrir arquivo
    if(!out){
        cout<<"Erro ao abrir arquivo para backup de pedidos.\n";
        return;
    }
    int total = gerPedidos.getTotalPedidos();
    out.write((char*)&total, sizeof(total));
    out.write((char*)gerPedidos.getArrayPedidos(), sizeof(Pedido)*total);
    out.close(); //Fecha arquivo
    cout<<"Backup de pedidos concluido com sucesso.\n";
}

//Carrega pedidos de arquivo binário
void Data::carregarPedidos(ManagerPedidos& gerPedidos){
    ifstream in("pedidos.dat", ios::binary);

    //Exibe e retorna se deu erro ao abrir arquivo
    if(!in){
        cout<<"Nenhum backup de pedidos encontrado.\n";
        return;
    }
    int total;
    in.read((char*)&total, sizeof(total));
    in.read((char*)gerPedidos.getArrayPedidos(), sizeof(Pedido)*total);
    gerPedidos.setTotalPedidos(total);
    in.close(); //Fecha arquivo
    cout<<"Pedidos restaurados do backup com sucesso.\n";
}
