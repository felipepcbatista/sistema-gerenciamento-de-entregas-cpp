#include "ManagerPedidos.h"
#include "Validador.h"
#include <iostream>
#include <cstring>
using namespace std;

//Cadastrar Pedido
void ManagerPedidos::cadastrarPedido(ManagerLocais& gerLocais) {

    //Validador: limite de pedidos
    if (totalPedidos >= MAX_PEDIDOS) {
        cout << "Limite de pedidos cadastrados atingido.\n";
        return;
    }

    //Exibe e retorna se não houver locais cadastrados -> Pedido depende de local
    if(gerLocais.getTotalLocais()==0){
        gerLocais.listaLocais();
        return;
    }

    int idPedido = totalPedidos;
    int id_localOrigem, id_localDestino;

    cout << "\nDigite o [ID] do local de origem da entrega:\n";
    gerLocais.listaLocais();

    //Validador: entrada não numérica
    id_localOrigem = Validador::lerInteiro("\nID: ", 1, gerLocais.getTotalLocais());

    cout << "\nDigite o [ID] do local de destino da entrega:\n";
    gerLocais.listaLocais();

    //Validador: entrada não numérica
    id_localDestino = Validador::lerInteiro("\nID: ", 1, gerLocais.getTotalLocais());

    char localOrigem[300];
    char localDestino[300];
    strcpy(localOrigem, gerLocais.getEnderecoByID(id_localOrigem));
    strcpy(localDestino, gerLocais.getEnderecoByID(id_localDestino));

    pedidos[totalPedidos] = Pedido(idPedido, localOrigem, localDestino);
    totalPedidos++;

    cout << "Pedido cadastrado com sucesso!" << endl;
}

//Atualizar Pedido
void ManagerPedidos::atualizarPedido(ManagerLocais& gerLocais) {

    //Exibe e retorna se não houver pedidos cadastrados
    if (totalPedidos == 0) {
        listaPedidos();
        return;
    }

    //Exibe e retorna se não houver locais cadastrados -> Pedido depende de local
    if(gerLocais.getTotalLocais()==0){
        gerLocais.listaLocais();
        return;
    }

    int idPedido;
    cout << "Digite o [ID] do pedido a ser atualizado:\n";
    listaPedidos();

    //Validador: entrada não numérica
    idPedido = Validador::lerInteiro("\nID: ", 1, totalPedidos);

    int id_tempLocalOrigem, id_tempLocalDestino;

    cout << "Digite o [ID] do novo local de origem da entrega:\n";
    gerLocais.listaLocais();

    //Validador: entrada não numérica
    id_tempLocalOrigem = Validador::lerInteiro("\nID: ", 1, gerLocais.getTotalLocais());

    cout << "Digite o [ID] do novo local de destino da entrega:\n";
    gerLocais.listaLocais();

    //Validador: entrada não numérica
    id_tempLocalDestino = Validador::lerInteiro("\nID: ", 1, gerLocais.getTotalLocais());

    char tempLocalOrigem[300];
    char tempLocalDestino[300];
    strcpy(tempLocalOrigem, gerLocais.getEnderecoByID(id_tempLocalOrigem));
    strcpy(tempLocalDestino, gerLocais.getEnderecoByID(id_tempLocalDestino));

    pedidos[idPedido - 1] = Pedido(idPedido - 1, tempLocalOrigem, tempLocalDestino);
}

//Exibe lista de pedidos cadastrados
void ManagerPedidos::listaPedidos() {
    cout<<"\n---Pedidos cadastrados:---\n";

    //Exibe e retorna se não houver pedidos cadastrados
    if (totalPedidos == 0) {
        cout << "Nenhum pedido cadastrado.\n";
        return;
    }

    for (int i = 0; i < totalPedidos; i++) {
        cout << "[" << pedidos[i].getID() + 1 << "]"
             << " | Origem: " << pedidos[i].getOrigem()
             << " | Destino: " << pedidos[i].getDestino()
             << endl;
    }
}

//Remover Pedido
void ManagerPedidos::removerPedido() {

    //Exibe e retorna se não houver pedidos cadastrados
    if (totalPedidos == 0) {
        listaPedidos();
        return;
    }

    int idPedido;
    cout << "Informe o [ID] do pedido a ser removido:\n";
    listaPedidos();

    //Validador: entrada não numérica
    idPedido = Validador::lerInteiro("\nID: ", 1, totalPedidos);

    for (int i = idPedido - 1; i < totalPedidos - 1; i++) {
        pedidos[i] = pedidos[i + 1];
    }
    totalPedidos--;

    cout << "Pedido removido com sucesso!" << endl;
}

//Setters
void ManagerPedidos::setTotalPedidos(int total) { totalPedidos = total; }

//Getters
Pedido ManagerPedidos::getPedidoByID(int id) const { return pedidos[id - 1]; }
int ManagerPedidos::getTotalPedidos() const { return totalPedidos; }
Pedido* ManagerPedidos::getArrayPedidos() { return pedidos; }
