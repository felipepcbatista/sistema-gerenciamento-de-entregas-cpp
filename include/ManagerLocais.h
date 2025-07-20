#ifndef MANAGERLOCAIS_H
#define MANAGERLOCAIS_H
#include "Local.h"

class ManagerLocais {
private:
    static const int MAX = 100;
    Local locais[MAX];
    int totalLocais = 0;

public:
    void cadastrarLocal();
    void atualizarLocal();
    void listaLocais();
    void removerLocal();

    const char* getEnderecoByID(int id);
    int getIDporEndereco(const char* endereco);
    void setTotalLocais(int total);
    double getCoordenadaXporID(int id) const;
    double getCoordenadaYporID(int id) const;
    int getTotalLocais() const;
    Local* getArrayLocais() const;
};

#endif
