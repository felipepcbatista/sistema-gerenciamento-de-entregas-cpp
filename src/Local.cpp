#include 'Local.h'
#include <iostream>
#include <cstring>
using namespace std;

Local::Local(){
    strcpy(endereco, "");
    coordenadaX=0.0;
    coordenadaY=0.0;
}

Local::Local(const char* endereco, double coordenadaX, double coordenadaY){
    setEndereco(endereco);
    setCoordenadaX(coordenadaX);
    setCoordenadaY(coordenadaY);
}

Local::setEndereco (const char* endereco){ strcpy(this->endereco, endereco); }
Local::setCoordenadaX (double coordenadaX){ this->coordenadaX=coordenadaX; }
Local::setCoordenadaY (double coordenadaY){ this->coordenadaY=coordenadaY; }

Local::getEndereco()const{ return endereco; }
Local::getCoordenadaX()const{ return coordenadaX; }
Local::getCoordenadaY()const{ return coordenadaY; }
