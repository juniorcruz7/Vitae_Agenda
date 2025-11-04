#pragma once
<<<<<<< HEAD

=======
#include "model/ClientesModel.h"
#include "BaseRepository.h"
>>>>>>> agenda
#include <vector>
#include <string>

// Repositório concreto para Clientes, herda de BaseRepository.
// Gerencia o acesso aos dados (leitura/escrita) de ClientesModel.
class ClientesRepository : public BaseRepository<ClientesModel> {
private:
    int proximo_id; // Contador para gerar novos IDs

<<<<<<< HEAD
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
=======
public:
    ClientesRepository(); // Construtor

    // --- Métodos obrigatórios (override) da BaseRepository ---
    void garantirArquivo() override; // Verifica/cria o arquivo de dados
    void salvar(ClientesModel& cliente) override; // Salva um novo cliente
    void editar(int id, const ClientesModel& clienteEditado); // Edita um cliente existente
    void deletar(int id) override; // Deleta um cliente
    ClientesModel buscarId(int id) override; // Busca um cliente pelo ID
    std::vector<ClientesModel> listar() override; // Lista todos os clientes
>>>>>>> agenda
};