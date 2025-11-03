#include "view/TelaAgendamentos.h"
#include "view/TelaInicial.h"
#include "controller/AgendamentosController.h"
#include "model/AgendamentosModel.h"
#include "repository/AgendamentosRepository.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

AgendamentosController controladorAgendamentos;

void TelaAgendamentos::exibirMenu() {
    string op;
    TelaInicial telaInicial;
    bool fim = false;

    do {
        system("cls");

        cout << "----- AGENDAMENTOS -----\n\n";
        cout << "[1] Cadastrar Agendamento\n";
        cout << "[2] Listar    Agendamentos\n";
        cout << "[3] Editar    Agendamento\n";
        cout << "[4] Deletar   Agendamento\n\n";
        
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
            telaInicial.exibirMenu();
        }

    } while (!fim);
}

void TelaAgendamentos::telaCadastro() {
    system("cls");
    string data, horario, descricao;
    string op;

    cout << "----- CADASTRO DE AGENDAMENTO -----\n\n";
    cout << "Digite a data do agendamento: ";
    getline(cin, data);
    cout << "Digite o horario: ";
    getline(cin, horario);
    cout << "Digite a descricao: ";
    getline(cin, descricao);

    // Chamando o método específico do controller
    controladorAgendamentos.criar_agendamento(data, horario, descricao);

    cout << "\nRealizar outro agendamento?\n";
    cout << "[1] Sim\n[2] Nao\n";

    cout << "\nOpcao: ";
    getline(cin, op);

    if (op == "1") {
        telaCadastro();
    } else if (op == "2") {
        exibirMenu();
    }
}

void TelaAgendamentos::telaListagem() {
    system("cls");
    vector<AgendamentosModel> vetor = controladorAgendamentos.listar();
    string op;

    cout << "----- AGENDAMENTOS CADASTRADOS -----\n\n";

    for (const auto& agendamento : vetor) {
        cout << "ID: " << agendamento.pegar_id_agendamento()
             << ", Data: " << agendamento.pegar_data()
             << ", Horário: " << agendamento.pegar_horario()
             << ", Descrição: " << agendamento.pegar_descricao() << "\n";
    }

    system("pause");
    exibirMenu();
}

void TelaAgendamentos::telaDeletar() {
    system("cls");
    string id, op;

    cout << "----- DELETAR AGENDAMENTO -----\n\n";
    cout << "Digite o ID do agendamento que deseja deletar: ";
    getline(cin, id);
    int _id = stoi(id);

    auto agendamento = controladorAgendamentos.buscar(_id);

    cout << "\nDeletar: "
         << "ID: " << agendamento.pegar_id_agendamento()
         << ", Data: " << agendamento.pegar_data()
         << ", Horário: " << agendamento.pegar_horario()
         << ", Descrição: " << agendamento.pegar_descricao() << "?\n\n";

    cout << "[1] Sim\n[2] Nao\n";

    cout << "\nOpcao: ";
    getline(cin, op);

    if (op == "1") {
        controladorAgendamentos.deletar(_id);
        cout << "Agendamento deletado.";
    } else if (op == "2") {
        exibirMenu();
    }
}

void TelaAgendamentos::telaEditar() {
    system("cls");
    string id, op;
    string data, horario, descricao;

    cout << "----- EDITAR AGENDAMENTO -----\n\n";
    cout << "Digite o ID do agendamento que deseja editar: ";
    getline(cin, id);
    int _id = stoi(id);

    auto agendamento = controladorAgendamentos.buscar(_id);

    cout << "\nEditar: "
         << "ID: " << agendamento.pegar_id_agendamento()
         << ", Data: " << agendamento.pegar_data()
         << ", Horário: " << agendamento.pegar_horario()
         << ", Descrição: " << agendamento.pegar_descricao() << "?\n\n";

    cout << "[1] Sim\n[2] Nao\n";

    cout << "\nOpcao: ";
    getline(cin, op);

    if (op == "1") {
        cout << "Nova data: ";
        getline(cin, data);
        cout << "Novo horário: ";
        getline(cin, horario);
        cout << "Nova descrição: ";
        getline(cin, descricao);

        agendamento.alterar_data(data);
        agendamento.alterar_horario(horario);
        agendamento.alterar_descricao(descricao);

        controladorAgendamentos.editar(_id, agendamento);
        cout << "Agendamento editado.\n\n";
        system("pause");
        exibirMenu();
    } else {
        exibirMenu();
    }
}
