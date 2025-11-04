<<<<<<< HEAD
# Define a versão mínima do CMake necessária
cmake_minimum_required(VERSION 3.10)

# Nome do seu projeto (opcional, mas bom para organização)
project(VITAE_AGENDA VERSION 1.0)

# Define o padrão C++ que você está usando (mude se for outro, como C++17 ou C++20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 1. Adiciona os diretórios de inclusão (onde estão seus arquivos .h)
# Isso permite que o compilador encontre as definições de classe
include_directories(include)

# 2. Encontra todos os arquivos de cabeçalho (.h)
# Embora não seja estritamente necessário para o executável, ajuda IDEs e o próprio CMake
file(GLOB HEADERS "include/controller/*.h"
                   "include/model/*.h"
                   "include/repository/*.h"
                   "include/view/*.h")

# 3. Encontra todos os arquivos de código-fonte (.cpp)
# O GLOB pega todos os .cpp dentro da pasta src/ e subpastas
file(GLOB SOURCES "src/controller/*.cpp"
                  "src/model/*.cpp"
                  "src/repository/*.cpp"
                  "src/view/*.cpp"
                  "main.cpp") # Adiciona o arquivo principal main.cpp

# 4. Cria o executável
# O primeiro argumento é o nome do executável final (o que você vai rodar)
# O segundo argumento é a lista de todos os arquivos de código-fonte (.cpp)
add_executable(vitae_agenda_app ${SOURCES} ${HEADERS})

# Se você estiver usando bibliotecas externas (como Qt, SDL, etc.),
# você precisará adicioná-las aqui com comandos como:
# find_package(...)
# target_link_libraries(vitae_agenda_app biblioteca_necessaria)
=======
cmake_minimum_required(VERSION 3.25)
project(Vitae_Agenda)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Lista de todos os arquivos-fonte do projeto
set(SOURCES
        main.cpp
        src/controller/AgendamentoController.cpp
        src/controller/ClientesController.cpp
        src/model/AgendamentoModel.cpp
        src/model/ClientesModel.cpp
        src/repository/AgendamentoRepository.cpp
        src/repository/ClientesRepository.cpp
        src/view/TelaAgendamentos.cpp
        src/view/TelaClientes.cpp
        src/view/TelaInicial.cpp
)

# Cria o executável
add_executable(Vitae_Agenda ${SOURCES})

# No Windows, força console application (usa main() ao invés de WinMain)
if(WIN32)
    set_target_properties(Vitae_Agenda PROPERTIES WIN32_EXECUTABLE OFF)
endif()

# Inclui os diretórios de headers
target_include_directories(Vitae_Agenda PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/controller
        ${PROJECT_SOURCE_DIR}/include/model
        ${PROJECT_SOURCE_DIR}/include/repository
        ${PROJECT_SOURCE_DIR}/include/view
)
>>>>>>> agenda
