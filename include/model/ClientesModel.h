#pragma once
#include <string>

using namespace std;

// Classe Model: representa a entidade 'Cliente' e armazena seus dados.
class ClientesModel {
    private:
        // Dados do cliente
    string nome;
    string cpf;
    int id;
        // Variável estática: contador global para todos os objetos ClientesModel
    static int numClientes;

    public:
        // Construtor padrão
        ClientesModel() {};

        // Construtor para criar um novo cliente (provavelmente usado com auto-incremento de ID)
        ClientesModel (string _nome, string _cpf);

        // Construtor para carregar um cliente (quando o ID já existe)
        ClientesModel (string _nome, string _cpf, int _id);

        // --- Getters (Métodos de acesso) ---
        int pegarId() const;
        string pegarNome() const;
        string pegarCpf() const;

        // --- Setters (Métodos de modificação) ---
        void alterarNome (string _nome); 
        void alterarCpf(string _cpf);
        void definirId(int _id);

        // --- Método estático ---
        // Retorna o contador total de clientes
        static int pegarNumClientes();
};