#ifndef MAN_H
#define MAN_H
#include <iostream>
#include <string>

using namespace std;

class Man{
private:
    string name;
public:
    Man() {}
    Man(string name){
        this->name = name;
    }

    string getName() const{
        return name;
    }

    friend ostream& operator << (ostream& out, Man& man){
        out << man.name;
        return out;
    }
};


#endif // MAN_H
