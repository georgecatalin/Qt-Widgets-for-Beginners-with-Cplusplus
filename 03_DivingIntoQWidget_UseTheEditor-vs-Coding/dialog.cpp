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


void Dialog::on_btnReject_clicked()
{
 QMessageBox::information(this,"Name","Hello "+ui->txtName->text());
 this->accept(); //Hides the modal dialog and sets the result code to Accepted.
}
