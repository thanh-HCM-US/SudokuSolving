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
    void setPath(QString string) { qDebug() << string; m_path = string;}

signals:

public slots:
    void showInputWidget();

private:
    QWidget* m_parent;
    QString m_path;
};

#endif // INPUTFROMSOURCE_H
