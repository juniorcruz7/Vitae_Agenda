#include "model/ClientesModel.h"
#include <string>

using namespace std;

<<<<<<< HEAD
int ClientesModel::numClientes = 0;

ClientesModel::ClientesModel(string _nome, string _cpf) {
    this->id=++numClientes;
    this->nome = _nome;
    this->cpf = _cpf;
}

ClientesModel::ClientesModel(string _nome, string _cpf, int _id) {
    this->id=_id;
    this->nome=_nome;
    this->cpf=_cpf;

    if (_id > id) {
        numClientes = _id;
    }
}
=======
// Inicializa a variável estática (contador global de clientes)
int ClientesModel::numClientes = 0;

// Construtor 1: Para criar um NOVO cliente.
ClientesModel::ClientesModel(string _nome, string _cpf)
    : nome(_nome), cpf(_cpf) {
    // Atribui um novo ID auto-incrementado
    id = ++numClientes;
}

// Construtor 2: Para carregar um cliente EXISTENTE (ex: do arquivo).
ClientesModel::ClientesModel(string _nome, string _cpf, int _id)
    : nome(_nome), cpf(_cpf), id(_id) {
        // Sincroniza o contador global caso um ID alto seja carregado
    if (_id > numClientes) {
        numClientes = _id;
        }
    }

// --- Getters (Métodos de acesso) ---
>>>>>>> agenda

int ClientesModel::pegarId()const{
    return id;
}

string ClientesModel::pegarNome()const{
    return nome;
}

string ClientesModel::pegarCpf()const{
    return cpf;
}

// --- Setters (Métodos de modificação) ---

void ClientesModel::alterarNome(string _nome) {
    this->nome = _nome;
}

void ClientesModel::alterarCpf(string _cpf) {
    this->cpf = _cpf;
}

void ClientesModel::definirId(int _id) {
    id = _id;
}

// --- Método estático ---

// Retorna o valor atual do contador global
int ClientesModel::pegarNumClientes() {
    return numClientes;
}