#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->btnConnect,&QPushButton::clicked,this,&Dialog::doStuffs);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::doStuffs()
{
    qInfo()<<"Clicked"<<QDateTime::currentDateTime().toString();
    this->accept(); //Will close the form
}


void Dialog::on_btnEditor_clicked()
{
    qDebug()<<"Extra stuff";
    doStuffs();
}
