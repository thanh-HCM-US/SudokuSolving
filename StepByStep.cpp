#include "StepByStep.h"
#include "mainwindow.h"
#include <QtDebug>

StepByStep::StepByStep(QString string, QWidget *parent)
    : QPushButton (string, parent),
      m_parent(parent)
{
    connect(this, &QPushButton::clicked, this, &StepByStep::solveOneStep);
}

bool StepByStep::solveOneStep()
{
    if (static_cast<MainWindow*>(m_parent)->find1())
    {
        return true;
    }
    if (static_cast<MainWindow*>(m_parent)->findOnlyOneMatch())
    {
        return true;
    }
    if (static_cast<MainWindow*>(m_parent)->findDuplicate())
    {
        return true;
    }
    return false;
}
