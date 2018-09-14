#include "area.h"
#include "proband.h"
#include "pushbutton.h"
#include "scenemanager.h"
#include "target.h"

#include <QCoreApplication>
#include <QDebug>
#include <iterator>

SceneManager::SceneManager(QGraphicsScene *scene)
{
    m_Scene = scene;
}

void SceneManager::createUi()
{
    m_Scene->setSceneRect(0, 0, 800, 600);
    StartButton = new PushButton(m_Scene, "Start");

    ProbandArea = new Area(800, 500);
    m_Scene->addItem(ProbandArea);
    ProbandArea->setPos(0, 50);

    ProbandTarget = new Target(400, 0, 20, 20);
    ProbandTarget->setParentItem(ProbandArea);
}
