// src/lab-fila/totem_window.cpp

#include "totem_window.h" // <-- Inclui o novo cabeçalho
#include <QApplication>
#include <QVBoxLayout>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QMessageBox>
#include "queue_manager.h"

// O construtor agora é definido fora da classe, com "TotemWindow::"
TotemWindow::TotemWindow(QWidget* parent) : QWidget(parent) {
    setWindowTitle("Totem de Autoatendimento - GerenciaLab");
    setFixedSize(800, 600);  // Simule touch screen

    QVBoxLayout* layout = new QVBoxLayout(this);

    QComboBox* examCombo = new QComboBox();
    examCombo->addItems({"Hemograma", "Glicose", "Colesterol", "Outros"});  // Tipos de exame (configurável)
    layout->addWidget(examCombo);

    QCheckBox* preferentialCheck = new QCheckBox("Atendimento Preferencial (Idoso/Gestante/PCD)");
    layout->addWidget(preferentialCheck);

    QPushButton* generateButton = new QPushButton("Gerar Senha");
    generateButton->setStyleSheet("font-size: 24px;");  // Botão grande
    layout->addWidget(generateButton);

    connect(generateButton, &QPushButton::clicked, [=]() {
        QString exam = examCombo->currentText();
        bool pref = preferentialCheck->isChecked();
        QueueManager::getInstance()->issueTicket(exam, pref);
        
        // Pequena melhoria: não chame getNextTicket(), pois pode não ser a senha que acabou de ser gerada.
        // É melhor obter o ID de outra forma ou apenas mostrar uma mensagem genérica.
        // Por enquanto, vamos manter a lógica original para focar na compilação.
        QMessageBox::information(this, "Senha Gerada", "Sua senha foi gerada com sucesso!\n(Impressão simulada)");
    });
}