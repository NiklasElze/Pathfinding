#include "eventconnector.h"
#include "globalconfig.h"

EventConnector::EventConnector(SceneManager *sceneManager, EvolutionController *evolutionController)
{
    m_SceneManager = sceneManager;
    m_EvolutionController = evolutionController;
}

void EventConnector::connectEvents()
{
    connect(m_SceneManager->PopulationTextBox, SIGNAL(textChanged()), this, SLOT(checkMaxLength()));
    connect(m_SceneManager->GenerationsTextBox, SIGNAL(textChanged()), this, SLOT(checkMaxLength()));
    connect(m_SceneManager->StartButton, SIGNAL(clicked()), this, SLOT(startEvolution()));
}

void EventConnector::checkMaxLength()
{
    QTextEdit *textBox = static_cast<QTextEdit*>(sender());

    QString content = textBox->toPlainText();

    if (content.length() > 4)
    {
        textBox->setText(content.left(4));
    }
}

void EventConnector::startEvolution()
{
    GlobalConfig::MutationChance = m_SceneManager->MutationChanceTextBox->toPlainText().toInt();
    GlobalConfig::NumberOfBestProbands = m_SceneManager->ProbandsTextBox->toPlainText().toInt();
    GlobalConfig::NumberOfGenerations = m_SceneManager->GenerationsTextBox->toPlainText().toInt();
    GlobalConfig::NumberOfSteps = m_SceneManager->StepsTextBox->toPlainText().toInt();
    GlobalConfig::PopulationSize = m_SceneManager->PopulationTextBox->toPlainText().toInt();
    GlobalConfig::ShowGenerationResult = m_SceneManager->ShowGenResultCheckBox->isChecked();
    GlobalConfig::ShowSteps = m_SceneManager->ShowStepsCheckBox->isChecked();

    m_EvolutionController->startEvolution();
}
