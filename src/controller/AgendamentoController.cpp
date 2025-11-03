#include "controller/AgendamentosController.h"
#include "repository/AgendamentosRepository.h"
#include <vector>
#include <string>

AgendamentosRepository repoAgendamento;

void AgendamentosController::cadastrar(AgendamentosModel& item) {
    repoAgendamento.salvar(item);
}

void AgendamentosController::editar(int id, const AgendamentosModel& itemEditado) {
    repoAgendamento.editar(id, itemEditado);
}

void AgendamentosController::deletar(int id) {
    repoAgendamento.deletar(id);
}

AgendamentosModel AgendamentosController::buscar(int id) {
    return repoAgendamento.buscarId(id);
}

std::vector<AgendamentosModel> AgendamentosController::listar() {
    return repoAgendamento.listar();
}

// Método específico
void AgendamentosController::criar_agendamento(const std::string& data, const std::string& horario, const std::string& descricao) {
    AgendamentosModel a(data, horario, descricao, 0);
    cadastrar(a);
}
