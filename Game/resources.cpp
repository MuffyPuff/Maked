#include "resources.h"

Resources::Resources()
{
    //connect(this, SIGNAL(resourcesChanged()), this, SLOT(checkResources()));
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

void Resources::updateFood(ll foodChange)
{
    food  += foodChange;
}

void Resources::updateWood(ll woodChange)
{
    wood  += woodChange;
}

void Resources::updateStone(ll stoneChange)
{
    stone += stoneChange;
}

void Resources::updateMoney(ll moneyChange)
{
    money += moneyChange;
}
/*
void Resources::updateResources(ll foodChange, ll woodChange, ll stoneChange, ll moneyChange)
{
    food  += foodChange;
    wood  += woodChange;
    stone += stoneChange;
    money += moneyChange;
    emit resourcesChanged();
}
*/
/*******************************
 *           TODO              *
 *******************************/
void Resources::checkResources()
{
    if(food  < 0 || wood < 0 || stone < 0 || money < 0) emit gameOver();

}

