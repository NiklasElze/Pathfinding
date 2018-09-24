#ifndef CHILDMANAGER_H
#define CHILDMANAGER_H

#include "area.h"
#include "proband.h"

class ChildManager
{
private:
    Area *m_Area;
public:
    ChildManager(Area* area);
    Proband* createChild(Proband *mother, Proband *father);
    Proband* onePointRecombination(Proband *mother, Proband *father);
    Proband* twoPointsRecombination(Proband *mother, Proband *father);
    Proband* randomRecombination(Proband *mother, Proband *father);
};

#endif // CHILDMANAGER_H
