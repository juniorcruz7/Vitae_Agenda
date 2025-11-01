#pragma once
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
};