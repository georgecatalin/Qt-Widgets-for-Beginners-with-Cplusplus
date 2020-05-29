#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //Needed?
    //Q_INIT_RESOURCE(resources);

    MyLib mylib;
    ui->lineEdit->setText(mylib.message());

    QPixmap img(":/files/images/accept.png");
    ui->label->setPixmap(img);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    accept();
}
