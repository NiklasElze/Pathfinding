#ifndef EVENTCONNECTOR_H
#define EVENTCONNECTOR_H

#include "evolutioncontroller.h"



class EventConnector : public QObject{
    Q_OBJECT

private:
    EvolutionController *m_EvolutionController;
public slots:
    void startEvolution();
public:
    EventConnector();
    void setEvolutionController(EvolutionController *evolutionController);
};

#endif // EVENTCONNECTOR_H
