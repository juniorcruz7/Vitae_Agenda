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
    TelaInicial tela;
    
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
            //Deletar
        default: //Voltar para Tela Inicial
            tela.exibirMenu();
        }

    } while (op =! 0);
}

void TelaClientes::telaCadastro() {
    string nome, cpf;

    system("cls");
    cout << "----- CADASTRO DE CLIENTES -----\n\n";
    cout << "Digite o nome do cliente: \n";
    getline(cin,nome);
    cout << "Digite o CPF do cliente: \n";
    getline(cin,cpf);
    
    controlador.cadastrarCliente(nome,cpf);
}

void TelaClientes::telaListagem() {
    vector <ClientesModel> vetor = controlador.listarCliente();
    for (const auto& lista : vetor) {
        cout << "ID: " << lista.pegarId() << ", Nome: " << lista.pegarNome() << ", CPF: " << lista.pegarCpf() << "\n";
    }
}