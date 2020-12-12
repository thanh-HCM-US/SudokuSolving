#include "Mediator.h"
#include <QtDebug>

Mediator::Mediator(GridSudoku* parent)
    : m_parent(parent)
{
}

void Mediator::addSudoku(Sudoku* sudoku)
{
    m_vectorSudoku.append(sudoku);
}

void Mediator::allotherSudokuUpdateRemove(Sudoku* sudoku, unsigned int value_Dec)
{
    for (QVector<Sudoku*>::iterator it = m_vectorSudoku.begin();
         it != m_vectorSudoku.end();
         ++it)
    {
        if (*it != sudoku)
        {
            (*it)->updateSubValue(true,true,value_Dec);
        }
    }
}

void Mediator::allotherSudokuUpdateRemove(Sudoku* sudoku1,
                                          Sudoku* sudoku2,
                                          unsigned int value_Bin)
{
    for (QVector<Sudoku*>::iterator it = m_vectorSudoku.begin();
         it != m_vectorSudoku.end();
         ++it)
    {
        if ((*it != sudoku1) && (*it != sudoku2))
        {
            (*it)->updateSubValue(true,false,value_Bin);
        }
    }
}

//at now, I don't need to use this method to solving sudoku
void Mediator::allotherSudokuUpdateRemove(Sudoku* sudoku1,
                                          Sudoku* sudoku2,
                                          Sudoku* sudoku3,
                                          unsigned int value_Bin)
{
    for (QVector<Sudoku*>::iterator it = m_vectorSudoku.begin();
         it != m_vectorSudoku.end();
         ++it)
    {
        if ((*it != sudoku1) && (*it != sudoku2) && (*it != sudoku3))
        {
            //TODO
        }
    }
}

void Mediator::allotherSudokuUpdateAdd(Sudoku* sudoku, unsigned int value)
{
    for (QVector<Sudoku*>::iterator it = m_vectorSudoku.begin();
         it != m_vectorSudoku.end();
         ++it)
    {
        if (*it != sudoku)
        {
            (*it)->updateSubValue(false,true,value);
        }
    }
}

//at now, I don't need to use this method to solving sudoku
void Mediator::allotherSudokuUpdateAdd(Sudoku* sudoku1,
                                       Sudoku* sudoku2,
                                       unsigned int value)
{
    for (QVector<Sudoku*>::iterator it = m_vectorSudoku.begin();
         it != m_vectorSudoku.end();
         ++it)
    {
        if ((*it != sudoku1) && (*it != sudoku2))
        {
            //TODO
        }
    }
}

//at now, I don't need to use this method to solving sudoku
void Mediator::allotherSudokuUpdateAdd(Sudoku* sudoku1,
                                       Sudoku* sudoku2,
                                       Sudoku* sudoku3,
                                       unsigned int value)
{
    for (QVector<Sudoku*>::iterator it = m_vectorSudoku.begin();
         it != m_vectorSudoku.end();
         ++it)
    {
        if ((*it != sudoku1) && (*it != sudoku2) && (*it != sudoku3))
        {
            //TODO
        }
    }
}
