#ifndef VEICULO_H
#define VEICULO_H

class Veiculo{
private:
    char marca[100];
    char modelo[100];
    char placa[8];
    char localAtual[300];
    bool disponivel;
public:
    Veiculo();
    Veiculo(const char* marca, const char* modelo, const char* placa, const char* localAtual, bool disponivel);
    void setMarca (const char* marca);
    void setModelo (const char* modelo);
    void setPlaca (const char* placa);
    void setLocalAtual (const char* localAtual);
    void setDisponivel (bool disponivel);

    const char* getMarca()const;
    const char* getModelo()const;
    const char* getPlaca()const;
    const char* getLocalAtual()const;
    bool getDisponivel()const;
};

#endif
