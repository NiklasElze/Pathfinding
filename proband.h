#ifndef PROBAND_H
#define PROBAND_H

#include <QGraphicsRectItem>
#include <direction.h>
#include <chrono>
#include <thread>
#include <QGraphicsScene>

class Proband : public QGraphicsRectItem
{
private:
    bool m_IsDead = false;
    void generateDirections();
public:
    Proband();
    Proband(Direction directs[]);
    int id;
    bool targetReached;
    int distance;
    int stepsToTarget;
    Direction directions[1000];
    void setDistance(int dist);
    void markAsClosest();
    void removeFromUi();
};

#endif // PROBAND_H
