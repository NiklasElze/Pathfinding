#ifndef PROXY_H
#define PROXY_H


class Proxy
{
public:
    Proxy(int x, int y);
    Proxy *nextProxy;
    int distance;
    int x;
    int y;
};

#endif // PROXY_H
