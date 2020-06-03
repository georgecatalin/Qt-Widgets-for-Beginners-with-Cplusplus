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


void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this,"Hello",ui->txtFirst->text());
    this->accept();
}

void Dialog::on_buttonBox_rejected()
{
    this->reject();
}

void Dialog::next()
{
    int index=ui->stackedWidget->currentIndex();
    index++;

    if(index>ui->stackedWidget->count()) index=ui->stackedWidget->count()-1;

    ui->stackedWidget->setCurrentIndex(index);

    checkButtons();
}

void Dialog::back()
{
    int index=ui->stackedWidget->currentIndex();
    index--;

    if(index<0) index=0;

    ui->stackedWidget->setCurrentIndex(index);

    checkButtons();
}

void Dialog::init()
{
    btnBack=new QPushButton("Back",this);
    btnNext=new QPushButton("Next",this);

    connect(btnBack,&QPushButton::clicked,this,&Dialog::back);
    connect(btnNext,&QPushButton::clicked, this,&Dialog::next);

    ui->buttonBox->addButton(btnBack,QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnNext,QDialogButtonBox::ButtonRole::ActionRole);

    QWidget* qWidget=new QWidget(this);
    QLabel* lblNothing=new QLabel("Add your controls here",this);
    QHBoxLayout* qHBoxLayout=new QHBoxLayout(this);

    /* *** void QBoxLayout::addWidget(QWidget *widget, int stretch = 0, Qt::Alignment alignment = Qt::Alignment())
     * Adds widget to the end of this box layout, with a stretch factor of stretch and
     * alignment alignment.
     * *** */

    qHBoxLayout->addWidget(lblNothing);

    /* *** void QWidget::setLayout(QLayout *layout)
     * Sets the layout manager for this widget to layout.
     * *** */

    qWidget->setLayout(qHBoxLayout);

    ui->stackedWidget->addWidget(qWidget);

    ui->stackedWidget->setCurrentIndex(0);

    checkButtons();
}

void Dialog::checkButtons()
{
    /* *** First Page *** */
    if(ui->stackedWidget->currentIndex()==0)
    {
        btnBack->setEnabled(false);
        btnNext->setEnabled(true);
        return;
    }

    /* *** Last Page *** */
    if(ui->stackedWidget->currentIndex()== ui->stackedWidget->count())
    {
        btnBack->setEnabled(true);
        btnNext->setEnabled(false);
    }

    /* *** Other Pages *** */
    btnBack->setEnabled(true);
    btnNext->setEnabled(true);
}
