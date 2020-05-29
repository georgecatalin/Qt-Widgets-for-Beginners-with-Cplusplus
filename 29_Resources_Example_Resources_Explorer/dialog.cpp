#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    load();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    this->accept();
}

void Dialog::on_listWidget_itemSelectionChanged()
{
    QListWidgetItem* item=ui->listWidget->currentItem();
    ui->lblName->setText(item->text());
    ui->lblImage->setPixmap(item->icon().pixmap(30,30));
}

void Dialog::load()
{
    QDir qDir(":/");
    scan(qDir.entryInfoList());
}

void Dialog::scan(QFileInfoList myList)
{
    foreach (QFileInfo info, myList)
    {
        /* ***
         * QString QFileInfo::absolutePath() ::: Returns a file's path absolute path. This doesn't include the file name.
         * QString QFileInfo::absoluteFilePath() :::Returns an absolute path including the file name.
        * *** */

        qInfo()<<info.absoluteFilePath();

        if(info.isDir())
        {
              QDir qDir(info.absoluteFilePath());
              scan(qDir.entryInfoList());
        }
        else
        {
           QListWidgetItem* item=new QListWidgetItem(ui->listWidget);
           item->setText(info.absoluteFilePath());
           item->setIcon(QIcon(info.absoluteFilePath()));

           ui->listWidget->addItem(item);
        }

}}
