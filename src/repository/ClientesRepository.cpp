#include "repository/ClientesRepository.h"
#include "model/ClientesModel.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

using namespace std;

ClientesRepository::ClientesRepository() : BaseRepository<ClientesModel>("data/clientes.txt"), proximo_id(0) {
    garantirArquivo();

    // Inicializa o próximo ID com base no maior ID existente no arquivo
    vector<ClientesModel> clientes = listar(); // 'listar' já chama garantirArquivo
    if (clientes.empty()) {
        proximo_id = 0;
    } else {
        proximo_id = clientes.back().pegarId(); 
    }
}

void ClientesRepository::garantirArquivo() {
    if (!filesystem::exists("data")) {
            filesystem::create_directory("data");
        }
    if (!filesystem::exists(arquivo)) {
            ofstream out(arquivo);
            out.close();
        }
}

void ClientesRepository::salvar(ClientesModel& cliente) {
    garantirArquivo();

    if (cliente.pegarId() == 0) {      
        cliente.definirId(++proximo_id); 
    }

    ofstream out(arquivo, ios::app);
    out << cliente.pegarId() << ","
        << cliente.pegarNome() << ","
        << cliente.pegarCpf() << "\n";

    out.close();
}

vector <ClientesModel> ClientesRepository::listar() {
    garantirArquivo();
    vector <ClientesModel> clientes;
    ifstream in(this->arquivo);
    string linha;

    while (getline(in, linha)) {
        stringstream ss(linha);
        string idStr, nome, cpf;

        getline(ss, idStr, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');

        if (!idStr.empty())
            clientes.emplace_back(nome, cpf, stoi(idStr));
    }

    in.close();
    return clientes;
}

ClientesModel ClientesRepository::buscarId(int _id) {
    garantirArquivo();
    ifstream in(this->arquivo);
    string linha;

    while (getline(in, linha)) {
        stringstream ss(linha);
        string idStr, nome, cpf;

        getline(ss, idStr, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');

        if (!idStr.empty() && stoi(idStr) == _id) {
            in.close();
            return ClientesModel(nome, cpf, _id);  // retorna imediatamente
        }
    }

    in.close();
    
}


void ClientesRepository::deletar(int _id) {
    garantirArquivo();
    ifstream in(this->arquivo);
    
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

    ofstream out(this->arquivo, ios::trunc);
    for (const auto& l : linhas) {
        out << l << "\n";
    }
    out.close();
}

void ClientesRepository::editar(int _id, const ClientesModel& clienteEditado) {
    garantirArquivo();
    ifstream in(this->arquivo);

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

    ofstream out(this->arquivo, ios::trunc);
    for (const auto& l : linhas) {
        out << l << "\n";
    }
    out.close();      
}