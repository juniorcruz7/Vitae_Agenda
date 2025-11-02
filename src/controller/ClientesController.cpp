#include "controller/ClientesController.h"
#include "model/ClientesModel.h"
#include "repository/ClientesRepository.h"

extern ClientesRepository repositorio;

using namespace std;

void ClientesController::cadastrar( ClientesModel& item) {
    repositorio.salvar(item);
}

void ClientesController::editar(int id, const ClientesModel& itemEditado) {
    repositorio.editar(id, itemEditado);
}

void ClientesController::deletar(int id) {
    repositorio.deletar(id);
}

ClientesModel ClientesController::buscar(int id) {
    return repositorio.buscarId(id);
}

vector<ClientesModel> ClientesController::listar() {
    return repositorio.listar();
}

ClientesModel ClientesController::buscarID(int id) {
    return buscar(id);
}

void ClientesController::cadastrarCliente(const string& nome, const string& cpf, int id) {
    ClientesModel cliente(nome, cpf, id);
    cadastrar(cliente);
}