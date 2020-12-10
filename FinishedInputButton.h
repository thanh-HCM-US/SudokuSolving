#ifndef FINISHEDINPUTBUTTON_H
#define FINISHEDINPUTBUTTON_H

#include <QWidget>
#include <QPushButton>
#include "mainwindow.h"

class MainWindow;

class FinishedInputButton : public QPushButton
{
    Q_OBJECT
public:
    explicit FinishedInputButton(QString, MainWindow *parent = nullptr);

signals:

public slots:
    void clicked();

private:
    bool m_clicked;
    MainWindow* m_parent;
};

#endif // FINISHEDINPUTBUTTON_H
