#include "target.h"

Target::Target(int x, int y, int width, int height)
{
    setRect(x, y, width, height);
    QBrush brush = QBrush(QColor(201, 0, 0));
    setBrush(brush);
}

int Target::getTargetX()
{
    return boundingRect().x() + round(boundingRect().width() / 2);
}

int Target::getTargetY()
{
    return boundingRect().y() + round(boundingRect().height() / 2);
}
