#ifndef ROTAS_H
#define ROTAS_H

class ManagerLocais;
class ManagerVeiculos;
class ManagerPedidos;

class Rotas{
private:
    double calcularDistancia(double x1, double y1, double x2, double y2);
public:
    void simularEntrega(ManagerLocais& gerLocais, ManagerVeiculos& gerVeiculos, ManagerPedidos& gerPedidos);
};

#endif
