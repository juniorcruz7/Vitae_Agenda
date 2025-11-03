#include "AgendamentosModel.h"
#include <string>
#include <iostream>

using namespace std;

AgendamentosModel::AgendamentosModel() {
    data = "";
    horario = "";
    descricao = "";
    id_agendamento = 0;
}

AgendamentosModel::AgendamentosModel(string _data, string _horario, string _descricao, int _id_agendamento) {
    this->data = _data;
    this->horario = _horario;
    this->descricao = _descricao;
    this->id_agendamento = _id_agendamento;
}

AgendamentosModel::~AgendamentosModel() {

}

int AgendamentosModel::pegarId() const {
    return id_agendamento;
}

string AgendamentosModel::pegarData() const {
    return data;
}

string AgendamentosModel::pegarHorario() const {
    return horario;
}

string AgendamentosModel::pegarDescricao() const {
    return descricao;
}

void AgendamentosModel::alterarData(string _data) {
    this->data = _data;
}

void AgendamentosModel::alterarHorario(string _horario) {
    this->horario = _horario;
}

void AgendamentosModel::alterarDescricao(string _descricao) {
    this->descricao = _descricao;
}
