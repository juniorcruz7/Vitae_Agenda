#pragma once
#include <vector>
#include <string>

template <typename T>
class BaseRepository {
protected:
    std::string arquivo;    

public:
    BaseRepository(const std::string& nomeArquivo) : arquivo(nomeArquivo) {}

    virtual void garantirArquivo() = 0;
    virtual void salvar(T& item) = 0;
    virtual void deletar(int id) = 0;
    virtual T buscarId(int id) = 0;
    virtual std::vector<T> listar() = 0;

    virtual ~BaseRepository() = default;
};
