#ifndef ABSTARCTDISCOBJECT_H
#define ABSTARCTDISCOBJECT_H

#include <string>

using std::string;

class DiscObject
{
    string root; // PathDiscObject* root; - так можно???
    string name;
    string create_time;

public:
    DiscObject();
    DiscObject(string root, string name);
    string getRoot();
    string getName();
    string getCreateTime();

protected:
    void init();
};

#endif // ABSTARCTDISCOBJECT_H
