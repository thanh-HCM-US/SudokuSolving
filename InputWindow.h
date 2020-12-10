#ifndef INPUTWINDOW_H
#define INPUTWINDOW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class InputFromSource;

class InputWindow : public QWidget
{
    Q_OBJECT
public:
    explicit InputWindow(InputFromSource *parent = nullptr);

signals:

public slots:

private:
    InputFromSource* m_parent;
};

#endif // INPUTWINDOW_H
