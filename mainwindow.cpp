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
    GridPart* gridPart = new GridPart();
    RequestPart* requestPart = new RequestPart(this);

    hBoxLayout->addWidget(gridPart);
    hBoxLayout->addWidget(requestPart);
    setLayout(hBoxLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
