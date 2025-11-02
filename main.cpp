#include "controller/ClientesController.h"
#include <iostream>

int main() {
    ClientesController clientesCtrl;

    std::cout << "Teste de listar clientes:\n";
    clientesCtrl.listar();

    return 0;
}
