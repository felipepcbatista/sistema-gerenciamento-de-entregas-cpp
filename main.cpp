#include <iostream>
#include <cstring>
#include <limits>
#include <fstream>
#include <math.h>
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

    const char* getEnderecoByID(int id){ return locais[id-1].getEndereco(); }
    int getIDporEndereco(const char* endereco){
        for (int i=0; i<totalLocais; i++){
            if(strcmp(endereco, locais[i].getEndereco())==0)
                return i;
        }
    }

    void setTotalLocais(int total){ totalLocais=total; }

    double getCoordenadaXporID(int id){ return locais[id].getCoordenadaX(); }
    double getCoordenadaYporID(int id){ return locais[id].getCoordenadaY(); }
    int getTotalLocais() { return totalLocais; }
    Local* getArrayLocais() { return locais; }
};

class Veiculo{
private:
    char marca[100];
    char modelo[100];
    char placa[8];
    char localAtual[300];
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
    void cadastrarVeiculo(Local& locais, ManagerLocais& gerLocais){
        char marca[100];
        char modelo[100];
        char placa[8];
        int id_localAtual=-1;
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
        strcpy(localAtual, gerLocais.getEnderecoByID(id_localAtual));
        veiculos[totalVeiculos]=Veiculo(marca, modelo, placa, localAtual, disponivel);
        totalVeiculos++;
    }
    void atualizarVeiculo(Local& locais, ManagerLocais& gerLocais){
        char tempMarca[100];
        char tempModelo[100];
        char tempPlaca[8];
        int id;
        int id_tempLocalAtual=-1;
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
        strcpy(tempLocalAtual, gerLocais.getEnderecoByID(id_tempLocalAtual));

        veiculos[id-1]=Veiculo(tempMarca, tempModelo, tempPlaca, tempLocalAtual, tempDisponivel);
    }
    void listaVeiculos(ManagerLocais& locais){
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

    void setTotalVeiculos(int total){ totalVeiculos=total; }

    int getTotalVeiculos(){ return totalVeiculos; }
    Veiculo& getVeiculo(int id){ return veiculos[id]; }
    Veiculo* getArrayVeiculos(){ return veiculos; }
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
    void cadastrarPedido(Local& locais, ManagerLocais& gerLocais){
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
    void atualizarPedido(Local& locais, ManagerLocais& gerLocais){
        int idPedido;
        int id_tempLocalOrigem;
        int id_tempLocalDestino;

        cout<<"Digite o [ID] do pedido a ser atualizado:\n";
        listaPedidos();
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

    void setTotalPedidos(int total){ totalPedidos=total; }

    Pedido getPedidoByID(int id){ return pedidos[id-1]; }
    int getTotalPedidos() { return totalPedidos; }
    Pedido* getArrayPedidos(){ return pedidos; }
};

class Rotas{
private:
    double calcularDistancia(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    }
public:

    void simularEntrega(ManagerLocais& locais, ManagerVeiculos& veiculos, ManagerPedidos& pedidos){
        int idPedido;
        cout<<"ID do pedido: ";
        cin>>idPedido;

        Pedido pedido = pedidos.getPedidoByID(idPedido);

        const char* origemEndereco = pedido.getOrigem();
        const char* destinoEndereco = pedido.getDestino();

        int idOrigem = locais.getIDporEndereco(origemEndereco);
        int idDestino = locais.getIDporEndereco(destinoEndereco);

        double origemX = locais.getCoordenadaXporID(idOrigem);
        double origemY = locais.getCoordenadaYporID(idOrigem);
        double destinoX = locais.getCoordenadaXporID(idDestino);
        double destinoY = locais.getCoordenadaYporID(idDestino);

        int idMelhorVeiculo = -1;
        double menorDistancia = std::numeric_limits<double>::max();

        for (int i=0; i<veiculos.getTotalVeiculos(); i++){
            if (veiculos.getVeiculo(i).getDisponivel()){
                const char* localVeiculo = veiculos.getVeiculo(i).getLocalAtual();
                int idLocalVeiculo = locais.getIDporEndereco(localVeiculo);

                double veiculoX = locais.getCoordenadaXporID(idLocalVeiculo);
                double veiculoY = locais.getCoordenadaYporID(idLocalVeiculo);

                double distanciaAteOrigem = calcularDistancia(veiculoX, veiculoY, origemX, origemY);
                if(distanciaAteOrigem < menorDistancia){
                    menorDistancia=distanciaAteOrigem;
                    idMelhorVeiculo=i;
                }
            }
        }

        double distanciaEntrega = calcularDistancia(origemX, origemY, destinoX, destinoY);

        cout<<"ENTREGA:\n";
        cout<<"Veiculo escolhido: [ "<<idMelhorVeiculo+1<< "] "
        <<veiculos.getVeiculo(idMelhorVeiculo).getMarca()<<" "<<veiculos.getVeiculo(idMelhorVeiculo).getModelo()
        <<" - Placa: "<<veiculos.getVeiculo(idMelhorVeiculo).getPlaca()<<endl;
        cout<<"Distancia ate o local de origem: "<<menorDistancia<<" km\n";
        cout<<"Distancia da entrega (origem -> destino): "<<distanciaEntrega<<"km\n";
        cout<<"Tempo estimado da entrega: "<<(distanciaEntrega/30)*60<<" minutos\n";

        veiculos.getVeiculo(idMelhorVeiculo).setLocalAtual(destinoEndereco);
        veiculos.getVeiculo(idMelhorVeiculo).setDisponivel(false);
    }
};

class Data{
public:

    void salvarLocais(ManagerLocais& gerLocais){
        ofstream out("locais.dat", ios::binary);
        if(!out){
            cout<<"Erro ao abrir arquivo para backup de locais.\n";
            return;
        }
        int total = gerLocais.getTotalLocais();
        out.write((char*)&total, sizeof(total));
        out.write((char*)gerLocais.getArrayLocais(), sizeof(Local)*total);
        out.close();
        cout<<"Backup de locais concluido com sucesso.\n";
    }

    void carregarLocais(ManagerLocais& gerLocais){
        ifstream in("locais.dat", ios::binary);
        if(!in){
            cout<<"Nenhum backup de locais encontrado.\n";
            return;
        }
        int total;
        in.read((char*)&total, sizeof(total));
        in.read((char*)gerLocais.getArrayLocais(), sizeof(Local)*total);
        gerLocais.setTotalLocais(total);
        in.close();
        cout<<"Locais restaurados do backup com sucesso.\n";
    }

    void salvarVeiculos(ManagerVeiculos& gerVeiculos){
        ofstream out("veiculos.dat", ios::binary);
        if(!out){
            cout<<"Erro ao abrir arquivo para backup de veiculos.\n";
            return;
        }
        int total = gerVeiculos.getTotalVeiculos();
        out.write((char*)&total, sizeof(total));
        out.write((char*)gerVeiculos.getArrayVeiculos(), sizeof(Veiculo)*total);
        out.close();
        cout<<"Backup de veiculos concluido com sucesso.\n";
    }

    void carregarVeiculos(ManagerVeiculos& gerVeiculos){
        ifstream in("veiculos.dat", ios::binary);
        if(!in){
            cout<<"Nenhum backup de veiculos encontrado.\n";
            return;
        }
        int total;
        in.read((char*)&total, sizeof(total));
        in.read((char*)gerVeiculos.getArrayVeiculos(), sizeof(Veiculo)*total);
        gerVeiculos.setTotalVeiculos(total);
        in.close();
        cout<<"Veiculos restaurados do backup com sucesso.\n";
    }

    void salvarPedidos(ManagerPedidos& gerPedidos){
        ofstream out("pedidos.dat", ios::binary);
        if(!out){
            cout<<"Erro ao abrir arquivo para backup de pedidos.\n";
            return;
        }
        int total = gerPedidos.getTotalPedidos();
        out.write((char*)&total, sizeof(total));
        out.write((char*)gerPedidos.getArrayPedidos(), sizeof(Pedido)*total);
        out.close();
        cout<<"Backup de pedidos concluido com sucesso.\n";
    }
};

int main()
{
    //Main vai aqui
}
