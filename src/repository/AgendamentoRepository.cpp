#include "repository/AgendamentosRepository.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <stdexcept>

using namespace std;

AgendamentosRepository::AgendamentosRepository(const string& nomeArquivo)
    : BaseRepository<AgendamentosModel>(nomeArquivo) // inicializa a base
{
    listar();
}


void AgendamentosRepository::garantirArquivo() {
    if (!filesystem::exists("data")) {
        filesystem::create_directory("data");
    }
    if (!filesystem::exists(arquivo)) {
        ofstream out(arquivo);
        out.close();
    }
}

void AgendamentosRepository::salvar(AgendamentosModel& agendamento) {
    garantirArquivo();
    if (agendamento.pegar_id_agendamento() == 0) { 
        agendamento.definirId(++proximo_id);       
    }

    ofstream out(arquivo, ios::app);    
    out << agendamento.pegar_id_agendamento() << ","
        << agendamento.pegar_data() << ","
        << agendamento.pegar_horario() << ","
        << agendamento.pegar_descricao() << "\n";
    out.close();
}

vector<AgendamentosModel> AgendamentosRepository::listar() {
    garantirArquivo();
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

        if (!idStr.empty()) {
            int id = stoi(idStr);
            if (id > proximo_id) proximo_id = id; 
            lista.emplace_back(data, horario, descricao, id);
        }
    }
    return lista;
}

AgendamentosModel AgendamentosRepository::buscarId(int id) {
    garantirArquivo();
    vector<AgendamentosModel> lista = listar();
    for (const auto& a : lista) {
        if (a.pegar_id_agendamento() == id) {
            return a;
        }
    }
    throw runtime_error("Agendamento com o ID informado não encontrado.");
}

void AgendamentosRepository::deletar(int id) {
    garantirArquivo();
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

void AgendamentosRepository::editar(int id, const AgendamentosModel& agendamento) {
    vector<AgendamentosModel> lista = listar();
    ofstream out(arquivo, ios::trunc);

    for (auto& a : lista) {
        if (a.pegar_id_agendamento() == id) {
            out << id << "," 
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
