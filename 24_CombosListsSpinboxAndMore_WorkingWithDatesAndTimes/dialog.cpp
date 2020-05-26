#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_timeEdit_userTimeChanged(const QTime &time)
{
    ui->dateTimeEdit->setTime(time);
}

void Dialog::on_dateEdit_userDateChanged(const QDate &date)
{
    ui->dateTimeEdit->setDate(date);
}

void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this,"Selected"," You selected: \t"+ui->dateTimeEdit->dateTime().toString(Qt::DateFormat::LocalDate));
    this->accept();
}

void Dialog::on_buttonBox_rejected()
{
    this->reject();
}
