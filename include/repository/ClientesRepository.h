#pragma once

#include <vector>

using namespace std;

class ClientesModel;

class ClientesRepository {
    public:
    string arquivo = "data/clientes.txt";

    void garantirArquivo();

    void salvar(const ClientesModel& cliente);

    vector <ClientesModel> listar();
    
    ClientesModel buscarId(int _id);
    
    void deletar(int _id);
};