#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{

}

void Game::addPlayer(qint8 id)
{
    players.append(new Player(this));
    players.back()->setID(id);
}
