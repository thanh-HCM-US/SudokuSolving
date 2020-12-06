#ifndef FINISHEDINPUTBUTTON_H
#define FINISHEDINPUTBUTTON_H

#include <QWidget>
#include <QPushButton>

class FinishedInputButton : public QPushButton
{
    Q_OBJECT
public:
    explicit FinishedInputButton(QString, QWidget *parent = nullptr);

signals:

public slots:

private:
    bool m_clicked;
};

#endif // FINISHEDINPUTBUTTON_H
