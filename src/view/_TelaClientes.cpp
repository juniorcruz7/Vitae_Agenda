#include "view/_TelaClientes.h"
#include "view/_TelaInicial.h"
#include <iostream>

using namespace std;

void _TelaClientes::exibirMenu() {
    int op;
    _TelaInicial tela;

    do {
        system("cls");

        cout << "----- CLIENTES -----\n\n";
        cout << "[1] Cadastrar Clientes\n";
        cout << "[2] Listar    Clientes\n";
        cout << "[3] Editar    Clientes\n";
        cout << "[4] Deletar   Clientes\n\n";

        cout << "[0] Voltar";

        cin >> op;

        switch (op)
        {
        case 1:
            //Cadastrar
            break;
        case 2:
            //Listar
            break;
        case 3:
            //Editar
            break;
        case 4:
            //Deletar
            break;
        default: //Voltar para Tela Inicial
            tela.exibirMenu();
                break;

        }

    } while (op != 0);
}