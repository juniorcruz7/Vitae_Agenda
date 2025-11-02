#pragma once

#include "model/AgendamentoModel.h"
#include <string>
#include <vector>

using namespace std;

class AgendamentosController {

private:
    vector<AgendamentosModel> agendamentos;
    int proximo_id;

public:

    AgendamentosController();

    void criar_agendamento(const string& data, const string& horario, const string& descricao);
    void listar_agendamentos() const;
    void remover_agendamentos(int id);
    void editar_agendamentos(int id, const string& nova_data, const string& novo_horario, const string& nova_descricao);

};