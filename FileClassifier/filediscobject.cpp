#include "filediscobject.h"

FileDiscObject::FileDiscObject(): DiscObject(){
}

FileDiscObject::FileDiscObject(std::string root, std::string name) : DiscObject(root, name){
}

long FileDiscObject::getSize(){
    return size;
}

