#include "proxyservice.h"

ProxyService::ProxyService(ObstacleController *obstacleController)
{
    m_ObstacleController = obstacleController;
}

void ProxyService::setProxies(Target *target, Proband *proband, vector<Proxy*> *proxies)
{
    int fromX = proband->boundingRect().x();
    int fromY = proband->boundingRect().y();
    int toX = target->getTargetX();
    int toY = target->getTargetY();

    if (m_ObstacleController->pathContainsObstacle(fromX, fromY, toX, toY))
    {

    }
}

void ProxyService::getProxy(int fromX, int fromY, int toX, int toY, vector<Proxy*> *proxies)
{
    /*int fromX2 = round((fromX + toX) / 2);
    int fromY2 = round((fromY + toY) / 2);

    bool blockedByObstacle = false;

    if (m_ObstacleController->pathContainsObstacle(fromX2, fromY2, toX, toY))
    {
        blockedByObstacle = true;
        getProxy(fromX2, fromY2, toX, toY, proxies);
    }

    if (m_ObstacleController->pathContainsObstacle(fromX, fromY, fromX2, fromY2))
    {
        blockedByObstacle = true;
        getProxy(fromX, fromY, fromX2, fromY2, proxies);
    }

    if (!blockedByObstacle && m_ObstacleController->pointIsInObstacle(fromX, fromY))
    {
        Proxy *proxy = new Proxy(fromX, fromY);

    }*/
}
