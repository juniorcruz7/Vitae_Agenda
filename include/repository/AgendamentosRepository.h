#pragma once
#include "BaseRepository.h"
#include "model/AgendamentosModel.h"
#include <vector>
#include <string>

class AgendamentosRepository : public BaseRepository<AgendamentosModel> {
private:
    int proximo_id;
    std::vector<AgendamentosModel> agendamentos;
    std::string arquivo;


public:
    AgendamentosRepository(const std::string& nomeArquivo = "data/agendamentos.txt");
    void garantirArquivo() override;
    void salvar(AgendamentosModel& agendamento) override; 
    void editar(int id, const AgendamentosModel& agendamento) override;
    void deletar(int id) override;
    AgendamentosModel buscarId(int id) override;
    std::vector<AgendamentosModel> listar() override;
};