#include "selections.h"
#include "ui_selections.h"

Selections::Selections(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Selections)
{
    ui->setupUi(this);
    init();
}

Selections::~Selections()
{
    delete ui;
}

QString Selections::selected()
{
    return m_selected;
}

void Selections::setSelected(QString value)
{
    m_selected="";
    for(int i=0;i<ui->listWidget->count();i++)
    {
        QListWidgetItem* item=ui->listWidget->item(i);

        if(item->text()==value)
        {
            item->setSelected(true); //Sets the selected state of the item to select.
            m_selected=value;
            return;
        }
    }
}

void Selections::on_buttonBox_accepted()
{
    if(ui->listWidget->currentItem())
    {
        m_selected=ui->listWidget->currentItem()->text();
    }

    this->accept();
}

void Selections::on_buttonBox_rejected()
{
    this->reject();
}

void Selections::init()
{
    QDir root=QDir(":/files/images");

    QFileInfoList myList=root.entryInfoList();

    foreach (QFileInfo info, myList)
    {
        QListWidgetItem* item=new QListWidgetItem(ui->listWidget);
        item->setText(info.absoluteFilePath());
        item->setIcon(QIcon(info.absoluteFilePath()));

        ui->listWidget->addItem(item);
    }

}


