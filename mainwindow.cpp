#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GridSudoku.h"
#include "FinishedInputButton.h"
#include "InputFromSource.h"
#include "StepByStep.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QTime>

class FinishedInputButton;

MainWindow::MainWindow(QWidget *parent) :
    QWidget (parent)
    //ui(new Ui::MainWindow)
{
    this->setLayout(new QHBoxLayout());

    QHBoxLayout* hBoxLayout = qobject_cast<QHBoxLayout*>(this->layout());
    QVBoxLayout* vBoxLayout = new QVBoxLayout(this);

    m_gridSudoku = new GridSudoku();

    m_inputFromSource = new InputFromSource("Input From Source",this);
    m_inputFromSource->resize(150,40);

    m_finishedInput = new FinishedInputButton("Finished Input", this);
    m_finishedInput->resize(150,40);

    m_stepByStep = new StepByStep("Step By Step", this);
    m_stepByStep->resize(150, 40);

    m_finalResult = new QPushButton("Final Result", this);
    m_finalResult->resize(150,40);
    connect(m_finalResult, &QPushButton::clicked, this, &MainWindow::sovleAllSudoku);

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

    hBoxLayout->addWidget(m_gridSudoku);
    hBoxLayout->addLayout(vBoxLayout);
    setLayout(hBoxLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_gridSudoku;
    delete m_inputFromSource;
    delete m_finishedInput;
    delete m_stepByStep;
    delete m_finalResult;
    delete m_quit;
}

void MainWindow::finishedInputButtonClicked()
{
    m_gridSudoku->finishedInputButtonClicked();
}

QVector<Sudoku*>::iterator
MainWindow::getItOfVectorSudoku()
{
    QVector<Sudoku*>::iterator it = m_gridSudoku->getItOfVectorSudoku();
    return it;
}

void MainWindow::sovleAllSudoku()
{
    qDebug() << " start MainWindow::sovleAllSudoku" << QTime::currentTime();

    while (m_stepByStep->solveOneStep())
    {   //no thing to do
        //just wating until all sudoku square will be filled
    }

    QVector<Sudoku*>::iterator it =
                m_gridSudoku->getItOfVectorSudoku();
    bool isGoodJob = true;
    while (it != nullptr)
    {
        if (!(*it)->isHasMainValue())
        {
            isGoodJob = false;
            break;
        }
        ++it;
    }

    if (!isGoodJob)
    {
        qDebug() << "still any sudoku doesn't be filled";
    }
    else
    {
        qDebug() << "GOOD JOB";
    }
    qDebug() << " stop MainWindow::sovleAllSudoku" << QTime::currentTime();
}
