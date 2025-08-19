# Define a biblioteca "lab-painel" para o módulo de exibição
add_library(lab-painel STATIC
    # Add source files here when they exist
)

# Include directories
target_include_directories(lab-painel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link with Qt5 and common library
target_link_libraries(lab-painel PRIVATE 
    Qt5::Widgets 
    common
)
