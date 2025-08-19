# CMakeLists.txt (no topo do projeto)

cmake_minimum_required(VERSION 3.10)
project(GerenciaLab)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Adicione esta linha para forçar o uso do framework OpenGL correto
set(Qt6Gui_OPENGL_LIBRARIES "-framework OpenGL" CACHE STRING "OpenGL framework for Qt GUI")

# A linha acima DEVE vir ANTES do find_package
find_package(Qt6 COMPONENTS Widgets Sql REQUIRED)
# Você não precisa mais do find_package(OpenGL REQUIRED), pode remover ou comentar
# find_package(OpenGL REQUIRED)

add_subdirectory(src/common)
add_subdirectory(src/lab-fila)
add_subdirectory(src/lab-painel)

add_executable(GerenciaLab src/main/main.cpp)

target_link_libraries(GerenciaLab PRIVATE 
    Qt6::Widgets 
    Qt6::Sql 
    common 
    lab-fila 
    lab-painel
)