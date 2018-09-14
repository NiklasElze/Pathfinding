#include "obstacle.h"

#include <QBrush>

Obstacle::Obstacle(int x, int y, int width, int height)
{
    setRect(x, y, width, height);
    QBrush brush = QBrush(QColor(93, 134, 222));
    setBrush(brush);
}
