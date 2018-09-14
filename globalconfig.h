#ifndef GLOBALCONFIG_H
#define GLOBALCONFIG_H


class GlobalConfig
{
public:
    GlobalConfig();
    static int NumberOfGenerations;
    static int PopulationSize;
    static int NumberOfBestProbands;
    static int MutationChance;
    static int NumberOfSteps;
    static bool ShowSteps;
    static bool ShowGenerationResult;
};

#endif // GLOBALCONFIG_H
