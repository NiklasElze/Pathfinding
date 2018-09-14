#include "eventconnector.h"

void EventConnector::startEvolution()
{
    m_EvolutionController->startEvolution();
}

EventConnector::EventConnector()
{
}

void EventConnector::setEvolutionController(EvolutionController *evolutionController)
{
    m_EvolutionController = evolutionController;
}
