// src/common/queue_manager.h

#ifndef QUEUE_MANAGER_H
#define QUEUE_MANAGER_H

#include <QObject>
#include <QList>
#include "ticket.h" 
#include "queue_model.h"

class QueueManager : public QObject {
    Q_OBJECT

private:
    static QueueManager* instance;
    QueueModel model; 

    QueueManager();

public:
    static QueueManager* getInstance();

    void issueTicket(const QString& examType, bool isPreferential);
    Ticket getNextTicket();
    void callNext();
    void finishCurrent(int id);
    QList<Ticket> getCurrentQueue();

signals:
    void queueUpdated();
    void ticketCalled(const Ticket& ticket);
};

#endif // QUEUE_MANAGER_H