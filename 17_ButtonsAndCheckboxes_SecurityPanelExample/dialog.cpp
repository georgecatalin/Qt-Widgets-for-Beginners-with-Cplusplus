#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->btnOne,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->btnTwo,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->btnThree,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->btnFour,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->btnFIve,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->btnSix,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->btnSeven,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->btnNine,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->btnZero,&QPushButton::clicked,this,&Dialog::append);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::append()
{
    QPushButton* myButton=qobject_cast<QPushButton*>(sender());

    if(!myButton) return;

    temp.append(myButton->text());
    ui->lblNotify->setText("Typed: "+temp);

    if(code.isEmpty())
    {
        ui->btnSave->setEnabled(true);
        ui->btnVerify->setEnabled(false);
    }
    else
    {
        ui->btnSave->setEnabled(false);
        ui->btnVerify->setEnabled(true);
    }
}


void Dialog::on_btnSave_clicked()
{
    code=temp;
    temp.clear();

    ui->btnSave->setEnabled(false);
    ui->btnVerify->setEnabled(true);

    ui->lblNotify->setText("Please type the code again and click verify.");

    QMessageBox::information(this,"Saved",ui->lblNotify->text());
}

void Dialog::on_btnVerify_clicked()
{
  if(temp==code)
  {
      QMessageBox::information(this,"Code","The codes match.");
  }
  else
  {
      QMessageBox::critical(this,"Code","The codes does not match");
  }

  temp.clear();
  ui->lblNotify->setText("Enter your code and click verify.");
}
