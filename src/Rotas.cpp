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

double Rotas::calcularDistancia(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

void Rotas::simularEntrega(ManagerLocais& gerLocais, ManagerVeiculos& gerVeiculos, ManagerPedidos& gerPedidos){
    int idPedido;
    cout<<"\nDigite o [ID] do pedido a ser entregue:\n";
    gerPedidos.listaPedidos();
    idPedido = Validador::lerInteiro("\nID: ", 1, gerPedidos.getTotalPedidos());

    Pedido pedido = gerPedidos.getPedidoByID(idPedido);

    const char* origemEndereco = pedido.getOrigem();
    const char* destinoEndereco = pedido.getDestino();

    int idOrigem = gerLocais.getIDporEndereco(origemEndereco);
    int idDestino = gerLocais.getIDporEndereco(destinoEndereco);

    if (idOrigem == -1 || idDestino == -1) {
    cout << "Origem ou destino nao encontrado nos locais cadastrados.\n";
    return;
}

    double origemX = gerLocais.getCoordenadaXporID(idOrigem);
    double origemY = gerLocais.getCoordenadaYporID(idOrigem);
    double destinoX = gerLocais.getCoordenadaXporID(idDestino);
    double destinoY = gerLocais.getCoordenadaYporID(idDestino);

    int idMelhorVeiculo = -1;
    double menorDistancia = std::numeric_limits<double>::max();
    double velocidade = 30.0;

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
        cout<<"Nenhum veiculo disponivel no momento.\n";
        return;
    }

    double distanciaEntrega = calcularDistancia(origemX, origemY, destinoX, destinoY);

    cout<<"\n===ENTREGA:===\n";
    cout<<"Veiculo escolhido: "
    <<gerVeiculos.getVeiculo(idMelhorVeiculo).getMarca()<<" "<<gerVeiculos.getVeiculo(idMelhorVeiculo).getModelo()
    <<" - Placa: "<<gerVeiculos.getVeiculo(idMelhorVeiculo).getPlaca()<<endl;
    cout << fixed << setprecision(2);
    cout<<"Distancia ate o local de origem: "<<menorDistancia<<" km\n";
    cout<<"Distancia da entrega (origem -> destino): "<<distanciaEntrega<<"km\n";
    cout<<"Tempo estimado da entrega: "<<(distanciaEntrega/velocidade)*60<<" minutos\n";

    gerVeiculos.getVeiculo(idMelhorVeiculo).setLocalAtual(destinoEndereco);
    gerVeiculos.getVeiculo(idMelhorVeiculo).setDisponivel(false);
}
