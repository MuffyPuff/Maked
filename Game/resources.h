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
    ll food;
    ll wood;
    ll stone;
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
