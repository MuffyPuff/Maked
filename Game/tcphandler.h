#ifndef TCPHANDLER_H
#define TCPHANDLER_H

#include <QObject>
#include "player.h"
#include "trade.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QSignalMapper>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
class TcpHandler : public QObject
{
    Q_OBJECT
    QList<QTcpSocket *> clients;
    QTcpServer *server;
    QSignalMapper *mapper;
    enum class Instructions
    {
        TRADE_OFFER, // player is offering a new trade
        TRADE_ACCEPT, // player accepted another player's trade
        TRADE_DECLINE, // player declined another player's trade
        END_TURN
    };

public:
    explicit TcpHandler(QObject *parent = 0);

signals:
    void newPlayer(qint8);
    void newInstruction(QJsonDocument, qint8);
    void finishedTurn(qint8 clientID);
    void createTrade(qint8 clientID,
                     ResourceType requestedResource,
                     ull requestedAmount,
                     ResourceType offeredResource,
                     ull offeredAmount);
    void acceptTrade(qint8 clientID, qint8 fromPlayer);
    void declineTrade(qint8 clientID, qint8 fromPlayer);
public slots:
    void newConnection();
    void readData(int);
    void interpretInstruction(const QJsonDocument& qson, qint8);
    void sendOffer(Trade *);


};

#endif // TCPHANDLER_H
