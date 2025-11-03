#include "view/_TelaClientes.h"
#include "view/_TelaInicial.h"
#include "controller/ClientesController.h"
#include "model/ClientesModel.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ClientesController controlador;


void _TelaClientes::exibirMenu() {
    string op;
    _TelaInicial telainicial;
    bool fim = false;

    do {
        system("cls");

        cout << "----- CLIENTES -----\n\n";
        cout << "[1] Cadastrar Clientes\n";
        cout << "[2] Listar    Clientes\n";
        cout << "[3] Editar    Clientes\n";
        cout << "[4] Deletar   Clientes\n\n";

        cout << "[0] Voltar\n";

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

void _TelaClientes::telaCadastro() {
    system("cls");
    string nome, cpf;
    string op;

    cout << "----- CADASTRO DE CLIENTES -----\n\n";
    cout << "Digite o nome do cliente: \n";
    getline(cin,nome);
    cout << "\nDigite o CPF do cliente: \n";
    getline(cin,cpf);
    
    controlador.cadastrarCliente(nome,cpf);

    cout << "Realizar outro cadastro?\n";
    cout << "[1] Sim\n";
    cout << "[2] Não\n";

    getline(cin, op);

    if (op == "1") {
        telaCadastro();
    } else if (op == "2") {
        exibirMenu();
    };
}

void _TelaClientes::telaListagem() {
    system("cls");
    vector <ClientesModel> vetor = controlador.listar();
    string op;
    
    cout << "----- CLIENTES CADASTRADOS -----\n\n";

    for (const auto& lista : vetor) {
        cout << "ID: " << lista.pegarId() << ", Nome: " << lista.pegarNome() << ", CPF: " << lista.pegarCpf() << "\n";
    }

    cout << "[0] Voltar\n";
    getline(cin, op);

    if (op == "0") {
        exibirMenu();
    }
}

void _TelaClientes::telaDeletar() {
    system("cls");
    string id, op;

    cout << "----- DELETAR CLIENTES -----\n\n";
    cout << "Digite o ID de quem você deseja deletar: \n";

    getline(cin, id);

    int _id = stoi(id);
    auto cliente = controlador.buscarID(_id);

    cout << "\nDeletar: ";
    cout << "ID: " << cliente.pegarId() << ", Nome: " << cliente.pegarNome() << ", CPF: " << cliente.pegarCpf() << "?\n";
    
    cout << "[1] Sim\n";
    cout << "[2] Não\n";

    getline(cin, op);

    if (op == "1") {
        controlador.deletar(_id);
        cout << "Cliente deletado.";
    } else if (op == "2") {
        exibirMenu();
    }
}

void _TelaClientes::telaEditar() {
    system("cls");
    string id, op;
    string nome, cpf;

    cout << "----- EDITAR CLIENTES -----\n\n";
    cout << "Digite o ID do cliente que você deseja editar: \n";

    getline(cin, id);
    int _id = stoi(id);
    auto cliente = controlador.buscarID(_id);

    cout << "\nEditar: ";
    cout << "ID: " << cliente.pegarId() << ", Nome: " << cliente.pegarNome() << ", CPF: " << cliente.pegarCpf() << "?\n";

    cout << "[1] Sim\n";
    cout << "[2] Não\n";

    getline(cin, op);

    cout << "Nome: ";
    getline(cin, nome);

    cout << "\nCPF: ";
    getline(cin, cpf);

    cliente.alterarNome(nome);
    cliente.alterarCpf(cpf);

    if (op == "1") {
        controlador.editar(_id, cliente);
        cout << "Cliente deletado.";
    } else if (op == "2") {
        exibirMenu();
    }
}