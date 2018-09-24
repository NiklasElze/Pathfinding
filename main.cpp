#include "eventconnector.h"
#include "evolutioncontroller.h"
#include "scenemanager.h"

#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();

    SceneManager *sceneManager = new SceneManager(scene);

    QGraphicsView *view = new QGraphicsView();
    view->setScene(scene);
    view->setFixedSize(800, 600);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sceneManager->createUi();
    view->show();

    EvolutionController *evolutionController = new EvolutionController(sceneManager);

    EventConnector *eventConnector = new EventConnector(sceneManager, evolutionController);
    eventConnector->connectEvents();

    return a.exec();
}
