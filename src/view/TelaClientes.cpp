#include "include/view/TelaClientes.h"
#include "include/view/TelaInicial.h"
#include "include/controller/ClientesController.h"
#include "include/model/ClientesModel.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ClientesController controlador;

void TelaClientes::exibirMenu() {
    int op;
    
    do {
        system("cls");

        cout << "----- CLIENTES -----\n\n";
        cout << "[1] Cadastrar Clientes\n";
        cout << "[2] Listar    Clientes\n";
        cout << "[3] Editar    Clientes\n";
        cout << "[4] Deletar   Clientes\n\n";

        cout << "[0] Voltar";

        cin >> op;

        switch (op)
        {
        case 1:
            telaCadastro();
        case 2:
            telaListagem();
        case 3:
            //Editar
        case 4:
            telaDeletar();
        default: //Voltar para Tela Inicial
            exibirMenu();
        }

    } while (op =! 0);
}

void TelaClientes::telaCadastro() {
    system("cls");
    string nome, cpf;
    int op;

    cout << "----- CADASTRO DE CLIENTES -----\n\n";
    cout << "Digite o nome do cliente: \n";
    getline(cin,nome);
    cout << "Digite o CPF do cliente: \n";
    getline(cin,cpf);
    
    controlador.cadastrarCliente(nome,cpf);

    cout << "Realizar outro cadastro?\n";
    cout << "[1] Sim\n";
    cout << "[2] Não\n";

    cin >> op;

    if (op == 1) {
        telaCadastro();
    } else if (op == 2) {
        exibirMenu();
    };
}

void TelaClientes::telaListagem() {
    system("cls");
    vector <ClientesModel> vetor = controlador.listarCliente();
    int op;
    
    cout << "----- CLIENTES CADASTRADOS -----\n\n";

    for (const auto& lista : vetor) {
        cout << "ID: " << lista.pegarId() << ", Nome: " << lista.pegarNome() << ", CPF: " << lista.pegarCpf() << "\n";
    }

    cout << "[0] Voltar";
    cin >> op;

    if (op == 0) {
        exibirMenu();
    }
}

void TelaClientes::telaDeletar() {
    system("cls");
    int id;
    int op;

    cout << "----- DELETAR CLIENTES -----\n\n";
    cout << "Digite o ID de quem você deseja deletar: \n";

    cin >> id;
    auto cliente = controlador.buscarID(id);

    cout << "\nCerteza que deseja deletar: ";
    cout << "ID: " << cliente.pegarId() << ", Nome: " << cliente.pegarNome() << ", CPF: " << cliente.pegarCpf() << "\n";
    
    cout << "[1] Sim";
    cout << "[2] Não";

    if (op == 1) {
        controlador.deletarCliente(id);
        cout << "Cliente deletado.";
    } else if (op == 2) {
        exibirMenu();
    }
}