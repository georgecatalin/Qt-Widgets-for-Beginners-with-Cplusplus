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


void Dialog::on_btnOK_clicked()
{
    QString order="Your order is:\r\n";

    QString icecream=getOption(ui->grpIceCream);
    QString toppings=getOption(ui->grpToppings);
    QString syrup=getOption(ui->grpSyrup);
    QString size=getOption(ui->grpSize);

    order+="Type: "+icecream+"\r\n";
    order+="Topping: "+toppings+"\r\n";
    order+="Syrup: "+syrup+"\r\n";
    order+="Size: "+size+"\r\n";

    QMessageBox::information(this,"Your order",order);

    this->accept();
}

void Dialog::on_btnCancel_clicked()
{
    QMessageBox::critical(this,"What??","You do not want icecream?");
    this->reject();
}

QString Dialog::getOption(QObject* myObject)
{
    QString myOption="None";
    QList<QRadioButton*> myList=myObject->findChildren<QRadioButton*>(QString(),Qt::FindDirectChildrenOnly);

    foreach (QRadioButton* button, myList)
    {
        if(button->isChecked())
        {
            myOption =button->text();
        }
    }

    return myOption;
}
