// src/lab-fila/receptionist_window.h

#ifndef RECEPTIONIST_WINDOW_H
#define RECEPTIONIST_WINDOW_H

#include <QWidget>

// Declaração antecipada (Forward Declaration) para evitar incluir o .h do QListWidget aqui
class QListWidget;

class ReceptionistWindow : public QWidget {
    Q_OBJECT

public:
    explicit ReceptionistWindow(QWidget* parent = nullptr);

private slots:
    void updateQueueList();

private:
    QListWidget* queueList;
};

#endif // RECEPTIONIST_WINDOW_H