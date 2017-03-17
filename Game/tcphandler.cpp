#include "tcphandler.h"

TcpHandler::TcpHandler(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, QTcpServer::newConnection, this, TcpHandler::newConnection);
}

void TcpHandler::newConnection()
{
    emit newPlayer(clients.size());
    clients.append(server->nextPendingConnection());
}
