#include <iostream>
#include <cstring>
#include <limits>
#include <fstream>
#include <cmath>
#include <cctype>
#define MAX 100
using namespace std;

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

    const char* getEndereco()const{ return endereco; }
    double getCoordenadaX()const{ return coordenadaX; }
    double getCoordenadaY()const{ return coordenadaY; }
};

class ManagerLocais{
private:
    Local locais[MAX];
    int totalLocais=0;
public:
    void cadastrarLocal(){
        if(totalLocais>=MAX){
            cout<<"Limite de locais cadastrados atingido.\n";
            return;
        }

        char endereco[300];
        double coordenadaX;
        double coordenadaY;

        cout<<"Endereco do local: ";
        cin.getline(endereco, 300);
        if(!Validador::stringNaoVazia(endereco)){
            cout<<"Endereco invalido.\n";
            return;
        }
        for (int i=0; i<totalLocais; i++){
            if(strcmp(endereco, locais[i].getEndereco())==0){
                cout<<"Este endereco ja esta cadastrado.\n";
                return;
            }
        }

        cout<<"Coordenadas:\n";
        cout<<"X: ";
        cin>>coordenadaX;
        if(!Validador::entradaNumerica(coordenadaX)){
            Validador::limparEntrada();
            cout<<"Coordenada invalida.\n";
            return;
        }
        cout<<"Y: ";
        cin>>coordenadaY;
        if(!Validador::entradaNumerica(coordenadaY)){
            Validador::limparEntrada();
            cout<<"Coordenada invalida.\n";
            return;
        }
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
        if(!Validador::entradaNumerica(id) || !Validador::idValido(id, totalLocais)){
            Validador::limparEntrada();
            cout<<"ID invalido. Local nao encontrado.\n";
            return;
        }
        cin.ignore();
        cout<<"Novo endereco: ";
        cin.getline(tempEndereco, 300);
        if(!Validador::stringNaoVazia(tempEndereco)){
            cout<<"Endereco invalido.\n";
            return;
        }
        cout<<"Novas coordenadas:\n";
        cout<<"X: ";
        cin>>tempCoordenadaX;
        if(!Validador::entradaNumerica(tempCoordenadaX)){
            Validador::limparEntrada();
            cout<<"Coordenada invalida.\n";
            return;
        }
        cout<<"Y: ";
        cin>>tempCoordenadaY;
        if(!Validador::entradaNumerica(tempCoordenadaY)){
            Validador::limparEntrada();
            cout<<"Coordenada invalida.\n";
            return;
        }
        cin.ignore();

        locais[id-1]=Local(tempEndereco, tempCoordenadaX, tempCoordenadaY);

        cout<<"Local atualizado com sucesso!"<<endl;
    }
    void listaLocais(){
        if(totalLocais==0){
            cout<<"Nenhum local cadastrado.\n";
            return;
        }

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
        if(!Validador::entradaNumerica(id) || !Validador::idValido(id, totalLocais)){
            Validador::limparEntrada();
            cout<<"ID invalido. Local nao encontrado.\n";
            return;
        }
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
        return -1;
    }

    void setTotalLocais(int total){ totalLocais=total; }

    double getCoordenadaXporID(int id)const{ return locais[id].getCoordenadaX(); }
    double getCoordenadaYporID(int id)const{ return locais[id].getCoordenadaY(); }
    int getTotalLocais()const{ return totalLocais; }
    Local* getArrayLocais()const{ return locais; }
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
        strcpy(localAtual, "");
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

    const char* getMarca()const{ return marca; }
    const char* getModelo()const{ return modelo; }
    const char* getPlaca()const{ return placa; }
    const char* getLocalAtual()const{ return localAtual; }
    bool getDisponivel()const{ return disponivel; }
};

class ManagerVeiculos{
private:
    Veiculo veiculos[MAX];
    int totalVeiculos=0;
public:
    void cadastrarVeiculo(ManagerLocais& gerLocais){
        if(totalVeiculos>=MAX){
            cout<<"Limite de veiculos cadastrados atingido.\n";
            return;
        }

        char marca[100];
        char modelo[100];
        char placa[8];
        int id_localAtual;
        bool disponivel=true;

        cout<<"Digite o ID da localizacao atual do veiculo:\n";
        gerLocais.listaLocais();
        cout<<"ID: ";
        cin>>id_localAtual;
        if(!Validador::idValido(id, gerLocais.getTotalLocais())){
            Validador::limparEntrada();
            cout<<"ID invalido. Local nao encontrado.\n";
            return;
        }
        cin.ignore();
        cout<<"Marca do veiculo: ";
        cin.getline(marca, 100);
        if(!Validador::stringNaoVazia(marca)){
            cout<<"Marca invalida.\n";
            return;
        }
        cout<<"Modelo do veiculo: ";
        cin.getline(modelo, 100);
        if(!Validador::stringNaoVazia(modelo)){
            cout<<"Modelo invalida.\n";
            return;
        }
        cout<<"Placa do veiculo(7 caracteres): ";
        cin.getline(placa, 8);
        if(!Validador::placaValida(placa)){
            Validador::limparEntrada();
            cout<<"Placa invalida. Deve conter exatamente 7 caracteres.\n";
            return;
        }

        char localAtual[300];
        strcpy(localAtual, gerLocais.getEnderecoByID(id_localAtual));
        veiculos[totalVeiculos]=Veiculo(marca, modelo, placa, localAtual, disponivel);
        totalVeiculos++;
    }
    void atualizarVeiculo(ManagerLocais& gerLocais){
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
        if(!Validador::entradaNumerica(id) || !Validador::idValido(id, totalVeiculos)){
            Validador::limparEntrada();
            cout<<"ID invalido. Veiculo nao encontrado.\n";
            return;
        }
        cin.ignore();
        cout<<"Nova marca do veiculo: ";
        cin.getline(tempMarca, 100);
        if(!Validador::stringNaoVazia(tempMarca)){
            cout<<"Marca invalida.\n";
            return;
        }
        cout<<"Novo modelo do veiculo: ";
        cin.getline(tempModelo, 100);
        if(!Validador::stringNaoVazia(tempModelo)){
            cout<<"Modelo invalido.\n";
            return;
        }
        cout<<"Nova placa do veiculo: ";
        cin.getline(tempPlaca, 8);
        if(!Validador::stringNaoVazia(tempPlaca) || !Validador::placaValida(tempPlaca)){
            cout<<"Placa invalida. Deve conter exatamente 7 caracteres.\n";
            return;
        }
        cout<<"Digite o [ID] da nova localizacao do veiculo:\n";
        gerLocais.listaLocais();
        cout<<"ID: ";
        cin>>id_tempLocalAtual;
        if(!Validador::idValido(id_tempLocalAtual, gerLocais.getTotalLocais())){
            Validador::limparEntrada();
            cout<<"ID invalido.\n";
            return;
        }

        char tempLocalAtual[300];
        strcpy(tempLocalAtual, gerLocais.getEnderecoByID(id_tempLocalAtual));

        veiculos[id-1]=Veiculo(tempMarca, tempModelo, tempPlaca, tempLocalAtual, tempDisponivel);
    }
    void listaVeiculos(){
        if(totalVeiculos==0){
            cout<<"Nenhum veiculo cadastrado.\n";
            return;
        }

        for (int i=0; i<totalVeiculos; i++){
            cout<<"["<<i+1<<"]"
            <<" | Marca: "<<veiculos[i].getMarca()
            <<" | Modelo: "<<veiculos[i].getModelo()
            <<" | Placa: "<<veiculos[i].getPlaca()
            <<" | Localizacao: "<<veiculos[i].getLocalAtual()
            <<" | Disponibilidade: "<<veiculos[i].getDisponivel()
            <<endl;
        }
    }
    void removerVeiculo(){
        int id;

        cout<<"Digite o [ID] do veiculo a ser removido:\n";
        listaVeiculos();
        cout<<"ID: ";
        cin>>id;
        if(!Validador::idValido(id)){
            Validador::limparEntrada();
            cout<<"ID invalido.\n";
            return;
        }
        cin.ignore();

        for(int i=id-1; i<totalVeiculos-1; i++){
            veiculos[i]=veiculos[i+1];
        }
        totalVeiculos--;

        cout<<"Veiculo removido com sucesso!"<<endl;
    }

    void setTotalVeiculos(int total){ totalVeiculos=total; }

    int getTotalVeiculos()const{ return totalVeiculos; }
    Veiculo& getVeiculo(int id)const{ return veiculos[id]; }
    Veiculo* getArrayVeiculos()const{ return veiculos; }
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
        setID(id);
        setOrigem(localOrigem);
        setDestino(localDestino);
    }

    void setID (int id){ this->id=id; }
    void setOrigem (const char* localOrigem){ strcpy(this->localOrigem, localOrigem); }
    void setDestino (const char* localDestino){ strcpy(this->localDestino, localDestino); }

    int getID()const{ return id; }
    const char* getOrigem()const{ return localOrigem; }
    const char* getDestino()const{ return localDestino; }
};

class ManagerPedidos{
private:
    Pedido pedidos[MAX];
    int totalPedidos=0;
public:
    void cadastrarPedido(ManagerLocais& gerLocais){
        if(totalPedidos>=MAX){
            cout<<"Limite de pedidos cadastrados atingido.\n";
            return;
        }

        int idPedido=totalPedidos;
        int id_localOrigem;
        int id_localDestino;

        cout<<"Digite o [ID] do local de origem da entrega:\n";
        gerLocais.listaLocais();
        cout<<"ID: ";
        cin>>id_localOrigem;
        if(!Validador::idValido(id_localOrigem, gerLocais.getTotalLocais())){
            Validador::limparEntrada();
            cout<<"ID invalido.\n";
            return;
        }
        cout<<"Digite o [ID] do local de destino da entrega:\n";
        gerLocais.listaLocais();
        cout<<"ID: ";
        cin>>id_localDestino;
        if(!Validador::idValido(id_localDestino, gerLocais.getTotalLocais())){
            Validador::limparEntrada();
            cout<<"ID invalido.\n";
            return;
        }
        cin.ignore();

        char localOrigem[300];
        char localDestino[300];
        strcpy(localOrigem, gerLocais.getEnderecoByID(id_localOrigem));
        strcpy(localDestino, gerLocais.getEnderecoByID(id_localDestino));

        pedidos[totalPedidos]=Pedido(idPedido, localOrigem, localDestino);
        totalPedidos++;

        cout<<"Pedido cadastrado com sucesso!"<<endl;
    }
    void atualizarPedido(ManagerLocais& gerLocais){
        int idPedido;
        int id_tempLocalOrigem;
        int id_tempLocalDestino;

        cout<<"Digite o [ID] do pedido a ser atualizado:\n";
        listaPedidos();
        cout<<"ID: ";
        cin>>idPedido;
        if(!Validador::idValido(idPedido, totalPedidos)){
            Validador::limparEntrada();
            cout<<"ID invalido.\n";
            return;
        }
        cout<<"Digite o [ID] do novo local de origem da entrega:\n";
        gerLocais.listaLocais();
        cout<<"ID: ";
        cin>>id_tempLocalOrigem;
        if(!Validador::idValido(id_tempLocalOrigem, gerLocais.getTotalLocais())){
            Validador::limparEntrada();
            cout<<"ID invalido.\n";
            return;
        }
        cout<<"Digite o [ID] do novo local de destino da entrega:\n";
        gerLocais.listaLocais();
        cout<<"ID: ";
        cin>>id_tempLocalDestino;
        if(!Validador::idValido(id_tempLocalDestino, gerLocais.getTotalLocais())){
            Validador::limparEntrada();
            cout<<"ID invalido.\n";
            return;
        }
        cin.ignore();

        char tempLocalOrigem[300];
        char tempLocalDestino[300];
        strcpy(tempLocalOrigem, gerLocais.getEnderecoByID(id_tempLocalOrigem));
        strcpy(tempLocalDestino, gerLocais.getEnderecoByID(id_tempLocalDestino));

        pedidos[idPedido-1]=Pedido(idPedido-1, tempLocalOrigem, tempLocalDestino);
    }
    void listaPedidos(){
        if(totalPedidos==0){
            cout<<"Nenhum pedido cadastrado.\n";
            return;
        }

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
        if(!Validador::idValido(idPedido, totalPedidos)){
            Validador::limparEntrada();
            cout<<"ID invalido.\n";
            return;
        }
        cin.ignore();

        for (int i=idPedido-1; i<totalPedidos; i++){
            pedidos[i]=pedidos[i+1];
        }
        totalPedidos--;

        cout<<"Pedido removido com sucesso!"<<endl;
    }

    void setTotalPedidos(int total){ totalPedidos=total; }

    Pedido getPedidoByID(int id)const{ return pedidos[id-1]; }
    int getTotalPedidos()const{ return totalPedidos; }
    Pedido* getArrayPedidos()const{ return pedidos; }
};

class Rotas{
private:
    double calcularDistancia(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    }
public:

    void simularEntrega(ManagerLocais& gerLocais, ManagerVeiculos& gerVeiculos, ManagerPedidos& gerPedidos){
        int idPedido;
        cout<<"ID do pedido: ";
        cin>>idPedido;
        if(!Validador::idValido(idPedido, gerPedidos.getTotalPedidos())){
            Validador::limparEntrada();
            cout<<"ID invalido.\n";
            return;
        }

        Pedido pedido = gerPedidos.getPedidoByID(idPedido);

        const char* origemEndereco = pedido.getOrigem();
        const char* destinoEndereco = pedido.getDestino();

        int idOrigem = gerLocais.getIDporEndereco(origemEndereco);
        int idDestino = gerLocais.getIDporEndereco(destinoEndereco);

        double origemX = gerLocais.getCoordenadaXporID(idOrigem);
        double origemY = gerLocais.getCoordenadaYporID(idOrigem);
        double destinoX = gerLocais.getCoordenadaXporID(idDestino);
        double destinoY = gerLocais.getCoordenadaYporID(idDestino);

        int idMelhorVeiculo = -1;
        double menorDistancia = std::numeric_limits<double>::max();

        for (int i=0; i<gerVeiculos.getTotalVeiculos(); i++){
            if (gerVeiculos.getVeiculo(i).getDisponivel()){
                const char* localVeiculo = gerVeiculos.getVeiculo(i).getLocalAtual();
                int idLocalVeiculo = gerLocais.getIDporEndereco(localVeiculo);

                double veiculoX = gerLocais.getCoordenadaXporID(idLocalVeiculo);
                double veiculoY = gerLocais.getCoordenadaYporID(idLocalVeiculo);

                double distanciaAteOrigem = calcularDistancia(veiculoX, veiculoY, origemX, origemY);
                if(distanciaAteOrigem < menorDistancia){
                    menorDistancia=distanciaAteOrigem;
                    idMelhorVeiculo=i;
                }
            }
        }

        if(idMelhorVeiculo==-1){
            cout<<"Nenhnum veiculo disponivel no momento.\n";
            return;
        }

        double distanciaEntrega = calcularDistancia(origemX, origemY, destinoX, destinoY);

        cout<<"ENTREGA:\n";
        cout<<"Veiculo escolhido: [ "<<idMelhorVeiculo+1<< "] "
        <<gerVeiculos.getVeiculo(idMelhorVeiculo).getMarca()<<" "<<gerVeiculos.getVeiculo(idMelhorVeiculo).getModelo()
        <<" - Placa: "<<gerVeiculos.getVeiculo(idMelhorVeiculo).getPlaca()<<endl;
        cout<<"Distancia ate o local de origem: "<<menorDistancia<<" km\n";
        cout<<"Distancia da entrega (origem -> destino): "<<distanciaEntrega<<"km\n";
        cout<<"Tempo estimado da entrega: "<<(distanciaEntrega/30)*60<<" minutos\n";

        gerVeiculos.getVeiculo(idMelhorVeiculo).setLocalAtual(destinoEndereco);
        gerVeiculos.getVeiculo(idMelhorVeiculo).setDisponivel(false);
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

    void carregarPedidos(ManagerPedidos& gerPedidos){
        ifstream in("pedidos.dat", ios::binary);
        if(!in){
            cout<<"Nenhum backup de pedidos encontrado.\n";
            return;
        }
        int total;
        in.read((char*)&total, sizeof(total));
        in.read((char*)gerPedidos.getArrayPedidos(), sizeof(Pedido)*total);
        gerPedidos.setTotalPedidos(total);
        in.close();
        cout<<"Veiculos restaurados do backup com sucesso.\n";
    }
};

class Sistema{
private:
    ManagerLocais gerLocais;
    ManagerVeiculos gerVeiculos;
    ManagerPedidos gerPedidos;
    Rotas simuladorRotas;
    Data persistencia;
public:

    void executar(){
        int opcao;
        do{
            exibirMenu();
            cin>>opcao;
            cin.ignore();
            tratarOpcao(opcao);
        }while(opcao!=0);
    }

    void exibirMenu(){
        cout<<"=====MENU PRINCIPAL=====\n";
        cout<<"[1]Cadastrar Local\n";
        cout<<"[2]Atualizar Local\n";
        cout<<"[3]Remover Local\n";
        cout<<"[4]Listar Locais\n";
        cout<<"[5]Cadastrar Veiculo\n";
        cout<<"[6]Atualizar Veiculo\n";
        cout<<"[7]Remover Veiculo\n";
        cout<<"[8]Listar Veiculos\n";
        cout<<"[9]Cadastrar Pedido\n";
        cout<<"[10]Atualizar Pedido\n";
        cout<<"[11]Remover Pedido\n";
        cout<<"[12]Listar Pedidos\n";
        cout<<"[13]Simular Entrega\n";
        cout<<"[14]Salvar Dados\n";
        cout<<"[15]Carregar Dados\n";
        cout<<"[0]Sair\n";
        cout<<"Escolha uma opcao: ";
    }

    void tratarOpcao(int opc){
        switch(opc){
            case 1: gerLocais.cadastrarLocal();break;
            case 2: gerLocais.atualizarLocal();break;
            case 3: gerLocais.removerLocal();break;
            case 4: gerLocais.listaLocais();break;
            case 5: gerVeiculos.cadastrarVeiculo(gerLocais);break;
            case 6: gerVeiculos.atualizarVeiculo(gerLocais);break;
            case 7: gerVeiculos.removerVeiculo();break;
            case 8: gerVeiculos.listaVeiculos();break;
            case 9: gerPedidos.cadastrarPedido(gerLocais);break;
            case 10: gerPedidos.atualizarPedido(gerLocais);break;
            case 11: gerPedidos.removerPedido();break;
            case 12: gerPedidos.listaPedidos();break;
            case 13: simuladorRotas.simularEntrega(gerLocais, gerVeiculos, gerPedidos);break;
            case 14:
                persistencia.salvarLocais(gerLocais);
                persistencia.salvarVeiculos(gerVeiculos);
                persistencia.salvarPedidos(gerPedidos);
                break;
            case 15:
                persistencia.carregarLocais(gerLocais);
                persistencia.carregarVeiculos(gerVeiculos);
                persistencia.carregarPedidos(gerPedidos);
                break;
            case 0:
                cout<<"Encerrando...\n";
                break;
            default:
                cout<<"Opcao invalida\n";
        }
    }
};

class Validador{
public:

    static int lerInteiro(const char* mensagem, int min, int max){
        int valor;
        while(true){
            cout<<mensagem;
            cin>>valor;
            if(cin.fail() || valor<min || valor >max){
                cout<<"Entrada invalida. Tente um numero entre "<<min" e "<<max<<endl;
                limparEntrada();
            }
            else{
                limparEntrada();
                return valor;
            }
        }
    }

    static double lerDouble(const char* mensagem){
        double valor;
        while(true){
            cout<<mensagem;
            cin>>valor;
            if(cin.fail()){
                cout<<"Entrada invalida. Digite um valor numerico.\n";
                limparEntrada();
            }
            else{
                limparEntrada();
                return valor;
            }
        }
    }

    static bool stringVazia(const char* texto){
        return strlen(texto)==0;
    }

    static bool nomeLocalRepetido(const char* nome, Local locais[], int totalLocais){
        for (int i=0; i<totalLocais; i++){
            if(stricmp(locais[i].getEndereco(), nome)==0){
                return true;
            }
        }
        return false;
    }

    static bool coordenadaRepetida(double x, double y, Local locais, int totalLocais){
        for(int i=0; i<totalLocais; i++){
            if(locais[i].getCoordenadaX()==x && locais[i].getCoordenadaY()==y){
                return true;
            }
        }
        return false;
    }

    static bool placaRepetida(const char* placa, Veiculo veiculos[], int totalVeiculos){
        for (int i=0; i<totalVeiculos; i++){
            if (stricmp(veiculos[i].getPlaca(), placa)==0){
                return true;
            }
        }
        return false;
    }

    static bool idRepetido(int id, Pedido pedidos[], int totalPedidos){
        for(int i=0; i<totalPedidos; i++){
            if(pedidos[i].getID()==id){
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Sistema sistema;
    sistema.executar();
    return 0;
}
