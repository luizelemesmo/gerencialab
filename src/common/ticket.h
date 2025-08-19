#ifndef TICKET_H
#define TICKET_H

#include <QString>
#include <QDateTime>

struct Ticket {
    int id;
    QString examType;
    bool isPreferential;
    QDateTime issueTime;
    QString status;  // "waiting", "called", "finished"
};

#endif