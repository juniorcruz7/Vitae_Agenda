#include "include/view/TelaClientes.h"
#include "src/view/TelaInicial.cpp"
#include <iostream>

using namespace std;

void TelaClientes::exibirMenu() {
    int op;
    TelaInicial tela;

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