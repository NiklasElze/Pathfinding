#ifndef PROXYSERVICE_H
#define PROXYSERVICE_H

#include "obstaclecontroller.h"
#include "proband.h"
#include "proxy.h"
#include "target.h"

using namespace std;

class ProxyService
{
private:
    ObstacleController *m_ObstacleController;
    void getProxy(int fromX, int fromY, int toX, int toY, vector<Proxy *> *proxies);
public:
    ProxyService(ObstacleController *obstacleController);
    void setProxies(Target *target, Proband *proband, vector<Proxy*> *proxies);
};

#endif // PROXYSERVICE_H
