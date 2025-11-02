#include "include/repository/AgendamentosRepository.h"
#include <fstream>
#include <sstream>

using namespace std;

AgendamentosRepository::AgendamentosRepository(string nomeArquivo) {
    arquivo = nomeArquivo;
}

void AgendamentosRepository::salvar(const AgendamentosModel& agendamento) {
    ofstream out(arquivo, ios::app);
    out << agendamento.pegar_id_agendamento() << ","
        << agendamento.pegar_data() << ","
        << agendamento.pegar_horario() << ","
        << agendamento.pegar_descricao() << "\n";
}

vector<AgendamentosModel> AgendamentosRepository::listar() const {
    vector<AgendamentosModel> lista;
    ifstream in(arquivo);
    string linha;

    while (getline(in, linha)) {
        stringstream ss(linha);
        string idStr, data, horario, descricao;

        getline(ss, idStr, ',');
        getline(ss, data, ',');
        getline(ss, horario, ',');
        getline(ss, descricao, ',');

        if (!idStr.empty())
            lista.emplace_back(data, horario, descricao, stoi(idStr));
    }

    return lista;
}

void AgendamentosRepository::remover(int id) {
    vector<AgendamentosModel> lista = listar();
    ofstream out(arquivo, ios::trunc); 

    for (const auto& a : lista) {
        if (a.pegar_id_agendamento() != id) {
            out << a.pegar_id_agendamento() << ","
                << a.pegar_data() << ","
                << a.pegar_horario() << ","
                << a.pegar_descricao() << "\n";
        }
    }
}

void AgendamentosRepository::editar(const AgendamentosModel& agendamento) {
    vector<AgendamentosModel> lista = listar();
    ofstream out(arquivo, ios::trunc);

    for (auto& a : lista) {
        if (a.pegar_id_agendamento() == agendamento.pegar_id_agendamento()) {
            out << agendamento.pegar_id_agendamento() << ","
                << agendamento.pegar_data() << ","
                << agendamento.pegar_horario() << ","
                << agendamento.pegar_descricao() << "\n";
        } else {
            out << a.pegar_id_agendamento() << ","
                << a.pegar_data() << ","
                << a.pegar_horario() << ","
                << a.pegar_descricao() << "\n";
        }
    }
}
