#include "include/controller/ClientesController.h"
#include "include/model/ClientesModel.h"
#include "include/repository/ClientesRepository.h"

using namespace std;

void ClientesController::cadastrarCliente(string& nome, string& cpf) {
    ClientesModel cliente(nome, cpf);
    ClientesRepository repositorio;
   
    repositorio.salvar(cliente);
}

vector <ClientesModel> ClientesController::listarCliente() {
    ClientesRepository repositorio;

    return repositorio.listar();
}