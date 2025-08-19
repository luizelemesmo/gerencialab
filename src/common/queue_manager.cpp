// src/common/queue_manager.cpp

#include "queue_manager.h"
#include "queue_model.h"     // Use cabeçalhos (.h)
#include "ticket_factory.h"  // Use cabeçalhos (.h)

// Inicialização da instância estática
QueueManager* QueueManager::instance = nullptr;

// Construtor privado (pode ficar vazio)
QueueManager::QueueManager() {}

QueueManager* QueueManager::getInstance() {
    if (!instance) {
        instance = new QueueManager();
    }
    return instance;
}

void QueueManager::issueTicket(const QString& examType, bool isPreferential) {
    Ticket ticket = TicketFactory::createTicket(examType, isPreferential);
    model.addTicket(ticket);
    emit queueUpdated();
}

Ticket QueueManager::getNextTicket() {
    auto queue = model.getQueue();
    if (!queue.isEmpty()) {
        return queue.first();
    }
    return Ticket{}; // Retorna um ticket vazio se a fila estiver vazia
}

void QueueManager::callNext() {
    Ticket next = getNextTicket();
    if (next.id != 0) {
        model.callTicket(next.id);
        emit ticketCalled(next);
    }
}

void QueueManager::finishCurrent(int id) {
    model.finishTicket(id);
    emit queueUpdated();
}

QList<Ticket> QueueManager::getCurrentQueue() {
    return model.getQueue();
}