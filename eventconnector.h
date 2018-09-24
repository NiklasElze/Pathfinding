#ifndef EVENTCONNECTOR_H
#define EVENTCONNECTOR_H

#include "evolutioncontroller.h"

class EventConnector : public QObject{
    Q_OBJECT

private:
    EvolutionController *m_EvolutionController;
    SceneManager *m_SceneManager;
private slots:
    void startEvolution();
    void checkMaxLength();
public:
    EventConnector(SceneManager *sceneManager, EvolutionController *evolutionController);
    void connectEvents();
};

#endif // EVENTCONNECTOR_H
