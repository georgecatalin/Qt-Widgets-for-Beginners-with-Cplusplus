#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
}

Editor::~Editor()
{
    delete ui;
}

void Editor::on_buttonBox_accepted()
{
    m_music.setAlbum(ui->txtAlbum->text()) ;
    m_music.setArtist(ui->txtArtist->text());
    m_music.setNotes(ui->txtNotes->toPlainText());
    m_music.setRelease(ui->deRelease->date());

    this->accept();
}

void Editor::on_buttonBox_rejected()
{
    this->reject();
}

Music Editor::music() const
{
    return m_music;
}

void Editor::setMusic(const Music &music)
{
    m_music = music;

    ui->txtArtist->setText(m_music.artist());
    ui->txtAlbum->setText(m_music.album());
    ui->txtNotes->setPlainText(m_music.notes());
    ui->deRelease->setDate(m_music.release());
}
