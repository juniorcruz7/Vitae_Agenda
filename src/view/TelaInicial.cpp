#include "view/TelaInicial.h"
#include "view/TelaClientes.h"
#include <iostream>

using namespace std;

void TelaInicial::exibirMenu() {
    TelaClientes telaclientes;
    int op;

    do {
        system("cls");

        cout << "++++++++++++++++++++++++\n";
        cout << "----- VITAE AGENDA -----\n";
        cout << "++++++++++++++++++++++++\n\n";

        cout << "MENU\n\n";
        cout << "[1] Clientes\n";
        cout << "[2] Agendamentos\n\n";
        cout << "[0] Sair\n\n";

        cout << "Opcao: ";

        cin >> op;

        if (op == 1) {
            telaclientes.exibirMenu();
        } else if (op == 2) {

        } else {
            exit(EXIT_SUCCESS);
        }
    } while(op != 0);
}