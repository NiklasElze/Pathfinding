#include "area.h"
#include "globalconfig.h"
#include "proband.h"
#include "pushbutton.h"
#include "scenemanager.h"
#include "target.h"

#include <QCoreApplication>
#include <QDebug>
#include <QLabel>
#include <iterator>

SceneManager::SceneManager(QGraphicsScene *scene)
{
    m_Scene = scene;
}

void SceneManager::createUi()
{
    m_Scene->setSceneRect(0, 0, 800, 600);
    StartButton = new PushButton(m_Scene, "Start");
    StartButton->setGeometry(680, 10, 100, 30);

    QLabel *labelPopulation = new QLabel();
    labelPopulation->setText("Population size:");
    labelPopulation->setGeometry(5, 5, 100, 20);
    m_Scene->addWidget(labelPopulation);

    PopulationTextBox = new QTextEdit();
    PopulationTextBox->setText(std::to_string(GlobalConfig::PopulationSize).c_str());
    PopulationTextBox->setGeometry(110, 4, 45, 20);
    PopulationTextBox->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_Scene->addWidget(PopulationTextBox);

    QLabel *labelGenerations = new QLabel();
    labelGenerations->setText("Generations:");
    labelGenerations->setGeometry(5, 30, 100, 20);
    m_Scene->addWidget(labelGenerations);

    GenerationsTextBox = new QTextEdit();
    GenerationsTextBox->setText(std::to_string(GlobalConfig::NumberOfGenerations).c_str());
    GenerationsTextBox->setGeometry(110, 30, 45, 20);
    GenerationsTextBox->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_Scene->addWidget(GenerationsTextBox);

    QLabel *labelProbands = new QLabel();
    labelProbands->setText("Best Probands:");
    labelProbands->setGeometry(160, 5, 90, 20);
    m_Scene->addWidget(labelProbands);

    ProbandsTextBox = new QTextEdit();
    ProbandsTextBox->setText(std::to_string(GlobalConfig::NumberOfBestProbands).c_str());
    ProbandsTextBox->setGeometry(255, 4, 45, 20);
    ProbandsTextBox->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_Scene->addWidget(ProbandsTextBox);

    QLabel *labelSteps = new QLabel();
    labelSteps->setText("Steps:");
    labelSteps->setGeometry(160, 30, 90, 20);
    m_Scene->addWidget(labelSteps);

    StepsTextBox = new QTextEdit();
    StepsTextBox->setText(std::to_string(GlobalConfig::NumberOfSteps).c_str());
    StepsTextBox->setGeometry(255, 30, 45, 20);
    StepsTextBox->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_Scene->addWidget(StepsTextBox);

    QLabel *labelMutationChance = new QLabel();
    labelMutationChance->setText("Mutation chance %:");
    labelMutationChance->setGeometry(315, 5, 115, 20);
    m_Scene->addWidget(labelMutationChance);

    MutationChanceTextBox = new QTextEdit();
    MutationChanceTextBox->setText(std::to_string(GlobalConfig::MutationChance).c_str());
    MutationChanceTextBox->setGeometry(435, 5, 45, 20);
    MutationChanceTextBox->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_Scene->addWidget(MutationChanceTextBox);

    QLabel *labelShowSteps = new QLabel();
    labelShowSteps->setText("Show steps:");
    labelShowSteps->setGeometry(315, 30, 75, 20);
    m_Scene->addWidget(labelShowSteps);

    ShowStepsCheckBox = new QCheckBox();
    ShowStepsCheckBox->setChecked(GlobalConfig::ShowSteps);
    ShowStepsCheckBox->setGeometry(395, 30, 15, 20);
    m_Scene->addWidget(ShowStepsCheckBox);

    QLabel *lablShowGenResult = new QLabel();
    lablShowGenResult->setText("Show gen. result:");
    lablShowGenResult->setGeometry(420, 30, 105, 20);
    m_Scene->addWidget(lablShowGenResult);

    ShowGenResultCheckBox = new QCheckBox();
    ShowGenResultCheckBox->setChecked(GlobalConfig::ShowGenerationResult);
    ShowGenResultCheckBox->setGeometry(530, 30, 15, 20);
    m_Scene->addWidget(ShowGenResultCheckBox);

    ProbandArea = new Area(800, 500);
    m_Scene->addItem(ProbandArea);
    ProbandArea->setPos(0, 50);

    ProbandTarget = new Target(400, 0, 20, 20);
    ProbandTarget->setParentItem(ProbandArea);
}
