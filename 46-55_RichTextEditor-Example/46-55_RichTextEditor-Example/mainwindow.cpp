#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->textEdit);

    m_path="";
    m_changed=false;

    newFile();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    checkSaved();
    newFile();
}

void MainWindow::on_actionOpen_triggered()
{
    checkSaved();
    openFile();
}

void MainWindow::on_actionSave_triggered()
{
    /* *** If something special required, do here *** */
    saveFile(m_path);
}

void MainWindow::on_actionSave_As_triggered()
{
    saveFileAs();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionFind_triggered()
{

}

void MainWindow::on_actionReplace_triggered()
{

}

void MainWindow::on_actionSelect_All_triggered()
{
    ui->textEdit->selectAll();
}

void MainWindow::on_actionZoom_In_triggered()
{
    ui->textEdit->zoomIn(3);
}

void MainWindow::on_actionZoom_out_triggered()
{
    ui->textEdit->zoomOut(3);
}

void MainWindow::on_actionBold_triggered()
{

}

void MainWindow::on_actionItalic_triggered()
{

}

void MainWindow::on_actionUnderline_triggered()
{

}

void MainWindow::on_actionStrikethrough_triggered()
{

}

void MainWindow::on_actionColor_triggered()
{

}

void MainWindow::on_actionFont_triggered()
{

}

void MainWindow::on_actionHelp_triggered()
{

}

void MainWindow::on_actionAbout_triggered()
{

}

void MainWindow::on_textEdit_textChanged()
{
    m_changed=true;
}

void MainWindow::newFile()
{
    ui->textEdit->clear();
    ui->statusbar->showMessage("New File");

    m_changed=false;
    m_path="";
}

void MainWindow::openFile()
{
    QString path=QFileDialog::getOpenFileName(this,"Open file",QString(),"Text Format files (*.txt);;All files (*.*)");
    if(path.isEmpty()) return;

    QFile qFile(path);
    if(!qFile.open(QIODevice::ReadOnly))
    {
       QMessageBox::critical(this,"Error",qFile.errorString());
       return;
    }

    QTextStream stream(&qFile);
    ui->textEdit->setHtml(stream.readAll());

    qFile.close();

    m_changed=false;
    m_path=path;

    ui->statusbar->showMessage("Open file: "+ path);
}

void MainWindow::saveFile(QString path)
{
    if(path.isEmpty())
    {
        saveFileAs();
        return;
    }

    QFile qFile(path);

    if(!qFile.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Error",qFile.errorString());
        ui->statusbar->showMessage("Error when saving file.");
        return;
    }

    QTextStream stream(&qFile);
    stream<<ui->textEdit->toHtml();

    qFile.close();

    m_changed=false;
    m_path=path;

    ui->statusbar->showMessage("Saved file to "+ path);
}

void MainWindow::saveFileAs()
{
    QString path=QFileDialog::getSaveFileName(this,"Save file as: ");
    if(path.isEmpty()) return;

    saveFile(path);
}

void MainWindow::checkSaved()
{
    if(m_changed==false) return;

    QMessageBox::StandardButton myValue=QMessageBox::question(this,"Save file?","You have changes in your file. Would you like to save it?");

    if(myValue!=QMessageBox::StandardButton::Yes) return;

    if(m_path.isEmpty())
    {
        saveFileAs();
    }
    else
    {
        saveFile(m_path);
    }
}


void MainWindow::closeEvent(QCloseEvent *event)
{

    event->accept();
}

