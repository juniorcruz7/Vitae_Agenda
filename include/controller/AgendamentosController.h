#pragma once
<<<<<<< HEAD

#include "../model//AgendamentosModel.h"
=======
#include "model/AgendamentosModel.h"
#include "BaseController.h"
>>>>>>> agenda
#include <string>
#include <vector>

using namespace std;

<<<<<<< HEAD
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
=======
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
>>>>>>> agenda
