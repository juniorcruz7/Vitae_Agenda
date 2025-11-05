#include "AgendamentosController.h"
#include <iostream>
#include <vector>

using namespace std;

AgendamentosController::AgendamentosController() {
    proximo_id = 1;
}

void AgendamentosController::criar_agendamento(const string& data, const string& horario, const string& descricao) {
    AgendamentosModel novo(data, horario, descricao, proximo_id++);
    agendamentos.push_back(novo);
}

void AgendamentosController::listar_agendamentos() const {
    for (const auto& agendamento : agendamentos) {
        cout << "ID : " << agendamento.pegar_id_agendamento()
             << " | Data: " << agendamento.pegar_data()
             << " | Horário: " << agendamento.pegar_horario()
             << " | Descrição: " << agendamento.pegar_descricao() << endl;
    }
}

void AgendamentosController::remover_agendamentos(int id) {
    for (auto it = agendamentos.begin(); it != agendamentos.end(); ++it) {
        if (it->pegar_id_agendamento() == id) {
            agendamentos.erase(it);
            break;
        }
    }
}

void AgendamentosController::editar_agendamentos(int id, const string &nova_data, const string &novo_horario, const string &nova_descricao) {
    for (auto& agendamento : agendamentos) {
        if (agendamento.pegar_id_agendamento() == id) {
            agendamento.alterar_data(nova_data);
            agendamento.alterar_horario(novo_horario);
            agendamento.alterar_descricao(nova_descricao);
            break;
        }
    }
}
