#pragma once

#include "model/AgendamentosModel.h"
#include "BaseController.h"
#include <string>
#include <vector>

using namespace std;

class AgendamentosController : public ControllerBase<AgendamentosModel> {

private:
    vector<AgendamentosModel> agendamentos;
    int proximo_id;


public:
    AgendamentosController() = default;

    void cadastrar(AgendamentosModel& item) override;
    void editar(int id, AgendamentosModel& itemEditado);
    void deletar(int id) override;
    AgendamentosModel buscar(int id) override;
    vector<AgendamentosModel> listar() override;

    void criar_agendamento(string& nomeCliente, string& data, const string& horario, const string& descricao);
};