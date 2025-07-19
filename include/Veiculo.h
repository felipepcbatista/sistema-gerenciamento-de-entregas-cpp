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
    Veiculo(const char*, const char*, const char*, const char*, bool);
    void setMarca (const char*);
    void setModelo (const char*);
    void setPlaca (const char*);
    void setLocalAtual (const char*);
    void setDisponivel (bool);

    const char* getMarca()const;
    const char* getModelo()const;
    const char* getPlaca()const;
    const char* getLocalAtual()const;
    bool getDisponivel()const;
};

#endif
