#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QMessageBox>
#include "queue_manager.h"  // Link à DLL via include ou QLibrary

class TotemWindow : public QWidget {
public:
    TotemWindow(QWidget* parent = nullptr) : QWidget(parent) {
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
            QMessageBox::information(this, "Senha Gerada", "Sua senha é: " + QString::number(QueueManager::getInstance()->getNextTicket().id) + "\n(Impressão simulada)");
        });
    }
};