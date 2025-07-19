#ifndef DATA_H
#define DATA_H

class ManagerLocais;
class ManagerVeiculos;
class ManagerPedidos;

class Data{
public:
    void salvarLocais(ManagerLocais& gerLocais);
    void carregarLocais(ManagerLocais& gerLocais);
    void salvarVeiculos(ManagerVeiculos& gerVeiculos);
    void carregarVeiculos(ManagerVeiculos& gerVeiculos);
    void salvarPedidos(ManagerPedidos& gerPedidos);
    void carregarPedidos(ManagerPedidos& gerPedidos);
};

#endif
