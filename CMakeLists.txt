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