#ifndef REQUESTPART_H
#define REQUESTPART_H

#include <QWidget>
#include <QPushButton>

class RequestPart : public QWidget
{
    Q_OBJECT
public:
    explicit RequestPart(QWidget *parent = nullptr);
    virtual ~RequestPart();

signals:

public slots:

private:
    QPushButton* m_finishedInput;
    QPushButton* m_stepByStep;
    QPushButton* m_finalResult;
    QPushButton* m_quit;
};

#endif // REQUESTPART_H
