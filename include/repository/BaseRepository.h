#pragma once
#include <vector>

template<typename T>
class BaseRepository {
public:
    virtual void salvar(const T& model) = 0;
    virtual std::vector<T> listar() = 0;
    virtual ~BaseRepository() {}
};
