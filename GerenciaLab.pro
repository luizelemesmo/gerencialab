QT += core widgets gui sql

TARGET = GerenciaLab
TEMPLATE = app

# Versão do C++
CONFIG += c++17

# Diretórios de código fonte
SOURCES += \
    src/main/main.cpp \
    src/common/queue_manager.cpp \
    src/common/queue_model.cpp \
    src/common/ticket_factory.cpp \
    src/lab-fila/receptionist_window.cpp \
    src/lab-fila/totem_window.cpp

# Diretórios de headers
HEADERS += \
    src/common/queue_manager.h \
    src/common/queue_model.h \
    src/common/ticket_factory.h \
    src/common/ticket.h \
    src/lab-fila/receptionist_window.h \
    src/lab-fila/totem_window.h

# Diretórios de include
INCLUDEPATH += \
    src/common \
    src/lab-fila \
    src/lab-painel

# Configurações de compilação
CONFIG += debug
CONFIG += warn_on

# Flags de compilação
QMAKE_CXXFLAGS += -Wall -Wextra

# Diretório de saída
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build/moc 