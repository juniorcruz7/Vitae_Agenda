#pragma once
#include <string>
#include <iostream>

using namespace std;

class AgendamentosModel {

private:
    string data, horario, descricao;

public:
    int id_agendamento;

    AgendamentosModel(): data(""), horario(""), descricao(""), id_agendamento(0) {}
    AgendamentosModel(string data, string horario, string descricao, int id_agendamento):
        data(data), horario(horario), descricao(descricao), id_agendamento(id_agendamento) {};
    ~AgendamentosModel();

    int pegar_id_agendamento() const;
    string pegar_data() const;
    string pegar_horario() const;
    string pegar_descricao() const;

    void alterar_data(string data);
    void alterar_horario(string horario);
    void alterar_descricao(string descricao);
    void definirId(int novoId) { id_agendamento = novoId; }

};