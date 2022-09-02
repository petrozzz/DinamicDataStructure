#ifndef FILEDISCOBJECT_H
#define FILEDISCOBJECT_H
#include "FileClassifier/discobject.h"

class FileDiscObject : public DiscObject
{
    string root;
    string name;
    long size;
    string create_time;

public:
    FileDiscObject();
    FileDiscObject(string root, string name);
    long getSize();

private:


};

#endif // FILEDISCOBJECT_H
