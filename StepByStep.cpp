#include "StepByStep.h"
#include "mainwindow.h"
#include <QtDebug>

StepByStep::StepByStep(QString string, QWidget *parent)
    : QPushButton (string, parent),
      m_parent(parent)
{
    connect(this, &QPushButton::clicked, this, &StepByStep::solveOneStep);
}

void StepByStep::solveOneStep()
{
    if (static_cast<MainWindow*>(m_parent)->find1())
    {
        return;
    }
    if (static_cast<MainWindow*>(m_parent)->findOnlyOneMatch())
    {
        return;
    }
}
