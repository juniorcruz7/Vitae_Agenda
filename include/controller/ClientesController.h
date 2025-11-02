#pragma once
#include <BaseController.h>
#include <vector>
#include <string>
using namespace std;

class ClientesModel;

class ClientesController : public ControllerBase<ClientesModel> {
public:
    ClientesController();

    void cadastrar(const ClientesModel& item) override;
    void editar(int id, const ClientesModel& itemEditado) override;
    void deletar(int id) override;
    ClientesModel buscar(int id) override;
    vector<ClientesModel> listar() const override;
    ClientesModel buscarID(int id);

    void cadastrarCliente(const std::string& nome, const std::string& cpf);
};
