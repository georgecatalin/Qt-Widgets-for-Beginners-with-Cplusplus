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


void Dialog::on_commandLinkButton_clicked()
{
    selectOption(sender());
}

void Dialog::on_commandLinkButton_2_clicked()
{
    selectOption(sender());
}

void Dialog::on_commandLinkButton_3_clicked()
{
    selectOption(sender());
}

void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this,"OK","Closing");
    this->accept();
}

void Dialog::on_buttonBox_rejected()
{
    QMessageBox::critical(this,"Cancel","Closing");
    this->reject();
}

void Dialog::on_buttonBox_helpRequested()
{
    QMessageBox::question(this,"Help","Help me");
}

void Dialog::selectOption(QObject* object)
{
    QCommandLinkButton* myButton=qobject_cast<QCommandLinkButton*>(object);

    if(!myButton) return;

    ui->lblSelected->setText(myButton->text());

    QMessageBox::information(this,myButton->text(),myButton->description());
}
