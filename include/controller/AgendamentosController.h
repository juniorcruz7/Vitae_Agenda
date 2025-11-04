#pragma once
#include "model/AgendamentosModel.h"
#include "BaseController.h"
#include <string>
#include <vector>

using namespace std;

// Controlador concreto que implementa a lógica para Agendamentos.
class AgendamentosController : public ControllerBase<AgendamentosModel> {

private:
    vector<AgendamentosModel> agendamentos; // Armazenamento dos dados em memória
    int proximo_id; // Contador local (parece ser duplicado da classe base)

public:
    AgendamentosController() = default;

    // Métodos obrigatórios (override) herdados de ControllerBase
    void cadastrar(AgendamentosModel& item) override;
    void editar(int id, AgendamentosModel& itemEditado); // Função de edição
    void deletar(int id) override;
    AgendamentosModel buscar(int id) override;
    vector<AgendamentosModel> listar() override;

    // Método auxiliar (helper) para a View criar um agendamento
    void criar_agendamento(string& nomeCliente, string& data, const string& horario, const string& descricao);
};