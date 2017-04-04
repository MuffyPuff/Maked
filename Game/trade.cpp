#include "trade.h"

Trade::Trade(QObject *parent) : QObject(parent)
{

}

void Trade::startTrade(Player *trader)
{
    firstPlayer = trader;
}

void Trade::offerTrade(ResourceType requestedResource,
                       ull requestedAmount,
                       ResourceType offeredResource,
                       ull offeredAmount)
{
    firstPlayerAmount = offeredAmount;
    firstPlayerType = offeredResource;
}

void Trade::trade(ResourceType resource, ull amount)
{

}
