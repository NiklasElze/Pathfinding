#include "pushbutton.h"

PushButton::PushButton(QGraphicsScene *scene, std::string text)
{
    setText(text.c_str());
    scene->addWidget(this);
}
