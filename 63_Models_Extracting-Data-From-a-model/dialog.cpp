#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    init();
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::init()
{
    /* *** building a simple model *** */
    for (int i=0;i<30;i++)
    {
        qStandardItemModel.appendRow(new QStandardItem(QString("Element number %0").arg(i)));
    }

    /* *** set the view *** */
    ui->listView->setModel(&qStandardItemModel);
}



void Dialog::on_buttonBox_accepted()
{
    /* *** extract the data out of the model *** */
    QStringList myList;

    for (int i=0;i<30;i++)
    {
        QStandardItem* itemOfTheModel=qStandardItemModel.item(i,0); // same as qStandardItemModel.item(i) as column is default to 0 in the definition of item()
        myList.append(itemOfTheModel->text());
    }

    /* *** transpose the QStringList to a string *** */
    QString myMessage=myList.join("\r\n");

    QMessageBox::information(this,"Extracted data from the model", myMessage);

    this->accept();
}

void Dialog::on_buttonBox_rejected()
{
    this->reject();
}

