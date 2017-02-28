#include <music.h>
#include <QDebug>
#include <id3/tag.h>
#include <id3/utils.h>
#include <id3/misc_support.h>
#include <id3/readers.h>
#include <id3/io_helpers.h>
#include <QFile>
Music::Music (const char* name, const char* path) {
    m_name = new char[sizeof(char)*512];
    m_path = new char[sizeof(char)*512];
    strcpy (m_name, name);
    strcpy (m_path, path);
    m_tag = NULL;
}

char* Music::getName() {
    return m_name;
}

char* Music::getPath() {
    return m_path;
}

Tag* Music::getTag() {
    return m_tag;
}

void Music::setName(char *name) {
    m_name = name;
}

void Music::setPath(char *path) {
    m_path = path;
}

void Music::setTag(const ID3_Tag& id3tag, const char* picpath) {
    if (!m_tag) {
        m_tag = new Tag;
    }
    ID3_Tag::ConstIterator* iter = id3tag.CreateIterator();

    const ID3_Frame* frame = NULL;
    while (NULL != (frame = iter->GetNext())) {
      ID3_FrameID eFrameID = frame->GetID();
      switch (eFrameID) {
        case ID3FID_ALBUM: {
            m_tag->album = ID3_GetString(frame, ID3FN_TEXT);
            //qDebug() << "ALBUM" << m_tag->album;
            break;
        }
        case ID3FID_COMPOSER: {
            m_tag->composer = ID3_GetString(frame, ID3FN_TEXT);
            //qDebug() << "COMPOSER" << m_tag->composer;
            break;
        }
        case ID3FID_COPYRIGHT: {
            m_tag->copyright = ID3_GetString(frame, ID3FN_TEXT);
            //qDebug() << "COPYRIGHT" << m_tag->copyright;
            break;
        }
        case ID3FID_TITLE: {
            m_tag->title = ID3_GetString(frame, ID3FN_TEXT);
            //qDebug() << "TITTLE" << m_tag->title;
            break;
        }
        case ID3FID_YEAR: {
            m_tag->year = ID3_GetString(frame, ID3FN_TEXT);
            //qDebug() << "YEAR" << m_tag->year;
            break;
        }
        case ID3FID_PICTURE: {
            m_tag->picpath = new char[sizeof (char) * 512];
            strcpy(m_tag->picpath, picpath);
            frame->GetField(ID3FN_DATA)->ToFile(m_tag->picpath);
            //qDebug() << "PICTURE" << m_tag->picpath;
            break;
        }
      }
    }
    delete iter;
}

void Music::printTag() {
    qDebug() << "ALBUM" << m_tag->album;
    qDebug() << "COMPOSER" << m_tag->composer;
    qDebug() << "COPYRIGHT" << m_tag->copyright;
    qDebug() << "TITTLE" << m_tag->title;
    qDebug() << "YEAR" << m_tag->year;
}

Music::~Music() {
    if (m_tag) {
        if (m_tag->album) delete [](m_tag->album);
        if (m_tag->composer) delete [](m_tag->composer);
        if (m_tag->copyright) delete [](m_tag->copyright);
        if (m_tag->picpath){
            QFile pic(m_tag->picpath);
            pic.remove();
             delete [](m_tag->picpath);
        }
        if (m_tag->title) delete [](m_tag->title);
        if (m_tag->year) delete [](m_tag->year);
        delete m_tag;
    }
    delete []m_name;
    delete []m_path;
//    qDebug() << "end destructor";
}
