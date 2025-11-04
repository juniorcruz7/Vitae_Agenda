#include "view/TelaAgendamentos.h"
#include "view/TelaInicial.h"
#include "controller/AgendamentosController.h"
<<<<<<< HEAD
=======
#include "model/AgendamentosModel.h"
#include "repository/AgendamentosRepository.h"
#include "model/ClientesModel.h"
#include "repository/ClientesRepository.h"
>>>>>>> agenda
#include <iostream>
#include <string>
#include <vector>

using namespace std;

<<<<<<< HEAD
AgendamentosController controlador;

void TelaAgendamentos::exibirMenu() {
    string op;
    TelaInicial telainicial;
=======
// Instância do controlador para esta tela
AgendamentosController controladorAgendamentos;
ClientesRepository repositorioClientes;

// Função principal que exibe o menu e gerencia a navegação
void TelaAgendamentos::exibirMenu() {
    string op;
    TelaInicial telaInicial;
>>>>>>> agenda
    bool fim = false;

    // Loop principal do menu
    do {
        system("cls"); // Limpa a tela

<<<<<<< HEAD
        cout << "----- CLIENTES -----\n\n";
        cout << "[1] Cadastrar Clientes\n";
        cout << "[2] Listar    Clientes\n";
        cout << "[3] Editar    Clientes\n";
        cout << "[4] Deletar   Clientes\n\n";

        cout << "[0] Voltar\n";

        cout << "Opcao: ";
        getline(cin, op);

=======
        // Exibe as opções
        cout << "----- AGENDAMENTOS -----\n\n";
        cout << "[1] Cadastrar \tAgendamento\n";
        cout << "[2] Listar \tAgendamentos\n";
        cout << "[3] Editar \tAgendamento\n";
        cout << "[4] Deletar \tAgendamento\n\n";
        cout << "[0] Voltar\n";

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
            telaInicial.exibirMenu(); // Volta para a tela anterior
>>>>>>> agenda
        }

    } while (!fim);
}

<<<<<<< HEAD
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
=======
// Tela de cadastro de novos agendamentos
void TelaAgendamentos::telaCadastro() {
    system("cls");
    string data, horario, descricao, op, id, nomeCliente;

    cout << "----- CADASTRO DE AGENDAMENTO -----\n\n";
    
    // Coleta os dados do usuário
    cout << "Digita o ID do cliente para o agendamento: ";
    getline(cin, id);

    int _id = stoi(id); 
    if (_id > ClientesModel::pegarNumClientes()) {
        cout << "\nID inexistente. Tente novamente.\n\n";
        system("pause");
        telaCadastro(); // Reinicia a função
        return;
    } else {
        string cliente = repositorioClientes.buscarId(_id).pegarNome();
        cout << "Cliente selecionado: " << cliente << "\n\n";

        cout << "Digite a data do agendamento: ";
        getline(cin, data);
        cout << "Digite o horario: ";
        getline(cin, horario);
        cout << "Digite a descricao: ";
        getline(cin, descricao);

        // Envia os dados para o controlador criar o agendamento
        controladorAgendamentos.criar_agendamento(cliente, data, horario, descricao);
        cout << "\nAgendamento cadastrado com sucesso!\n";
        // Pergunta se deseja cadastrar outro
        cout << "\nRealizar outro agendamento?\n";
        cout << "[1] Sim\n[2] Nao\n";
        cout << "\nOpcao: ";
        getline(cin, op);

        if (op == "1") {
            telaCadastro(); // Chama a função novamente (recursão)
        } else if (op == "2") {
            exibirMenu(); // Volta ao menu
        }
    }
}

// Tela que lista todos os agendamentos
void TelaAgendamentos::telaListagem() {
    system("cls");
    
    // Busca o vetor de agendamentos no controlador
    vector<AgendamentosModel> vetor = controladorAgendamentos.listar();

    cout << "----- AGENDAMENTOS CADASTRADOS -----\n\n";

    // Itera pelo vetor e imprime cada agendamento
    for (auto& agendamento : vetor) {
        cout << "ID: " << agendamento.pegar_id_agendamento()
             << ", Cliente: " << agendamento.pegar_cliente() << ", "    
             << ", Data: " << agendamento.pegar_data()
             << ", Horário: " << agendamento.pegar_horario()
             << ", Descrição: " << agendamento.pegar_descricao() << "\n";
    }

    cout << "\n";
    system("pause"); // Pausa para o usuário ler
    exibirMenu();
}

// Tela de deleção de agendamentos
void TelaAgendamentos::telaDeletar() {
    system("cls");
    string id, op;

    cout << "----- DELETAR AGENDAMENTO -----\n\n";
    cout << "Digite o ID do agendamento que deseja deletar: ";
    getline(cin, id);
    int _id = stoi(id); // Converte a string (ID) para inteiro

    if (_id > controladorAgendamentos.listar().size()) {
        cout << "\nID inexistente. Tente novamente.\n\n";
        system("pause");
        telaDeletar(); // Reinicia a função
        return;
    } else {
        // Busca o agendamento para confirmar a deleção
        auto agendamento = controladorAgendamentos.buscar(_id);

        // Exibe os dados e pede confirmação
        cout << "\nDeletar: "
            << "ID: " << agendamento.pegar_id_agendamento()
            << "Cliente: " << agendamento.pegar_cliente() << ", "
            << ", Data: " << agendamento.pegar_data()
            << ", Horário: " << agendamento.pegar_horario()
            << ", Descrição: " << agendamento.pegar_descricao() << "?\n\n";

        cout << "[1] Sim\n[2] Nao\n";
        cout << "\nOpcao: ";
        getline(cin, op);

        if (op == "1") {
            // Envia o ID para o controlador deletar
            controladorAgendamentos.deletar(_id);
            cout << "Agendamento deletado.\n\n";
            system("pause");
            exibirMenu();
        } else if (op == "2") {
            exibirMenu();
        }
    }
}

// Tela de edição de agendamentos
void TelaAgendamentos::telaEditar() {
    system("cls");
    string id, op;
    string data, horario, descricao;

    cout << "----- EDITAR AGENDAMENTO -----\n\n";
    cout << "Digite o ID do agendamento que deseja editar: ";
    getline(cin, id);
    int _id = stoi(id); // Converte ID para inteiro
    if (_id > controladorAgendamentos.listar().size()) {
        cout << "\nID inexistente. Tente novamente.\n\n";
        system("pause");
        telaEditar(); // Reinicia a função
        return;
    } else {
        // Busca o agendamento original
        auto agendamento = controladorAgendamentos.buscar(_id);

        // Mostra o agendamento e pede confirmação
        cout << "\nEditar: "
            << "ID: " << agendamento.pegar_id_agendamento()
            << ", Data: " << agendamento.pegar_data()
            << ", Horario: " << agendamento.pegar_horario()
            << ", Descricao: " << agendamento.pegar_descricao() << "?\n\n";

        cout << "[1] Sim\n[2] Nao\n";
        cout << "\nOpcao: ";
        getline(cin, op);

        if (op == "1") {
            // Pede os novos dados
            cout << "\nDigite os novos dados do agendamento:\n";
            cout << "Nova data: ";
            getline(cin, data);
            cout << "Novo horario: ";
            getline(cin, horario);
            cout << "Nova descricao: ";
            getline(cin, descricao);

            // Atualiza o objeto local
            agendamento.alterar_data(data);
            agendamento.alterar_horario(horario);
            agendamento.alterar_descricao(descricao);

            // Envia o ID e o objeto modificado para o controlador
            controladorAgendamentos.editar(_id, agendamento);
            
            cout << "Agendamento editado.\n\n";
            system("pause");
            exibirMenu();
        } else {
            exibirMenu();
        }
    }
>>>>>>> agenda
}