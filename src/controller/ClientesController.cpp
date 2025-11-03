#include "controller/ClientesController.h"
#include "model/ClientesModel.h"
#include "repository/ClientesRepository.h"

ClientesRepository repoCliente;

using namespace std;
ClientesController::ClientesController() {}

void ClientesController::cadastrar( ClientesModel& item) {
    repoCliente.salvar(item);
}

void ClientesController::editar(int id, const ClientesModel& itemEditado) {
    repoCliente.editar(id, itemEditado);
}

void ClientesController::deletar(int id) {
    repoCliente.deletar(id);
}

ClientesModel ClientesController::buscar(int id) {
    return repoCliente.buscarId(id);
}

vector<ClientesModel> ClientesController::listar() {
    return repoCliente.listar();
}

ClientesModel ClientesController::buscarID(int id) {
    return buscar(id);
}

void ClientesController::cadastrarCliente(const string& nome, const string& cpf) {
    ClientesModel cliente(nome, cpf);
    cadastrar(cliente);
}