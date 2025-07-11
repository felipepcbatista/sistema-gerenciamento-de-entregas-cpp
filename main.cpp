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
    void atualizarLocal(){
        char tempEndereco[300];
        double tempCoordenadaX;
        double tempCoordenadaY;
        int id;

        cout<<"Digite o [ID] do local a ser atualizado:\n";
        listaLocais();
        cout<<"ID: ";
        cin>>id;
        cin.ignore();
        cout<<"Novo endereco: ";
        cin.getline(tempEndereco, 300);
        cout<<"Novas coordenadas:\n";
        cout<<"X: ";
        cin>>tempCoordenadaX;
        cout<<"Y: ";
        cin>>tempCoordenadaY;
        cin.ignore();

        locais[id-1]=Local(tempEndereco, tempCoordenadaX, tempCoordenadaY);

        cout<<"Local atualizado com sucesso!"<<endl;
    }
    void listaLocais(){
        for (int i=0; i<totalLocais; i++){
            cout<<"["<<i+1<<"]"
            <<" | Endereco: "<<locais[i].getEndereco()
            <<" | Coordenada X: "<<locais[i].getCoordenadaX()
            <<" | Coordenada Y: "<<locais[i].getCoordenadaY()
            <<endl;
        }
    }
    void removerLocal(){
        int id;

        cout<<"Digite o [ID] do local a ser removido:\n";
        listaLocais();
        cout<<"ID: ";
        cin>>id;
        cin.ignore();

        for (int i=id-1; i<totalLocais-1; i++){
            locais[i]=locais[i+1];
        }
        totalLocais--;

        cout<<"Local removido com sucesso!"<<endl;
    }
};

class Veiculo{
private:
    char marca[100];
    char modelo[100];
    char placa[8];
    char localAtual;
    bool disponivel;
public:

    Veiculo(){
        strcpy(marca, "");
        strcpy(modelo, "");
        strcpy(placa, "");
        id_localAtual=-1;
        disponivel=true;
    }

    Veiculo(const char* marca, const char* modelo, const char* placa, const char* localAtual, bool disponivel){
        setMarca(marca);
        setModelo(modelo);
        setPlaca(placa);
        setLocalAtual(localAtual);
        setDisponivel(disponivel);
    }

    void setMarca (const char* marca){ strcpy(this->marca, marca); }
    void setModelo (const char* modelo){ strcpy(this->modelo, modelo); }
    void setPlaca (const char* placa){ strcpy(this->placa, placa); }
    void setLocalAtual (const char* localAtual){ strcpy(this->localAtual, localAtual); }
    void setDisponivel (bool disponivel){ this->disponivel=disponivel; }

    const char* getMarca(){ return marca; }
    const char* getModelo(){ return modelo; }
    const char* getPlaca(){ return placa; }
    const char* getLocalAtual(){ return localAtual; }
    bool getDisponivel(){ return disponivel; }
};

class ManagerVeiculos{
private:
    Veiculo veiculos[MAX];
    int totalVeiculos=0;
public:
    void cadastrarVeiculo(Locais& locais){
        char marca[100];
        char modelo[100];
        char placa[8];
        int id_localAtual;
        bool disponivel=true;

        cout<<"Localizacao atual do veiculo:\n";
        gerLocais.listaLocais();
        cout<<"ID: ";
        cin>>id_localAtual;
        cin.ignore();
        cout<<"Marca do veiculo: ";
        cin.getline(marca, 100);
        cout<<"Modelo do veiculo: ";
        cin.getline(modelo, 100);
        cout<<"Placa do veiculo(7 caracteres): ";
        cin.getline(placa, 8);

        char localAtual[300];
        strcpy(localAtual, locais[id_localAtual-1].getEndereco());
        veiculos[totalVeiculos]=Veiculo(marca, modelo, placa, localAtual, disponivel);
        totalVeiculos++;
    }
    void atualizarVeiculo(Locais& locais){
        char tempMarca[100];
        char tempModelo[100];
        char tempPlaca[8];
        int id;
        int id_tempLocalAtual[300];
        bool tempDisponivel=true;

        cout<<"Digite o [ID] do veiculo a ser atualizado:\n";
        listaVeiculos();
        cout<<"ID: ";
        cin>>id;
        cin.ignore();
        cout<<"Nova marca do veiculo: ";
        cin.getline(tempMarca, 100);
        cout<<"Novo modelo do veiculo: ";
        cin.getline(tempModelo, 100);
        cout<<"Nova placa do veiculo: ";
        cin.getline(tempPlaca, 8);
        cout<<"Digite o [ID] da nova localizacao do veiculo:\n";
        locais.listaLocais();
        cout<<"ID: ";
        cin>>id_tempLocalAtual;

        char tempLocalAtual[300];
        strcpy(tempLocalAtual, locais[id_tempLocalAtual-1].getEndereco());

        veiculos[id-1]=Veiculo(tempMarca, tempModelo, tempPlaca, tempLocalAtual, tempDisponivel);
    }
    void listaVeiculos(Local& locais, Veiculo& veiculos){
        for (int i=0; i<totalVeiculos; i++){
            cout<<"["<<i+1<<"]"
            <<" | Marca: "<<veiculos[i].getMarca()
            <<" | Modelo: "<<veiculos[i].getModelo()
            <<" | Placa: "<<veiculos[i].getPlaca()
            <<" | Localizacao: "<<locais[i].getEndereco()
            <<"Disponibilidade: "<<veiculos[i].getDisponivel()
            <<endl;
        }
    }
    void removerVeiculo(){
        int id;

        cout<<"Digite o [ID] do veiculo a ser removido:\n";
        listaVeiculos();
        cout<<"ID: ";
        cin>>id;
        cin.ignore();

        for(int i=id-1; i<totalVeiculos; i++){
            veiculos[i]=veiculos[i+1];
        }
        totalVeiculos--;

        cout<<"Veiculo removido com sucesso!"<<endl;
    }
};

class Pedido{
private:
    int id;
    char localOrigem[300];
    char localDestino[300];
public:

    Pedido(){
        id=0;
        strcpy(localOrigem, "");
        strcpy(localDestino, "");
    }

    Pedido(int id, const char* localOrigem, const char* localDestino){
        setId(id);
        setOrigem(localOrigem);
        setDestino(localDestino);
    }

    void setID (int id){ this->id=id; }
    void setOrigem (const char* localOrigem){ strcpy(this->localOrigem, localOrigem); }
    void setDestino (const char* localDestino){ strcpy(this->localDestino, localDestino); }

    int getID(){ return id; }
    const char* getOrigem(){ return localOrigem; }
    const char* getDestino(){ return localDestino; }
};

class ManagerPedidos{
private:
    Pedido pedidos[MAX];
    int totalPedidos=0;
public:
    void cadastrarPedido(Local& locais){
        int idPedido=totalPedidos;
        int id_localOrigem;
        int id_localDestino;

        cout<<"Digite o [ID] do local de origem da entrega:\n";
        locais.listaLocais();
        cout<<"ID: ";
        cin>>id_localOrigem;
        cout<<"Digite o [ID] do local de destino da entrega:\n";
        locais.listaLocais();
        cout<<"ID: ";
        cin>>id_localDestino;
        cin.ignore();

        char localOrigem[300];
        char localDestino[300];
        strcpy(localOrigem, locais[id_localOrigem-1].getEndereco());
        strcpy(localDestino, locais[id_localDestino-1].getEndereco());

        pedidos[totalPedidos]=Pedido(idPedido, localOrigem, localDestino);
        totalPedidos++;

        cout<<"Pedido cadastrado com sucesso!"<<endl;
    }
    void atualizarPedido(Local& locais){
        int idPedido;
        int id_tempLocalOrigem;
        int id_tempLocalDestino;

        cout<<"Digite o [ID] do pedido a ser atualizado:\n";
        listaPedidos()
        cout<<"ID: ";
        cin>>idPedido;
        cout<<"Digite o [ID] do novo local de origem da entrega:\n";
        locais.listaLocais();
        cout<<"ID: ";
        cin>>id_tempLocalOrigem;
        cout<<"Digite o [ID] do novo local de destino da entrega:\n";
        locais.listaLocais();
        cout<<"ID: ";
        cin>>id_tempLocalDestino;
        cin.ignore();

        char tempLocalOrigem[300];
        char tempLocalDestino[300];
        strcpy(tempLocalOrigem, locais[id_tempLocalOrigem-1].getEndereco());
        strcpy(tempLocalDestino, locais[id_tempLocalDestino-1].getEndereco());

        pedidos[idPedido-1]=Pedido(idPedido-1, tempLocalOrigem, tempLocalDestino);
    }
    void listaPedidos(){
        for (int i=0; i<totalPedidos; i++){
            cout<<"["<<pedidos[i].getID()<<"]"
            <<" | Origem: "<<pedidos[i].getOrigem()
            <<" | Destino: "<<pedidos[i].getDestino()
            <<endl;
        }
    }
    void removerPedido(){
        int idPedido;

        cout<<"Informe o [ID] do pedido a ser removido:\n";
        listaPedidos();
        cout<<"ID: ";
        cin>>idPedido;
        cin.ignore();

        for (int i=idPedido-1; i<totalPedidos; i++){
            pedidos[i]=pedidos[i+1];
        }
        totalPedidos--;

        cout<<"Pedido removido com sucesso!"<<endl;
    }
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
