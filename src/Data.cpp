#include 'Data.h'
#include 'ManagerLocais.h'
#include 'ManagerVeiculos.h'
#include 'ManagerPedidos.h'
#include <iostream>
#include <fstream>
using namespace std;

Data::salvarLocais(ManagerLocais& gerLocais){
    ofstream out("locais.dat", ios::binary);
    if(!out){
        cout<<"Erro ao abrir arquivo para backup de locais.\n";
        return;
    }
    int total = gerLocais.getTotalLocais();
    out.write((char*)&total, sizeof(total));
    out.write((char*)gerLocais.getArrayLocais(), sizeof(Local)*total);
    out.close();
    cout<<"Backup de locais concluido com sucesso.\n";
}

Data::carregarLocais(ManagerLocais& gerLocais){
    ifstream in("locais.dat", ios::binary);
    if(!in){
        cout<<"Nenhum backup de locais encontrado.\n";
        return;
    }
    int total;
    in.read((char*)&total, sizeof(total));
    in.read((char*)gerLocais.getArrayLocais(), sizeof(Local)*total);
    gerLocais.setTotalLocais(total);
    in.close();
    cout<<"Locais restaurados do backup com sucesso.\n";
}

Data::salvarVeiculos(ManagerVeiculos& gerVeiculos){
    ofstream out("veiculos.dat", ios::binary);
    if(!out){
        cout<<"Erro ao abrir arquivo para backup de veiculos.\n";
        return;
    }
    int total = gerVeiculos.getTotalVeiculos();
    out.write((char*)&total, sizeof(total));
    out.write((char*)gerVeiculos.getArrayVeiculos(), sizeof(Veiculo)*total);
    out.close();
    cout<<"Backup de veiculos concluido com sucesso.\n";
}

Data::carregarVeiculos(ManagerVeiculos& gerVeiculos){
    ifstream in("veiculos.dat", ios::binary);
    if(!in){
        cout<<"Nenhum backup de veiculos encontrado.\n";
        return;
    }
    int total;
    in.read((char*)&total, sizeof(total));
    in.read((char*)gerVeiculos.getArrayVeiculos(), sizeof(Veiculo)*total);
    gerVeiculos.setTotalVeiculos(total);
    in.close();
    cout<<"Veiculos restaurados do backup com sucesso.\n";
}

Data::salvarPedidos(ManagerPedidos& gerPedidos){
    ofstream out("pedidos.dat", ios::binary);
    if(!out){
        cout<<"Erro ao abrir arquivo para backup de pedidos.\n";
        return;
    }
    int total = gerPedidos.getTotalPedidos();
    out.write((char*)&total, sizeof(total));
    out.write((char*)gerPedidos.getArrayPedidos(), sizeof(Pedido)*total);
    out.close();
    cout<<"Backup de pedidos concluido com sucesso.\n";
}

Data::carregarPedidos(ManagerPedidos& gerPedidos){
    ifstream in("pedidos.dat", ios::binary);
    if(!in){
        cout<<"Nenhum backup de pedidos encontrado.\n";
        return;
    }
    int total;
    in.read((char*)&total, sizeof(total));
    in.read((char*)gerPedidos.getArrayPedidos(), sizeof(Pedido)*total);
    gerPedidos.setTotalPedidos(total);
    in.close();
    cout<<"Veiculos restaurados do backup com sucesso.\n";
}
