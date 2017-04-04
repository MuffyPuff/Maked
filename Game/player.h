#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QTextStream>
#include "resources.h"

using ull = unsigned long long;
using ll = long long;
using unit = unsigned int;
enum class ResourceType
{
    Food,
    Wood,
    Stone
};

class Player : public QObject
{
    Q_OBJECT
    Resources resources;
    ResourceType resourceType;
    qint8 socketID;
public:
    explicit Player(QObject *parent = 0);
    void setResource(ResourceType type);
    void setID(qint8 id) {socketID = (id);}
    qint8 getID(){ return socketID; }
signals:

public slots:
    endOfTurnUpdate();
};

#endif // PLAYER_H
