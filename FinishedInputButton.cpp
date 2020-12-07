#include "FinishedInputButton.h"

#include <QtDebug>
#include <QTime>

FinishedInputButton::FinishedInputButton(QString string, RequestPart *parent)
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
        qDebug() << QTime::currentTime();
        m_parent->finishedInputButtonClicked();
    }
}
