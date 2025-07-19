#include 'Sistema.h'
#include <iostream>
using namespace std;

Sistema::executar(){
    int opcao;
    do{
        exibirMenu();
        cin>>opcao;
        cin.ignore();
        tratarOpcao(opcao);
    }while(opcao!=0);
}

Sistema::exibirMenu(){
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

Sistema::tratarOpcao(int opc){
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
