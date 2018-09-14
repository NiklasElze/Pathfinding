#ifndef OBSTACLECONTROLLER_H
#define OBSTACLECONTROLLER_H

#include "area.h"
#include "obstacle.h"

using namespace std;

class ObstacleController
{
private:
    Area *m_Area;
    vector<Obstacle*> *m_Obstacles;
    bool fieldIsHerizontalyInObstacle(int x1, int y1, int x2, int y2, Obstacle *obstacle);
    bool fieldIsVerticallyInObstacle(int x1, int y1, int x2, int y2, Obstacle *obstacle);
    bool obstacleIsPartiallyVerticallyInField(int x1, int y1, int x2, int y2, Obstacle *obstacle);
    bool obstacleIsPartiallyHorizontallyInField(int x1, int y1, int x2, int y2, Obstacle *Obstacle);
    bool pointIsInObstacle(int x, int y, Obstacle *obstacle);
public:
    ObstacleController(Area * area);
    void LoadPreset(int presetId);
    bool hitsObstalce(int newX, int newY);
    bool pathContainsObstacle(int fromX, int toX, int fromY, int toY);
    Obstacle* getObstacle(int x, int y);
};

#endif // OBSTACLECONTROLLER_H
