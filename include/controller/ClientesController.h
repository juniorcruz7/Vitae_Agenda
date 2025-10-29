#pragma once

class ClientesController {
    public:
    void cadastrarCliente(string& nome, string& cpf);     

    vector <ClientesModel> listarCliente();
};