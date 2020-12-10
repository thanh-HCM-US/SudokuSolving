include "RequestPart.h"
#include "FinishedInputButton.h"
#include <QVBoxLayout>
#include <QCoreApplication>

#include "mainwindow.h"
class MainWindow;

RequestPart::RequestPart(MainWindow *parent)
    : QWidget(parent),
      m_parent(parent)
{
    QVBoxLayout* vBoxLayout = new QVBoxLayout(this);

    //m_finishedInput = new FinishedInputButton("Finished Input", this);
    //m_finishedInput->resize(150,40);

    m_stepByStep = new QPushButton("Step By Step", this);
    m_stepByStep->resize(150, 40);

    m_finalResult = new QPushButton("Final Result", this);
    m_finalResult->resize(150,40);

    m_quit = new QPushButton("Quit", this);
    m_quit->resize(150,40);
    connect(m_quit, &QPushButton::clicked, QCoreApplication::instance(), &QCoreApplication::quit);

    vBoxLayout->addStretch(1);
    vBoxLayout->addWidget(m_finishedInput);
    vBoxLayout->addWidget(m_stepByStep);
    vBoxLayout->addWidget(m_finalResult);
    vBoxLayout->addWidget(m_quit);
    vBoxLayout->addStretch(1);

    setLayout(vBoxLayout);
}

RequestPart::~RequestPart()
{
    delete m_stepByStep;
    delete m_finalResult;
}

void RequestPart::finishedInputButtonClicked()
{
    m_parent->finishedInputButtonClicked();
}
