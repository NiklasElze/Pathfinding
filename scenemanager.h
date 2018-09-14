#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "area.h"
#include "moveservice.h"
#include "proband.h"
#include "pushbutton.h"
#include "target.h"

#include <QGraphicsScene>

class SceneManager
{
private:
    QGraphicsScene *m_Scene;
public:
    SceneManager(QGraphicsScene *scene);
    Area* ProbandArea;
    Target* ProbandTarget;
    PushButton* StartButton;
    void createUi();
};

#endif // SCENEMANAGER_H
