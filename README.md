# Vitae Agenda

Relatório de Desenvolvimento do programa **Vitae Agenda** (Sistema de Gerenciamento de Agendamentos), feito para a cadeira de Estrutura de Dados Orientada a Objetos do curso de Sistemas de Informação da UFPE.

## Índice
- [1. Equipe](#equipe)
    - [1.1 Membros](#equipe-membros)
- [2. Sobre o programa](#sobre-o-programa)
    - [2.1 Proposta](#sobre-o-programa-proposta)
- [3. Estrutura do projeto](#estrutura)
- [4. Conceitos utilizados](#conceitos)
- [5. Como instalar e rodar o programa](#instalar)

<a id="equipe"></a>
## Equipe

<a id="equipe-membros"></a>

### Membros
<div align="center">
    <table width="100%">
        <tr>
            <td align="center"><a href="https://github.com/guimontenegro07"><img src="https://avatars.githubusercontent.com/u/212376548?v=4" width="100px"><br /><sub><b>Guilherme Montenegro</b></sub></a><br/></td>
            <td align="center"><a href="https://github.com/juniorcruz7"><img src="https://avatars.githubusercontent.com/u/224153797?v=4" width="100px"><br /><sub><b>Severino João</b></sub></a><br/></td>
            <td align="center"><a href="#"><img src="https://avatars.githubusercontent.com/u/9919?s=200&v=4" width="100px"><br /><sub><b>Emanuel Terto</b></sub></a><br/></td>
            <td align="center"><a href="https://github.com/vitorlins0"><img src="https://avatars.githubusercontent.com/u/224650528?s=400&u=2f8410fff56376138168b428f32bc664d3b4963d&v=4" width="100px"><br /><sub><b>João Vitor Baracho</b></sub></a><br/></td>
        </tr>
    </table>
</div>

<a id="sobre-o-programa"></a>

## Sobre o Programa

<a id="sobre-o-programa-proposta"></a>

### Proposta
Tendo em vista a necessidade de organização em consultórios médicos e serviços de agendamento, o **Vitae Agenda** é um sistema capaz de registrar clientes e marcar horários de acordo com a disponibilidade.
O sistema simula um pequeno banco de dados local através de arquivos de texto, permitindo operações completas de CRUD (Create, Read, Update, Delete) tanto para pacientes quanto para a agenda.

<a id="estrutura"></a>

```
vitae-agenda/
├── docs/ # Documentação do projeto (HTML/CSS)
├── include/ # Declarações das classes (Headers)
│ ├── controller/ # Lógica de negócio e controle de fluxo
│ ├── model/ # Modelagem das entidades (Cliente, Agendamento)
│ ├── repository/ # Gerenciamento da persistência de dados
│ └── view/ # Telas e interação com o usuário
├── src/ # Código-fonte (Implementações .cpp)
├── .gitignore # Arquivos ignorados pelo Git
├── CMakeLists.txt # Configuração de build do projeto
├── LICENSE # Licença de uso
├── main.cpp # Ponto de entrada do sistema
└── README.md # Relatório do projeto
```

## Estrutura do projeto
O projeto segue uma arquitetura modular baseada no padrão MVC, separando responsabilidades em diferentes diretórios:

<a id="conceitos"></a>
## Conceitos utilizados
### Programação Orientada a Objetos
- **Abstração** → As classes de `repository` e `controller` utilizam abstrações onde classes base definem o funcionamento geral e classes derivadas especializam o contexto.

- **Herança** → A superclasse `BaseController` possui métodos herdados pelas filhas `AgendamentosController` e `ClientesController`. O mesmo ocorre nos repositórios, garantindo reaproveitamento de código.

- **Encapsulamento** → Dados sensíveis dos pacientes (como CPF) são protegidos dentro das classes do `model` e acessados apenas por métodos específicos, evitando modificações externas indevidas.

- **Polimorfismo** → Métodos como `cadastrar`, `editar` e `deletar` presentes na classe base são sobrescritos nas classes derivadas para se comportarem de maneira específica para Clientes ou Agendamentos.

### Modularização
- O código é organizado em pastas lógicas dentro de `include/` e `src/`:
    - *`controller/`*
    - *`model/`*
    - *`repository/`*
    - *`view/`*

### Manipulação de Arquivos
- Uso da camada `repository` para persistência de dados em arquivos de texto (`.txt`), simulando um banco de dados.

<a id="instalar"></a>
## Como instalar e rodar o programa

### Pré-requisitos
Certifique-se de ter instalado:

- Compilador C++ (GCC ou Clang).
- CMake (versão 3.10 ou superior).

### 1. Clone o repositório e entre no diretório

```
git clone https://github.com/juniorcruz7/Vitae_Agenda
cd Vitae_Agenda
```

## 2. Compile o programa usando CMake

```
mkdir build
cd build
cmake ..
cmake --build .
```

## 3. Execute o programa

No MacOS/Linux

```
./Vitae_Agenda
```

No Windows

```
.\Vitae_Agenda.exe
```
