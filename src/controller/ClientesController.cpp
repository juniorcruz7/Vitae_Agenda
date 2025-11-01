#include "include/controller/ClientesController.h"
#include "include/model/ClientesModel.h"
#include "include/repository/ClientesRepository.h"

ClientesRepository repositorio;

using namespace std;

ClientesModel ClientesController:: buscarID(int _id) {
    
    return repositorio.buscarId(_id);
}

void ClientesController::cadastrarCliente(string& nome, string& cpf) {
    ClientesModel cliente(nome, cpf);
       
    repositorio.salvar(cliente);
}

vector <ClientesModel> ClientesController::listarCliente() {
    
    return repositorio.listar();
}

void ClientesController::deletarCliente(int _id) {   
    
    return repositorio.deletar(_id); 
}

void ClientesController::editarClientes(int _id, ClientesModel clienteEditado) {
    
    return repositorio.editar(_id, clienteEditado);
}