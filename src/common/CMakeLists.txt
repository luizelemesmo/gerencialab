# Define a biblioteca estática "common" com todos os arquivos de implementação (.cpp)
add_library(common STATIC
    ticket_factory.cpp
    queue_model.cpp
    queue_manager.cpp  
)

# Torna os arquivos de cabeçalho (.h) desta pasta visíveis para quem usar a biblioteca "common"
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Linka a biblioteca "common" com os módulos do Qt que ela utiliza
target_link_libraries(common PUBLIC Qt6::Core Qt6::Sql)