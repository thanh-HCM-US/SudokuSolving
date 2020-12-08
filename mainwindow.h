#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include "Gridpart.h"
#include "RequestPart.h"

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

private:
    Ui::MainWindow *ui;

    GridPart* m_gridPart;
    QPushButton* m_inputFromSource;
    QPushButton* m_finishedInput;
    QPushButton* m_stepByStep;
    QPushButton* m_finalResult;
    QPushButton* m_quit;
};

#endif // MAINWINDOW_H
