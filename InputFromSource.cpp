#include "InputFromSource.h"
#include <QDebug>
#include <QLineEdit>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include "mainwindow.h"
#include "Sudoku.h"

InputFromSource::InputFromSource(QString string, QWidget *parent)
    : QPushButton (string, parent),
      m_parent(parent)
{
    connect(this, &QPushButton::clicked, this, &InputFromSource::showInputWidget);
}

void InputFromSource::showInputWidget()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open    File"),
                "D://",
                "All File (*.*);;Text File (*.txt)");

    qDebug() << "InputFromSource::showInputWidget start" << QTime::currentTime();
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() <<"Cannot open file for reading";
      }
    QTextStream in(&file);
    QVector<Sudoku*>::iterator itSudoku =
            static_cast<MainWindow*>(m_parent)->getItOfVectorSudoku();
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QRegExp rx("[,]");// match a comma or a space
        QStringList list = line.split(rx, QString::SkipEmptyParts);
        for (QStringList::iterator it = list.begin();
             it != list.end();
             ++it)
        {
            (*itSudoku)->setMainValue((*it).toInt());
            ++itSudoku;
        }
    }
    qDebug() << "InputFromSource::showInputWidget stop" << QTime::currentTime();
}
