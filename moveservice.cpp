#include "moveservice.h"

#include <QDebug>

MoveService::MoveService(Area *area)
{
    m_Area = area;
}

void MoveService::moveProband(Proband *proband, int turn)
{
    int moveX = 0;
    int moveY = 0;

    switch (proband->directions[turn]) {
    case Up:
        moveX = 0;
        moveY = -1;
        break;
    case Left:
        moveX = -1;
        moveY = 0;
        break;
    case Right:
        moveX = 1;
        moveY = 0;
        break;
    case UpLeft:
        moveX = -1;
        moveY = -1;
        break;
    case UpRight:
        moveX = 1;
        moveY = -1;
        break;
    case Down:
        moveX = 0;
        moveY = 1;
        break;
    case DownLeft:
        moveX = -1;
        moveY = 1;
        break;
    case DownRight:
        moveX = 1;
        moveY = 1;
        break;
    default:
        break;
    }

    int toX = proband->x() + proband->boundingRect().x() + moveX;
    int toY = proband->y() + proband->boundingRect().y() + moveY;

    if (!isValidMove(toX, toY))
    {
        return;
    }

    proband->moveBy(moveX, moveY);
}

bool MoveService::isValidMove(int toX, int toY)
{
    return !(isHittingBottomBorder(toY) ||
            isHittingTopBorder(toY) ||
            isHittingLeftBorder(toX) ||
            isHittingRightBorder(toX));
}

bool MoveService::isHittingBottomBorder(int toY)
{
    int border = m_Area->boundingRect().y() + m_Area->boundingRect().size().height();

    return toY + 10 >= border;
}

bool MoveService::isHittingTopBorder(int toY)
{
    int border = m_Area->boundingRect().y();

    return toY <= border;
}

bool MoveService::isHittingLeftBorder(int toX)
{
    int border = m_Area->boundingRect().x();

    return toX <= border;
}

bool MoveService::isHittingRightBorder(int toX)
{
    int border = m_Area->boundingRect().x() + m_Area->boundingRect().size().width();

    return toX + 10 >= border;
}
