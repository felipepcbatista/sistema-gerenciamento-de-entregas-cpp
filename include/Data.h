#ifndef DATA_H
#define DATA_H

class Data{
public:
    void salvarLocais(ManagerLocais&);
    void carregarLocais(ManagerLocais&);
    void salvarVeiculos(ManagerVeiculos&);
    void carregarVeiculos(ManagerVeiculos&);
    void salvarPedidos(ManagerPedidos&);
    void carregarPedidos(ManagerPedidos&);
};

#endif
