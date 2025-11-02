cmake_minimum_required(VERSION 3.16)
project(Vitae_Agenda LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/controller
        ${PROJECT_SOURCE_DIR}/include/model
        ${PROJECT_SOURCE_DIR}/include/repository
        ${PROJECT_SOURCE_DIR}/include/view
)

# Pesquisa todos os arquivos .cpp dentro de src/
file(GLOB_RECURSE SRC_FILES
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# Remove temporariamente os arquivos de telas problemáticas
list(FILTER SRC_FILES EXCLUDE REGEX ".*TelaClientes.cpp$")
list(FILTER SRC_FILES EXCLUDE REGEX ".*TelaAgendamentos.cpp$")
list(FILTER SRC_FILES EXCLUDE REGEX ".*TelaInicial.cpp$")

# Adiciona o executável com os arquivos restantes
add_executable(Vitae_Agenda
        ${SRC_FILES}
        main.cpp
)

message(STATUS "Project source dir: ${PROJECT_SOURCE_DIR}")
message(STATUS "Found source files: ${SRC_FILES}")
