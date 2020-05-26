#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->chkEnabled->setChecked(ui->txtTest->isEnabled());
    ui->chkReadOnly->setChecked(ui->txtTest->isReadOnly());
    ui->chkClearButton->setChecked(ui->txtTest->isClearButtonEnabled());

    QMetaEnum qMetaEnum=QMetaEnum::fromType<QLineEdit::EchoMode>(); //actual qMetaEnum is a key, value pair

    for (int i=0;i<qMetaEnum.keyCount();i++)
    {
        /* ***
         * const char *QMetaEnum::valueToKey(int value)
         * Returns the string that is used as the name of the given enumeration value,
         * or nullptr if value is not defined.
        *** */

        /* ***
         * int QMetaEnum::value(int index)
         * Returns the value with the given index; or returns -1 if there is no such value.
         * *** */

      ui->cmbEcho->addItem(qMetaEnum.valueToKey(i),qMetaEnum.value(i));
    }
}

Dialog::~Dialog()
{
    delete ui;
}

/* ***
 * num QLineEdit::EchoMode
 * This enum type describes how a line edit should display its contents.

 * Description
 * QLineEdit::Normal =0
 * Display characters as they are entered. This is the default.

 * QLineEdit::NoEcho =1
 * Do not display anything. This may be appropriate for passwords where even the
 * length of the password should be kept secret.
 *
 * QLineEdit::Password=2
 * Display platform-dependent password mask characters instead of the characters
 * actually entered.
 *
 * QLineEdit::PasswordEchoOnEdit=3
 * Display characters as they are entered while editing otherwise display characters
 *  as with Password.
* ***/


void Dialog::on_cmbEcho_currentIndexChanged(int index)
{
    QMetaEnum qMetaEnum=QMetaEnum::fromType<QLineEdit::EchoMode>();

    /* ***
     * int QMetaEnum::keyToValue() const
     * Returns the integer value of the given enumeration key, or -1 if key is not defined.
     * ***/

    int myValue=qMetaEnum.keyToValue(ui->cmbEcho->currentText().toLocal8Bit().data());
    /* *** used
     * currentText().toLocal8Bit().data() TO COVERT FROM QSTRING TO const char *
     * ***  */
     QLineEdit::EchoMode mode=static_cast<QLineEdit::EchoMode>(myValue);

    ui->txtTest->setEchoMode(mode);

}

void Dialog::on_txtDefault_textChanged(const QString &arg1)
{
    ui->txtTest->setText(arg1);
}

void Dialog::on_chkEnabled_toggled(bool checked)
{
    ui->txtTest->setEnabled(checked);
}

void Dialog::on_chkReadOnly_toggled(bool checked)
{
   ui->txtTest->setReadOnly(checked);
}

void Dialog::on_chkClearButton_toggled(bool checked)
{
    ui->txtTest->setClearButtonEnabled(checked);
}

void Dialog::on_buttonBox_accepted()
{
 QMessageBox::information(this,"Entered:","You entered: "+ui->txtTest->text());
 this->accept();
}
