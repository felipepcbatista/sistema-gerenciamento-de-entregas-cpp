#ifndef MANAGERLOCAIS_H
#define MANAGERLOCAIS_H
#include "Local.h"

class ManagerLocais {
private:
    static const int MAX = 100;
    Local* locais[MAX];
    int totalLocais = 0;

public:
    void cadastrarLocal();
    void atualizarLocal();
    void listaLocais();
    void removerLocal();

    const char* getEnderecoByID(int);
    int getIDporEndereco(const char*);
    void setTotalLocais(int);
    double getCoordenadaXporID(int) const;
    double getCoordenadaYporID(int) const;
    int getTotalLocais() const;
    Local* getArrayLocais() const;
};

#endif
