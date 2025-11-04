#pragma once
#include "model/ClientesModel.h"
#include "BaseRepository.h"
#include <vector>
#include <string>

class ClientesRepository : public BaseRepository<ClientesModel> {
private:
    int proximo_id; 

public:

    ClientesRepository();

    void garantirArquivo() override;
    void salvar(ClientesModel& cliente) override;
    void editar(int id, const ClientesModel& clienteEditado);
    void deletar(int id) override;
    ClientesModel buscarId(int id) override;
    std::vector<ClientesModel> listar() override;
};
