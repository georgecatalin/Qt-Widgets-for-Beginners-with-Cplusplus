#ifndef MUSIC_H
#define MUSIC_H

#include <QObject>
#include <QString>
#include <QDate>

/* *** This is the data container class *** */

class Music
{
public:
    Music();

    QString album() const;
    void setAlbum(const QString &album);

    QString artist() const;
    void setArtist(const QString &artist);

    QString notes() const;
    void setNotes(const QString &notes);

    QDate release() const;
    void setRelease(const QDate &release);

private:
    QString m_album;
    QString m_artist;
    QString m_notes;
    QDate m_release;
};

#endif // MUSIC_H
