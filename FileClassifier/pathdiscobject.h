#ifndef PATHDISCOBJECT_H
#define PATHDISCOBJECT_H
#include "discobject.h"
#include <string>

using std::string;

class PathDiscObject: public DiscObject
{
public:
    PathDiscObject();
    PathDiscObject(string root, string name);
};

#endif // PATHDISCOBJECT_H
