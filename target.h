#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

class Target : public QGraphicsRectItem
{
public:
    Target(int x, int y, int width, int height);
    int getTargetX();
    int getTargetY();
};

#endif // TARGET_H
