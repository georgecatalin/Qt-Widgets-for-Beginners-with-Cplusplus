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


void Dialog::on_pushButton_clicked()
{
    QString myToppings;

    QObjectList myControls=this->children();

    foreach (QObject* control, myControls)
    {
        if(control->inherits("QCheckBox"))
        {
            QCheckBox* myCheckBox=qobject_cast<QCheckBox*>(control);
            if (myCheckBox && myCheckBox->isChecked())
            {
                myToppings += myCheckBox->text()+"\r\n";
            }
        }
    }

    QMessageBox::information(this,"Menu","The order should contain the following ingredients:\r\n"+myToppings);
}
