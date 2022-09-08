#ifndef EXAPTIONS_H
#define EXAPTIONS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Exaption{
protected:
    string text;
public:
    virtual string what() = 0;
};

class MathExaption : public Exaption{
public:
    MathExaption(){
        text = "Mathematical error.";
    }
    MathExaption(string text){
        this->text = text;
    }
    string what(){
        return text;
    }
};

class FileException: public Exaption{
public:
    FileException(){
        text = "Error when working with file.";
    }
    FileException(string text){
        this->text = text;
    }
    string what(){
        return text;
    }
};
class FileNotFound: public FileException{
public:
    FileNotFound() :FileException("File not found."){}
};


class DivisionByZero: public MathExaption{
public:
    DivisionByZero() : MathExaption("Error. Division by 0."){
    }
};

double checkDiv(int a, int b){
    if(b == 0) throw DivisionByZero();
    else
        return (double)a / b;
}

void openFile(string path){
    ifstream in(path);
    if(in.is_open()){
        cout << "File is opened.";
    } else {
        throw FileNotFound();
        in.close(); // - он не открыт
    }
}

void test_exaption(){
    try {
        checkDiv(5, 2);
        openFile("adfdf.txt");
        checkDiv(5, 0);
    }
    catch (DivisionByZero ex) {
        cout << ex.what() << endl;
    }
    catch (FileNotFound ex){
        cout << ex.what() << endl;
    }
}

#endif // EXAPTIONS_H
