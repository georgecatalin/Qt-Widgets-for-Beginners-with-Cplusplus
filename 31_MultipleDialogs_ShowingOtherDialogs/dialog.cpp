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


void Dialog::on_btnWIthParent_clicked()
{
    /* *** With Parent *** */
    Dialog2* dialog=new Dialog2(this);
    dialog->show();
}

void Dialog::on_btnWithoutParent_clicked()
{
    /* *** Without Parent *** */
    Dialog2* dialog=new Dialog2(nullptr);
    dialog->show();
}
