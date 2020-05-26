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

void Dialog::init()
{
    ui->comboBox->setEditable(true);

    ui->buttonBox->addButton("Clear",QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton("Remove",QDialogButtonBox::ButtonRole::ActionRole);
}

void Dialog::load()
{
    QSettings qSettings;
    ui->comboBox->setCurrentText(qSettings.value("combo","").toString());

    int comboSize=qSettings.beginReadArray("comboArray");
    for(int i=0;i<comboSize;i++)
    {
        qSettings.setArrayIndex(i);
        ui->comboBox->addItem(qSettings.value("itemToCombo","").toString());
    }
    qSettings.endArray();


    int listSize=qSettings.beginReadArray("listArray");
    for (int i=0;i<listSize;i++)
    {
        qSettings.setArrayIndex(i);
        ui->listWidget->addItem(qSettings.value("itemInList","").toString());
    }

    qSettings.endArray();
}

void Dialog::save()
{
    QSettings qSettings;
    qSettings.clear();

    qSettings.setValue("combo",ui->comboBox->currentText());

    qSettings.beginWriteArray("comboArray");
    for (int i=0;i<ui->comboBox->count();i++)
    {
        qSettings.setArrayIndex(i);
        qSettings.setValue("itemInCombo",ui->comboBox->itemText(i));
    }
    qSettings.endArray();

    qSettings.beginWriteArray("listArray");
    for (int i=0;i<ui->listWidget->count();i++)
    {
        qSettings.setArrayIndex(i);
        qSettings.setValue("itemInList",ui->listWidget->item(i)->text());
    }
    qSettings.endArray();
}


void Dialog::on_btnAdd_clicked()
{
    if(ui->comboBox->findText(ui->comboBox->currentText())<0)
    {
        ui->comboBox->addItem(ui->comboBox->currentText());
    }

    ui->listWidget->addItem(ui->comboBox->currentText());
}

void Dialog::on_buttonBox_clicked(QAbstractButton* button)
{
    qDebug()<<button->text();

    if(button->text().contains("OK"))
    {
        this->save();
        this->accept();
        return;
    }

    if(button->text().contains("Cancel"))
    {
        this->reject();
        return;
    }

    if(button->text().contains("Clear"))
    {
        ui->comboBox->clear();
        ui->listWidget->clear();
        return;
    }

    /* *** This button only deletes the selected items *** */
    if(button->text().contains("Remove"))
    {
        QList<QListWidgetItem*> myList= ui->listWidget->selectedItems();

        foreach (QListWidgetItem* element, myList)
        {
            ui->listWidget->removeItemWidget(element);
            delete element;
        }
        return;
    }
}
