#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QVector>

#include "Sudoku.h"
#include <GridSudoku.h>

class Sudoku;
class GridSudoku;

class Mediator
{
public:
    Mediator(GridSudoku*);
    ~Mediator() {}      //list Sudoku* will be deleted at m_parent

    void addSudoku(Sudoku*);

    QVector<Sudoku*> getVectorSudoku()
    {
        return m_vectorSudoku;
    }

    void allotherSudokuUpdateRemove(Sudoku*, unsigned int value_Dec);
    void allotherSudokuUpdateRemove(Sudoku*, Sudoku*, unsigned int value_Bin);
    void allotherSudokuUpdateRemove(Sudoku*, Sudoku*, Sudoku*, unsigned int value_Bin);
    void allotherSudokuUpdateAdd(Sudoku*, unsigned int);
    void allotherSudokuUpdateAdd(Sudoku*, Sudoku*, unsigned int);
    void allotherSudokuUpdateAdd(Sudoku*, Sudoku*, Sudoku*, unsigned int);

private:
    QVector<Sudoku*> m_vectorSudoku;
    GridSudoku* m_parent;
};

#endif // MEDIATOR_H
