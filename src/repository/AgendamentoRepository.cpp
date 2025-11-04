#include "repository/AgendamentosRepository.h"
#include "model/ClientesModel.h"
#include <fstream> // Para manipulação de arquivos (ifstream, ofstream)
#include <sstream> // Para parsear linhas (stringstream)
#include <filesystem> // Para verificar/criar diretórios
#include <stdexcept>

using namespace std;

// Construtor: define o arquivo e inicializa o 'proximo_id'
AgendamentosRepository::AgendamentosRepository() : BaseRepository<AgendamentosModel>("data/agendamentos.txt"), proximo_id(0) {
    garantirArquivo();

// Carrega a lista para encontrar o maior ID existente
    vector<AgendamentosModel> agendamentosExistentes = listar(); 
    if (agendamentosExistentes.empty()) {
        proximo_id = 0;
    } else {
// Define o próximo ID com base no ID do último item (assume lista ordenada)
        proximo_id = agendamentosExistentes.back().pegar_id_agendamento(); 
    }
}

// Verifica se a pasta "data" e o arquivo "agendamentos.txt" existem; se não, cria eles.
void AgendamentosRepository::garantirArquivo() {
    if (!filesystem::exists("data")) {
        filesystem::create_directory("data");
    }
    if (!filesystem::exists(arquivo)) {
        ofstream out(arquivo);
        out.close();
    }
}

// Salva um novo agendamento no arquivo
void AgendamentosRepository::salvar(AgendamentosModel& agendamento) {
    garantirArquivo();
// Se o ID for 0, é um novo agendamento, então atribui o próximo ID.
    if (agendamento.pegar_id_agendamento() == 0) { 
        agendamento.definirId(++proximo_id);
    }

// Abre o arquivo em modo 'append' (adiciona ao final)
    ofstream out(arquivo, ios::app);
    out << agendamento.pegar_id_agendamento() << ","
        << agendamento.pegar_cliente() << ","
        << agendamento.pegar_data() << ","
        << agendamento.pegar_horario() << ","
        << agendamento.pegar_descricao() << "\n";
    out.close();
}

// Lê o arquivo "agendamentos.txt" e retorna um vetor de AgendamentosModel
vector<AgendamentosModel> AgendamentosRepository::listar() {
    garantirArquivo();
    vector<AgendamentosModel> lista;
    ifstream in(arquivo); // Abre o arquivo para leitura
    string linha;

// Lê o arquivo linha por linha
    while (getline(in, linha)) {
        stringstream ss(linha); // Stringstream para "quebrar" a linha
        string idStr, data, horario, descricao, nomeCliente;

// Extrai os dados separados por vírgula
        getline(ss, idStr, ',');
        getline(ss, nomeCliente, ',');
        getline(ss, data, ',');
        getline(ss, horario, ',');
        getline(ss, descricao, ',');

        if (!idStr.empty()) { // Ignora linhas vazias
            int id = stoi(idStr); // Converte ID de string para int
            if (id > proximo_id) proximo_id = id; // Atualiza o contador de ID
// Adiciona o agendamento lido ao vetor
            lista.emplace_back(nomeCliente, data, horario, descricao, id);
        }
    }
    return lista;
}

// Busca um agendamento pelo ID
AgendamentosModel AgendamentosRepository::buscarId(int id) {
    garantirArquivo();
    vector<AgendamentosModel> lista = listar(); // Carrega todos os agendamentos
// Itera na lista até encontrar o ID
    for (const auto& a : lista) {
        if (a.pegar_id_agendamento() == id) {
            return a; // Retorna o agendamento encontrado
        }
    }
// (Aviso: esta função não retorna nada se não encontrar o ID)
}

// Deleta um agendamento do arquivo
void AgendamentosRepository::deletar(int id) {
    garantirArquivo();
    vector<AgendamentosModel> lista = listar(); // Carrega tudo da memória
// Abre o arquivo em modo 'trunc' (apaga o conteúdo anterior)
    ofstream out(arquivo, ios::trunc);

// Reescreve o arquivo, pulando o item com o ID para deletar
    for (auto& a : lista) {
        if (a.pegar_id_agendamento() != id) {
            out << a.pegar_id_agendamento() << ","
                << a.pegar_cliente() << ","
                << a.pegar_data() << ","
                << a.pegar_horario() << ","
                << a.pegar_descricao() << "\n";
        }
    }
}

// Edita um agendamento no arquivo
void AgendamentosRepository::editar(int id, AgendamentosModel& agendamento) {
    vector<AgendamentosModel> lista = listar(); // Carrega tudo
// Abre o arquivo apagando o conteúdo
    ofstream out(arquivo, ios::trunc);

// Reescreve o arquivo
    for (auto& a : lista) {
        if (a.pegar_id_agendamento() == id) {
// Se for o ID, escreve os dados do 'agendamento' (novo)
        out << id << "," 
                << agendamento.pegar_cliente() << ","
                << agendamento.pegar_data() << ","
                << agendamento.pegar_horario() << ","
                << agendamento.pegar_descricao() << "\n";
        } else {
// Se não for o ID, reescreve o agendamento antigo ('a')
            out << a.pegar_id_agendamento() << ","
                << a.pegar_cliente() << ","
                << a.pegar_data() << ","
                << a.pegar_horario() << ","
                << a.pegar_descricao() << "\n";
        }
    }
}