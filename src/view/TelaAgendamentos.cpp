#include "view/TelaAgendamentos.h"
#include "view/TelaInicial.h"
#include "controller/AgendamentosController.h"
#include "model/AgendamentosModel.h"
#include "repository/AgendamentosRepository.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Instância do controlador para esta tela
AgendamentosController controladorAgendamentos;

// Função principal que exibe o menu e gerencia a navegação
void TelaAgendamentos::exibirMenu() {
    string op;
    TelaInicial telaInicial;
    bool fim = false;

    // Loop principal do menu
    do {
        system("cls"); // Limpa a tela

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
        if (op == "1") {
            telaCadastro();
        } else if (op == "2") {
            telaListagem();
        } else if (op == "3") {
            telaEditar();
        } else if (op == "4") {
            telaDeletar();
        } else if (op == "0") {
            telaInicial.exibirMenu(); // Volta para a tela anterior
        }

    } while (!fim);
}

// Tela de cadastro de novos agendamentos
void TelaAgendamentos::telaCadastro() {
    system("cls");
    string data, horario, descricao, op;

    cout << "----- CADASTRO DE AGENDAMENTO -----\n\n";
    
    // Coleta os dados do usuário
    cout << "Digite a data do agendamento: ";
    getline(cin, data);
    cout << "Digite o horario: ";
    getline(cin, horario);
    cout << "Digite a descricao: ";
    getline(cin, descricao);

    // Envia os dados para o controlador criar o agendamento
    controladorAgendamentos.criar_agendamento(data, horario, descricao);

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

// Tela que lista todos os agendamentos
void TelaAgendamentos::telaListagem() {
    system("cls");
    
    // Busca o vetor de agendamentos no controlador
    vector<AgendamentosModel> vetor = controladorAgendamentos.listar();

    cout << "----- AGENDAMENTOS CADASTRADOS -----\n\n";

    // Itera pelo vetor e imprime cada agendamento
    for (const auto& agendamento : vetor) {
        cout << "ID: " << agendamento.pegar_id_agendamento()
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

    // Busca o agendamento para confirmar a deleção
    auto agendamento = controladorAgendamentos.buscar(_id);

    // Exibe os dados e pede confirmação
    cout << "\nDeletar: "
         << "ID: " << agendamento.pegar_id_agendamento()
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

// Tela de edição de agendamentos
void TelaAgendamentos::telaEditar() {
    system("cls");
    string id, op;
    string data, horario, descricao;

    cout << "----- EDITAR AGENDAMENTO -----\n\n";
    cout << "Digite o ID do agendamento que deseja editar: ";
    getline(cin, id);
    int _id = stoi(id); // Converte ID para inteiro

    // Busca o agendamento original
    auto agendamento = controladorAgendamentos.buscar(_id);

    // Mostra o agendamento e pede confirmação
    cout << "\nEditar: "
         << "ID: " << agendamento.pegar_id_agendamento()
         << ", Data: " << agendamento.pegar_data()
         << ", Horário: " << agendamento.pegar_horario()
         << ", Descrição: " << agendamento.pegar_descricao() << "?\n\n";

    cout << "[1] Sim\n[2] Nao\n";
    cout << "\nOpcao: ";
    getline(cin, op);

    if (op == "1") {
        // Pede os novos dados
        cout << "\nDigite os novos dados do agendamento:\n";
        cout << "Nova data: ";
        getline(cin, data);
        cout << "Novo horário: ";
        getline(cin, horario);
        cout << "Nova descrição: ";
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