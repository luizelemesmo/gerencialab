// src/common/ticket_factory.cpp

#include "ticket_factory.h"
#include <QRandomGenerator>
#include <QDateTime> // Incluído para QDateTime::currentDateTime()

// Adicionamos o prefixo "TicketFactory::" ao método estático
Ticket TicketFactory::createTicket(const QString& examType, bool isPreferential) {
    Ticket ticket;
    ticket.id = QRandomGenerator::global()->bounded(10000);  // ID aleatório simulado
    ticket.examType = examType;
    ticket.isPreferential = isPreferential;
    ticket.issueTime = QDateTime::currentDateTime();
    ticket.status = "waiting";
    return ticket;
}