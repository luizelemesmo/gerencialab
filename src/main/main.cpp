#include <QApplication>
#include <QMetaType> // Para registrar tipos customizados

// 1. Inclua os CABEÇALHOS (.h) das suas janelas e tipos
#include "ticket.h"
#include "totem_window.h"
#include "receptionist_window.h"


int main(int argc, char* argv[]) {
    // 2. Registre seus tipos customizados ANTES de criar o QApplication
    qRegisterMetaType<Ticket>("Ticket");

    QApplication app(argc, argv);

    // 3. O bloco QLibrary foi removido, pois o CMake já linka a biblioteca

    // Inicie as telas que desejar
    TotemWindow totem;
    totem.show();

    ReceptionistWindow receptionist;
    receptionist.show();

    return app.exec();
}