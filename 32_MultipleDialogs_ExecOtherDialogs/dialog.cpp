#include "dialog.h"
#include "ui_dialog.h"

/* *** a fantastic guide about pointers:
 * https://medium.com/young-coder/an-illustrated-guide-to-memory-the-stack-the-heap-and-pointers-40a604f7bc53
 * **** */

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

/* *** int QDialog::exec()
 * Shows the dialog as a modal dialog, blocking the program until
 * the user closes it. The function returns a DialogCode result.
 * *** */

/* use show() when you want to be able to create multiple dialogs, use exec()
 * when you want only one dialog and to block to user to take a decision
 *  *** */

void Dialog::on_btnWith_clicked()
{
    Dialog2* dialog=new Dialog2(this);
    dialog->exec();
}

void Dialog::on_btnWithout_clicked()
{
    /* *** Pointers are not deleted automatically.
    * If you open a new dialog without a parent while having the modal without parent
    *  on the screen
    * *** */

    Dialog2* dialog=new Dialog2(nullptr);
    dialog->exec();
}
