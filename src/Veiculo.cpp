#include 'Veiculo.h'
#include <iostream>
#include <cstring>
using namespace std;

Veiculo::Veiculo(){
    strcpy(marca, "");
    strcpy(modelo, "");
    strcpy(placa, "");
    strcpy(localAtual, "");
    disponivel=true;
}

Veiculo::Veiculo(const char* marca, const char* modelo, const char* placa, const char* localAtual, bool disponivel){
    setMarca(marca);
    setModelo(modelo);
    setPlaca(placa);
    setLocalAtual(localAtual);
    setDisponivel(disponivel);
}

Veiculo::setMarca (const char* marca){ strcpy(this->marca, marca); }
Veiculo::setModelo (const char* modelo){ strcpy(this->modelo, modelo); }
Veiculo::setPlaca (const char* placa){ strcpy(this->placa, placa); }
Veiculo::setLocalAtual (const char* localAtual){ strcpy(this->localAtual, localAtual); }
Veiculo::setDisponivel (bool disponivel){ this->disponivel=disponivel; }

Veiculo::getMarca()const{ return marca; }
Veiculo::getModelo()const{ return modelo; }
Veiculo::getPlaca()const{ return placa; }
Veiculo::getLocalAtual()const{ return localAtual; }
Veiculo::getDisponivel()const{ return disponivel; }
