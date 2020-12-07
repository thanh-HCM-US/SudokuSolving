#include "Sudoku.h"
#include <string>
#include <iostream>
#include <QString>

#include "Mediator.h"

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
      m_subValue(511),   // 511 == 0x111111111
      m_hasMainValue(false)

{
    this->setFrameStyle(QFrame::Box);
    this->setFixedSize(45,45);
    connect(this, &QTextEdit::textChanged, this, &Sudoku::setMainValue);
}

Sudoku::~Sudoku()
{
    std::cout << "out";
}

void Sudoku::showMainValue()
{

    QTextCursor textCursor = this->textCursor();
    this->selectAll();
    this->setFontPointSize(18);
    this->setAlignment(Qt::AlignCenter);
    this->setTextColor(Qt::blue);
    this->setTextCursor(textCursor);
}

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
            strSubValue += " ";
        }
    }

    this->setText(strSubValue);
    QTextCursor textCursor = this->textCursor();
    this->selectAll();
    this->setFontPointSize(6);
    this->setAlignment(Qt::AlignCenter);
    this->setTextCursor(textCursor);
}

void Sudoku::setMainValue()
{
    if (m_finishedInput == true)
    {
        return;
    }
    QString str = this->toPlainText();
    unsigned int mainValue;
    mainValue = static_cast<unsigned int>(str.toInt());
    if ((mainValue > 9) )//|| (m_mainValue < 1))
    {
        this->clear();
        mainValue = 0;
        for (int i=0; i<3; ++i)     //for case clear m_mainValue
        {
            m_vectorMediator[i]->allotherSudokuUpdateAdd(this, m_mainValue);
        }
        m_mainValue = 0;
        return;
    }
    if (mainValue == 0)
    {
        m_hasMainValue = false;
        return;
    }

    if (m_mainValue!=0)         //for case changing m_mainValue
    {
        for (int i=0; i<3; ++i)
        {
            m_vectorMediator[i]->allotherSudokuUpdateAdd(this, m_mainValue);
        }
    }

    m_mainValue = mainValue;
    for (int i=0; i<3; ++i)
    {
        m_vectorMediator[i]->allotherSudokuUpdateRemove(this, m_mainValue);
    }
    m_hasMainValue = true;
}

void Sudoku::updateMainValue()
{}

unsigned int Sudoku::getMainValue()
{
    return m_mainValue;
}

void Sudoku::updateSubValueAdd(unsigned int addValue)
{
    if (!m_hasMainValue)
    {
        m_subValue = m_subValue | (1 << (addValue - 1));
        if (m_finishedInput)
        {
            showSubValue();
        }
    }
}

void Sudoku::updateSubValueRemove(unsigned int removeValue)
{
    if (!m_hasMainValue)
    {
        m_subValue = m_subValue & (511 - (1 << (removeValue - 1)));
        if (m_finishedInput)
        {
            showSubValue();
        }
    }
}

bool Sudoku::isHasMainValue()
{
    return m_hasMainValue;
}

void Sudoku::setFinishedInput(bool isFinishedInput)
{
    m_finishedInput = isFinishedInput;
}

void Sudoku::addMediator(Mediator* mediator)
{
    m_vectorMediator.append(mediator);
    mediator->addSudoku(this);
}
