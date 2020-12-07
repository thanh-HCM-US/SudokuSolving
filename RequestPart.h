#ifndef REQUESTPART_H
#define REQUESTPART_H

#include <QWidget>
#include <QPushButton>

class MainWindow;

class RequestPart : public QWidget
{
    Q_OBJECT
public:
    explicit RequestPart(MainWindow *parent = nullptr);
    virtual ~RequestPart();

    void finishedInputButtonClicked();

signals:

public slots:

private:
    QPushButton* m_finishedInput;
    QPushButton* m_stepByStep;
    QPushButton* m_finalResult;
    QPushButton* m_quit;

    //QWidget* m_parent;
    MainWindow* m_parent;
};

#endif // REQUESTPART_H
