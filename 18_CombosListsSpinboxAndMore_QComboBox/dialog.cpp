#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    init();
    load();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_comboBox_currentIndexChanged(int index)
{
 ui->label_2->setText(QString::number(index)+"..."+ui->comboBox->currentText());
}

void Dialog::on_btnSave_clicked()
{
    QSettings qSettings;
    qSettings.setValue("rememberCombobox",ui->comboBox->currentIndex());

    QMessageBox::information(this,"Saved","Selection saved, please close and re-open the application");
}

void Dialog::init()
{
    ui->comboBox->clear();

    for (int i=0;i<20;i++)
    {
        ui->comboBox->addItem("Item number: "+QString::number(i));
    }
}

void Dialog::load()
{
    QSettings qSettings;
    QVariant myValue=qSettings.value("rememberCombobox",0);

    bool convertedOk;
    int index=myValue.toInt(&convertedOk);

    if(!convertedOk)
    {
        QMessageBox::critical(this,"Loading eror","Error while loading the preset value");
        return;
    }

    if(index<ui->comboBox->count())
    {
        ui->comboBox->setCurrentIndex(index);
    }
    else
    {
        ui->comboBox->setCurrentIndex(0);
    }
}
