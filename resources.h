#ifndef RESOURCES_H
#define RESOURCES_H
#include <QObject>
#include <QTextStream>

using ull = unsigned long long;
using ll = long long;
using unit = unsigned int;
class Resources: public QObject
{
    Q_OBJECT
    //Q_.PROPERTY(ll food READ foodGet WRITE updateFood NOTIFY changedFood)
    ll food;
    //Q_.PROPERTY(ll wood READ woodGet WRITE updateWood NOTIFY changedWood)
    ll wood;
    //Q_.PROPERTY(ll stone READ stoneGet WRITE updateStone NOTIFY changedStone)
    ll stone;
    //Q_.PROPERTY(ll money READ moneyGet WRITE updateMoney NOTIFY changedMoney)
    ll money;

public:
    Resources();
    void distrubuteResources(); //Set resources to certain values at the begining
    void outputResources();
public slots:
    //void updateResources(ll foodChange, ll woodChange, ll stoneChange, ll moneyChange);
    void updateFood  (ll foodChange );
    void updateWood  (ll woodChange );
    void updateStone (ll stoneChange);
    void updateMoney (ll moneyChange);
    void checkResources();
signals:
    //resourcesChanged();
    gameOver();

};

#endif // RESOURCES_H
