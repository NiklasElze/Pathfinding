#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "area.h"
#include "moveservice.h"
#include "proband.h"
#include "pushbutton.h"
#include "target.h"

#include <QGraphicsScene>
#include <QTextEdit>
#include <QCheckBox>

class SceneManager
{
private:
    QGraphicsScene *m_Scene;
public:
    SceneManager(QGraphicsScene *scene);
    Area* ProbandArea;
    Target* ProbandTarget;
    PushButton* StartButton;
    QTextEdit* PopulationTextBox;
    QTextEdit* GenerationsTextBox;
    QTextEdit* ProbandsTextBox;
    QTextEdit* StepsTextBox;
    QTextEdit* MutationChanceTextBox;
    QCheckBox* ShowStepsCheckBox;
    QCheckBox* ShowGenResultCheckBox;
    void createUi();
};

#endif // SCENEMANAGER_H
