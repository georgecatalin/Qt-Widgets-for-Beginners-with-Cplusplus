#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->btnCheckable->setChecked(true);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnCheckable_clicked()
{
    qDebug()<<"btnCheckable is set to: "<<ui->btnCheckable->isChecked();
}

void Dialog::on_btnAutoRepeat_clicked()
{
    qInfo()<<" Clicked the autorepeat button";
}

void Dialog::on_btnDefault_clicked()
{
    qInfo()<<"Default button clicked";
}

void Dialog::on_btnQuit_clicked()
{
    this->accept();
}

void Dialog::on_btnIsChecked_clicked()
{
    QString myMessage;

    if(ui->btnCheckable->isChecked())
    {
        myMessage="Yes, it is checked!";
    }
    else
    {
        myMessage="No, it is not checked!";
    }

    QMessageBox::information(this,"Check verification",myMessage);
}

void Dialog::on_btnToggleAutoRepeat_clicked()
{
    bool myValue=!ui->btnAutoRepeat->autoRepeat();

    ui->btnAutoRepeat->setAutoRepeat(myValue);
    qDebug()<<"Repeat:"<<ui->btnAutoRepeat->autoRepeat();
}

void Dialog::on_btnToggleDefault_clicked()
{
  bool myValue=!ui->btnDefault->isDefault();

  qDebug()<<"Default on the btnDefault:"<<ui->btnDefault->isDefault();
}
