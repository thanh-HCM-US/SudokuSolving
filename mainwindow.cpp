#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Gridpart.h"
#include "FinishedInputButton.h"
#include "InputFromSource.h"
#include "StepByStep.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>

class FinishedInputButton;

MainWindow::MainWindow(QWidget *parent) :
    QWidget (parent)
    //ui(new Ui::MainWindow)
{
    this->setLayout(new QHBoxLayout());

    QHBoxLayout* hBoxLayout = qobject_cast<QHBoxLayout*>(this->layout());
    QVBoxLayout* vBoxLayout = new QVBoxLayout(this);

    m_gridPart = new GridPart();

    m_inputFromSource = new InputFromSource("Input From Source",this);
    m_inputFromSource->resize(150,40);

    m_finishedInput = new FinishedInputButton("Finished Input", this);
    m_finishedInput->resize(150,40);

    m_stepByStep = new StepByStep("Step By Step", this);
    m_stepByStep->resize(150, 40);

    m_finalResult = new QPushButton("Final Result", this);
    m_finalResult->resize(150,40);

    m_quit = new QPushButton("Quit", this);
    m_quit->resize(150,40);
    connect(m_quit, &QPushButton::clicked, QCoreApplication::instance(), &QCoreApplication::quit);

    vBoxLayout->addStretch(1);
    vBoxLayout->addWidget(m_inputFromSource);
    vBoxLayout->addWidget(m_finishedInput);
    vBoxLayout->addWidget(m_stepByStep);
    vBoxLayout->addWidget(m_finalResult);
    vBoxLayout->addWidget(m_quit);
    vBoxLayout->addStretch(1);

    hBoxLayout->addWidget(m_gridPart);
    hBoxLayout->addLayout(vBoxLayout);
    setLayout(hBoxLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::finishedInputButtonClicked()
{
    m_gridPart->finishedInputButtonClicked();
}

QVector<Sudoku*>::iterator
MainWindow::getItOfVectorSudoku()
{
    QVector<Sudoku*>::iterator it = m_gridPart->getItOfVectorSudoku();
    return it;
}
