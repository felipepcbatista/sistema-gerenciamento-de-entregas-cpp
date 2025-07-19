#include 'Pedido.h'
#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

Pedido::Pedido(){
    id=0;
    strcpy(localOrigem, "");
    strcpy(localDestino, "");
}

Pedido::Pedido(int id, const char* localOrigem, const char* localDestino){
    setID(id);
    setOrigem(localOrigem);
    setDestino(localDestino);
}

Pedido::setID (int id){ this->id=id; }
Pedido::setOrigem (const char* localOrigem){ strcpy(this->localOrigem, localOrigem); }
Pedido::setDestino (const char* localDestino){ strcpy(this->localDestino, localDestino); }

Pedido::getID()const{ return id; }
Pedido::getOrigem()const{ return localOrigem; }
Pedido::getDestino()const{ return localDestino; }
