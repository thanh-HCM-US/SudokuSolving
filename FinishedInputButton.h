#ifndef FINISHEDINPUTBUTTON_H
#define FINISHEDINPUTBUTTON_H

#include <QWidget>
#include <QPushButton>
#include "RequestPart.h"

class RequestPart;

class FinishedInputButton : public QPushButton
{
    Q_OBJECT
public:
    explicit FinishedInputButton(QString, RequestPart *parent = nullptr);

signals:

public slots:
    void clicked();

private:
    bool m_clicked;
    RequestPart* m_parent;
};

#endif // FINISHEDINPUTBUTTON_H
