#pragma once
#include "BaseRepository.h"
#include "model/AgendamentosModel.h"
#include <vector>
#include <string>

using namespace std;

class AgendamentosRepository : public BaseRepository<AgendamentosModel> {
private:
    int proximo_id;
    vector<AgendamentosModel> agendamentos;

public:
    AgendamentosRepository();

    void garantirArquivo() override;
    void salvar(AgendamentosModel& agendamento) override; 
    void editar(int id, const AgendamentosModel& agendamento) override;
    void deletar(int id) override;
    AgendamentosModel buscarId(int id) override;
    std::vector<AgendamentosModel> listar() override;
};