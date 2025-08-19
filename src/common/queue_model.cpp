// src/common/queue_model.cpp

#include "queue_model.h"
#include <QSqlQuery> // QSqlQuery é um detalhe de implementação, então o include fica aqui.

// O construtor agora é qualificado com o nome da classe
QueueModel::QueueModel() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("gerencialab.db");
    if (!db.open()) {
        // Tratar erro
    }
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS tickets (id INT PRIMARY KEY, examType TEXT, isPreferential BOOL, issueTime DATETIME, status TEXT)");
}

// Todos os outros métodos também recebem o prefixo "QueueModel::"
void QueueModel::addTicket(const Ticket& ticket) {
    QSqlQuery query;
    query.prepare("INSERT INTO tickets (id, examType, isPreferential, issueTime, status) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(ticket.id);
    query.addBindValue(ticket.examType);
    query.addBindValue(ticket.isPreferential);
    query.addBindValue(ticket.issueTime);
    query.addBindValue(ticket.status);
    query.exec();
}

QList<Ticket> QueueModel::getQueue() {
    QList<Ticket> queue;
    QSqlQuery query("SELECT * FROM tickets WHERE status = 'waiting' ORDER BY isPreferential DESC, issueTime ASC");
    while (query.next()) {
        Ticket t;
        t.id = query.value(0).toInt();
        t.examType = query.value(1).toString();
        t.isPreferential = query.value(2).toBool();
        t.issueTime = query.value(3).toDateTime();
        t.status = query.value(4).toString();
        queue.append(t);
    }
    return queue;
}

void QueueModel::callTicket(int id) {
    QSqlQuery query;
    query.prepare("UPDATE tickets SET status = 'called' WHERE id = ?");
    query.addBindValue(id);
    query.exec();
}

void QueueModel::finishTicket(int id) {
    QSqlQuery query;
    query.prepare("UPDATE tickets SET status = 'finished' WHERE id = ?");
    query.addBindValue(id);
    query.exec();
}