#pragma once

#include <vector>

using namespace std;

class ClientesModel;

class ClientesRepository {
    private:
    string arquivo = "data/clientes.txt";

    public:
    void salvar(const ClientesModel& cliente);
    vector <ClientesModel> listar() const;
    ClientesModel buscarId(int _id);

};