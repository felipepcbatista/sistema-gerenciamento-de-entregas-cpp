#ifndef MANAGERVEICULOS_H
#define MANAGERVEICULOS_H

#include "Veiculo.h"
#include "ManagerLocais.h"

const int MAX = 100;

class ManagerVeiculos {
private:
    Veiculo veiculos[MAX];
    int totalVeiculos = 0;
public:
    void cadastrarVeiculo(ManagerLocais& gerLocais);
    void atualizarVeiculo(ManagerLocais& gerLocais);
    void listaVeiculos();
    void removerVeiculo();
    void setTotalVeiculos(int total);

    int getTotalVeiculos() const;
    Veiculo getVeiculo(int id) const;
    Veiculo* getArrayVeiculos();
};

#endif
