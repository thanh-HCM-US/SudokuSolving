#include "Mediator.h"

Mediator::Mediator(GridPart* parent)
    : m_parent(parent)
{

}

void Mediator::addSudoku(Sudoku* sudoku)
{
    m_vectorSudoku.append(sudoku);
}

void Mediator::allotherSudokuUpdateRemove(Sudoku* sudoku, unsigned int value)
{
    for (QVector<Sudoku*>::iterator it = m_vectorSudoku.begin();
         it != m_vectorSudoku.end();
         ++it)
    {
        if (*it != sudoku)
        {
            (*it)->updateSubValueRemove(value);
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
