#pragma once
#include <string>
#include <iostream>
#include "model/ClientesModel.h" // Dependência (embora não pareça usada nos membros)

using namespace std;

// Classe Model: representa a entidade 'Agendamento'.
class AgendamentosModel
{

private:
    string data, horario, descricao, nomeCliente; // Dados do agendamento

public:
    // O ID é público, o que é incomum (geralmente é privado com getters/setters)
    int id_agendamento;

    // Construtor padrão
    AgendamentosModel() : nomeCliente(""), data(""), horario(""), descricao(""), id_agendamento(0) {}
    // Construtor para preencher todos os dados
    AgendamentosModel(string nomeCliente, string data, string horario, string descricao, int id_agendamento) : nomeCliente(nomeCliente), data(data), horario(horario), descricao(descricao), id_agendamento(id_agendamento) {};
    ~AgendamentosModel(); // Destrutor (definição provavelmente está no .cpp)

    // --- Getters (Métodos de acesso) ---
    int pegar_id_agendamento() const;
    string pegar_data() const;
    string pegar_horario() const;
    string pegar_descricao() const;
    string pegar_cliente();

    // --- Setters (Métodos de modificação) ---
    void alterar_data(string data);
    void alterar_horario(string horario);
    void alterar_descricao(string descricao);
    void definirId(int novoId) { id_agendamento = novoId; } // Setter inline
    int pegarId() const { return id_agendamento; } // Getter inline
};
