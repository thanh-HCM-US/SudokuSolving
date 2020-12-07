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

    void allotherSudokuUpdateRemove(Sudoku*, unsigned int);
    void allotherSudokuUpdateAdd(Sudoku*, unsigned int);

private:
    QVector<Sudoku*> m_vectorSudoku;
    GridPart* m_parent;
};

#endif // MEDIATOR_H
