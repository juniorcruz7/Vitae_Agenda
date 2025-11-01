#pragma once

#include <vector>
#include <string>

using namespace std;

class ClientesModel;

class ClientesRepository {
    private:
    string arquivo;
    public:
    ClientesRepository();

    void garantirArquivo();

    void salvar(const ClientesModel& cliente);

    vector <ClientesModel> listar();
    
    ClientesModel buscarId(int _id);
    
    void deletar(int _id);

    void editar (int _id, ClientesModel clienteEditado);
};