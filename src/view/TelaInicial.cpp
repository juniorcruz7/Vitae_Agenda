#include "view/TelaInicial.h"
<<<<<<< HEAD
#include "view/TelaClientes.h"
=======
#include "view/TelaClientes.h" // Inclui a tela de clientes
#include "view/TelaAgendamentos.h" // Inclui a tela de agendamentos
>>>>>>> agenda
#include <iostream>

using namespace std;

// Função principal da TelaInicial, serve como o ponto de entrada da navegação
void TelaInicial::exibirMenu() {
<<<<<<< HEAD
    TelaClientes telaclientes;
    int op;
=======
    // Cria instâncias das sub-telas que podem ser chamadas
    TelaClientes telaclientes;
    TelaAgendamentos telaagendamentos;
>>>>>>> agenda

    int op; // Variável para guardar a opção do usuário

    do {
        system("cls"); // Limpa o console

// Imprime o cabeçalho e as opções do menu principal
        cout << "++++++++++++++++++++++++\n";
        cout << "----- VITAE AGENDA -----\n";
        cout << "++++++++++++++++++++++++\n\n";

        cout << "MENU\n\n";
        cout << "[1] Clientes\n";
        cout << "[2] Agendamentos\n\n";
        cout << "[0] Sair\n\n";

        cout << "Opcao: ";

        cin >> op; // Lê a opção (como inteiro)

<<<<<<< HEAD
        if (op == 1) {
            telaclientes.exibirMenu();
        } else if (op == 2) {
            
        } else {
            exit(EXIT_SUCCESS);
        }
    } while(op =! 0);
};
=======
        // Roteamento: decide para qual tela navegar
        if (op == 1) {
            telaclientes.exibirMenu(); // Chama o menu de clientes
        } else if (op == 2) {
            telaagendamentos.exibirMenu(); // Chama o menu de agendamentos
        } else {
        // Qualquer outra opção (incluindo 0) encerra o programa
            exit(EXIT_SUCCESS); 
        }
    } while(op != 0); // O loop continua (embora a lógica 'else' saia no 0)
}
>>>>>>> agenda
