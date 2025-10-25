#pragma once
#include "include/model/ClientesModel.h"
#include <vector>
#include <string>

using namespace std;

class ClientesRepository {
    private:
    string arquivo = "data/clientes.txt";

    public:
    void salvar(const ClientesModel& cliente);
    vector <ClientesModel> listar() const;

};