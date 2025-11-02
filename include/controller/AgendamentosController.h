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
    void editar(int id, const AgendamentosModel& itemEditado) override;
    void deletar(int id) override;
    AgendamentosModel buscar(int id) override;
    vector<AgendamentosModel> listar() override;

    void criar_agendamento(const std::string& data, const std::string& horario, const std::string& descricao);
};