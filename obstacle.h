#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <qgraphicsitem.h>

class Obstacle : public QGraphicsRectItem
{
public:
    Obstacle(int x, int y, int width, int height);
};

#endif // OBSTACLE_H
