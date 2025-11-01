#include "include/repository/ClientesRepository.h"
#include "include/model/ClientesModel.h"
#include <fstream>
#include <sstream>
#include <filesystem>

using namespace std;

void ClientesRepository::garantirArquivo() {
        if (!filesystem::exists(arquivo)) {
            ofstream out(arquivo);
            out.close();
        }
}

void ClientesRepository::salvar(const ClientesModel& cliente) {
    garantirArquivo();
    ofstream out(arquivo, ios::app);
    out << cliente.pegarId() << "," << cliente.pegarNome() << "," << cliente.pegarCpf() << "\n";

    out.close();
}

vector <ClientesModel> ClientesRepository::listar() {
    garantirArquivo();
    vector <ClientesModel> clientes;
    ifstream in(arquivo);
    string linha;

    while (getline(in, linha)) {
        stringstream ss(linha);
        string idStr, nome, cpf;

        getline(ss, idStr, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');

        if (!idStr.empty())
            clientes.emplace_back(stoi(idStr), nome, cpf);
    }

    in.close();
    return clientes;
}

ClientesModel ClientesRepository::buscarId(int _id) {
    garantirArquivo();
    ifstream in(arquivo);
    string linha;
    bool encontrado = false;

    while (getline(in, linha)) {
        stringstream ss(linha);
        string idStr, nome, cpf;

        getline(ss, idStr, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');

        if (!idStr.empty()) {
            int id = stoi(idStr);
            if (id == _id) {
                return ClientesModel(nome, cpf, id);
                encontrado = true;
            }
        }
    }
    if (!encontrado) {
        throw runtime_error("\nCliente com o ID informado não encontrado.");
    }

    in.close();
}

void ClientesRepository::deletar(int _id) {
    garantirArquivo();
    ifstream in(arquivo);
    
    vector<string> linhas;
    string linha;
    bool encontrado = false;

    while (getline(in, linha)) {
        stringstream ss(linha);
        string idStr, nome, cpf;

        getline(ss, idStr, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');

        if (!idStr.empty()) {
            int id = stoi(idStr);

            if (id != _id) {
                linhas.push_back(linha);
            } else {
                encontrado = true;
            }
        }
    }

    in.close();

    ofstream out(arquivo, ios::trunc);
    for (const auto& l : linhas) {
        out << l << "\n";
    }
    out.close();
}

void ClientesRepository::editar(int _id, ClientesModel clienteEditado) {
    garantirArquivo();
    ifstream in(arquivo);

    vector <string> linhas;
    string linha;
    bool encontrado = false;

    while (getline(in, linha)) {
        stringstream ss(linha);
        string idStr, nome, cpf;

        getline(ss, idStr, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');

        if (!idStr.empty()) {
            int id = stoi(idStr);
            if (id == _id) {
                string novaLinha = to_string(clienteEditado.pegarId()) + "," + clienteEditado.pegarNome() + "," + clienteEditado.pegarCpf();
                linhas.push_back(novaLinha);
                encontrado = true;
            } else {
                linhas.push_back(linha);
            }
        }
    }

    in.close();

    ofstream out(arquivo, ios::trunc);
    for (const auto& l : linhas) {
        out << l << "\n";
    }
    out.close();      
}