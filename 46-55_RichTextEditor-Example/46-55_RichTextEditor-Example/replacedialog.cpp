#include "replacedialog.h"
#include "ui_replacedialog.h"

ReplaceDialog::ReplaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplaceDialog)
{
    ui->setupUi(this);

    init();
    save();
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}

void ReplaceDialog::on_buttonBox_rejected()
{
    this->reject();
}

void ReplaceDialog::replace()
{
    this->save();
    this->accept();
}

void ReplaceDialog::replaceAll()
{
    this->save();
    m_all=true;
    this->accept();
}

QString ReplaceDialog::replaceText() const
{
    return m_replaceText;
}

QString ReplaceDialog::text() const
{
    return m_text;
}

bool ReplaceDialog::all() const
{
    return m_all;
}

void ReplaceDialog::init()
{
    QPushButton* btnReplace=new QPushButton("Replace", this);
    QPushButton* btnReplaceAll=new QPushButton("ReplaceAll",this);

    connect(btnReplace,&QPushButton::clicked,this,&ReplaceDialog::replace);
    connect(btnReplaceAll,&QPushButton::clicked,this,&ReplaceDialog::replaceAll);

    ui->buttonBox->addButton(btnReplace,QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnReplaceAll,QDialogButtonBox::ButtonRole::ActionRole);
}

void ReplaceDialog::save()
{
    m_text=ui->txtFind->text();
    m_replaceText=ui->txtReplace->text();

    m_all=false; //boolean for replacing all at once
}
