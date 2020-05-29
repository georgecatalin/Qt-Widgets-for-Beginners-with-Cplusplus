#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnLoad_clicked()
{
    QFile qFile(":/documents/files/Files/file.txt");

    if(!qFile.exists())
    {
        QMessageBox::critical(this,"File does not exist", "Error, the file does not exist in the resources.");
        return;
    }

    if(!qFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"Error",qFile.errorString());
        return;
    }

    QTextStream in(&qFile);
    ui->plainTextEdit->setPlainText(in.readAll());
    qFile.close();
}

void Dialog::on_btnSave_clicked()
{
    QFile qFile(":/documents/files/Files/file.txt");

    if(!qFile.exists())
    {
        QMessageBox::critical(this,"Error","The file does not exist.");
        return;
    }

    if(!qFile.isWritable())
    {
        QMessageBox::critical(this,"Error-Unwrittable file","This file in not writable.");
        return;
    }
    else
    {
        QMessageBox::information(this,"Writtable file","This file is writtable.");
        return;
    }

    if(!qFile.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Error",qFile.errorString());
        return;
    }



    QTextStream out(&qFile);
    out<< ui->plainTextEdit->toPlainText();


    qFile.close();
}
