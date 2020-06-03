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
    this->accept();
}

void Dialog::hrClicked()
{
    QMessageBox::information(this,"HR","You sent the info to HR");
}

void Dialog::legalClicked()
{
    QMessageBox::information(this,"Legal","You sent the info to Legal");
}

void Dialog::nextClicked()
{
    int tabIndex=ui->tabWidget->currentIndex();
    int max=ui->tabWidget->count()-1;

    tabIndex++;

    if(tabIndex>max) tabIndex=max;

    ui->tabWidget->setCurrentIndex(tabIndex);
}

void Dialog::backClicked()
{
    int tabIndex=ui->tabWidget->currentIndex();
    int min=0;

    tabIndex--;

    if(tabIndex<min) tabIndex=0;

    ui->tabWidget->setCurrentIndex(tabIndex);
}

void Dialog::init()
{
    /* *** Create two buttons in the first tab *** */
    QPushButton* btnBack=new QPushButton("Back",this);
    QPushButton* btnNext=new QPushButton("Next",this);

    connect(btnBack,&QPushButton::clicked,this,&Dialog::backClicked);
    connect(btnNext,&QPushButton::clicked,this,&Dialog::nextClicked);

    /* *** Position the buttons to the user interface *** */
    ui->buttonBox->addButton(btnBack,QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnNext,QDialogButtonBox::ButtonRole::ActionRole);

    /* *** Update the tabs *** */
    ui->tabWidget->setTabText(0,"Profile");
    ui->tabWidget->setTabText(1,"Notes");

    /* *** Add a new tab *** */
    QWidget* qWidget=new QWidget(this); //using 'this' which is the dialog object as a parent ensures no memory leaks, once the dialog is closed
    ui->tabWidget->addTab(qWidget,"Send");

    /* *** Create two buttons in the newly added tab *** */
    QPushButton* btnHr=new QPushButton("HR",this);
    QPushButton* btnLegal=new QPushButton("Legal",this);

    connect(btnHr,&QPushButton::clicked,this,&Dialog::hrClicked);
    connect(btnLegal,&QPushButton::clicked,this,&Dialog::legalClicked);

    /* ***  Construct programatically the layout of the new tab, includes widgets *** */

    QVBoxLayout* qVboxLayout=new QVBoxLayout(qWidget);

    /* *** void QBoxLayout::addWidget(QWidget *widget, int stretch = 0, Qt::Alignment alignment = Qt::Alignment())
     * Adds widget to the end of this box layout, with a stretch factor of stretch and alignment alignment.
     * *** */

    qVboxLayout->addWidget(btnHr);
    qVboxLayout->addWidget(btnLegal);

    qWidget->setLayout(qVboxLayout);
}
