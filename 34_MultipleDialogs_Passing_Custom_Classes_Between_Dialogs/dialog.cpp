#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPushButton* myButton=new QPushButton("Edit",this);
    ui->buttonBox->addButton(myButton,QDialogButtonBox::ButtonRole::ActionRole);
    connect(myButton,&QPushButton::clicked,this,&Dialog::on_edit);

    m_music.setAlbum("And Justice for All");
    m_music.setArtist("Metallica");
    m_music.setRelease(QDate(1987,7,9));
    m_music.setNotes("Good stuff!!!");

    load();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this,"Selection", ui->plainTextEdit->toPlainText());
    this->accept();
}

void Dialog::on_buttonBox_rejected()
{
    this->reject();
}

void Dialog::on_edit()
{
  Editor* dialog =new Editor(this);
  dialog->setMusic(m_music);
  dialog->exec();

  /* *** after closing the Editor child dialog widget *** */
  m_music=dialog->music();

  load();
  delete(dialog);
}

void Dialog::load()
{
  ui->plainTextEdit->clear();
  ui->plainTextEdit->setReadOnly(true);

  /* *** Set the string you wish to load in the plain edit widget *** */
  QString data;

  data.append("Artist: "+m_music.artist()+"\r\n");
  data.append(("Album: "+m_music.album()+"\r\n"));
  data.append("Notes:"+m_music.notes()+"\r\n");
  data.append("Release:"+m_music.release().toString()+"\r\n");

  ui->plainTextEdit->setPlainText(data);
}
