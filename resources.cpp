#include "resources.h"

Resources::Resources()
{
    connect(this, SIGNAL(resourcesChanged()), this, SLOT(checkResources()));
}

void Resources::distrubuteResources()
{
   money = wood = stone = food = 5000;
}

void Resources::outputResources()
{
    QTextStream console(stdout);
    console << "Food\t: "  << food  << "\n";
    console << "Wood\t: "  << wood  << "\n";
    console << "Money\t: " << money << "\n" ;
    console << "Stone\t: " << stone << "\n";
}

void Resources::updateResources(ll foodChange, ll woodChange, ll stoneChange, ll moneyChange)
{
    food  += foodChange;
    wood  += woodChange;
    stone += stoneChange;
    money += moneyChange;
    emit resourcesChanged();
}

void Resources::checkResources()
{/*
    if(food  < 0) gameOver();
    if(wood  < 0) gameOver();
    if(money < 0) gameOver();
    if(stone < 0) gameOver();*/
}
