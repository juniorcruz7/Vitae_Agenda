#pragma once
#include "BaseRepository.h"
#include "ClientesModel.h"
#include <vector>
#include <string>

class ClientesRepository : public BaseRepository<ClientesModel> {
private:
    int proximo_id; 

public:
    ClientesRepository(const std::string& nomeArquivo = "data/clientes.txt")
        : BaseRepository<ClientesModel>(nomeArquivo), proximo_id(0) {}

    void garantirArquivo() override;
    void salvar(ClientesModel& cliente) override;
    void editar(int id, const ClientesModel& clienteEditado) override;
    void deletar(int id) override;
    ClientesModel buscarId(int id) override;
    std::vector<ClientesModel> listar() override;
};
