#ifndef MUSIC_H
#define MUSIC_H
#include <string>
#include <id3/tag.h>
#include <id3/utils.h>
#include <id3/misc_support.h>
#include <id3/readers.h>
#include <id3/io_helpers.h>
#include <string.h>
using namespace dami;

typedef struct Tagstruct {
    char* album = NULL;
    char* composer = NULL;
    char* copyright = NULL;
    char* title = NULL;
    char* picpath = NULL;
    char* year = NULL;
}Tag ;

class Music {
    char* m_name = NULL;
    char* m_path =NULL;
    Tag* m_tag =NULL;

public:
    Music (const char* name = "", const char* path = "");
    virtual ~Music ();
    char* getName ();
    char* getPath ();
    void setName (char* name);
    void setPath (char* path);
    Tag* getTag ();
    void setTag (const ID3_Tag &id3tag, const char* picpath);
    void printTag ();
};

#endif // MUSIC_H
