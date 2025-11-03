#pragma once
#include <string>

using namespace std;

class ClientesModel {
    private:
        string nome;
        string cpf;
        int id;
        static int numClientes;
    public:
        ClientesModel (string _nome, string _cpf);

        ClientesModel (string _nome, string _cpf, int _id);

        int pegarId() const;

        string pegarNome() const;

        void alterarNome (string _nome); 

        string pegarCpf() const;

        void alterarCpf(string _cpf);

        void definirId(int _id);

        static int pegarNumClientes();
};