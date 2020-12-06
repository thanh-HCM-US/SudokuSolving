#include "FinishedInputButton.h"

FinishedInputButton::FinishedInputButton(QString string, QWidget *parent)
    : QPushButton (string, parent),
      m_clicked(false)
{

}
