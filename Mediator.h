#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QVector>

#include "Sudoku.h"
#include <Gridpart.h>

class Sudoku;
class GridPart;

class Mediator
{
public:
    Mediator(GridPart*);

    void addSudoku(Sudoku*);

    QVector<Sudoku*> getVectorSudoku()
    {
        return m_vectorSudoku;
    }

    void allotherSudokuUpdateRemove(Sudoku*, unsigned int);
    void allotherSudokuUpdateRemove(Sudoku*, Sudoku*, unsigned int);
    void allotherSudokuUpdateRemove(Sudoku*, Sudoku*, Sudoku*, unsigned int);
    void allotherSudokuUpdateAdd(Sudoku*, unsigned int);
    void allotherSudokuUpdateAdd(Sudoku*, Sudoku*, unsigned int);
    void allotherSudokuUpdateAdd(Sudoku*, Sudoku*, Sudoku*, unsigned int);

private:
    QVector<Sudoku*> m_vectorSudoku;
    GridPart* m_parent;
};

#endif // MEDIATOR_H
