#include "Veiculo.h"
#include <cstring>

Veiculo::Veiculo() {
    strcpy(marca, "");
    strcpy(modelo, "");
    strcpy(placa, "");
    strcpy(localAtual, "");
    disponivel = true;
}

Veiculo::Veiculo(const char* marca, const char* modelo, const char* placa, const char* localAtual, bool disponivel) {
    setMarca(marca);
    setModelo(modelo);
    setPlaca(placa);
    setLocalAtual(localAtual);
    setDisponivel(disponivel);
}

void Veiculo::setMarca(const char* marca) { strcpy(this->marca, marca); }
void Veiculo::setModelo(const char* modelo) { strcpy(this->modelo, modelo); }
void Veiculo::setPlaca(const char* placa) { strcpy(this->placa, placa); }
void Veiculo::setLocalAtual(const char* localAtual) { strcpy(this->localAtual, localAtual); }
void Veiculo::setDisponivel(bool disponivel) { this->disponivel = disponivel; }

const char* Veiculo::getMarca() const { return marca; }
const char* Veiculo::getModelo() const { return modelo; }
const char* Veiculo::getPlaca() const { return placa; }
const char* Veiculo::getLocalAtual() const { return localAtual; }
bool Veiculo::getDisponivel() const { return disponivel; }
