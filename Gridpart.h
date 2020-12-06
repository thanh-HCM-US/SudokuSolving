#ifndef GRIDPART_H
#define GRIDPART_H

#include <QGridLayout>
#include <QVector>
#include <QWidget>
#include "Sudoku.h"

class GridPart : public QWidget
{
public:
    GridPart(QWidget* parent = nullptr);
    virtual ~GridPart() {}
private:
    QVector<Sudoku*>* m_vectorSudoku;
};

#endif // GRIDPART_H
