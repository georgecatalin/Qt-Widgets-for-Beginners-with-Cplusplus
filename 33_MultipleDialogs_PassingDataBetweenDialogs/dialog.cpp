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


void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this,"Selected","You have selected: \r\n"+ ui->lineEdit->text());
    this->accept();
}

void Dialog::on_buttonBox_rejected()
{
    this->reject();
}

void Dialog::on_pushButton_clicked()
{
    Selections* dialog=new Selections(this);

    //Set the default variable in the new Selections object
    dialog->setSelected(ui->lineEdit->text());

    //Exec (Show the dialog)
    dialog->exec();

    //Read back the new selection
    ui->lineEdit->setText(dialog->selected());
}
