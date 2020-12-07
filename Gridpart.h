#ifndef GRIDPART_H
#define GRIDPART_H

#include <QGridLayout>
#include <QVector>
#include <QWidget>

#include "Sudoku.h"

class Mediator;

class GridPart : public QWidget
{
public:
    GridPart(QWidget* parent = nullptr);
    virtual ~GridPart() {}

    void finishedInputButtonClicked();
private:
    void combineSudokuWithMediator();

    QVector<Sudoku*> m_vectorSudoku;
    QVector<Mediator*> m_vectorMeditorRow;
    QVector<Mediator*> m_vectorMeditorColumn;
    QVector<Mediator*> m_vectorMeditorSquare;
};

#endif // GRIDPART_H
