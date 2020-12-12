#include "FinishedInputButton.h"
#include "mainwindow.h"
#include <QtDebug>


FinishedInputButton::FinishedInputButton(QString string, QWidget *parent)
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
        static_cast<MainWindow*>(m_parent)->finishedInputButtonClicked();
    }
}
