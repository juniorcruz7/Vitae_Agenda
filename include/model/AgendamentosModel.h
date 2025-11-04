#pragma once
#include <string>
#include <iostream>
#include "model/ClientesModel.h"

using namespace std;

class AgendamentosModel
{

private:
    string data, horario, descricao, nomeCliente;

public:
    int id_agendamento;

    AgendamentosModel() : nomeCliente(""), data(""), horario(""), descricao(""), id_agendamento(0) {}
    AgendamentosModel(string nomeCliente, string data, string horario, string descricao, int id_agendamento) : nomeCliente(nomeCliente), data(data), horario(horario), descricao(descricao), id_agendamento(id_agendamento) {};
    ~AgendamentosModel();

    int pegar_id_agendamento() const;
    string pegar_data() const;
    string pegar_horario() const;
    string pegar_descricao() const;

    void alterar_data(string data);
    void alterar_horario(string horario);
    void alterar_descricao(string descricao);
    void definirId(int novoId) { id_agendamento = novoId; }
    int pegarId() const { return id_agendamento; }
    string pegar_cliente();
};