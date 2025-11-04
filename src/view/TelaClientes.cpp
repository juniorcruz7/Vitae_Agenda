#include "view/TelaClientes.h"
#include "view/TelaInicial.h"
#include "controller/ClientesController.h"
#include "model/ClientesModel.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

<<<<<<< HEAD
ClientesController controlador;


=======
// Instância do controlador para esta tela
ClientesController controladorClientes;

// Função principal que exibe o menu e gerencia a navegação
>>>>>>> agenda
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

<<<<<<< HEAD
        cout << "[0] Voltar\n";

        cout << "Opcao: ";
        getline(cin, op);

=======
        cout << "\nOpcao: ";
        getline(cin, op); // Captura a opção do usuário

        // Navega para a tela correspondente
>>>>>>> agenda
        if (op == "1") {
            telaCadastro();
        } else if (op == "2") {
            telaListagem();
        } else if (op == "3") {
            telaEditar();
        } else if (op == "4") {
            telaDeletar();
        } else if (op == "0") {
<<<<<<< HEAD
            telainicial.exibirMenu();
=======
            telainicial.exibirMenu(); // Volta para a tela anterior
>>>>>>> agenda
        }

    } while (!fim);
}

<<<<<<< HEAD
=======
// Tela de cadastro de novos clientes
>>>>>>> agenda
void TelaClientes::telaCadastro() {
    system("cls");
    string nome, cpf, op;

    cout << "----- CADASTRO DE CLIENTES -----\n\n";
<<<<<<< HEAD
    cout << "Digite o nome do cliente: \n";
    getline(cin,nome);
    cout << "\nDigite o CPF do cliente: \n";
    getline(cin,cpf);
    
    controlador.cadastrarCliente(nome,cpf);

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

void TelaClientes::telaListagem() {
    system("cls");
    vector <ClientesModel> vetor = controlador.listarCliente();
    string op;
    
    cout << "----- CLIENTES CADASTRADOS -----\n\n";

    for (const auto& lista : vetor) {
        cout << "ID: " << lista.pegarId() << ", Nome: " << lista.pegarNome() << ", CPF: " << lista.pegarCpf() << "\n";
    }

    cout << "[0] Voltar\n";

    cout << "Opcao: ";
    getline(cin, op);

    if (op == "0") {
        exibirMenu();
    }
}

=======
    
    // Coleta os dados do usuário
    cout << "Digite o nome completo do cliente: ";
    getline(cin,nome);
    cout << "Digite o CPF do cliente: ";
    getline(cin,cpf);
    
    // Envia os dados para o controlador criar o cliente
    controladorClientes.cadastrarCliente(nome,cpf);
    cout << "\nCliente cadastrado com sucesso!\n";
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
>>>>>>> agenda
void TelaClientes::telaDeletar() {
    system("cls");
    string id, op;

    cout << "----- DELETAR CLIENTES -----\n\n";
<<<<<<< HEAD
    cout << "Digite o ID de quem você deseja deletar: \n";

    getline(cin, id);

    int _id = stoi(id);
    auto cliente = controlador.buscarID(_id);

    cout << "\nDeletar: ";
    cout << "ID: " << cliente.pegarId() << ", Nome: " << cliente.pegarNome() << ", CPF: " << cliente.pegarCpf() << "?\n";
    
    cout << "[1] Sim\n";
    cout << "[2] Não\n";

    cout << "Opcao: ";
    getline(cin, op);

    if (op == "1") {
        controlador.deletarCliente(_id);
        cout << "Cliente deletado.";
=======
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
>>>>>>> agenda
    } else if (op == "2") {
        exibirMenu();
    }
}

<<<<<<< HEAD
=======
// Tela de edição de clientes
>>>>>>> agenda
void TelaClientes::telaEditar() {
    system("cls");
    string id, op;
    string nome, cpf;

    cout << "----- EDITAR CLIENTES -----\n\n";
<<<<<<< HEAD
    cout << "Digite o ID do cliente que você deseja editar: \n";

    getline(cin, id);
    int _id = stoi(id);
    auto cliente = controlador.buscarID(_id);

    cout << "\nEditar: ";
    cout << "ID: " << cliente.pegarId() << ", Nome: " << cliente.pegarNome() << ", CPF: " << cliente.pegarCpf() << "?\n";

    cout << "[1] Sim\n";
    cout << "[2] Não\n";
    cout << "Opcao: ";

    getline(cin, op);

    cout << "\nNome: ";
    getline(cin, nome);

    cout << "\nCPF: ";
    getline(cin, cpf);

    cliente.alterarNome(nome);
    cliente.alterarCpf(cpf);

    if (op == "1") {
        controlador.editarClientes(_id, cliente);
        cout << "Cliente deletado.";
=======
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
>>>>>>> agenda
    } else if (op == "2") {
        exibirMenu();
    }
}