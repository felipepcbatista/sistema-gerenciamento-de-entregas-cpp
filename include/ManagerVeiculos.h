#ifndef MANAGERVEICULOS_H
#define MANAGERVEICULOS_H

class Veiculo;

class ManagerVeiculos{
private:
    Veiculo veiculos[MAX];
    int totalVeiculos=0;
public:
    void cadastrarVeiculo(ManagerLocais& gerLocais);
    void atualizarVeiculo(ManagerLocais& gerLocais);
    void listaVeiculos();
    void removerVeiculo();
    void setTotalVeiculos(int total);

    int getTotalVeiculos()const;
    Veiculo& getVeiculo(int id)const;
    Veiculo* getArrayVeiculos()const;
};

#endif
