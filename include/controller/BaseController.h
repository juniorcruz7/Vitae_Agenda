#pragma once
#include <vector>

// Classe de template: define uma interface genérica para controladores
template <typename T>
class ControllerBase {
protected:
    int proximo_id;

public:
    ControllerBase() : proximo_id(1) {}

    // --- Métodos de interface pura (= 0) ---
    // Classes filhas são obrigadas a implementar estas funções.
    virtual void cadastrar(T& item) = 0;
    virtual void deletar(int id) = 0;
    virtual T buscar(int id) = 0;
    virtual std::vector<T> listar() = 0;


    // Destrutor virtual padrão (boa prática para classes base)
     virtual ~ControllerBase() = default;
};