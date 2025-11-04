#include "controller/AgendamentosController.h"
#include "repository/AgendamentosRepository.h" // Inclui o repositório para interagir com os dados
#include "model/ClientesModel.h"
#include <vector>
#include <string>

using namespace std;

// Instância do repositório que o controlador usará para acessar os dados
AgendamentosRepository repoAgendamento;

// --- Implementação dos métodos da interface ---
// (Note: 'override' está faltando aqui, mas estava no .h)

// Passa o item para o repositório salvar
void AgendamentosController::cadastrar(AgendamentosModel& item) {
    repoAgendamento.salvar(item);
}

// Passa a edição para o repositório
void AgendamentosController::editar(int id, AgendamentosModel& itemEditado) {
    repoAgendamento.editar(id, itemEditado);
}

// Passa a deleção para o repositório
void AgendamentosController::deletar(int id) {
    repoAgendamento.deletar(id);
}

// Pede ao repositório para buscar um item
AgendamentosModel AgendamentosController::buscar(int id) {
    return repoAgendamento.buscarId(id);
}

// Pede ao repositório a lista completa
std::vector<AgendamentosModel> AgendamentosController::listar() {
    return repoAgendamento.listar();
}

// --- Método auxiliar ---
// Método chamado pela View para simplificar a criação de um agendamento
void AgendamentosController::criar_agendamento(string& nomeCliente, std::string& data, const std::string& horario, const std::string& descricao) {
    //