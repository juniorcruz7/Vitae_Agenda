#pragma once
#include <vector>

template <typename T>
class ControllerBase {
protected:
    int proximo_id;

public:
    ControllerBase() : proximo_id(1) {}

    virtual void cadastrar(const T& item) = 0;
    virtual void editar(int id, const T& itemEditado) = 0;
    virtual void deletar(int id) = 0;
    virtual T buscar(int id) = 0;
    virtual std::vector<T> listar() const = 0;


    virtual ~ControllerBase() = default;
};
