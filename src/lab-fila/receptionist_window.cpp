#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include "queue_manager.cpp"

class ReceptionistWindow : public QWidget {
    QListWidget* queueList;

public:
    ReceptionistWindow(QWidget* parent = nullptr) : QWidget(parent) {
        setWindowTitle("Tela da Recepcionista - GerenciaLab");

        QVBoxLayout* layout = new QVBoxLayout(this);

        queueList = new QListWidget();
        updateQueueList();
        layout->addWidget(queueList);

        QPushButton* callButton = new QPushButton("Chamar Próxima Senha");
        layout->addWidget(callButton);

        QPushButton* finishButton = new QPushButton("Finalizar Atendimento");
        layout->addWidget(finishButton);

        connect(callButton, &QPushButton::clicked, [=]() {
            QueueManager::getInstance()->callNext();
            updateQueueList();
        });

        connect(finishButton, &QPushButton::clicked, [=]() {
            if (queueList->currentItem()) {
                int id = queueList->currentItem()->data(Qt::UserRole).toInt();
                QueueManager::getInstance()->finishCurrent(id);
                updateQueueList();
            }
        });

        // Observer: Conecta ao signal para atualizar em tempo real
        connect(QueueManager::getInstance(), &QueueManager::queueUpdated, this, &ReceptionistWindow::updateQueueList);
    }

private:
    void updateQueueList() {
        queueList->clear();
        auto queue = QueueManager::getInstance()->getCurrentQueue();
        for (const auto& t : queue) {
            QListWidgetItem* item = new QListWidgetItem(QString("Senha %1 - %2 %3").arg(t.id).arg(t.examType).arg(t.isPreferential ? "(Preferencial)" : ""));
            item->setData(Qt::UserRole, t.id);
            queueList->addItem(item);
        }
    }
};