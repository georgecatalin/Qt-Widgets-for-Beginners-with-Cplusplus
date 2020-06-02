#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    m_selected=ui->comboBox->currentText();
    this->accept();

}

void Dialog::on_buttonBox_rejected()
{
    this->reject();
}

QString Dialog::selected() const
{
    return m_selected;
}

void Dialog::setList(QStringList list)
{
    ui->comboBox->addItems(list);
}

