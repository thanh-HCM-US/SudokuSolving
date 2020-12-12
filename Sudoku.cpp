#include "Sudoku.h"
#include <string>
#include <iostream>
#include <QString>
#include <QDebug>

#include "Mediator.h"
#include "utility.h"

Sudoku::Sudoku()
    : m_mainValue(0),
      m_subValue(511),   // 511 == 0x111111111
      m_numSubValue(9),
      m_hasMainValue(false),
      m_finishedInput(false)
{
    this->setFrameStyle(QFrame::Box);
    this->setFixedSize(45,45);
    this->setFont(QFont("Arial",20,40));
    this->setAlignment(Qt::AlignCenter);
    connect(this, &QTextEdit::textChanged, this, &Sudoku::setMainValueFromKey);
}

Sudoku::~Sudoku()
{
    std::cout << "out";
}

void Sudoku::showMainValue()
{
    //QTextCursor textCursor = this->textCursor();
    //this->selectAll();
    //this->setFontPointSize(18);
    //this->setAlignment(Qt::AlignCenter);
    //this->setTextCursor(textCursor);
}

void Sudoku::showSubValue()
{
    this->setText(m_subValueByText);
    QTextCursor textCursor = this->textCursor();
    this->selectAll();
    this->setFontPointSize(6);
    this->setAlignment(Qt::AlignCenter);
    this->setTextCursor(textCursor);
}

void Sudoku::setMainValueFromKey()
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
        allotherSudokuUpdateAdd();
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
        allotherSudokuUpdateAdd();
    }

    m_mainValue = mainValue;
    m_hasMainValue = true;
    allotherSudokuUpdateRemove();
}

void Sudoku::setMainValue(int value_Dec)
{
    if ((value_Dec > 0) && (value_Dec <10))
    {
        this->setPlainText(QString::number(value_Dec));
        this->setAlignment(Qt::AlignCenter);
        m_mainValue = static_cast<unsigned int>(value_Dec);
        m_hasMainValue = true;
        allotherSudokuUpdateRemove();
    }
}

void Sudoku::updateMainValue(unsigned int value_Bin)
{

}

unsigned int Sudoku::getMainValue()
{
    return m_mainValue;
}

void Sudoku::updateSubValueAdd(unsigned int addValue)
{
    if (!m_hasMainValue)
    {
        m_subValue = m_subValue | (1 << (addValue - 1));
        m_numSubValue = checkNumSubValue(m_subValue);
        m_subValueByText = convertSubValueIntToText(static_cast<int>(m_subValue));
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
        m_numSubValue = checkNumSubValue(m_subValue);
        m_subValueByText = convertSubValueIntToText(static_cast<int>(m_subValue));
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

void Sudoku::allotherSudokuUpdateRemove()
{
    for (int i=0; i<3; ++i)
    {
        m_vectorMediator[i]->allotherSudokuUpdateRemove(this, m_mainValue);
    }
}

void Sudoku::allotherSudokuUpdateAdd()
{
    for (int i=0; i<3; ++i)
    {
        m_vectorMediator[i]->allotherSudokuUpdateAdd(this, m_mainValue);
    }
}
