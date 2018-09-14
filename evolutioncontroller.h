#ifndef EVOLUTIONCONTROLLER_H
#define EVOLUTIONCONTROLLER_H

#include "childmanager.h"
#include "moveservice.h"
#include "proband.h"
#include "scenemanager.h"

using namespace std;

class EvolutionController
{
private:
    ChildManager *m_ChildManager;
    MoveService *m_MoveService;
    SceneManager *m_SceneManager;
    bool m_TargetReached;
    int m_LastProbandId;
    void createNewGeneration(vector<Proband*> *bestProbands, vector<Proband*> *newGeneration);
    void generateNewPopulation(vector<Proband*> *population, bool removeOld);
    void processGeneration(int generation, vector<Proband*> *population);
    void findClosestProband(vector<Proband*> *closestProbands, vector<Proband*> *population);
    void setClosest(Proband *proband, int lastIndex, vector<Proband*> *closestProbands);
    void calculateDistance(Proband *proband);
public:
    EvolutionController(SceneManager *sceneManager);
    void startEvolution();
};

#endif // EVOLUTIONCONTROLLER_H
