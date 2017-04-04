#ifndef TRADE_H
#define TRADE_H

#include <QObject>
#include "player.h"
class Trade : public QObject
{
    Q_OBJECT
    Player *firstPlayer;
    Player *secondPlayer;
    ResourceType firstPlayerType;
    ull firstPlayerAmount;
    ResourceType secondPlayerType;
    ull secondPlayerAmount;


public:
    explicit Trade(QObject *parent = 0);
    void startTrade(Player *trader);
    void offerTrade(ResourceType requestedResource, ull requestedAmount, ResourceType offeredResource, ull offeredAmount);
    void trade(ResourceType resource, ull amount);
    Player* getFirstPlayer() { return firstPlayer; }
    Player* getSecondPlayer() { return secondPlayer; }


signals:

public slots:
};

#endif // TRADE_H
