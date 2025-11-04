#pragma once
#include "BaseRepository.h"
#include "model/AgendamentosModel.h"
#include <vector>
#include <string>

using namespace std;

// Repositório concreto para Agendamentos, herda de BaseRepository.
// Gerencia o acesso aos dados (leitura/escrita) de AgendamentosModel.
class AgendamentosRepository : public BaseRepository <AgendamentosModel> {
private:
    int proximo_id; // Contador de ID
    vector <AgendamentosModel> agendamentos; // Cache dos agendamentos em memória

public:
    AgendamentosRepository(); // Construtor

    // --- Métodos obrigatórios (override) da BaseRepository ---
    void garantirArquivo() override; // Verifica se o arquivo de dados existe
    void salvar(AgendamentosModel& agendamento) override; // Salva um novo agendamento
    void editar(int id, AgendamentosModel& agendamento); // Edita um agendamento (não está na base?)
    void deletar(int id) override; // Deleta um agendamento
    AgendamentosModel buscarId(int id) override; // Busca um agendamento
    vector <AgendamentosModel> listar() override; // Lista todos os agendamentos
};