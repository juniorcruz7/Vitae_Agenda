#include "view/TelaAgendamentos.h"
#include "view/TelaInicial.h"
#include "controller/AgendamentosController.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

AgendamentosController controlador;

void TelaAgendamentos::exibirMenu() {
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

        cout << "Opcao: ";
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

void TelaAgendamentos::telaCadastro() {
    system("cls");
    string nome, cpf, op;

    cout << "----- CADASTRO DE AGENDAMENTOS -----\n\n";
    cout << "Digite o nome do cliente: \n";
    getline(cin,nome);
    cout << "\nDigite o CPF do cliente: \n";
    getline(cin,cpf);
    
    //controlador.criar_agendamento();

    cout << "Realizar outro cadastro?\n";
    cout << "[1] Sim\n";
    cout << "[0] Não\n";

    cout << "Opcao: ";
    getline(cin, op);

    if (op == "1") {
        telaCadastro();
    } else if (op == "2") {
        exibirMenu();
    };
}

void TelaAgendamentos::telaListagem() {
    // Implementacao da tela de listagem de agendamentos
}

void TelaAgendamentos::telaEditar() {
    // Implementacao da tela de edicao de agendamentos
}

void TelaAgendamentos::telaDeletar() {
    // Implementacao da tela de delecao de agendamentos
}