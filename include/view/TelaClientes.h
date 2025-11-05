#pragma once

// Classe View: Define a tela de gerenciamento de Clientes.
class TelaClientes {
    public:
    // Funções que exibem as diferentes "telas" (menus) para o usuário.
    void exibirMenu(); // Menu principal (Cadastrar, Listar, etc.)

    void telaCadastro(); // Tela para inserir novo cliente
    
    void telaListagem(); // Tela para mostrar todos os clientes
    
    void telaDeletar(); // Tela para remover um cliente
    
    void telaEditar(); // Tela para modificar um cliente
};