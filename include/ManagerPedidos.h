#ifndef MANAGERPEDIDOS_H
#define MANAGERPEDIDOS_H

#include "Pedido.h"
#include "ManagerLocais.h"

const int MAX_PEDIDOS = 100;

class ManagerPedidos {
private:
    Pedido pedidos[MAX_PEDIDOS];
    int totalPedidos = 0;

public:
    void cadastrarPedido(ManagerLocais& gerLocais);
    void atualizarPedido(ManagerLocais& gerLocais);
    void listaPedidos();
    void removerPedido();
    void setTotalPedidos(int total);

    Pedido getPedidoByID(int id) const;
    int getTotalPedidos() const;
    Pedido* getArrayPedidos();
};

#endif
