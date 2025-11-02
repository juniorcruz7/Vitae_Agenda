#include "model/AgendamentosModel.h"
#include <string>
#include <iostream>

using namespace std;

AgendamentosModel::AgendamentosModel() {
    data = "";
    horario = "";
    descricao = "";
    id_agendamento = 0;
}

AgendamentosModel::AgendamentosModel(string data, string horario, string descricao, int id_agendamento) {
    this->data = data;
    this->horario = horario;
    this->descricao = descricao;
    this->id_agendamento = id_agendamento;
}

AgendamentosModel::~AgendamentosModel() {

}

int AgendamentosModel::pegar_id_agendamento() const {
    return id_agendamento;
}

string AgendamentosModel::pegar_data() const {
    return data;
}

string AgendamentosModel::pegar_horario() const {
    return horario;
}

string AgendamentosModel::pegar_descricao() const {
    return descricao;
}

void AgendamentosModel::alterar_data(string data) {
    this->data = data;
}

void AgendamentosModel::alterar_horario(string horario) {
    this->horario = horario;
}

void AgendamentosModel::alterar_descricao(string descricao) {
    this->descricao = descricao;
}