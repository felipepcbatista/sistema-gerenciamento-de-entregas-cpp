#ifndef MANAGERVEICULOS_H
#define MANAGERVEICULOS_H

#include <string>
#include "Veiculo.h"
#include "Pedido.h"
#include "ManagerLocais.h"

const int MAX = 100;

class ManagerVeiculos {
private:
    Veiculo* veiculos[MAX];
    int totalVeiculos;
public:
    void cadastrarVeiculo(ManagerLocais& gerLocais);
    void atualizarVeiculo(ManagerLocais& gerLocais);
    void listarVeiculos();
    void removeVeiculo();
    void setTotalVeiculos(int total);

    int getTotalVeiculos() const;
    Veiculo* getVeiculo(int id) const;
    Veiculo** getArrayVeiculos() const;
};

#endif
