#ifndef TCPHANDLER_H
#define TCPHANDLER_H

#include <QObject>
#include "player.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
class TcpHandler : public QObject
{
    Q_OBJECT
    QList<QTcpSocket *> clients;
    QTcpServer *server;
public:
    explicit TcpHandler(QObject *parent = 0);

signals:
    void newPlayer(qint8);
public slots:
    void newConnection();

};

#endif // TCPHANDLER_H
