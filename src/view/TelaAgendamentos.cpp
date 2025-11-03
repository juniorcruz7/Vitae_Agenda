#include "view/TelaAgendamentos.h"
#include "view/TelaInicial.h"
#include "controller/AgendamentosController.h"
#include "model/AgendamentosModel.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

AgendamentosController controlador_agendamento;

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
            break;
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
    cout << "Digite o horário: ";
    getline(cin, horario);
    cout << "Digite a descrição: ";
    getline(cin, descricao);

    // Chamando o método específico do controller
    controlador_agendamento.criar_agendamento(data, horario, descricao);

    cout << "Realizar outro cadastro?\n";
    cout << "[1] Sim\n[2] Não\n";
    getline(cin, op);

    if (op == "1") {
        telaCadastro();
    } else {
        exibirMenu();
    }
}

void TelaAgendamentos::telaListagem() {
    system("cls");
    vector<AgendamentosModel> vetor = controlador_agendamento.listar();
    string op;

    cout << "----- AGENDAMENTOS CADASTRADOS -----\n\n";

    for (const auto& agendamento : vetor) {
        cout << "ID: " << agendamento.pegar_id_agendamento()
             << ", Data: " << agendamento.pegar_data()
             << ", Horário: " << agendamento.pegar_horario()
             << ", Descrição: " << agendamento.pegar_descricao() << "\n";
    }

    cout << "[0] Voltar\n";
    getline(cin, op);

    if (op == "0") {
        exibirMenu();
    }
}

void TelaAgendamentos::telaDeletar() {
    system("cls");
    string id, op;

    cout << "----- DELETAR AGENDAMENTO -----\n\n";
    cout << "Digite o ID do agendamento que deseja deletar: ";
    getline(cin, id);
    int _id = stoi(id);
    auto agendamento = controlador_agendamento.buscar(_id);

    cout << "\nDeletar: "
         << "ID: " << agendamento.pegar_id_agendamento()
         << ", Data: " << agendamento.pegar_data()
         << ", Horário: " << agendamento.pegar_horario()
         << ", Descrição: " << agendamento.pegar_descricao() << "?\n";

    cout << "[1] Sim\n[2] Não\n";
    getline(cin, op);

    if (op == "1") {
        controlador_agendamento.deletar(_id);
        cout << "Agendamento deletado.";
    } else {
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
    auto agendamento = controlador_agendamento.buscar(_id);

    cout << "\nEditar: "
         << "ID: " << agendamento.pegar_id_agendamento()
         << ", Data: " << agendamento.pegar_data()
         << ", Horário: " << agendamento.pegar_horario()
         << ", Descrição: " << agendamento.pegar_descricao() << "?\n";

    cout << "[1] Sim\n[2] Não\n";
    getline(cin, op);

    cout << "Nova data: ";
    getline(cin, data);
    cout << "Novo horário: ";
    getline(cin, horario);
    cout << "Nova descrição: ";
    getline(cin, descricao);

    agendamento.alterar_data(data);
    agendamento.alterar_horario(horario);
    agendamento.alterar_descricao(descricao);

    if (op == "1") {
        controlador_agendamento.editar(_id, agendamento);
        cout << "Agendamento editado.";
    } else {
        exibirMenu();
    }
}
