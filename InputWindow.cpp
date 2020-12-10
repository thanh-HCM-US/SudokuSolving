#include "InputWindow.h"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include "InputFromSource.h"
#include <QFileDialog>
#include <QMessageBox>

InputWindow::InputWindow(InputFromSource *parent)
    : QWidget (parent),
      m_parent(parent)
{
    qDebug() << "khoi tao";

    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open    File"),
                "D://",
                "All File (*.*);;Text File (*.txt)");
    qDebug() << filename;
    m_parent->setPath(filename);
}
