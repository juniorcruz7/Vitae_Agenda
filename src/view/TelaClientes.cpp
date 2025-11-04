#include "view/TelaClientes.h"
#include "view/TelaInicial.h"
#include "controller/ClientesController.h"
#include "model/ClientesModel.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Instância do controlador para esta tela
ClientesController controladorClientes;

// Função principal que exibe o menu e gerencia a navegação
void TelaClientes::exibirMenu() {
    string op;
    TelaInicial telainicial;
    bool fim = false;

    // Loop principal do menu
    do {
        system("cls"); // Limpa a tela

        // Exibe as opções
        cout << "----- CLIENTES -----\n\n";
        cout << "[1] Cadastrar \tClientes\n";
        cout << "[2] Listar \tClientes\n";
        cout << "[3] Editar \tClientes\n";
        cout << "[4] Deletar \tClientes\n\n";
        cout << "[0] Voltar\n";

        cout << "\nOpcao: ";
        getline(cin, op); // Captura a opção do usuário

        // Navega para a tela correspondente
        if (op == "1") {
            telaCadastro();
        } else if (op == "2") {
            telaListagem();
        } else if (op == "3") {
            telaEditar();
        } else if (op == "4") {
            telaDeletar();
        } else if (op == "0") {
            telainicial.exibirMenu(); // Volta para a tela anterior
        }

    } while (!fim);
}

// Tela de cadastro de novos clientes
void TelaClientes::telaCadastro() {
    system("cls");
    string nome, cpf, op;

    cout << "----- CADASTRO DE CLIENTES -----\n\n";
    
    // Coleta os dados do usuário
    cout << "Digite o nome do cliente: ";
    getline(cin,nome);
    cout << "Digite o CPF do cliente: ";
    getline(cin,cpf);
    
    // Envia os dados para o controlador criar o cliente
    controladorClientes.cadastrarCliente(nome,cpf);

    // Pergunta se deseja cadastrar outro
    cout << "\nRealizar outro cadastro?\n";
    cout << "[1] Sim\n[2] Nao\n";
    cout << "\nOpcao: ";
    getline(cin, op);

    if (op == "1") {
        telaCadastro(); // Chama a função novamente (recursão)
    } else if (op == "2") {
        exibirMenu(); // Volta ao menu
    };
}

// Tela que lista todos os clientes
void TelaClientes::telaListagem() {
    system("cls");

    // Busca o vetor de clientes no controlador
    vector <ClientesModel> vetor = controladorClientes.listar();
    
    cout << "----- CLIENTES CADASTRADOS -----\n\n";

    // Itera pelo vetor e imprime cada cliente
    for (const auto& lista : vetor) {
        cout << "ID: " << lista.pegarId() 
             << ", Nome: " << lista.pegarNome() 
             << ", CPF: " << lista.pegarCpf() << "\n";
    }

    cout << "\n";
    system("pause"); // Pausa para o usuário ler
    exibirMenu();
}

// Tela de deleção de clientes
void TelaClientes::telaDeletar() {
    system("cls");
    string id, op;

    cout << "----- DELETAR CLIENTES -----\n\n";
    cout << "Digite o ID de quem voce deseja deletar: ";
    getline(cin, id);

    int _id = stoi(id); // Converte a string (ID) para inteiro

    // Validação de ID (lógica específica desta tela)
    if (_id > ClientesModel::pegarNumClientes()) {
        cout << "\nID inexistente. Tente novamente.\n\n";
        system("pause");
        telaDeletar(); // Reinicia a função
        return;
    }

    // Busca o cliente para confirmar a deleção
    auto cliente = controladorClientes.buscarID(_id);

    // Exibe os dados e pede confirmação
    cout << "\nDeletar: "
         << "ID: " << cliente.pegarId() 
         << ", Nome: " << cliente.pegarNome() 
         << ", CPF: " << cliente.pegarCpf() << "?\n\n";
    
    cout << "[1] Sim\n[2] Nao\n";
    cout << "\nOpcao: ";
    getline(cin, op);

    if (op == "1") {
        // Envia o ID para o controlador deletar
        controladorClientes.deletar(_id);
        cout << "Cliente deletado.\n\n";
        system("pause");
        exibirMenu();
    } else if (op == "2") {
        exibirMenu();
    }
}

// Tela de edição de clientes
void TelaClientes::telaEditar() {
    system("cls");
    string id, op;
    string nome, cpf;

    cout << "----- EDITAR CLIENTES -----\n\n";
    cout << "Digite o ID do cliente que voce deseja editar: ";
    getline(cin, id);

    int _id = stoi(id); // Converte ID para inteiro

    // Validação de ID (lógica específica desta tela)
    if (_id > ClientesModel::pegarNumClientes()) {
        cout << "\nID inexistente. Tente novamente.\n\n";
        system("pause");
        telaEditar(); // Reinicia a função
        return;
    }

    // Busca o cliente original
    auto cliente = controladorClientes.buscarID(_id);

    // Mostra o cliente e pede confirmação
    cout << "\nEditar: "
         << "ID: " << cliente.pegarId() 
         << ", Nome: " << cliente.pegarNome() 
         << ", CPF: " << cliente.pegarCpf() << "?\n\n";

    cout << "[1] Sim\n[2] Nao\n";
    cout << "\nOpcao: ";
    getline(cin, op);

    if (op == "1") {
        // Pede os novos dados
        cout << "\nDigite os novos dados do cliente:\n";
        cout << "Nome: ";
        getline(cin, nome);
        cout << "CPF: ";
        getline(cin, cpf);

        // Atualiza o objeto local
        cliente.alterarNome(nome);
        cliente.alterarCpf(cpf);

        // Envia o ID e o objeto modificado para o controlador
        controladorClientes.editar(_id, cliente);
        
        cout << "\nCliente editado.\n\n";
        system("pause");
        exibirMenu();
    } else if (op == "2") {
        exibirMenu();
    }
}