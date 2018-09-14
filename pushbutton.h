#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QGraphicsScene>
#include <QPushButton>



class PushButton : public QPushButton
{
public:
    PushButton(QGraphicsScene *scene, std::string text);
};

#endif // PUSHBUTTON_H
