#ifndef MANAGERPEDIDOS_H
#define MANAGERPEDIDOS_H

class ManagerPedidos{
private:
    Pedido pedidos[MAX];
    int totalPedidos=0;
public:
    void cadastrarPedido(ManagerLocais&);
    void atualizarPedido(ManagerLocais&);
    void listaPedidos();
    void removerPedido();
    void setTotalPedidos(int);
    Pedido getPedidoByID(int)const;
    int getTotalPedidos()const;
    Pedido* getArrayPedidos()const;
};

#endif
