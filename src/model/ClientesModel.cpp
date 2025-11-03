#include "model/ClientesModel.h"
#include <string>

using namespace std;

int ClientesModel::numClientes = 0;

ClientesModel::ClientesModel(string _nome, string _cpf)
    : nome(_nome), cpf(_cpf) {
    id = ++numClientes;
}

ClientesModel::ClientesModel(string _nome, string _cpf, int _id)
    : nome(_nome), cpf(_cpf), id(_id) {
        if (_id > numClientes) {
            numClientes = _id;
        }
    }


int ClientesModel::pegarId()const{
    return id;
}

string ClientesModel::pegarNome()const{
    return nome;
}

void ClientesModel::alterarNome(string _nome) {
    this->nome = _nome;
}

string ClientesModel::pegarCpf()const{
    return cpf;
}

void ClientesModel::alterarCpf(string _cpf) {
    this->cpf = _cpf;
}

void ClientesModel::definirId(int _id) {
    id = _id;
}

int ClientesModel::pegarNumClientes() {
            return numClientes;
        }