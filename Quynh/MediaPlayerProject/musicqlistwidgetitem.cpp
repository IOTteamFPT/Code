#include "musicqlistwidgetitem.h"
#include <QListWidgetItem>
MusicQListWidgetItem::MusicQListWidgetItem(const QString & text) :
    QListWidgetItem(text)
{

}

MusicQListWidgetItem::MusicQListWidgetItem(const QString & text, const char* name, const char* path) :
    QListWidgetItem(text),
    Music (name, path)
{

}
