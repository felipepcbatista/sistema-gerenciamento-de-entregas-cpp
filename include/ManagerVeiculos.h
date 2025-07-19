#ifndef MANAGERVEICULOS_H
#define MANAGERVEICULOS_H

class ManagerVeiculos{
private:
    Veiculo veiculos[MAX];
    int totalVeiculos=0;
public:
    void cadastrarVeiculo(ManagerLocais&);
    void atualizarVeiculo(ManagerLocais&);
    void listaVeiculos();
    void removerVeiculo();
    void setTotalVeiculos(int);

    int getTotalVeiculos()const;
    Veiculo& getVeiculo(int)const;
    Veiculo* getArrayVeiculos()const;
};

#endif
