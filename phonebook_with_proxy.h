#ifndef PHONEBOOK_WITH_PROXY_H
#define PHONEBOOK_WITH_PROXY_H
#include <iostream>

using namespace std;

class phonebook_with_proxy
{
    const string dbfilename = "dbfile.txt";
public:
    phonebook_with_proxy();    
    void generate_dbfile(int size);
};



#endif // PHONEBOOK_WITH_PROXY_H
