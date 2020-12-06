#include "Gridpart.h"
#include <QGridLayout>

GridPart::GridPart(QWidget* parent)
    : QWidget (parent)
{
    QGridLayout* layout = new QGridLayout(this);
    m_vectorSudoku = new QVector<Sudoku*>;
    int row=0;
    int colum=0;
    for (int i=0; i<81; ++i)
    {
        if ((i % 9) == 0)
        {
            ++row;
            colum = 0;
        }
        else
        {
            ++colum;
        }
        Sudoku* sudoku = new Sudoku();
        m_vectorSudoku->append(sudoku);
        layout->addWidget(sudoku, row, colum);
    }
    setLayout(layout);
}
