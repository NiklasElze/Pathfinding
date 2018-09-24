#include "evolutioncontroller.h"
#include "globalconfig.h"
#include "math.h"

#include <QCoreApplication>

using namespace std;

EvolutionController::EvolutionController(SceneManager *sceneManager)
{
    m_ChildManager = new ChildManager(sceneManager->ProbandArea);
    m_MoveService = new MoveService(sceneManager->ProbandArea);
    m_SceneManager = sceneManager;
    m_TargetReached = false;
}

void EvolutionController::startEvolution()
{
    m_LastProbandId = 0;
    vector<Proband*> *population = new vector<Proband*>();
    population->resize(GlobalConfig::PopulationSize);

    generateNewPopulation(population, false);

    for (int i = 0; i < GlobalConfig::NumberOfGenerations; i++)
    {
        std::string generationInfo = "Starting generation ";
        generationInfo += std::to_string(i + 1);

        processGeneration(i + 1, population);
    }
}

void EvolutionController::processGeneration(int generation, vector<Proband*> *population)
{
    try
    {
        for (int i = 0; i < GlobalConfig::NumberOfSteps; i++)
        {
            for (int j = 0; j < GlobalConfig::PopulationSize; j++)
            {
                Proband *proband = population->at(j);
                m_MoveService->moveProband(proband, i);
                calculateDistance(proband);

                if (proband->distance <= 5 && !proband->targetReached)
                {
                    proband->targetReached = true;
                    proband->stepsToTarget = i + 1;
                }
            }

            bool showSteps = GlobalConfig::ShowSteps;

            if (showSteps)
            {
                QCoreApplication::processEvents();
            }
        }

        vector<Proband*> *closestProbands = new vector<Proband*>();
        closestProbands->resize(GlobalConfig::NumberOfBestProbands);
        findClosestProband(closestProbands, population);

        bool showResults = GlobalConfig::ShowGenerationResult;

        if (showResults)
        {
            QCoreApplication::processEvents();
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

        if (generation < GlobalConfig::NumberOfGenerations)
        {
            createNewGeneration(closestProbands, population);
            return;
        }

        Proband *bestProband = population->at(0);

        for (int i = 1; i < GlobalConfig::PopulationSize; i++)
        {
            if (population->at(i)->targetReached && population->at(i)->stepsToTarget < bestProband->stepsToTarget)
            {
                bestProband = population->at(i);
            }
        }
    }
    catch (const std::exception& e)
    {
        string text = "Exception: ";
        text += e.what();
        qDebug(text.c_str());
    }
}

void EvolutionController::createNewGeneration(vector<Proband*> *bestProbands, vector<Proband*> *newGeneration)
{
    for (int i = 0; i < GlobalConfig::NumberOfBestProbands; i++)
    {
        Proband *top10Proband = new Proband(bestProbands->at(i)->directions);
        top10Proband->setParentItem(m_SceneManager->ProbandArea);
        newGeneration->at(i)->removeFromUi();
        newGeneration->at(i) = top10Proband;
    }

    for (int i = GlobalConfig::NumberOfBestProbands; i < GlobalConfig::PopulationSize; i++)
    {
        int fatherIndex = rand() % GlobalConfig::NumberOfBestProbands;
        int motherIndex = rand() % GlobalConfig::NumberOfBestProbands;

        while (motherIndex == fatherIndex)
        {
            motherIndex = rand() % GlobalConfig::NumberOfBestProbands;
        }

        Proband *mother = newGeneration->at(motherIndex);
        Proband *father = newGeneration->at(fatherIndex);

        Proband *child = m_ChildManager->createChild(mother, father);
        child->setParentItem(m_SceneManager->ProbandArea);
        child->id = ++m_LastProbandId;

        newGeneration->at(i)->removeFromUi();
        newGeneration->at(i) = child;
    }
}

void EvolutionController::generateNewPopulation(vector<Proband*> *population, bool removeOld = false)
{
    for (int i = 0; i < GlobalConfig::PopulationSize; i++)
    {
        if (removeOld)
        {
            population->at(i)->removeFromUi();
        }

        Proband *proband = new Proband();
        proband->setParentItem(m_SceneManager->ProbandArea);
        proband->id = ++m_LastProbandId;
        population->at(i) = proband;
    }
}

void EvolutionController::findClosestProband(vector<Proband*> *closestProbands, vector<Proband*> *population)
{
    for (int i = 0; i < GlobalConfig::PopulationSize; i++)
    {
        Proband *proband = population->at(i);

        setClosest(proband, 0, closestProbands);
    }

    for (int i = 0; i < GlobalConfig::NumberOfBestProbands; i++)
    {
        closestProbands->at(i)->markAsClosest();
    }
}

void EvolutionController::setClosest(Proband *proband, int lastIndex, vector<Proband*> *closestProbands)
{
    if (lastIndex >= GlobalConfig::NumberOfBestProbands)
    {
        return;
    }

    if (closestProbands->at(lastIndex) == 0)
    {
        closestProbands->at(lastIndex) = proband;
        return;
    }

    if (lastIndex >= 0 && lastIndex < GlobalConfig::NumberOfBestProbands && closestProbands->at(lastIndex)->distance >= proband->distance)
    {
        Proband *tempProband = proband;

        for (lastIndex; lastIndex < GlobalConfig::NumberOfBestProbands; lastIndex++)
        {
            Proband *lastProband = tempProband;
            tempProband = closestProbands->at(lastIndex);
            closestProbands->at(lastIndex) = lastProband;
        }

        return;
    }

    if (lastIndex >= 0 && lastIndex < GlobalConfig::NumberOfBestProbands && closestProbands->at(lastIndex)->distance < proband->distance)
    {
        setClosest(proband, ++lastIndex, closestProbands);
        return;
    }
}

void EvolutionController::calculateDistance(Proband *proband)
{
    int targetX = m_SceneManager->ProbandTarget->getTargetX();
    int targetY = m_SceneManager->ProbandTarget->getTargetY();

    int probandX = proband->x() + proband->boundingRect().x();
    int probandY = proband->y() + proband->boundingRect().y();

    int distanceX = 0;
    int distanceY = 0;

    distanceX = std::abs(targetX - probandX);
    distanceY = std::abs(targetY - probandY);

    proband->setDistance(distanceX + distanceY);
}
