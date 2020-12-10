#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include "Gridpart.h"
//#include "InputFromSource.h"

class InputFromSource;

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget   //QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void finishedInputButtonClicked();
    QVector<Sudoku*>::iterator
        getItOfVectorSudoku();

private:
    Ui::MainWindow *ui;

    GridPart* m_gridPart;
    InputFromSource* m_inputFromSource;
    QPushButton* m_finishedInput;
    QPushButton* m_stepByStep;
    QPushButton* m_finalResult;
    QPushButton* m_quit;
};

#endif // MAINWINDOW_H
