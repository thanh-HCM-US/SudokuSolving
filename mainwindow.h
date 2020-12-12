#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include "Gridpart.h"

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

    bool find1() { return m_gridPart->find1();}
    bool findOnlyOneMatch() { return m_gridPart->findOnlyOneMatch();}

private:
    Ui::MainWindow *ui;

    GridPart* m_gridPart;
    InputFromSource* m_inputFromSource;
    QPushButton* m_finishedInput;
    StepByStep* m_stepByStep;
    QPushButton* m_finalResult;
    QPushButton* m_quit;
};

#endif // MAINWINDOW_H
