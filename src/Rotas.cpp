#include "Rotas.h"
#include "Validador.h"
#include "ManagerLocais.h"
#include "ManagerVeiculos.h"
#include "ManagerPedidos.h"
#include "Pedido.h"
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
using namespace std;

//Calcula Distância Euclidiana
double Rotas::calcularDistancia(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

//Simulador de Entrega
void Rotas::simularEntrega(ManagerLocais& gerLocais, ManagerVeiculos& gerVeiculos, ManagerPedidos& gerPedidos){
    int idPedido;

    //Exibe e retorna se não houver pedidos cadastrados
    if(gerPedidos.getTotalPedidos()==0){
        gerPedidos.listaPedidos();
        return;
    }

    cout<<"\nDigite o [ID] do pedido a ser entregue:\n";
    gerPedidos.listaPedidos();

    //Validador: entrada não numérica
    idPedido = Validador::lerInteiro("\nID: ", 1, gerPedidos.getTotalPedidos());

    Pedido pedido = gerPedidos.getPedidoByID(idPedido);

    const char* origemEndereco = pedido.getOrigem();
    const char* destinoEndereco = pedido.getDestino();

    //Pega ID pelo Endereço
    int idOrigem = gerLocais.getIDporEndereco(origemEndereco);
    int idDestino = gerLocais.getIDporEndereco(destinoEndereco);

    //Exibe e retorna se não encontrar o ID de Origem ou Destino
    if (idOrigem == -1 || idDestino == -1) {
    cout << "Origem ou destino nao encontrado nos locais cadastrados.\n";
    return;
}

    //Pega coordenadas por ID
    double origemX = gerLocais.getCoordenadaXporID(idOrigem);
    double origemY = gerLocais.getCoordenadaYporID(idOrigem);
    double destinoX = gerLocais.getCoordenadaXporID(idDestino);
    double destinoY = gerLocais.getCoordenadaYporID(idDestino);

    int idMelhorVeiculo = -1;
    double menorDistancia = std::numeric_limits<double>::max(); //Inicializa menorDistancia com um número grande
    double velocidade = 30.0; //Inicializa Velocidade como 30km/h para padrão

    //Encontra veículo disponível mais próximo da origem
    for (int i=0; i<gerVeiculos.getTotalVeiculos(); i++){
        if (gerVeiculos.getVeiculo(i).getDisponivel()){
            const char* localVeiculo = gerVeiculos.getVeiculo(i).getLocalAtual(); //Pega a localização atual
            int idLocalVeiculo = gerLocais.getIDporEndereco(localVeiculo); //Pega ID da localização atual do veículo

            //Pega as coordenadas através do ID
            double veiculoX = gerLocais.getCoordenadaXporID(idLocalVeiculo);
            double veiculoY = gerLocais.getCoordenadaYporID(idLocalVeiculo);

            //Calcula distancia do veículo até a origem
            double distanciaAteOrigem = calcularDistancia(veiculoX, veiculoY, origemX, origemY);
            //Compara com a atual menor distância
            if(distanciaAteOrigem < menorDistancia){
                menorDistancia=distanciaAteOrigem;
                idMelhorVeiculo=i;
            }
        }
    }

    //Exibe e retorna se não houver veículos disponíveis
    if(idMelhorVeiculo==-1){
        cout<<"Nenhum veiculo disponivel no momento.\n";
        return;
    }

    //Calcula distância da origem até o destino
    double distanciaEntrega = calcularDistancia(origemX, origemY, destinoX, destinoY);

    //Exibe simulação
    cout<<"\n===ENTREGA:===\n";
    cout<<"Veiculo escolhido: "
    <<gerVeiculos.getVeiculo(idMelhorVeiculo).getMarca()<<" "<<gerVeiculos.getVeiculo(idMelhorVeiculo).getModelo()
    <<" - Placa: "<<gerVeiculos.getVeiculo(idMelhorVeiculo).getPlaca()<<endl;
    cout << fixed << setprecision(2);
    cout<<"Distancia ate o local de origem: "<<menorDistancia<<" km\n";
    cout<<"Distancia da entrega (origem -> destino): "<<distanciaEntrega<<"km\n";
    cout<<"Tempo estimado da entrega: "<<(distanciaEntrega/velocidade)*60<<" minutos\n";

    gerVeiculos.getVeiculo(idMelhorVeiculo).setLocalAtual(destinoEndereco); //Atualiza localização atual do veículo utilizado
    gerVeiculos.getVeiculo(idMelhorVeiculo).setDisponivel(false); //Indisponibiliza o veículo utilizado
}
