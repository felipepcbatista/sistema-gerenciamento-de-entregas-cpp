#include "Pedido.h"
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

void Pedido::setID (int id){ this->id=id; }
void Pedido::setOrigem (const char* localOrigem){ strcpy(this->localOrigem, localOrigem); }
void Pedido::setDestino (const char* localDestino){ strcpy(this->localDestino, localDestino); }

int Pedido::getID()const{ return id; }
const char* Pedido::getOrigem()const{ return localOrigem; }
const char* Pedido::getDestino()const{ return localDestino; }
