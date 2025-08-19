// src/common/ticket_factory.h

#ifndef TICKET_FACTORY_H
#define TICKET_FACTORY_H

#include "ticket.h"
#include <QString>

class TicketFactory {
public:
    static Ticket createTicket(const QString& examType, bool isPreferential);
};

#endif // TICKET_FACTORY_H