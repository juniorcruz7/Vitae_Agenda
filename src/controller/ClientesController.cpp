#include "controller/ClientesController.h"
#include "model/ClientesModel.h"
#include "repository/ClientesRepository.h" // Dependência para manipulação dos dados

// Instância do repositório que este controlador utilizará
ClientesRepository repoCliente;

using namespace std;
// Construtor padrão
ClientesController::ClientesController() {}

// --- Implementação dos métodos da interface ---
// O controlador age como uma ponte, repassando as chamadas para o repositório.

// Passa o cliente para o repositório salvar
void ClientesController::cadastrar( ClientesModel& item) { 
    repoCliente.salvar(item);
}

// Passa a edição para o repositório
void ClientesController::editar(int id, ClientesModel& itemEditado) {
    repoCliente.editar(id, itemEditado);
}

// Passa a deleção para o repositório
void ClientesController::deletar(int id) {
    repoCliente.deletar(id);
}

// Pede ao repositório para buscar um cliente
ClientesModel ClientesController::buscar(int id) {
    return repoCliente.buscarId(id);
}

// Pede ao repositório a lista de clientes
vector<ClientesModel> ClientesController::listar() {
    return repoCliente.listar();
}

// --- Métodos auxiliares (específicos desta classe) ---
// Função auxiliar que apenas repassa a chamada (talvez redundante)
ClientesModel ClientesController::buscarID(int id) {
    return buscar(id);
}

// Método chamado pela View para simplificar a criação de um cliente
void ClientesController::cadastrarCliente(const string& nome, const string& cpf) {
    // 1. Cria o objeto Model com os dados recebidos
    ClientesModel cliente(nome, cpf);
    // 2. Chama o método de cadastro principal
    cadastrar(cliente);
}