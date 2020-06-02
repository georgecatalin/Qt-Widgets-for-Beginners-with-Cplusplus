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
    QString message;
    message.append("Email: "+ui->txtEmail->text()+"\r\n");
    message.append("Name: "+ui->txtName->text()+"\r\n");

    QString food=getOptions(ui->grpFood);
    message.append("Food: "+food);

    QString activities=getOptions(ui->grpActivities);
    message.append("Activities: "+activities);

    QMessageBox::information(this,"Details",message);

    this->accept();
}

void Dialog::on_buttonBox_rejected()
{
    this->reject();
}

QString Dialog::getOptions(QGroupBox* group)
{
    QString choice;

    foreach (QObject* object, group->children())
    {
        QCheckBox* myCheckbox=qobject_cast<QCheckBox*>(object);

        /* *** Remember:
         * The continue statement breaks one iteration (in the loop), if a specified condition occurs, and
         * continues with the next iteration in the loop.
         *  *** */

        if(!myCheckbox) continue;

        if(myCheckbox->isChecked())
        {
            choice.append(myCheckbox->text()+"\r\n");
        }
    }
    return choice;
}
