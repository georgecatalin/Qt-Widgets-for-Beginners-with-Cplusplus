#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //Allow resize
    Qt::WindowFlags flags=0;
    flags |= Qt::WindowMinMaxButtonsHint; //Shows minimize and maximize button, allows user to resize windows
    flags |=Qt::WindowContextHelpButtonHint;

}

Dialog::~Dialog()
{
    delete ui;
}

