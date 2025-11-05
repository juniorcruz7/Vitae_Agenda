#pragma once
#include <vector>
#include <string>

// Template: Define uma interface genérica para repositórios (manipulação de dados/arquivos).
template <typename T>
class BaseRepository {
protected:
    std::string arquivo; // Nome do arquivo de banco de dados (ex: "clientes.csv")

public:
    // Construtor: define o nome do arquivo ao criar o repositório.
    BaseRepository(const std::string& nomeArquivo) : arquivo(nomeArquivo) {}

    // --- Métodos de interface pura (= 0) ---
    // Classes filhas (ex: ClientesRepository) são obrigadas a implementar.

    // Garante que o arquivo de dados exista.
    virtual void garantirArquivo() = 0;
    // Salva um novo item no arquivo.
    virtual void salvar(T& item) = 0;
    // Deleta um item do arquivo pelo ID.
    virtual void deletar(int id) = 0;
    // Busca e retorna um item pelo ID.
    virtual T buscarId(int id) = 0;
    // Carrega e retorna todos os itens do arquivo.
    virtual std::vector<T> listar() = 0;

    // Destrutor virtual padrão.
    virtual ~BaseRepository() = default;
};