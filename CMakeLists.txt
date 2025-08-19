# CMakeLists.txt (no topo do projeto)

cmake_minimum_required(VERSION 3.10)
project(GerenciaLab)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt5 components
find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)
message(STATUS "Qt5_DIR encontrado pelo CMake: ${Qt5_DIR}")

add_subdirectory(src/common)
add_subdirectory(src/lab-fila)
add_subdirectory(src/lab-painel)

add_executable(GerenciaLab src/main/main.cpp)

target_link_libraries(GerenciaLab PRIVATE 
    Qt5::Widgets 
    Qt5::Sql 
    common 
    lab-fila 
)