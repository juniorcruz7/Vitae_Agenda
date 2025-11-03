#pragma once
#include <string>
#include <iostream>

using namespace std;

class AgendamentosModel {

private:

    int id_agendamento;
    string data, horario, descricao;

public:

    AgendamentosModel();
    AgendamentosModel(string _data, string _horario, string _descricao, int _id_agendamento);
    ~AgendamentosModel();

    int pegarId() const;
    string pegarData() const;
    string pegarHorario() const;
    string pegarDescricao() const;

    void alterarData(string data);
    void alterarHorario(string horario);
    void alterarDescricao(string descricao);

};
