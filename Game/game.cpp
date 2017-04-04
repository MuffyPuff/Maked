#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{
    tcpHandler = new TcpHandler(this);

    //add connections
    connect(tcpHandler, SIGNAL(newPlayer(qint8)), this, SLOT(addPlayer(qint8)));
    connect(tcpHandler, SIGNAL(createTrade(qint8,ResourceType,ull,ResourceType,ull)), this, SLOT(createTrade(qint8,ResourceType,ull,ResourceType,ull)));
}

void Game::createTrade(qint8 clientID,
                       ResourceType typeRequested,
                       ull amountRequested,
                       ResourceType typeOffered,
                       ull amountOffered)
{
    Trade *newTrade = new Trade;
    newTrade->startTrade(players[clientID]);
    newTrade->offerTrade(typeRequested, amountRequested, typeOffered, amountOffered);
    activeTrades.append(newTrade);
}

void Game::addPlayer(qint8 id)
{
    players.append(new Player(this));
    players.back()->setID(id);
}
