#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{

}

void Game::createTrade(qint8 clientID, ResourceType typeRequested, ull amountRequested, ResourceType typeOffered, ull amountOffered)
{

}

void Game::addPlayer(qint8 id)
{
    players.append(new Player(this));
    players.back()->setID(id);
}
