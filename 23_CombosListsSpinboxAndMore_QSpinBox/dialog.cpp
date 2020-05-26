#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->load();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    this->save();
    this->accept();
}

void Dialog::on_buttonBox_rejected()
{
    this->reject();
}

void Dialog::load()
{
    /* *** reset the widgets to default values *** */
    ui->txtName->setText("");
    ui->sbAge->setValue(0);
    ui->sbQty->setValue(0);

    /* *** read the content of the existing file into values of the widgets *** */
    QFile myFile("fisier.dat");

    if(!myFile.exists()) return;

    QDataStream in(&myFile);

    if(!myFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"Error",myFile.errorString());
        return;
    }

    QString name;
    int age;
    double quantity;

    in>>name;
    in>>age;
    in>>quantity;

    ui->txtName->setText(name);
    ui->sbAge->setValue(age);
    ui->sbQty->setValue(quantity);
}

void Dialog::save()
{
    QFile myFile("fisier.dat");

    if(!myFile.open(QIODevice::WriteOnly))
    {
           QMessageBox::critical(this,"Error",myFile.errorString());
    }

    QDataStream out(&myFile);
    out<<ui->txtName->text();
    out<<ui->sbAge->value();
    out<<ui->sbQty->value();

    myFile.close();
    QMessageBox::information(this,"Saved","We have saved the file");
}
