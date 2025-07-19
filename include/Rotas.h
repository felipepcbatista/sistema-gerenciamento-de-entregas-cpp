#ifndef ROTAS_H
#define ROTAS_H

class Rotas{
private:
    double calcularDistancia(double, double, double, double);
public:
    void simularEntrega(ManagerLocais&, ManagerVeiculos&, ManagerPedidos&);
};

#endif
