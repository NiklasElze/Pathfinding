#include "area.h"

#include <QPainter>

Area::Area(int width, int height, QGraphicsScene *scene)
{
    setRect(0, 0, width, height);

    if (scene)
    {
        scene->addItem(this);
    }

    QBrush brush = QBrush(QColor(232, 233, 234));
    setBrush(brush);
}
