#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    load();

    /* *** Add buttons programatically next and use the icons stored as resources file *** */
    QPushButton* btnAccept=new QPushButton(QIcon(":/else/Image Files/dialog/iconfinder_12_Forbidden_2722398.png"),"OK",this);

    QPushButton* btnReject=new QPushButton("Reject",this);
    btnReject->setIcon(QIcon(":/else/Image Files/dialog/iconfinder_17_Forbidden_2722403.png"));

    /* *** Add the button you built programatically to the QDialogBox widget *** */
    ui->buttonBox->addButton(btnAccept,QDialogButtonBox::ButtonRole::AcceptRole);
    ui->buttonBox->addButton(btnReject,QDialogButtonBox::ButtonRole::RejectRole);

    /* *** connect the signals originated from events to the slots for the newly created button *** */
    connect(btnAccept,&QPushButton::clicked,this,&Dialog::acceptThisObject);
    connect(btnReject,&QPushButton::clicked,this,&QDialog::reject);

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnNew_clicked()
{
    ui->plainTextEdit->clear();
}

void Dialog::on_btnOpen_clicked()
{
    load();
}

void Dialog::on_btnSave_clicked()
{
    save();
    QMessageBox::information(this,"Saved","Your changes have been saved!");
}


void Dialog::closeEvent(QCloseEvent *event)
{
    if(m_saved==false)
    {
        QMessageBox::StandardButton btn=QMessageBox::question(this,"Save file?","Your files was changed. Would you like to save it?");
        if(btn==QMessageBox::StandardButton::Yes) save();
    }
    event->accept();
}
void Dialog::on_plainTextEdit_textChanged()
{
    m_saved=false;
}

void Dialog::load()
{
    QFile qFile("file.txt");

    if(!qFile.exists()) return;

    if(!qFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"Error",qFile.errorString());
        return;
    }

    QTextStream in(&qFile);
    ui->plainTextEdit->setPlainText(in.readAll());

    qFile.close();
    m_saved=true;
}

void Dialog::save()
{
    QFile qFile("file.txt");

    if(!qFile.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Error",qFile.errorString());
        return;
    }

    QTextStream out(&qFile);
    out<<ui->plainTextEdit->toPlainText();

    qFile.close();
    m_saved=true;
}

void Dialog::acceptThisObject()
{
    if(m_saved==false)
    {
        QMessageBox::critical(this,"Need to save?","You have unsaved changes in your file. Will save this automatically.");
        save();
    }

    accept();
}
