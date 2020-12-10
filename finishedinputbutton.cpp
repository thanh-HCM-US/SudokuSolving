#include "FinishedInputButton.h"

FinishedInputButton::FinishedInputButton(QString string, MainWindow *parent)
    : QPushButton (string, parent),
      m_clicked(false),
      m_parent(parent)
{
    connect(this, &QPushButton::clicked, this, &FinishedInputButton::clicked);
}

void FinishedInputButton::clicked()
{
    if (m_clicked == false)
    {
        m_clicked = true;
        m_parent->finishedInputButtonClicked();
    }
}
