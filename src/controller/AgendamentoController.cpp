#include "include/controller/AgendamentosController.h"
#include "include/repository/AgendamentosRepository.h"
#include <vector>
#include <string>

AgendamentosRepository repositorio;

void AgendamentosController::cadastrar(AgendamentosModel& item) {
    repositorio.salvar(item);
}

void AgendamentosController::editar(int id, const AgendamentosModel& itemEditado) {
    repositorio.editar(id, itemEditado);
}

void AgendamentosController::deletar(int id) {
    repositorio.deletar(id);
}

AgendamentosModel AgendamentosController::buscar(int id) {
    return repositorio.buscarId(id);
}

std::vector<AgendamentosModel> AgendamentosController::listar() {
    return repositorio.listar();
}

// Método específico
void AgendamentosController::criar_agendamento(const std::string& data, const std::string& horario, const std::string& descricao) {
    AgendamentosModel a(data, horario, descricao, proximo_id);
    cadastrar(a);
}
