#pragma once
#include <string>
#include <iostream>

using namespace std;

class AgendamentosModel {

private:

    static int id_agendamento;
    string data, horario, descricao;

public:

    AgendamentosModel();
    AgendamentosModel(string data, string horario, string descricao, int id_agendamento);
    ~AgendamentosModel();

    static int pegar_id_agendamento();
    string pegar_data() const;
    string pegar_horario() const;
    string pegar_descricao() const;

    void alterar_data(string data);
    void alterar_horario(string horario);
    void alterar_descricao(string descricao);
    void definirId(int novoId) { id_agendamento = novoId; }

};