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
            ull offeredResource = static_cast<ull>(qson.object().take("offeredResource").toInt());
            ResourceType requestedResourceType = static_cast<ResourceType>(qson.object().take("requestedResourceType").toInt());
            ull requestedResource = static_cast<ull>(qson.object().take("requestedResource").toInt());
            emit createTrade(clientID, requestedResourceType, requestedResource, offeredResourceType, offeredResource);
            break;
        case Instructions::TRADE_ACCEPT:
            qint8 fromPlayer = static_cast<qint8>(qson.object().take("fromPlayer").toInt());
            emit acceptTrade(clientID, fromPlayer);
            break;
        case Instructions::TRADE_DECLINE:
            qint8 fromPlayer = static_cast<qint8>(qson.object().take("fromPlayer").toInt());
            emit declineTrade(clientID, fromPlayer);
            break;
    }
}
