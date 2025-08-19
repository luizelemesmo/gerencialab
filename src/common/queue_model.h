// src/common/queue_model.h

#ifndef QUEUE_MODEL_H
#define QUEUE_MODEL_H

#include "ticket.h"
#include <QList>
#include <QSqlDatabase>

class QueueModel {
public:
    // Construtor que inicializa o banco de dados
    QueueModel();

    // Métodos públicos para gerenciar os tickets
    void addTicket(const Ticket& ticket);
    QList<Ticket> getQueue();
    void callTicket(int id);
    void finishTicket(int id);

private:
    // Conexão com o banco de dados
    QSqlDatabase db;
};

#endif // QUEUE_MODEL_H