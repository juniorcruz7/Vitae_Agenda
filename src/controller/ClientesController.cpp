#include "include/controller/ClientesController.h"
#include "include/model/ClientesModel.h"
#include "include/repository/ClientesRepository.h"

ClientesRepository repositorio;

using namespace std;

ClientesModel ClientesController:: buscarID(int _id) const {
    
    return repositorio.buscarId(_id);
}

void ClientesController::cadastrar(const ClientesModel& item) {
    ClientesModel cliente(nome, cpf);
       
    repositorio.salvar(cliente);
}

vector <ClientesModel> ClientesController::listar() const {
    
    return repositorio.listar();
}

void ClientesController::deletar(int _id) {   
    
    repositorio.deletar(_id); 
}

void ClientesController::editar(int _id, const ClientesModel& clienteEditado) {
    
    return repositorio.editar(_id, clienteEditado);
}