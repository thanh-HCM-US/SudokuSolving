#ifndef STEPBYSTEP_H
#define STEPBYSTEP_H

#include <QWidget>
#include <QPushButton>


class StepByStep : public QPushButton
{
    Q_OBJECT
public:
    explicit StepByStep(QString, QWidget *parent = nullptr);

signals:

public slots:
    void solveOneStep();

private:
    QWidget* m_parent;
};

#endif // STEPBYSTEP_H
