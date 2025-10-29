#include "include/repository/ClientesRepository.h"
#include "include/model/ClientesModel.h"
#include <fstream>
#include <sstream>

using namespace std;

void ClientesRepository::salvar(const ClientesModel& cliente) {
    ofstream out(arquivo, ios::app);
    out << cliente.pegarId() << "," << cliente.pegarNome() << "," << cliente.pegarCpf() << "\n";
}

vector <ClientesModel> ClientesRepository::listar()const{
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
    return clientes;
}
