#pragma once
<<<<<<< HEAD
#include <vector>
#include <string>

class ClientesModel;

using namespace std;

class ClientesController {
    public:
    ClientesModel buscarID(int _id); 

    void cadastrarCliente(string& nome, string& cpf);     

    vector <ClientesModel> listarCliente();

    void deletarCliente(int _id);

    void editarClientes(int _id, ClientesModel clienteEditado);
=======
#include "model/ClientesModel.h"
#include "BaseController.h"
#include <vector>
#include <string>
using namespace std;

class ClientesModel; // Declaração avançada (forward declaration)

// Controlador para a lógica de Clientes, herda de ControllerBase
class ClientesController : public ControllerBase<ClientesModel> {
public:
    ClientesController(); // Construtor

    // Métodos da interface base (override)
    void cadastrar(ClientesModel& item) override;
    void editar(int id, ClientesModel& itemEditado);
    void deletar(int id) override;
    ClientesModel buscar(int id) override;
    vector<ClientesModel> listar() override;

    // Métodos auxiliares para a View
    ClientesModel buscarID(int id);
    void cadastrarCliente(const std::string& nome, const std::string& cpf);
>>>>>>> agenda
};