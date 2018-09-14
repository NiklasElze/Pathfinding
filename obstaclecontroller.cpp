#include "obstaclecontroller.h"

ObstacleController::ObstacleController(Area *area)
{
    m_Area = area;
    m_Obstacles = new vector<Obstacle*>();
}

void ObstacleController::LoadPreset(int presetId)
{
    Obstacle *firstObstacle = new Obstacle(300, 400, 200, 10);
    firstObstacle->setParentItem(m_Area);


    m_Obstacles->resize(1);
    m_Obstacles->at(0) = firstObstacle;
}

bool ObstacleController::hitsObstalce(int newX, int newY)
{
    for (int i = 0; i < m_Obstacles->size(); i++)
    {
        Obstacle *obstacle = m_Obstacles->at(i);

        if (pointIsInObstacle(newX, newY, obstacle))
        {
            return true;
        }
    }

    return false;
}

Obstacle* ObstacleController::getObstacle(int x, int y)
{
    /*for (int i = 0; i < m_Obstacles->size(); i++)
    {
        Obstacle *obstacle = m_Obstacles->at(i);

        if (pointIsInObstacle(x, y, obstacle))
        {
            return obstacle;
        }
    }*/

    return new Obstacle(1, 1, 1, 1);
}

bool ObstacleController::pointIsInObstacle(int x, int y, Obstacle *obstacle)
{
    return x >= obstacle->boundingRect().x() && x <= obstacle->boundingRect().x() + obstacle->boundingRect().width() &&
            y >= obstacle->boundingRect().y() && y <= obstacle->boundingRect().y() + obstacle->boundingRect().height();
}

bool ObstacleController::pathContainsObstacle(int fromX, int fromY, int toX, int toY)
{
    for (int i = 0; i < m_Obstacles->size(); i++)
    {
        Obstacle *obstacle = m_Obstacles->at(i);

        if (fieldIsHerizontalyInObstacle(fromX, fromY, toX, toY, obstacle))
        {
            return true;
        }

        if (fieldIsVerticallyInObstacle(fromX, fromY, toX, toY, obstacle))
        {
            return true;
        }

        if (obstacleIsPartiallyVerticallyInField(fromX, fromY, toX, toY, obstacle))
        {
            return true;
        }

        if (obstacleIsPartiallyHorizontallyInField(fromX, fromY, toX, toY, obstacle))
        {
            return true;
        }
    }

    return false;
}

bool ObstacleController::fieldIsHerizontalyInObstacle(int x1, int y1, int x2, int y2, Obstacle *obstacle)
{
    return x1 >= obstacle->boundingRect().x() && x1 <= obstacle->boundingRect().x() + obstacle->boundingRect().width()
            && x2 >= obstacle->boundingRect().x() && x2 <= obstacle->boundingRect().x() + obstacle->boundingRect().width()
            && obstacleIsPartiallyVerticallyInField(x1, y1, x2, y2, obstacle);
}

bool ObstacleController::fieldIsVerticallyInObstacle(int x1, int y1, int x2, int y2, Obstacle *obstacle)
{
    return y1 >= obstacle->boundingRect().y() && y1 <= obstacle->boundingRect().y() + obstacle->boundingRect().height()
            && y2 >= obstacle->boundingRect().y() && y2 <= obstacle->boundingRect().y() + obstacle->boundingRect().height()
            && obstacleIsPartiallyHorizontallyInField(x1, y1, x2, y2, obstacle);
}

bool ObstacleController::obstacleIsPartiallyVerticallyInField(int x1, int y1, int x2, int y2, Obstacle *obstacle)
{
    return (obstacle->boundingRect().y() >= y1 && obstacle->boundingRect().y() <= y2) || (obstacle->boundingRect().y() >= y2 && obstacle->boundingRect().y() <= y1)
            || (obstacle->boundingRect().y() + obstacle->boundingRect().height() >= y1 && obstacle->boundingRect().y() + obstacle->boundingRect().height() <= y2)
                || (obstacle->boundingRect().y() + obstacle->boundingRect().height() >= y2 && obstacle->boundingRect().y() + obstacle->boundingRect().height() <= y1);
}

bool ObstacleController::obstacleIsPartiallyHorizontallyInField(int x1, int y1, int x2, int y2, Obstacle *obstacle)
{
    return (obstacle->boundingRect().x() >= x1 && obstacle->boundingRect().x() <= x2) || (obstacle->boundingRect().x() >= x2 && obstacle->boundingRect().x() <= x1)
            || (obstacle->boundingRect().x() + obstacle->boundingRect().width() >= x1 && obstacle->boundingRect().x() + obstacle->boundingRect().width() <= x2)
                || (obstacle->boundingRect().x() + obstacle->boundingRect().width() >= x2 && obstacle->boundingRect().x() + obstacle->boundingRect().width() <= x1);
}
