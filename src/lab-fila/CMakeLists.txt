# 1. Cria a biblioteca "lab-fila" com os arquivos .cpp da pasta atual
add_library(lab-fila SHARED
    totem_window.cpp
    receptionist_window.cpp
)

# 2. Informa que os arquivos de cabeçalho (.h) estão na pasta atual
target_include_directories(lab-fila PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 3. Conecta (linka) esta biblioteca com as dependências dela (Qt e a biblioteca "common")
target_link_libraries(lab-fila PRIVATE 
    Qt6::Widgets 
    common
    OpenGL::GL
)