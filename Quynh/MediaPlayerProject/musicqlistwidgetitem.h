#ifndef MusicQListWidgetItem_H
#define MusicQListWidgetItem_H
#include <QListWidgetItem>
#include "music.h"

class MusicQListWidgetItem : public QListWidgetItem , public Music
{
public:
    MusicQListWidgetItem(const QString & text);
    MusicQListWidgetItem(const QString & text, const char* name, const char* path);
};

#endif // MusicQListWidgetItem_H
