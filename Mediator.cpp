#include "Mediator.h"
#include <QtDebug>

Mediator::Mediator(GridPart* parent)
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
            (*it)->updateSubValueRemove(value_Dec);
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
            (*it)->updateSubValueRemove_Bin(value_Bin);
        }
    }
}

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
            (*it)->updateSubValueAdd(value);
        }
    }
}

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
