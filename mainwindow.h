#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include "GridSudoku.h"

class InputFromSource;
class StepByStep;

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

    bool find1() { return m_gridSudoku->find1();}
    bool findOnlyOneMatch() { return m_gridSudoku->findOnlyOneMatch();}
    bool findDuplicate() {return  m_gridSudoku->findDuplicate();}

    void sovleAllSudoku();

private:
    Ui::MainWindow *ui;

    GridSudoku* m_gridSudoku;
    InputFromSource* m_inputFromSource;
    QPushButton* m_finishedInput;
    StepByStep* m_stepByStep;
    QPushButton* m_finalResult;
    QPushButton* m_quit;
};

#endif // MAINWINDOW_H
