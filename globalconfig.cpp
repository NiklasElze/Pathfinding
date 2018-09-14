#include "globalconfig.h"

int GlobalConfig::NumberOfGenerations = 50;
int GlobalConfig::PopulationSize = 100;
int GlobalConfig::NumberOfBestProbands = 10;
int GlobalConfig::MutationChance = 1;
int GlobalConfig::NumberOfSteps = 800;
bool GlobalConfig::ShowSteps = false;
bool GlobalConfig::ShowGenerationResult = true;

GlobalConfig::GlobalConfig()
{
}
