#ifndef MANAGERPEDIDOS_H
#define MANAGERPEDIDOS_H
#define MAX 100

class Pedido;
class ManagerLocais;

class ManagerPedidos{
private:
    Pedido* pedidos[MAX];
    int totalPedidos=0;
public:
    void cadastrarPedido(ManagerLocais& gerLocais);
    void atualizarPedido(ManagerLocais& gerLocais);
    void listaPedidos();
    void removerPedido();
    void setTotalPedidos(int total);
    Pedido getPedidoByID(int id)const;
    int getTotalPedidos()const;
    Pedido* getArrayPedidos()const;
};

#endif
