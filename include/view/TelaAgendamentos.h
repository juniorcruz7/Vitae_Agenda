#pragma once

// Classe View: Define a tela de gerenciamento de Agendamentos.
class TelaAgendamentos {
    public:
    // Funções que exibem as diferentes "telas" (menus) para o usuário.
    void exibirMenu(); // Menu principal (Cadastrar, Listar, etc.)
    
    void telaCadastro(); // Tela para inserir novo agendamento
    
    void telaListagem(); // Tela para mostrar todos os agendamentos
    
    void telaEditar(); // Tela para modificar um agendamento
    
    void telaDeletar(); // Tela para remover um agendamento
};