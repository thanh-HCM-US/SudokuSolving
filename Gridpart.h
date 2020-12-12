#ifndef GRIDPART_H
#define GRIDPART_H

#include <QGridLayout>
#include <QVector>
#include <QWidget>
#include <QGridLayout>

#include "Sudoku.h"

class Mediator;

class GridPart : public QWidget
{
public:
    GridPart(QWidget* parent = nullptr);
    virtual ~GridPart() {}

    void finishedInputButtonClicked();

    QVector<Sudoku*>::iterator
            getItOfVectorSudoku();

    bool find1();

    bool findOnlyOneMatch();

    bool findDuplicate();
private:
    void combineSudokuWithMediator();

    void addSudokuIntoLayout3x3(Sudoku* sudoku, int row, int column);

    QVector<QGridLayout*> m_gridLayouts;
    QVector<QFrame*> m_lines;
    QVector<Sudoku*> m_vectorSudoku;
    QVector<Mediator*> m_vectorMeditorRow;
    QVector<Mediator*> m_vectorMeditorColumn;
    QVector<Mediator*> m_vectorMeditorSquare;
};

#endif // GRIDPART_H
