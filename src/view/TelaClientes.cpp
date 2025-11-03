#include "view/TelaClientes.h"
#include "view/TelaInicial.h"
#include "controller/ClientesController.h"
#include "model/ClientesModel.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ClientesController controladorClientes;


void TelaClientes::exibirMenu() {
    string op;
    TelaInicial telainicial;
    bool fim = false;

    do {
        system("cls");

        cout << "----- CLIENTES -----\n\n";
        cout << "[1] Cadastrar Clientes\n";
        cout << "[2] Listar    Clientes\n";
        cout << "[3] Editar    Clientes\n";
        cout << "[4] Deletar   Clientes\n\n";

        cout << "[0] Voltar\n";

        cout << "\nOpcao: ";
        getline(cin, op);

        if (op == "1") {
            telaCadastro();
        } else if (op == "2") {
            telaListagem();
        } else if (op == "3") {
            telaEditar();
        } else if (op == "4") {
            telaDeletar();
        } else if (op == "0") {
            telainicial.exibirMenu();
        }

    } while (!fim);
}

void TelaClientes::telaCadastro() {
    system("cls");
    string nome, cpf;
    string op;

    cout << "----- CADASTRO DE CLIENTES -----\n\n";
    cout << "Digite o nome do cliente: ";
    getline(cin,nome);
    cout << "Digite o CPF do cliente: ";
    getline(cin,cpf);
    
    controladorClientes.cadastrarCliente(nome,cpf);

    cout << "\nRealizar outro cadastro?\n";
    cout << "[1] Sim\n";
    cout << "[2] Nao\n";

    cout << "\nOpcao: ";
    getline(cin, op);

    if (op == "1") {
        telaCadastro();
    } else if (op == "2") {
        exibirMenu();
    };
}

void TelaClientes::telaListagem() {
    system("cls");
    vector <ClientesModel> vetor = controladorClientes.listar();
    string op;
    
    cout << "----- CLIENTES CADASTRADOS -----\n\n";

    for (const auto& lista : vetor) {
        cout << "ID: " << lista.pegarId() 
             << ", Nome: " << lista.pegarNome() 
             << ", CPF: " << lista.pegarCpf() << "\n\n";
    }
    system("pause");
    exibirMenu();
}

void TelaClientes::telaDeletar() {
    system("cls");
    string id, op;

    cout << "----- DELETAR CLIENTES -----\n\n";
    cout << "Digite o ID de quem voce deseja deletar: \n";

    getline(cin, id);

    int _id = stoi(id);

    if (_id > ClientesModel::pegarNumClientes()) {
        cout << "\nID inexistente. Tente novamente.\n\n";
        system("pause");
        telaDeletar();
        return;
    }

    auto cliente = controladorClientes.buscarID(_id);

    cout << "\nDeletar: ";
    cout << "ID: " << cliente.pegarId() 
         << ", Nome: " << cliente.pegarNome() 
         << ", CPF: " << cliente.pegarCpf() << "?\n\n";
    
    cout << "[1] Sim\n";
    cout << "[2] Nao\n";

    cout << "\nOpcao: ";
    getline(cin, op);

    if (op == "1") {
        controladorClientes.deletar(_id);
        cout << "Cliente deletado.\n\n";
        system("pause");
        exibirMenu();
    } else if (op == "2") {
        exibirMenu();
    }
}

void TelaClientes::telaEditar() {
    system("cls");
    string id, op;
    string nome, cpf;

    cout << "----- EDITAR CLIENTES -----\n\n";
    cout << "Digite o ID do cliente que voce deseja editar: \n";

    getline(cin, id);

    int _id = stoi(id);

    if (_id > ClientesModel::pegarNumClientes()) {
        cout << "\nID inexistente. Tente novamente.\n\n";
        system("pause");
        telaEditar();
        return;
    }

    auto cliente = controladorClientes.buscarID(_id);

    cout << "\nEditar: ";
    cout << "ID: " << cliente.pegarId() 
         << ", Nome: " << cliente.pegarNome() 
         << ", CPF: " << cliente.pegarCpf() << " ?\n";

    cout << "[1] Sim\n";
    cout << "[2] Nao\n";

    cout << "\nOpcao: ";
    getline(cin, op);

    if (op == "1") {
        cout << "\nDigite os novos dados do cliente:\n";
        cout << "\nNome: ";
        getline(cin, nome);

        cout << "\nCPF: ";
        getline(cin, cpf);

        cliente.alterarNome(nome);
        cliente.alterarCpf(cpf);

        controladorClientes.editar(_id, cliente);
        cout << "\nCliente editado.\n\n";
        system("pause");
        exibirMenu();
    } else if (op == "2") {
        exibirMenu();
    }
}