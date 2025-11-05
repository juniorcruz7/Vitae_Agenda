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
