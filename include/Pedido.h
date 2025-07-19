#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido{
private:
    int id;
    char localOrigem[300];
    char localDestino[300];
public:

    Pedido();
    Pedido(int, const char*, const char*);
    void setID (int);
    void setOrigem (const char*);
    void setDestino (const char*);
    int getID()const;
    const char* getOrigem()const;
    const char* getDestino()const;
};

#endif
