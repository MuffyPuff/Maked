#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QList>
#include "player.h"
#include "trade.h"

class Game : public QObject
{
    Q_OBJECT
    QList<Player *> players;
    QList<Trade *> activeTrades;
public:
    explicit Game(QObject *parent = 0);
signals:

public slots:
    //void instructionRecieved(Player *player, );
    void addPlayer(qint8 id);
};

#endif // GAME_H
