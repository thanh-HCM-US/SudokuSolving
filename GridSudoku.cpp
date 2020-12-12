#include "GridSudoku.h"
#include "Mediator.h"
#include <QGridLayout>
#include <QTime>
#include <QDebug>
#include <QFrame>
#include "utility.h"

GridSudoku::GridSudoku(QWidget* parent)
    : QWidget (parent)
{
    QGridLayout* layout = new QGridLayout(this);
    layout->setSpacing(0);

    for(int row = 0; row < 5; row += 1)
    {
        for (int column = 0; column < 5; column += 1)
        {
            if (((row % 2)==0) && ((column % 2)==0))
            {
                QGridLayout* layout3x3 = new QGridLayout(this);
                layout3x3->setSpacing(0);
                m_gridLayouts.append(layout3x3);
                layout->addLayout(layout3x3,row, column);
            }
            else if (((row % 2)==0) && ((column % 2)==1))
            {
                QFrame* line = new QFrame(this);
                m_lines.append(line);
                line->setLineWidth(10);
                line->setFrameShape(QFrame::VLine);
                layout->addWidget(line, row, column, 1, 1);
            }
            else if (((row % 2)==1) && ((column % 2)==0))
            {
                QFrame* line = new QFrame(this);
                m_lines.append(line);
                line->setLineWidth(10);
                line->setFrameShape(QFrame::HLine);
                layout->addWidget(line, row, column, 1, 1);
            }
        }
    }

    int row=-1;
    int column=0;
    for (int i=0; i<81; ++i)
    {
        if ((i % 9) == 0)
        {
            ++row;
            column = 0;
        }
        else
        {
            ++column;
        }
        Sudoku* sudoku = new Sudoku();
        m_vectorSudoku.append(sudoku);
        addSudokuIntoLayout3x3(sudoku, row, column);
    }
    setLayout(layout);

    for (int i=0; i<9; ++i)
    {
        Mediator* mediatorRow = new Mediator(this);
        m_vectorMeditorRow.append(mediatorRow);

        Mediator* mediatorColumn = new Mediator(this);
        m_vectorMeditorColumn.append(mediatorColumn);

        Mediator* mediatorSquare = new Mediator(this);
        m_vectorMeditorSquare.append(mediatorSquare);
    }
    combineSudokuWithMediator();
}

GridSudoku::~GridSudoku()
{
    m_gridLayouts.clear();
    m_lines.clear();
    m_vectorSudoku.clear();
    m_vectorMeditorRow.clear();
    m_vectorMeditorColumn.clear();
    m_vectorMeditorSquare.clear();
}

void GridSudoku::finishedInputButtonClicked()
{
    QVector<Sudoku*>::iterator it;
    for (it = m_vectorSudoku.begin(); it != m_vectorSudoku.end(); ++it)
    {
        (*it)->setFinishedInput(true);
    }

    for (it = m_vectorSudoku.begin(); it != m_vectorSudoku.end(); ++it)
    {
        if ((*it)->isHasMainValue() == false)
        {
            (*it)->showSubValue();
        }
    }
}

void GridSudoku::combineSudokuWithMediator()
{
    for (int i=0; i<81; ++i)
    {
        int row = i/9;
        int column = i%9;
        m_vectorSudoku[i]->addMediator(m_vectorMeditorRow[row]);
        m_vectorSudoku[i]->addMediator(m_vectorMeditorColumn[column]);

        if (row < 3)
        {
            if (column < 3){
                m_vectorSudoku[i]->addMediator(m_vectorMeditorSquare[0]);
            }
            else if (column < 6) {
                m_vectorSudoku[i]->addMediator(m_vectorMeditorSquare[1]);
            }
            else {
                m_vectorSudoku[i]->addMediator(m_vectorMeditorSquare[2]);
            }
        }
        else if (row < 6) {
            if (column < 3){
                m_vectorSudoku[i]->addMediator(m_vectorMeditorSquare[3]);
            }
            else if (column < 6) {
                m_vectorSudoku[i]->addMediator(m_vectorMeditorSquare[4]);
            }
            else {
                m_vectorSudoku[i]->addMediator(m_vectorMeditorSquare[5]);
            }
        }
        else {
            if (column < 3){
                m_vectorSudoku[i]->addMediator(m_vectorMeditorSquare[6]);
            }
            else if (column < 6) {
                m_vectorSudoku[i]->addMediator(m_vectorMeditorSquare[7]);
            }
            else {
                m_vectorSudoku[i]->addMediator(m_vectorMeditorSquare[8]);
            }
        }
    }
}

QVector<Sudoku*>::iterator
GridSudoku::getItOfVectorSudoku()
{
    QVector<Sudoku*>::iterator it = m_vectorSudoku.begin();
    return it;
}

bool GridSudoku::find1()
{
    bool result = false;
    for (int i = 0; i < 81; ++i)
    {
        if ((!m_vectorSudoku[i]->isHasMainValue()) && (m_vectorSudoku[i]->getNumSubValue() == 1))
        {
            int mainValueFound = convertSubValueToInt(m_vectorSudoku[i]->getSubValue());
            m_vectorSudoku[i]->setMainValue(mainValueFound);
            result =true;
            break;
        }
    }
    return result;
}

bool GridSudoku::findOnlyOneMatch()
{
    bool result = false;
    for (int i = 0; i < 9; ++i)
    {
        if (UTILITY_H::findOnlyOneMatch(m_vectorMeditorRow[i]))
        {
            result = true;
            break;
        }
        if (UTILITY_H::findOnlyOneMatch(m_vectorMeditorColumn[i]))
        {
            result = true;
            break;
        }
        if (UTILITY_H::findOnlyOneMatch(m_vectorMeditorSquare[i]))
        {
            result = true;
            break;
        }
    }
    return result;
}

bool GridSudoku::findDuplicate()
{
    bool result = false;
    for (int i = 0; i < 9; ++i)
    {
        if (UTILITY_H::findDuplicate(m_vectorMeditorRow[i]))
        {
            result = true;
        }
        if (UTILITY_H::findDuplicate(m_vectorMeditorColumn[i]))
        {
            result = true;
        }
        if (UTILITY_H::findDuplicate(m_vectorMeditorSquare[i]))
        {
            result = true;
        }
    }
    return result;
}

void GridSudoku::addSudokuIntoLayout3x3(Sudoku* sudoku, int row, int column)
{
    if (row < 3)
    {
        if (column < 3)
        {
            m_gridLayouts[0]->addWidget(sudoku, row, column%3);
        }
        else if (column < 6)
        {
            m_gridLayouts[1]->addWidget(sudoku, row, column%3);
        }
        else
        {
            m_gridLayouts[2]->addWidget(sudoku, row, column%3);
        }
    }
    else if (row < 6)
    {
        if (column < 3)
        {
            m_gridLayouts[3]->addWidget(sudoku, row%3, column%3);
        }
        else if (column < 6)
        {
            m_gridLayouts[4]->addWidget(sudoku, row%3, column%3);
        }
        else
        {
            m_gridLayouts[5]->addWidget(sudoku, row%3, column%3);
        }
    }
    else
    {
        if (column < 3)
        {
            m_gridLayouts[6]->addWidget(sudoku, row%3, column%3);
        }
        else if (column < 6)
        {
            m_gridLayouts[7]->addWidget(sudoku, row%3, column%3);
        }
        else
        {
            m_gridLayouts[8]->addWidget(sudoku, row%3, column%3);
        }
    }
}
