#include "Local.h"
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

void Local::setEndereco (const char* endereco){ strcpy(this->endereco, endereco); }
void Local::setCoordenadaX (double coordenadaX){ this->coordenadaX=coordenadaX; }
void Local::setCoordenadaY (double coordenadaY){ this->coordenadaY=coordenadaY; }

const char* Local::getEndereco()const{ return endereco; }
double Local::getCoordenadaX()const{ return coordenadaX; }
double Local::getCoordenadaY()const{ return coordenadaY; }
