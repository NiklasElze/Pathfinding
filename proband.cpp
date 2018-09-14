#include "proband.h"

#include <QBrush>
#include <QCoreApplication>
#include <QDebug>


Proband::Proband()
{
    setRect(400, 490, 10, 10);

    generateDirections();
}

Proband::Proband(Direction directs[])
{
    for (int i = 0; i < 1000; i++)
    {
        directions[i] = directs[i];
    }

    setRect(400, 490, 10, 10);
}

void Proband::generateDirections()
{
    for (int index = 0; index < 1000; index++)
    {
        int random = rand() % 8;
        directions[index] = static_cast<Direction>(random);
    }
}

void Proband::setDistance(int dist)
{
    distance = dist;
    std::string tooltip = std::to_string(id);
    tooltip += " | ";
    tooltip += std::to_string(dist);

    setToolTip(tooltip.c_str());
}

void Proband::markAsClosest()
{
    QBrush brush = QBrush(Qt::green);
    setBrush(brush);
}

void Proband::removeFromUi()
{
    if (scene()->items().contains(this))
    {
        scene()->removeItem(this);
    }

    delete this;
}
