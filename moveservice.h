#ifndef MOVESERVICE_H
#define MOVESERVICE_H

#include "area.h"
#include "proband.h"

class MoveService
{
private:
    Area *m_Area;
    bool isValidMove(int toX, int toY);
    bool isHittingBottomBorder(int toY);
    bool isHittingTopBorder(int toY);
    bool isHittingLeftBorder(int toX);
    bool isHittingRightBorder(int toX);
public:
    MoveService(Area* area);
    void moveProband(Proband *proband, int turn);
};

#endif // MOVESERVICE_H
