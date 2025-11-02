#include "include/controller/AgendamentosController.h"
#include "include/model/AgendamentosModel.h"
#include <iostream>

int main() {
    AgendamentosController ctrl;

    std::cout << "=== Cadastro de agendamentos ===\n";

    // Criar agendamentos (ID = 0, será definido pelo repositório)
    AgendamentosModel a1("2025-11-02", "10:00", "Consulta médica", 0);
    AgendamentosModel a2("2025-11-03", "14:00", "Reunião de trabalho", 0);

    ctrl.cadastrar(a1);
    ctrl.cadastrar(a2);

    // Listar todos
    std::cout << "\n=== Listando agendamentos ===\n";
    for (const auto& a : ctrl.listar()) {
    std::cout << a.pegar_id_agendamento() << " | "
              << a.pegar_data() << " | "
              << a.pegar_horario() << " | "
              << a.pegar_descricao() << "\n";
    }

    // Editar agendamento
    std::cout << "\n=== Editando agendamento ID 1 ===\n";
    AgendamentosModel editado("2025-11-02", "11:00", "Consulta médica - alterada", 1);
    ctrl.editar(1, editado);

    // Buscar por ID
    std::cout << "\n=== Buscando agendamento ID 1 ===\n";
    auto buscado = ctrl.buscar(1);
    std::cout << buscado.pegar_id_agendamento() << " | "
              << buscado.pegar_data() << " | "
              << buscado.pegar_horario() << " | "
              << buscado.pegar_descricao() << "\n";

    // Deletar agendamento
    std::cout << "\n=== Deletando agendamento ID 2 ===\n";
    ctrl.deletar(2);

    // Listar novamente
    std::cout << "\n=== Listando agendamentos após exclusão ===\n";
    for (const auto& a : ctrl.listar()) {
    std::cout << a.pegar_id_agendamento() << " | "
              << a.pegar_data() << " | "
              << a.pegar_horario() << " | "
              << a.pegar_descricao() << "\n";

    }

    return 0;
}
