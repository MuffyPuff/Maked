#include "player.h"

Player::Player(QObject *parent) : QObject(parent)
{

}

void Player::setResource(ResourceType type)
{
    resourceType = type;
}

Player::endOfTurnUpdate()
{
    switch(resourceType)
    {
        case ResourceType::Food:
            resources.updateFood(200);
        break;
        case ResourceType::Wood:
            resources.updateWood(200);
        break;
        case ResourceType::Stone:
            resources.updateStone(200);
        break;
    }
    resources.checkResources();
}
