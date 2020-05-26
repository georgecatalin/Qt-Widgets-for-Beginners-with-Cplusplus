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


void Dialog::on_fontComboBox_currentFontChanged(const QFont &f)
{
    if(ui->lineEdit->font().toString()!=f.toString()) ui->lineEdit->setFont(f);
}

void Dialog::on_buttonBox_accepted()
{
    this->save();
    this->accept();
}

void Dialog::on_buttonBox_rejected()
{
    this->reject();
}

void Dialog::init()
{
  /* *** set the current font in the font combo box as the font of the line edit *** */
   ui->fontComboBox->setCurrentFont(ui->lineEdit->font());
}

void Dialog::load()
{
 /* *** Load the setting and if it is not empty, set the font of the combo box as the one in the setting *** */

    QSettings qSettings("Freelancer","LearnQtWidgets");
    QString myValue=qSettings.value("fontLineEdit","").toString();
    QFont qFont;

    if(!myValue.isEmpty())
    {
        if(qFont.fromString(myValue)==true)
        {
            ui->fontComboBox->setCurrentFont(qFont);
        }
    }
}

void Dialog::save()
{
  /* *** Save the setting with the font in the line edit *** */
    QSettings qSettings("Freelancer","LearnQtWidgets");
    qSettings.setValue("fontLineEdit",ui->lineEdit->font().toString());
}
