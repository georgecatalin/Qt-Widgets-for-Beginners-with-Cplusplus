#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);

    init();
    save();
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::on_buttonBox_accepted()
{
    this->save();
    this->accept();
}

void FindDialog::on_buttonBox_rejected()
{
    this->reject();
}

void FindDialog::goBack()
{
    this->save();
    m_backwards=true;
    this->accept();
}

QString FindDialog::text() const
{
    return m_text;
}

void FindDialog::init()
{
    QPushButton* btnBack=new QPushButton("Back",this);
    connect(btnBack,&QPushButton::clicked,this,&FindDialog::goBack);

    ui->buttonBox->addButton(btnBack,QDialogButtonBox::ButtonRole::ActionRole); // when 'ActionRole' button goes to the left of 'Reject'
}

void FindDialog::save()
{
    /* *** This saves the content of the variables *** */
    m_text=ui->lineEdit->text();
    m_caseSensitive=ui->chkCaseSensitive->isChecked();
    m_wholeWords=ui->chkMatchWholeWord->isChecked();
    m_backwards=false;
}

bool FindDialog::backwards() const
{
    return m_backwards;
}

bool FindDialog::wholeWords() const
{
    return m_wholeWords;
}

bool FindDialog::caseSensitive() const
{
    return m_caseSensitive;
}
