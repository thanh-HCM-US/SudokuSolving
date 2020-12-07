#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Gridpart.h"
#include "RequestPart.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QWidget (parent)
    //ui(new Ui::MainWindow)
{
    this->setLayout(new QHBoxLayout());

    QHBoxLayout* hBoxLayout = qobject_cast<QHBoxLayout*>(this->layout());

    m_gridPart = new GridPart();
    m_requestPart = new RequestPart(this);

    hBoxLayout->addWidget(m_gridPart);
    hBoxLayout->addWidget(m_requestPart);
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
