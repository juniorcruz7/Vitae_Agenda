#include "repository/ClientesRepository.h"
#include "model/ClientesModel.h"
<<<<<<< HEAD
#include <fstream>
#include <sstream>
#include <filesystem>

using namespace std;

ClientesRepository::ClientesRepository() : arquivo("data/clientes.txt") {

}

void ClientesRepository::garantirArquivo() {
    if (!filesystem::exists("data")) {
            filesystem::create_directory("data");
        }
    if (!filesystem::exists(arquivo)) {
            ofstream out(arquivo);
            out.close();
        }
}

void ClientesRepository::salvar(const ClientesModel& cliente) {
    garantirArquivo();
    ofstream out(arquivo, ios::app);
    out << cliente.pegarId() << "," << cliente.pegarNome() << "," << cliente.pegarCpf() << "\n";
=======
#include <iostream>
#include <fstream> // Para manipulação de arquivos
#include <sstream> // Para parsear (quebrar) strings
#include <filesystem> // Para gerenciar pastas e arquivos

using namespace std;

// Construtor: Define o arquivo e inicializa o 'proximo_id'
ClientesRepository::ClientesRepository() : BaseRepository<ClientesModel>("data/clientes.txt"), proximo_id(0) {
    garantirArquivo();

// Inicializa o contador 'proximo_id' com base no maior ID já salvo
    vector<ClientesModel> clientes = listar(); // Carrega os clientes existentes
    if (clientes.empty()) {
        proximo_id = 0;
    } else {
        proximo_id = clientes.back().pegarId(); // Pega o ID do último cliente
    }
}

// Verifica se a pasta "data" e o arquivo "clientes.txt" existem; se não, cria eles.
void ClientesRepository::garantirArquivo() {
    if (!filesystem::exists("data")) {
        filesystem::create_directory("data");
    }
    if (!filesystem::exists(arquivo)) {
        ofstream out(arquivo);
        out.close();
    }
}

// Salva um novo cliente no arquivo
void ClientesRepository::salvar(ClientesModel& cliente) {
 garantirArquivo();

// Se o ID for 0, é um cliente novo, então atribui um ID
    if (cliente.pegarId() == 0) {
        cliente.definirId(++proximo_id); 
    }

// Abre o arquivo em modo 'append' (adiciona ao final)
    ofstream out(arquivo, ios::app);
    out << cliente.pegarId() << ","
        << cliente.pegarNome() << ","
        << cliente.pegarCpf() << "\n";
>>>>>>> agenda

    out.close();
}

<<<<<<< HEAD
=======
// Lê o arquivo "clientes.txt" e retorna um vetor de ClientesModel
>>>>>>> agenda
vector <ClientesModel> ClientesRepository::listar() {
    garantirArquivo();
    vector <ClientesModel> clientes;
    ifstream in(this->arquivo); // Abre o arquivo para leitura
    string linha;

// Lê o arquivo linha por linha
    while (getline(in, linha)) {
        stringstream ss(linha); // Stringstream para "quebrar" a linha
        string idStr, nome, cpf;

// Extrai os dados separados por vírgula
        getline(ss, idStr, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');

        if (!idStr.empty()) // Ignora linhas vazias
// Adiciona o cliente lido ao vetor (usando o construtor que define o ID)
            clientes.emplace_back(nome, cpf, stoi(idStr));
        }

    in.close();
    return clientes;
}

// Busca um cliente pelo ID (método otimizado, não carrega o vetor inteiro)
ClientesModel ClientesRepository::buscarId(int _id) {
    garantirArquivo();
    ifstream in(this->arquivo);
    string linha;

// Lê o arquivo linha por linha
    while (getline(in, linha)) {
        stringstream ss(linha);
        string idStr, nome, cpf;

        getline(ss, idStr, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');

<<<<<<< HEAD
        if (!idStr.empty())
            clientes.emplace_back(nome, cpf, stoi(idStr));
    }

    in.close();
    return clientes;
}

ClientesModel ClientesRepository::buscarId(int _id) {
    garantirArquivo();
    ifstream in(arquivo);
    string linha;
    bool encontrado = false;

    while (getline(in, linha)) {
        stringstream ss(linha);
        string idStr, nome, cpf;

        getline(ss, idStr, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');

        if (!idStr.empty()) {
            int id = stoi(idStr);
            if (id == _id) {
                return ClientesModel(nome, cpf, id);
                encontrado = true;
            }
        }
    }
    if (!encontrado) {
        throw runtime_error("\nCliente com o ID informado não encontrado.");
    }

    in.close();
}

void ClientesRepository::deletar(int _id) {
    garantirArquivo();
    ifstream in(arquivo);
    
    vector<string> linhas;
    string linha;
    bool encontrado = false;

=======
// Se encontrar o ID, constrói o objeto e o retorna imediatamente
        if (!idStr.empty() && stoi(idStr) == _id) {
            in.close();
            return ClientesModel(nome, cpf, _id);
        }
    }

    in.close();
// (Aviso: esta função não retorna nada se não encontrar o ID)
}

// Deleta um cliente do arquivo
void ClientesRepository::deletar(int _id) {
    garantirArquivo();
    ifstream in(this->arquivo);
 
    vector<string> linhas; // Vetor para armazenar as linhas que serão mantidas
    string linha;
    bool encontrado = false;

// Lê o arquivo e armazena apenas as linhas com ID diferente
>>>>>>> agenda
    while (getline(in, linha)) {
        stringstream ss(linha);
        string idStr, nome, cpf;

        getline(ss, idStr, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');

        if (!idStr.empty()) {
            int id = stoi(idStr);

            if (id != _id) {
<<<<<<< HEAD
                linhas.push_back(linha);
            } else {
                encontrado = true;
=======
                linhas.push_back(linha); // Mantém a linha
            } else {
                encontrado = true; // Marca que o ID foi encontrado (e pulado)
>>>>>>> agenda
            }
        }
    }

    in.close();

<<<<<<< HEAD
    ofstream out(arquivo, ios::trunc);
=======
// Abre o arquivo em modo 'trunc' (apaga o conteúdo anterior)
    ofstream out(this->arquivo, ios::trunc);
// Reescreve o arquivo apenas com as linhas mantidas
>>>>>>> agenda
    for (const auto& l : linhas) {
        out << l << "\n";
    }
    out.close();
}

<<<<<<< HEAD
void ClientesRepository::editar(int _id, ClientesModel clienteEditado) {
    garantirArquivo();
    ifstream in(arquivo);

    vector <string> linhas;
    string linha;
    bool encontrado = false;

=======
// Edita um cliente no arquivo
void ClientesRepository::editar(int _id, const ClientesModel& clienteEditado) {
    garantirArquivo();
    ifstream in(this->arquivo);

    vector <string> linhas; // Armazena todas as linhas (modificadas ou não)
    string linha;
    bool encontrado = false;

// Lê o arquivo
>>>>>>> agenda
    while (getline(in, linha)) {
        stringstream ss(linha);
        string idStr, nome, cpf;

        getline(ss, idStr, ',');
        getline(ss, nome, ',');
        getline(ss, cpf, ',');

        if (!idStr.empty()) {
            int id = stoi(idStr);
            if (id == _id) {
<<<<<<< HEAD
=======
// Se for o ID, formata a nova linha com os dados editados
>>>>>>> agenda
                string novaLinha = to_string(clienteEditado.pegarId()) + "," + clienteEditado.pegarNome() + "," + clienteEditado.pegarCpf();
                linhas.push_back(novaLinha);
                encontrado = true;
            } else {
<<<<<<< HEAD
=======
// Se não for o ID, adiciona a linha original
>>>>>>> agenda
                linhas.push_back(linha);
            }
        }
    }

    in.close();

<<<<<<< HEAD
    ofstream out(arquivo, ios::trunc);
    for (const auto& l : linhas) {
        out << l << "\n";
    }
    out.close();      
=======
// Abre o arquivo em modo 'trunc' (apaga tudo)
    ofstream out(this->arquivo, ios::trunc);
// Reescreve o arquivo com o vetor de linhas (antigas + modificada)
    for (const auto& l : linhas) {
        out << l << "\n";
    }
    out.close();
>>>>>>> agenda
}