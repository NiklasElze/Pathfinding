#include "GlobalConfig.h"
#include "childmanager.h"

ChildManager::ChildManager(Area* area)
{
    m_Area = area;
}

Proband* ChildManager::createChild(Proband *mother, Proband *father)
{
    Proband *child = randomRecombination(mother, father);

    return child;
}

Proband* ChildManager::onePointRecombination(Proband *mother, Proband *father)
{
    Proband *child = new Proband(mother->directions);

    int middle = rand() % GlobalConfig::NumberOfSteps;

    for (int i = 0; i < middle; i++)
    {
        int mutationValue = rand() % 100;

        if (mutationValue < GlobalConfig::MutationChance)
        {
            int random = rand() % 8;
            child->directions[i] = static_cast<Direction>(random);
        }
        else
        {
            child->directions[i] = mother->directions[i];
        }
    }

    for (int i = middle; i < GlobalConfig::NumberOfSteps; i++)
    {
        int mutationValue = rand() % 100;

        if (mutationValue < GlobalConfig::MutationChance)
        {
            int random = rand() % 8;
            child->directions[i] = static_cast<Direction>(random);
        }
        else
        {
            child->directions[i] = father->directions[i];
        }
    }

    return child;
}

Proband* ChildManager::twoPointsRecombination(Proband *mother, Proband *father)
{
    Proband *child = new Proband(mother->directions);

    int firstPoint = rand() % (GlobalConfig::NumberOfSteps - 1);
    int secondPoint = rand() % GlobalConfig::NumberOfSteps;

    while (secondPoint <= firstPoint)
    {
        //qDebug("meh");
        secondPoint = rand() % GlobalConfig::NumberOfSteps;
    }

    for (int i = 0; i < firstPoint; i++)
    {
        int mutationValue = rand() % 100;

        if (mutationValue < GlobalConfig::MutationChance)
        {
            int random = rand() % 8;
            child->directions[i] = static_cast<Direction>(random);
        }
        else
        {
            child->directions[i] = mother->directions[i];
        }
    }

    for (int i = firstPoint; i < secondPoint; i++)
    {
        int mutationValue = rand() % 100;

        if (mutationValue < GlobalConfig::MutationChance)
        {
            int random = rand() % 8;
            child->directions[i] = static_cast<Direction>(random);
        }
        else
        {
            child->directions[i] = father->directions[i];
        }
    }

    for (int i = secondPoint; i < GlobalConfig::NumberOfSteps; i++)
    {
        int mutationValue = rand() % 100;

        if (mutationValue < GlobalConfig::MutationChance)
        {
            int random = rand() % 8;
            child->directions[i] = static_cast<Direction>(random);
        }
        else
        {
            child->directions[i] = mother->directions[i];
        }
    }

    return child;
}

Proband* ChildManager::randomRecombination(Proband *mother, Proband *father)
{
    Proband *child = new Proband(mother->directions);

    for (int i = 0; i <GlobalConfig::NumberOfSteps; i++)
    {
        int randomValue = rand() % 2;

        if (randomValue == 0)
        {
            int mutationValue = rand() % 100;

            if (mutationValue < GlobalConfig::MutationChance)
            {
                int random = rand() % 8;
                child->directions[i] = static_cast<Direction>(random);
            }
            else
            {
                child->directions[i] = mother->directions[i];
            }

            continue;
        }

        int mutationValue = rand() % 100;

        if (mutationValue < GlobalConfig::MutationChance)
        {
            int random = rand() % 8;
            child->directions[i] = static_cast<Direction>(random);
        }
        else
        {
            child->directions[i] = father->directions[i];
        }
    }

    return child;
}
