#include "ManagerPedidos.h"
#include "Pedido.h"
#include "Validador.h"
#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

void ManagerPedidos::cadastrarPedido(ManagerLocais& gerLocais){
    if(totalPedidos>=MAX){
        cout<<"Limite de pedidos cadastrados atingido.\n";
        return;
    }

    int idPedido=totalPedidos;
    int id_localOrigem;
    int id_localDestino;

    cout<<"Digite o [ID] do local de origem da entrega:\n";
    gerLocais.listaLocais();
    id_localOrigem = Validador::lerInteiro("ID: ", 1, gerLocais.getTotalLocais());
    cout<<"Digite o [ID] do local de destino da entrega:\n";
    gerLocais.listaLocais();
    id_localDestino = Validador::lerInteiro("ID: ", 1, gerLocais.getTotalLocais());

    char localOrigem[300];
    char localDestino[300];
    strcpy(localOrigem, gerLocais.getEnderecoByID(id_localOrigem));
    strcpy(localDestino, gerLocais.getEnderecoByID(id_localDestino));

    pedidos[totalPedidos]=Pedido(idPedido, localOrigem, localDestino);
    totalPedidos++;

    cout<<"Pedido cadastrado com sucesso!"<<endl;
}
void ManagerPedidos::atualizarPedido(ManagerLocais& gerLocais){
    int idPedido;
    int id_tempLocalOrigem;
    int id_tempLocalDestino;

    cout<<"Digite o [ID] do pedido a ser atualizado:\n";
    listaPedidos();
    idPedido = Validador::lerInteiro("ID: ", 1, totalPedidos);
    cout<<"Digite o [ID] do novo local de origem da entrega:\n";
    gerLocais.listaLocais();
    cout<<"ID: ";
    id_tempLocalOrigem = Validador::lerInteiro("ID: ", 1, gerLocais.getTotalLocais());
    cout<<"Digite o [ID] do novo local de destino da entrega:\n";
    gerLocais.listaLocais();
    id_tempLocalDestino = Validador::lerInteiro("ID: ", 1, gerLocais.getTotalLocais());

    char tempLocalOrigem[300];
    char tempLocalDestino[300];
    strcpy(tempLocalOrigem, gerLocais.getEnderecoByID(id_tempLocalOrigem));
    strcpy(tempLocalDestino, gerLocais.getEnderecoByID(id_tempLocalDestino));

    pedidos[idPedido-1]=Pedido(idPedido-1, tempLocalOrigem, tempLocalDestino);
}
void ManagerPedidos::listaPedidos(){
    if(totalPedidos==0){
        cout<<"Nenhum pedido cadastrado.\n";
        return;
    }

    for (int i=0; i<totalPedidos; i++){
        cout<<"["<<pedidos[i].getID()<<"]"
        <<" | Origem: "<<pedidos[i].getOrigem()
        <<" | Destino: "<<pedidos[i].getDestino()
        <<endl;
    }
}
void ManagerPedidos::removerPedido(){
    int idPedido;

    cout<<"Informe o [ID] do pedido a ser removido:\n";
    listaPedidos();
    idPedido = Validador::lerInteiro("ID: ", 1, totalPedidos);

    for (int i=idPedido-1; i<totalPedidos-1; i++){
        pedidos[i]=pedidos[i+1];
    }
    totalPedidos--;

    cout<<"Pedido removido com sucesso!"<<endl;
}

void ManagerPedidos::setTotalPedidos(int total){ totalPedidos=total; }

Pedido ManagerPedidos::getPedidoByID(int id)const{ return pedidos[id-1]; }
int ManagerPedidos::getTotalPedidos()const{ return totalPedidos; }
Pedido* ManagerPedidos::getArrayPedidos()const{ return pedidos; }
