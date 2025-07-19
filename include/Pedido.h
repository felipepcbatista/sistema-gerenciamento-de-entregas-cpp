#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
private:
    int id;
    char localOrigem[300];
    char localDestino[300];

public:
    Pedido();
    Pedido(int id, const char* localOrigem, const char* localDestino);
    void setID(int id);
    void setOrigem(const char* localOrigem);
    void setDestino(const char* localDestino);
    int getID() const;
    const char* getOrigem() const;
    const char* getDestino() const;
};

#endif
