#include "Sudoku.h"
#include <string>
#include <iostream>
#include <QString>
#include <QDebug>

#include "Mediator.h"
#include "utility.h"

Sudoku::Sudoku()
    : m_mainValue_Dec(0),
      m_subValue_Bin(511),   // 511 == 0x111111111
      m_numSubValue_Dec(9),
      m_hasMainValue(false),
      m_finishedInput(false)
{
    this->setFrameStyle(QFrame::Box);
    this->setFixedSize(45,45);
    this->setFont(QFont("Arial",20,40));
    this->setAlignment(Qt::AlignCenter);
    connect(this, &QTextEdit::textChanged, this, &Sudoku::setMainValueFromKey);
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
        m_mainValue_Dec = 0;
        return;
    }
    if (mainValue == 0)
    {
        m_hasMainValue = false;
        return;
    }

    if (m_mainValue_Dec!=0)         //for case changing m_mainValue
    {
        allotherSudokuUpdateAdd();
    }

    m_mainValue_Dec = mainValue;
    m_hasMainValue = true;
    allotherSudokuUpdateRemove();
}

void Sudoku::setMainValue(int value_Dec)
{
    if ((value_Dec > 0) && (value_Dec <10))
    {
        this->setPlainText(QString::number(value_Dec));
        this->setAlignment(Qt::AlignCenter);
        m_mainValue_Dec = static_cast<unsigned int>(value_Dec);
        m_hasMainValue = true;
        allotherSudokuUpdateRemove();
    }
}

unsigned int Sudoku::getMainValue()
{
    return m_mainValue_Dec;
}

void Sudoku::updateSubValue(bool isRemove, bool isDecimal, unsigned int value)
{
    if (!m_hasMainValue)
    {
        if (isRemove)
        {
            if (isDecimal)
            {
                //for case, there is another sudoku be set mainValue
                //so, subValue at here need to be remove a value (Decimal) as 1, 3, 5, 6
                m_subValue_Bin = m_subValue_Bin & (511 - (1 << (value - 1)));
                m_numSubValue_Dec = checkNumSubValue(m_subValue_Bin);
                m_subValueByText = convertSubValueIntToText(static_cast<int>(m_subValue_Bin));
            }
            else        // Binary number
            {
                //for case, remove some subValue
                //ex: subValue is {1,2,3,5,7} = 0x001010111, it be remove {1,9} = 0x100000001
                m_subValue_Bin = m_subValue_Bin & (511 - value);
                m_numSubValue_Dec = checkNumSubValue(m_subValue_Bin);
                m_subValueByText = convertSubValueIntToText(static_cast<int>(m_subValue_Bin));
            }
        }
        else    //it will add some one or more subvalue
        {
            if (isDecimal)
            {
                m_subValue_Bin = m_subValue_Bin | (1 << (value - 1));
                m_numSubValue_Dec = checkNumSubValue(m_subValue_Bin);
                m_subValueByText = convertSubValueIntToText(static_cast<int>(m_subValue_Bin));
            }
        }

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
        m_vectorMediator[i]->allotherSudokuUpdateRemove(this, m_mainValue_Dec);
    }
}

void Sudoku::allotherSudokuUpdateAdd()
{
    for (int i=0; i<3; ++i)
    {
        m_vectorMediator[i]->allotherSudokuUpdateAdd(this, m_mainValue_Dec);
    }
}
