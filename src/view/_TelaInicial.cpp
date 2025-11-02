#include "view/_TelaInicial.h"
#include <iostream>
using namespace std;



void _TelaInicial::exibirMenu() {
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

        switch (op) {
            case 1:
                break;
            case 2:
                break;
            default:
                break;
        }
    } while(op != 0);
}
