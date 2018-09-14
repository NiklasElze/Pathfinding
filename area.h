#ifndef AREA_H
#define AREA_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QWidget>



class Area : public QGraphicsRectItem
{
public:
    Area(int width, int height, QGraphicsScene *scene = 0);
};

#endif // AREA_H
