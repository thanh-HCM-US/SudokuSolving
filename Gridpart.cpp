#include "Gridpart.h"
#include "Mediator.h"
#include <QGridLayout>
#include <QTime>
#include <QDebug>
#include "utility.h"

GridPart::GridPart(QWidget* parent)
    : QWidget (parent)
{
    QGridLayout* layout = new QGridLayout(this);
    int row=0;
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
        layout->addWidget(sudoku, row, column);
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

void GridPart::finishedInputButtonClicked()
{
    QVector<Sudoku*>::iterator it;
    for (it = m_vectorSudoku.begin(); it != m_vectorSudoku.end(); ++it)
    {
        (*it)->setFinishedInput(true);
    }
    qDebug() << QTime::currentTime() << " start";
    for (it = m_vectorSudoku.begin(); it != m_vectorSudoku.end(); ++it)
    {
        if ((*it)->isHasMainValue() == true)
        {
            (*it)->showMainValue();
        }
        else
        {
            (*it)->showSubValue();
        }
    }
    qDebug() << QTime::currentTime() << " stop";
}

void GridPart::combineSudokuWithMediator()
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
GridPart::getItOfVectorSudoku()
{
    QVector<Sudoku*>::iterator it = m_vectorSudoku.begin();
    return it;
}

bool GridPart::find1()
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
