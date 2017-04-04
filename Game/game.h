#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QList>
#include "player.h"
#include "trade.h"
#include "tcphandler.h"
class Game : public QObject
{
    Q_OBJECT
    QList<Player *> players;
    QList<Trade *> activeTrades;
    TcpHandler *tcpHandler;
public:
    explicit Game(QObject *parent = 0);
signals:
public slots:
    void createTrade(qint8 clientID, ResourceType typeRequested, ull amountRequested, ResourceType typeOffered, ull amountOffered);
    void addPlayer(qint8 id);
};

#endif // GAME_H
