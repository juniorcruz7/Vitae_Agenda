#include "include/view/TelaAgendamentos.h"
#include "src/view/TelaInicial.cpp"
#include <iostream>

using namespace std;

void TelaAgendamentos::exibirMenu() {
    int op;
    TelaInicial tela;

    do {
        system("cls");

        cout << "----- AGENDAMENTOS -----\n\n";
        cout << "[1] Cadastrar Agendamento\n";
        cout << "[2] Listar    Agendamento\n";
        cout << "[3] Editar    Agendamento\n";
        cout << "[4] Deletar   Agendamento\n\n";

        cout << "[0] Voltar";

        cin >> op;

        switch (op)
        {
        case 1:
            //Cadastrar
        case 2:
            //Listar
        case 3:
            //Editar
        case 4:
            //Deletar
        default: //Voltar para Tela Inicial
            tela.exibirMenu();
        }

    } while (op =! 0);
}