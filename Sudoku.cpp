#include "Sudoku.h"
#include <string>
#include <iostream>
#include <QString>

QString convertItoString(unsigned int i)
{
    QString strConverted;
    switch (i) {
    case 1:
        strConverted = "1";
        break;
    case 2:
        strConverted = "2";
        break;
    case 3:
        strConverted = "3";
        break;
    case 4:
        strConverted = "4";
        break;
    case 5:
        strConverted = "5";
        break;
    case 6:
        strConverted = "6";
        break;
    case 7:
        strConverted = "7";
        break;
    case 8:
        strConverted = "8";
        break;
    case 9:
        strConverted = "9";
        break;
    default:
        break;
    }
    return strConverted;
}

Sudoku::Sudoku()
    : m_mainValue(0),
      m_subValue(511)   // 511 == 0x111111111

{
    this->setFrameStyle(QFrame::Box);
    this->setFixedSize(40,40);
    showSubValue();
}

Sudoku::~Sudoku()
{
    std::cout << "out";
}

void Sudoku::showMainValue()
{}

void Sudoku::showSubValue()
{
    QString strSubValue;
    for (unsigned int i = 1; i < 10; ++i)
    {
        if ((m_subValue & (1 << (i-1))) != 0)
        {
            strSubValue += convertItoString(i);
        }
        else
        {
            strSubValue += " ";
        }

        if ((i == 3) || (i == 6))
        {
            strSubValue += "\n";
        }
        else if (i == 9)
        {/*nothing todo*/}
        else
        {
            strSubValue += "   ";
        }
    }

    this->setText(strSubValue);
    QTextCursor textCursor = this->textCursor();
    this->selectAll();
    this->setFontPointSize(6);
    this->setAlignment(Qt::AlignCenter);
    this->setTextColor(Qt::blue);
    this->setTextCursor(textCursor);
}

void Sudoku::setMainValue(unsigned int)
{}

unsigned int Sudoku::getMainValue()
{
    return m_mainValue;
}

void Sudoku::updateMainValue()
{}

void Sudoku::updateSubValueAdd(unsigned int addValue)
{
    m_subValue = m_subValue | (1 << (addValue - 1));
    showSubValue();
}

void Sudoku::updateSubValueRemove(unsigned int removeValue)
{
    m_subValue = m_subValue & (511 - (1 << (removeValue - 1)));
    showSubValue();
}
