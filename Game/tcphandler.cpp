#include "tcphandler.h"

TcpHandler::TcpHandler(QObject *parent) : QObject(parent)
{
    mapper = new QSignalMapper(this);
    server = new QTcpServer(this);
    connect(server, QTcpServer::newConnection, this, TcpHandler::newConnection);
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(readData(int)));
    connect(this, SIGNAL(newInstruction(QJsonDocument&,qint8)), this, SLOT(interpretInstruction(QJsonDocument,qint8)));
}
//called when server detects new connection
//it just works, k?
void TcpHandler::newConnection()
{
    emit newPlayer(clients.size());
    clients.append(server->nextPendingConnection());
    mapper->setMapping(clients.last(), clients.length()-1);
    connect(clients.last(), SIGNAL(readyRead()), mapper, SLOT(map()));
}

void TcpHandler::readData(int clientID)
{
    QByteArray data = clients[clientID]->readAll();
    emit newInstruction(QJsonDocument(QJsonDocument::fromBinaryData(data)), clientID);
}

void TcpHandler::interpretInstruction(const QJsonDocument &qson, qint8 clientID)
{
    Instructions recievedInstructionType = static_cast<Instructions>(qson.object().take("instruction").toInt());
    switch(recievedInstructionType)
    {
        case Instructions::END_TURN:
            emit finishedTurn(clientID);
            break;
        case Instructions::TRADE_OFFER:
            ResourceType offeredResourceType = static_cast<ResourceType>(qson.object().take("offeredResourceType").toInt());
            ull offeredResource = static_cast<ResourceType>(qson.object().take("offeredResource").toInt());
    }
}
