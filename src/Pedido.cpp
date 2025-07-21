#include "Pedido.h"
#include <cstring>

//Construtor Padrão
Pedido::Pedido() {
    id = 0;
    strcpy(localOrigem, "");
    strcpy(localDestino, "");
}

//Construtor Parametrizado
Pedido::Pedido(int id, const char* localOrigem, const char* localDestino) {
    setID(id);
    setOrigem(localOrigem);
    setDestino(localDestino);
}

//Setters
void Pedido::setID(int id) { this->id = id; }
void Pedido::setOrigem(const char* localOrigem) { strcpy(this->localOrigem, localOrigem); }
void Pedido::setDestino(const char* localDestino) { strcpy(this->localDestino, localDestino); }

//Getters
int Pedido::getID() const { return id; }
const char* Pedido::getOrigem() const { return localOrigem; }
const char* Pedido::getDestino() const { return localDestino; }
