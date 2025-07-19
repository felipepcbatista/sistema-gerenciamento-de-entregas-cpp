#ifndef SISTEMA_H
#define SISTEMA_H

class Sistema{
private:
    ManagerLocais gerLocais;
    ManagerVeiculos gerVeiculos;
    ManagerPedidos gerPedidos;
    Rotas simuladorRotas;
    Data persistencia;
public:
    void executar();
    void exibirMenu();
    void tratarOpcao(int opc);
};

#endif
