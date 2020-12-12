#ifndef INPUTFROMSOURCE_H
#define INPUTFROMSOURCE_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>


class InputFromSource : public QPushButton
{
    Q_OBJECT
public:
    explicit InputFromSource(QString, QWidget *parent = nullptr);
    void hehe(){}

signals:

public slots:
    void showInputWidget();

private:
    QWidget* m_parent;
};

#endif // INPUTFROMSOURCE_H
