#include "music.h"

Music::Music()
{

}

QString Music::album() const
{
    return m_album;
}

void Music::setAlbum(const QString &album)
{
    m_album = album;
}

QString Music::artist() const
{
    return m_artist;
}

void Music::setArtist(const QString &artist)
{
    m_artist = artist;
}

QString Music::notes() const
{
    return m_notes;
}

void Music::setNotes(const QString &notes)
{
    m_notes = notes;
}

QDate Music::release() const
{
    return m_release;
}

void Music::setRelease(const QDate &release)
{
    m_release = release;
}
