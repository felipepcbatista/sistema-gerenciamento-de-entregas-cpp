#include <iostream>
#include <cstring>
#include <limits>
#include <fstream>
#define MAX 100

class Local{
private:
    char endereco[300];
    double coordenadaX;
    double coordenadaY;
public:

    Local(){
        strcpy(endereco, "");
        coordenadaX=0.0;
        coordenadaY=0.0;
    }

    Local(const char* endereco, double coordenadaX, double coordenadaY){
        setEndereco(endereco);
        setCoordenadaX(coordenadaX);
        setCoordenadaY(coordenadaY);
    }

    void setEndereco (const char* endereco){ strcpy(this->endereco, endereco); }
    void setCoordenadaX (double coordenadaX){ this->coordenadaX=coordenadaX; }
    void setCoordenadaY (double coordenadaY){ this->coordenadaY=coordenadaY; }

    const char* getEndereco(){ return endereco; }
    double getCoordenadaX(){ return coordenadaX; }
    double getCoordenadaY(){ return coordenadaY; }
};

class ManagerLocais{
private:
    Local locais[MAX];
    int totalLocais=0;
public:
    void cadastrarLocal(){
        char endereco[300];
        double coordenadaX;
        double coordenadaY;

        cout<<"Endereco do local: ";
        cin.getline(endereco, 300);
        cout<<"Coordenadas:\n";
        cout<<"X: ";
        cin>>coordenadaX;
        cout<<"Y: ";
        cin>>coordenadaY;
        cin.ignore();

        locais[totalLocais]=Local(endereco, coordenadaX, coordenadaY);
        totalLocais++;

        cout<<"Local cadastrado com sucesso!"<<endl;
    }
};

class Veiculo{
//Veículo vai aqui
};

class Pedido{
//Pedido vai aqui
};

class Gerenciador{
//Gerenciador de Locais, Veículos e Pedidos vai aqui
};

class Rotas{
//Rotas vai aqui
};

int main()
{
    //Main vai aqui
}
