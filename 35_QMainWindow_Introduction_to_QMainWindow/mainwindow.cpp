#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->plainTextEdit); // setCentralWidget is a function associated to the QWindows object
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
  ui->plainTextEdit->clear();
  ui->statusbar->showMessage("");
  m_filename.clear();
}

void MainWindow::on_actionOpen_triggered()
{
    QString path=QFileDialog::getOpenFileName(this,"Open a file");
    QFile qFile(path);

    if(!qFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"Error",qFile.errorString());
        return;
    }

    QTextStream out(&qFile);
    ui->plainTextEdit->setPlainText(out.readAll());

    ui->statusbar->showMessage(path);

    qFile.close();
    m_filename=path;
}

void MainWindow::on_actionSave_triggered()
{
    QString path=QFileDialog::getSaveFileName(this,"Save file");
    QFile qFile(path);

    if(!qFile.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Error",qFile.errorString());
        return;
    }

    QTextStream in(&qFile);
    in<<ui->plainTextEdit->toPlainText();

    qFile.close();

    ui->statusbar->showMessage("Saved "+ path);
    m_filename=path;
}

void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}

void MainWindow::on_actionSelect_All_triggered()
{
    ui->plainTextEdit->selectAll();
}
